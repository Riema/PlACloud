#include "fileOwnCloud.h"
#include <sstream>
#include <kio/job.h>
#include <kurl.h>

FileOwnCloud::FileOwnCloud() {
}

bool FileOwnCloud::testExistenceOfOwnCloud(std::string userName, std::string cloudAdress, std::string port) {
    /*std::stringstream ss;
    ss << "webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php/.conf";
    KIO::StatJob sj = KIO::stat(KUrl(ss.str().c_str()));*/
}

void FileOwnCloud::openFilesInDolphin(std::string userName, std::string cloudAdress, std::string port) {
    std::stringstream ss;
    ss << "(dolphin webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php &)";
    system(ss.str().c_str());
}

FileOwnCloud::~FileOwnCloud() {
}

