#include <json/json.h>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>

class jsonfuction
{
public:
    //read json from mystrIn, if succeed return 0
    uint8_t readJsonFromString(const std::string& mystrIn,Json::Value *rootOut);

    //read json from jsonfile, if succeed return 0
    uint8_t readJsonFile(const std::string & filename,Json::Value *rootOut);

    void writeJsonFile(const std::string & filename,const Json::Value & root);

private:

    void writeFileFromString(const std::string& filename,const std::string& body);

    std::string readFileIntoString(const char * filename);
};