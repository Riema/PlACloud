#ifndef FILEOWNCLOUD_H
#define	FILEOWNCLOUD_H

class FileOwnCloud {
public:
    FileOwnCloud(std::string name, std::string adress, int port);
    ~FileOwnCloud();
    void openFilesInDolphin();
private:
    int port; 
    std::string userName;
    std::string cloudAdress;
};

#endif	/* FILEOWNCLOUD_H */

