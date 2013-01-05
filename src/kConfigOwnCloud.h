#ifndef KCONFIGOWNCLOUD_H
#define	KCONFIGOWNCLOUD_H

#include "../commons.h"

/**
 *  Is responsible for handling the KConfig part of program.
 */
class KConfigOwnCloud {
public:
    /**
     * Creates KConfig module
     */
    KConfigOwnCloud();
    
    /**
     * Destroys KConfig module
     */
    ~KConfigOwnCloud();
    
    /**
     * Method uploads KConfig files from standard KConfig directory to ownCloud
     * @param userName name of ownCloud user 
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void uploadConfigutarion(QString name, QString adress, QString port);
    
    /**
     * It gets list of directories with KConfig from ownCloud, 
     * it changes their name to date string representation readable by people
     * "yyyy-mm-dd hh:mm:ss"
     * @return list of date and time of directories 
     */
    QStringList getListOfDirectories();
private:
    /**
     * Creates directory in ownCloud to store the KConfig in.
     * The name begins with "." so Linux file browser doesn't show it by default.
     * The directory name is ".conf-placloud"
     * @param userName name of ownCloud user 
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void createConfigDirectory(QString name, QString adress, QString port);    
};

#endif	/* KCONFIGOWNCLOUD_H */

