#ifndef KCONFIGOWNCLOUD_H
#define	KCONFIGOWNCLOUD_H

#include "../commons.h"
#include <KIO/Job>
#include <QObject>

class ListReturnWithParamIntf {
public:
    virtual void onListReturnWithParam(QStringList list, void *param) = 0;
    virtual ~ListReturnWithParamIntf() {};
};

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
    virtual ~KConfigOwnCloud();

    /**
     * Method uploads KConfig files from standard KConfig directory to ownCloud
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void uploadConfigutarion(QString name, QString adress, QString port);

    /**
     * It gets list of directories with KConfig from ownCloud,
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     * @param gui instance for asynchronous callback
     * @param facade instance for asynchronous callback
     */
    void getListOfDirectories(QString name, QString adress, QString port, void *gui, ListReturnWithParamIntf *facade);
        
    /**
     * Callback the directory retrieving results
     * @param list list of string represented directories
     * @param gui instance for asynchronous callback
     * @param facade instance for asynchronous callback
     */
    void returnListOfDirectories(QStringList list,  void *gui, ListReturnWithParamIntf *facade);
    
    /**
     * Restore given KConfig directory
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     * @param directory identify directory to restore
     */
    void restoreKConfigDirectory(QString name, QString adress, QString port, QString directory);
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

/**
 * Class that does the asynchronous job of retrieving the list of directories
 */
class ListJobRunner : public QObject {
    Q_OBJECT // for signals and slots
public:
    /**
     * Creates the ListJob handling class
     * @param gui instance for asynchronous callback deep 2
     * @param facade instance for asynchronous callback deep 1
     * @param owner  instance for asynchronous callback deep 0
     */
    ListJobRunner(void *gui, ListReturnWithParamIntf *facade, KConfigOwnCloud *owner);

    /**
     * Destroyes the ListJob handling class
     */
    virtual ~ListJobRunner();

    /**
     * start the ListJob on ownCloud instance with given parameters
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void runJob(QString name, QString adress, QString port);
public slots:
    /**
     * It changes directories name to date string representation readable by people
     * "yyyy-mm-dd hh:mm:ss"
     * @param job job that ended
     * @param list List of found directories
     */
    void jobDone(KIO::Job *job, const KIO::UDSEntryList &list);
private:
    /**
     * instance for asynchronous callback deep 0
     */
    KConfigOwnCloud *owner;

    /**
     * instance for asynchronous callback deep 1
     */
    ListReturnWithParamIntf *facade;

    /**
     * instance for asynchronous callback deep 2
     */
    void *gui;
};
#endif	/* KCONFIGOWNCLOUD_H */

