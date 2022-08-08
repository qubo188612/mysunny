#include <json/jsonfuction.h>

uint8_t jsonfuction::readJsonFromString(const std::string& mystrIn ,Json::Value *rootOut)
{
    //1.创建工厂对象
    Json::CharReaderBuilder ReaderBuilder;
    ReaderBuilder["emitUTF8"] = true;//utf8支持,不加这句,utf8的中文字符会编程\uxxx
    //2.通过工厂对象创建 json阅读器对象
    std::unique_ptr<Json::CharReader> charread(ReaderBuilder.newCharReader());
    //3.创建json对象
    Json::Value root;
    //4.把字符串转变为json对象,数据写入root
    std::string strerr;
    bool isok = charread->parse(mystrIn.c_str(),mystrIn.c_str()+mystrIn.size(),&root,&strerr);
    if(!isok || strerr.size() != 0){
        return 1;
    }
    *rootOut=root;
    //5.返回有数据的json对象,这个json对象已经能用了
    return 0;
}

void jsonfuction::writeFileFromString(const std::string& filename,const std::string& body)
{
    std::ofstream ofile(filename);
    ofile<<body;
    ofile.close();
}

std::string jsonfuction::readFileIntoString(const char * filename)
{
    std::ifstream ifile(filename);
    if(!ifile.is_open()){
        std::cerr<<"文件打开错误";
    }
    std::ostringstream buf;
    std::string filestr;
    char ch;
    while(buf && ifile.get(ch)){
        buf.put(ch);
    }
    filestr = buf.str();
    return filestr;
}

uint8_t jsonfuction::readJsonFile(const std::string & filename,Json::Value *rootOut)
{
    //1.打开文件
    std::ifstream ifile;
    ifile.open(filename);
    
    //2.创建json读工厂对象
    Json::CharReaderBuilder ReaderBuilder;
    ReaderBuilder["emitUTF8"] = true;//utf8支持，不加这句，utf8的中文字符会编程\uxxx
    
    //3.创建json对象，等会要返回这个对象
    Json::Value root;
    
    //4.把文件转变为json对象，要用到上面的三个变量,数据写入root
    std::string strerr;
    bool ok = Json::parseFromStream(ReaderBuilder,ifile,&root,&strerr);
    if(!ok){
        return 1;
    }
    //5.返回存有数据的json，这个json对象已经能用了
    *rootOut=root;
    return 0;
}

void jsonfuction::writeJsonFile(const std::string & filename,const Json::Value & root)
{
    //1.写json的工厂对象
    Json::StreamWriterBuilder writebuild;
    writebuild["emitUTF8"] = true;//utf8支持,加这句,utf8的中文字符会编程\uxxx
    //2.把json对象转变为字符串
    std::string document = Json::writeString(writebuild,root);
    //3.调用前面的写文件函数,写入文件
    writeFileFromString(filename,document);
}