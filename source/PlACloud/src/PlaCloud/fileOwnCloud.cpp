#include "fileOwnCloud.h"
#include <sstream>

FileOwnCloud::FileOwnCloud() {
}

void FileOwnCloud::openFilesInDolphin(std::string userName, std::string cloudAdress, std::string port) {
    std::stringstream ss;
    ss << "(dolphin webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php &)";
    system(ss.str().c_str());
}

FileOwnCloud::~FileOwnCloud() {
}

