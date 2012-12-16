#ifndef FILEOWNCLOUD_H
#define	FILEOWNCLOUD_H

#include "../commons.h"

class FileOwnCloud {
public:
    FileOwnCloud();
    ~FileOwnCloud();
    void openFilesInDolphin(QString userName, QString cloudAdress, QString port);
    bool testExistenceOfOwnCloud(QString userName, QString cloudAdress, QString port);
private:
};

#endif	/* FILEOWNCLOUD_H */

