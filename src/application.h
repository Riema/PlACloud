#ifndef APPLICATION_H
#define	APPLICATION_H

#include "configurator.h"
#include "fileOwnCloud.h"
#include "../commons.h"
#include "kConfigOwnCloud.h"
#include <QApplication>

class Application : public QApplication {
    Q_OBJECT
public:
    explicit Application(int, char**);
    virtual ~Application();
    QString getOwnCloudUserName();
    QString getOwnCloudServer();
    QString getOwnCloudPort();
    bool isOwnCloudAutoBackUp();
    QStringList fillModel();
public slots:
    void openFilesInProgram();
    void safeKConfigNow();
    void setOwnCloudUserName();
    void setOwnCloudServer();
    void setOwnCloudPort(QString);
    void setOwnCloudAutoBackUp(bool);
private:
    QString toQString(std::string const &s);
    std::string fromQString(QString const &s);
    Configurator cnf;
    FileOwnCloud foc;
    KConfigOwnCloud kc;
};

#endif	/* APPLICATION_H */

