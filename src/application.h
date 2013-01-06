#ifndef APPLICATION_H
#define	APPLICATION_H

#include "configurator.h"
#include "fileOwnCloud.h"
#include "../commons.h"
#include "kConfigOwnCloud.h"
#include <QApplication>
#include <QNetworkConfigurationManager>

class ListReturnIntf {
public:
    virtual void onListReturn(QStringList list) = 0;
    virtual ~ListReturnIntf() {};
};

/**
 * It's an interface between UI and backend part of the PlACloud application.
 * It delegates work to proper backend class.
 */
class Application : public QApplication, public ListReturnWithParamIntf {
    Q_OBJECT // for signals and slots
public:
    /**
     * Creates the instance of Application
     */
    explicit Application(int, char**);
    
    /**
     * Destroys the Application
     */
    virtual ~Application();
    
    /**
     * @return ownCloud user name from configuration
     */
    QString getOwnCloudUserName();
    
    /**
     * @return ownCloud server address from configuration
     */
    QString getOwnCloudServer();
    
    /**
     * @return ownCloud server port from configuration
     */
    QString getOwnCloudPort();
    
    /**
     * @return true if KConfig automatic backup is turn on else false
     */
    bool isOwnCloudAutoBackUp();
    
    /**
     * Method used for getting list of KConfig directories
     * date and time of creation to fill the model in UI
     * @return list of directories date and time of creation
     */
    void fillModel(ListReturnIntf *gui);
    
    /**
     * @return true if there is network connection else false 
     */
    bool isNetworkConnection();
    
    void onListReturnWithParam(QStringList list, void *param);
public slots:
    /**
     * Accepts a forwards signal for opening file browser.
     */
    void openFilesInProgram();
    
    /**
     * Accepts a forwards signal for saving the configuration.
     */
    void saveKConfigNow();
    
    /**
     * Accepts a forwards signal for changing ownCloud user name.
     */
    void setOwnCloudUserName();
    
    /**
     * Accepts a forwards signal for changing ownCloud server address.
     */
    void setOwnCloudServer();
    
    /**
     * Accepts a forwards signal for changing ownCloud server port.
     */
    void setOwnCloudPort(QString);
    
    /**
     * Accepts a forwards signal for changing KConfig automatic backup.
     */
    void setOwnCloudAutoBackUp(bool);
private:
    /**
     * Converts from std::string to QString
     * @return QString
     */
    QString toQString(std::string const &s);
    
    /**
     * Converts from QString to std::string
     * @return std::string
     */
    std::string fromQString(QString const &s);
    
    /**
     * Object that takes care of configuration save & read
     */
    Configurator cnf;
    
    /**
     * Object that works with files on ownCloud
     */
    FileOwnCloud foc;
    
    /**
     * Object that works with KConfig a ownCloud
     */
    KConfigOwnCloud kc;
    
    /**
     * Manager to find out if there is network connection.
     */
    QNetworkConfigurationManager ncm;
};


#endif	/* APPLICATION_H */

