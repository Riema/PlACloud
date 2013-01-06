#ifndef FILEOWNCLOUD_H
#define	FILEOWNCLOUD_H

#include "../commons.h"

/**
 * Is responsible for handling the File part of program.
 */
class FileOwnCloud {
public:
    /**
     * Creates File module.
     */
    FileOwnCloud();

    /**
     * Destroys File module.
     */
    ~FileOwnCloud();

    /**
     * According to given parametres opens file browser Doplhin and
     * feeds him with address of ownCloud WebDAV to connect.
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void openFilesInDolphin(QString userName, QString cloudAdress, QString port);

    /**
     * It tests if on given address and port is ownCloud instance with given user.
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is runnings
     * @return true if the ownCloud exists else false
     */
    bool testExistenceOfOwnCloud(QString userName, QString cloudAdress, QString port);
private:
};

#endif	/* FILEOWNCLOUD_H */

