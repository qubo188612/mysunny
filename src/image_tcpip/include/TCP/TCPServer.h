#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <thread>
#include <algorithm>
#include <cctype>
#include <mutex>

#include "rclcpp/rclcpp.hpp"

using namespace std;

#define MAXPACKETSIZE 40960
#define MAX_CLIENT 1000
//#define CODA_MSG 4

struct descript_socket{
	int socket     = -1;
	string ip      = "";
	int id         = -1; 
	std::vector<char> message;
	bool enable_message_runtime = false;
};

class TCPServer
{
	public:
	int setup(int port, vector<int> opts = vector<int>());
	vector<descript_socket*> getMessage();
	void accepted();
	void Send(string msg, int id);
	void Send(char *msg, int length, int id);
	void detach(int id);
	void clean(int id);
        bool is_online();
	string get_ip_addr(int id);
	int get_last_closed_sockets();
	std::string get_last_closed_ip();
	void closed();

	private:
	int sockfd, n, pid;
	struct sockaddr_in serverAddress;
	struct sockaddr_in clientAddress;
	pthread_t serverThread[ MAX_CLIENT ];

	static vector<descript_socket*> newsockfd;
	static char msg[ MAXPACKETSIZE ];
	static vector<descript_socket*> Message;//[CODA_MSG];

	static bool isonline;
	static int last_closed;
	static std::string last_ip;
	static int num_client;
	static int num_client_ID;
	static std::mutex mt;
	static std::mutex fd;
	static void * Task(void * argv);
};

#endif
