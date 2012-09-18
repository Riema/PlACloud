#ifndef KCONFIGOWNCLOUD_H
#define	KCONFIGOWNCLOUD_H

class KConfigOwnCloud {
public:
    KConfigOwnCloud(std::string name, std::string adress, int port);
    ~KConfigOwnCloud();
private:
    void createConfigDirectory();
    void uploadConfigutarion();
    int port; 
    std::string userName;
    std::string cloudAdress;
};

#endif	/* KCONFIGOWNCLOUD_H */

