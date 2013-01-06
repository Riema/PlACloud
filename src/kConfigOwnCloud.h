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
     * it changes their name to date string representation readable by people
     * "yyyy-mm-dd hh:mm:ss"
     * @param userName name of ownCloud user
     * @param cloudAdress ownCloud instance address
     * @param port port where the ownCloud is running
     */
    void getListOfDirectories(QString name, QString adress, QString port, void *gui, ListReturnWithParamIntf *facade);
    
    void returnListOfDirectories(QStringList list,  void *gui, ListReturnWithParamIntf *facade);
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
 *
 */
class ListJobRunner : public QObject{
    Q_OBJECT // for signals and slots
public:
    ListJobRunner(void *gui, ListReturnWithParamIntf *facade, KConfigOwnCloud *owner);
    virtual ~ListJobRunner();
    void runJob(QString name, QString adress, QString port);
public slots:
    void jobDone(KIO::Job *job, const KIO::UDSEntryList &list);
private:
    KConfigOwnCloud *owner;
    ListReturnWithParamIntf *facade;
    void *gui;
};
#endif	/* KCONFIGOWNCLOUD_H */

