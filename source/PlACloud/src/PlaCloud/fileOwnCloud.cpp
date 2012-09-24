#include <sstream>
#include "fileOwnCloud.h"
#include "../commons.h"

FileOwnCloud::FileOwnCloud(std::string name, std::string adress, int port) {
    userName = name;
    cloudAdress = adress;
    this->port = port;
}

void FileOwnCloud::openFilesInDolphin(){
    std::stringstream ss;
    ss << "dolphin webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php";
    system(ss.str().c_str());
}

FileOwnCloud::~FileOwnCloud() {
}

