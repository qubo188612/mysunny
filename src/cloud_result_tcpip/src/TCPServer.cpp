#include "TCP/TCPServer.h" 

/*
char TCPServer::msg[MAXPACKETSIZE];
int TCPServer::num_client;
int TCPServer::num_client_ID;
int TCPServer::last_closed;
std::string TCPServer::last_ip;
bool TCPServer::isonline;
vector<descript_socket*> TCPServer::Message;
vector<descript_socket*> TCPServer::newsockfd;
std::mutex TCPServer::mt;
std::mutex TCPServer::fd;
*/
void* TCPServer::Task(void *arg)
{
	int n;
	struct descript_socket *desc = (struct descript_socket*) arg;
	pthread_detach(pthread_self());

        cerr << "open client[ id:"<< desc->id <<" ip:"<< desc->ip <<" socket:"<< desc->socket<<" send:"<< desc->enable_message_runtime <<" ]" << endl;
	while(rclcpp::ok())
	{
		n = recv(desc->socket, msg, MAXPACKETSIZE, 0);
		if(n != -1) 
		{
			if(n==0)
			{
			   isonline = false;
			   cerr << "close client[ id:"<< desc->id <<" ip:"<< desc->ip <<" socket:"<< desc->socket<<" ]" << endl;
			   last_closed = desc->id;
			   last_ip = desc->ip;
			   close(desc->socket);

			   std::lock_guard<std::mutex> guard(fd);

			   int id = desc->id;
			   auto new_end = std::remove_if(newsockfd.begin(), newsockfd.end(),
                				           		   [id](descript_socket *device)
		                              				   { return device->id == id; });

			   newsockfd.erase(new_end, newsockfd.end());

			   if(num_client>0) num_client--;
			   break;
			}
			desc->message.resize(n);
			for(int i=0;i<n;i++)
			{
				desc->message[i]=msg[i];
			}
	        std::lock_guard<std::mutex> guard(mt);
			Message.push_back( desc );
/*
			for(int i=0;i<newsockfd.size();i++)
			{
				cerr << "newsockfd["<< i 
					 <<"] id:"<< newsockfd[i]->id <<" ip:"<< newsockfd[i]->ip
					 <<" socket:" << newsockfd[i]->socket 
					 <<" enable_message_runtime:"<< newsockfd[i]->enable_message_runtime 
					 << endl;
			}
			for(int i=0;i<Message.size();i++)
			{
				cerr << "Message["<< i 
					 <<"] id:"<< Message[i]->id <<" ip:"<< Message[i]->ip
					 <<" socket:" << Message[i]->socket 
					 <<" enable_message_runtime:"<< Message[i]->enable_message_runtime 
					 << endl;
			}
*/
		}
	//	usleep(600);
		sleep(0);
    }
	if(desc != NULL)
	{
		delete desc;
		desc = NULL;
	}
	cerr << "exit thread: " << this_thread::get_id() << endl;
	pthread_exit(NULL);
	
	return 0;
}

int TCPServer::setup(int port, vector<int> opts)
{
	int opt = 1;
	isonline = false;
	last_closed = -1;
	last_ip.clear();
	sockfd = socket(AF_INET,SOCK_STREAM,0);
 	memset(&serverAddress,0,sizeof(serverAddress));

	for(unsigned int i = 0; i < opts.size(); i++) {
		if( (setsockopt(sockfd, SOL_SOCKET, opts.size(), (char *)&opt, sizeof(opt))) < 0 ) {
			cerr << "Errore setsockopt" << endl; 
      			return -1;
	      	}
	}

	serverAddress.sin_family      = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port        = htons(port);

	if((::bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress))) < 0){
		cerr << "Errore bind" << endl;
		return -1;
	}
	
 	if(listen(sockfd,5) < 0){
		cerr << "Errore listen" << endl;
		return -1;
	}
	num_client = 0;
	num_client_ID = 0;
	isonline = true;
	return 0;
}

void TCPServer::accepted()
{
	socklen_t sosize    = sizeof(clientAddress);
	descript_socket *so = new descript_socket;
	so->socket          = accept(sockfd,(struct sockaddr*)&clientAddress,&sosize);
	so->id              = num_client_ID;
	so->ip              = inet_ntoa(clientAddress.sin_addr);
	newsockfd.push_back( so );
	cerr << "accept client[ " << num_client <<  "," << newsockfd.size() <<  
						  "] id:" << newsockfd[num_client]->id << 
	                      " ip:" << newsockfd[num_client]->ip << 
		              " socket:" << newsockfd[num_client]->socket << " ]" << endl;
	pthread_create(&serverThread[num_client], NULL, &Task, (void *)newsockfd[num_client]);
	isonline=true;
	num_client++;
	num_client_ID++;
}

vector<descript_socket*> TCPServer::getMessage()
{
	std::lock_guard<std::mutex> guard(mt);
	return Message;
}

void TCPServer::Send(string msg, int id)
{
	for(int n=0;n<newsockfd.size();n++)
	{
		if(id==newsockfd[n]->id)
		{
			if(send(newsockfd[n]->socket,msg.c_str(),msg.length()+1,MSG_NOSIGNAL)==-1)
			{
				close(newsockfd[n]->socket);
			}
		}
	}
}

void TCPServer::Send(char *msg, int length, int id)
{
	for(int n=0;n<newsockfd.size();n++)
	{
		if(id==newsockfd[n]->id)
		{
			if(send(newsockfd[n]->socket,msg,length,MSG_NOSIGNAL)==-1)
			{
				close(newsockfd[n]->socket);
			}
		}
	}
}

int TCPServer::get_last_closed_sockets()
{
	return last_closed;
}

std::string TCPServer::get_last_closed_ip()
{
	return last_ip;
}

void TCPServer::clean(int id)
{
	std::lock_guard<std::mutex> guard(mt);
	Message.erase(Message.begin()+id);
	memset(msg, 0, MAXPACKETSIZE);
}

string TCPServer::get_ip_addr(int id)
{
	return newsockfd[id]->ip;
}

bool TCPServer::is_online() 
{
	return isonline;
}

void TCPServer::detach(int id)
{
	for(int n=0;n<newsockfd.size();n++)
	{
		if(id==newsockfd[n]->id)
		{
			close(newsockfd[n]->socket);
			newsockfd[n]->ip = "";
			newsockfd[n]->id = -1;
			newsockfd[n]->message.clear();
		}
	}
} 

void TCPServer::closed() 
{
	close(sockfd);
}

