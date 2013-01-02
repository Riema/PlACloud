#ifndef KCONFIGOWNCLOUD_H
#define	KCONFIGOWNCLOUD_H

class KConfigOwnCloud {
public:
    KConfigOwnCloud();
    ~KConfigOwnCloud();
    void uploadConfigutarion(QString name, QString adress, QString port);
private:
    void createConfigDirectory(QString name, QString adress, QString port);    
};

#endif	/* KCONFIGOWNCLOUD_H */

