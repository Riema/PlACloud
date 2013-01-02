#ifndef KCONFIGOWNCLOUD_H
#define	KCONFIGOWNCLOUD_H

#include "../commons.h"

class KConfigOwnCloud {
public:
    KConfigOwnCloud();
    ~KConfigOwnCloud();
    void uploadConfigutarion(QString name, QString adress, QString port);
    QStringList getListOfDirectories();
private:
    void createConfigDirectory(QString name, QString adress, QString port);    
};

#endif	/* KCONFIGOWNCLOUD_H */

