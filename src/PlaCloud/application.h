#ifndef APPLICATION_H
#define	APPLICATION_H

#include "configurator.h"
#include "fileOwnCloud.h"
#include <QApplication>
#include <QString>

class Application : public QApplication {
    Q_OBJECT
public:
    explicit Application(int, char**);
    virtual ~Application();
    QString getOwnCloudUserName();
    QString getOwnCloudServer();
    QString getOwnCloudPort();
public slots:
    void openFilesInProgram();
    void setOwnCloudUserName();
    void setOwnCloudServer();
    void setOwnCloudPort(QString);
private:
    QString toQString(std::string const &s);
    std::string fromQString(QString const &s);
    Configurator cnf;
    FileOwnCloud foc;
};

#endif	/* APPLICATION_H */

