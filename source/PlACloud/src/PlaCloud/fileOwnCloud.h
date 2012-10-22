#ifndef FILEOWNCLOUD_H
#define	FILEOWNCLOUD_H

#include "../commons.h"

class FileOwnCloud {
public:
    FileOwnCloud();
    ~FileOwnCloud();
    void openFilesInDolphin(std::string userName, std::string cloudAdress, std::string port);
    bool testExistenceOfOwnCloud(std::string userName, std::string cloudAdress, std::string port);
private:
};

#endif	/* FILEOWNCLOUD_H */

