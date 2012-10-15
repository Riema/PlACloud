#include "application.h"
#include "kConfigOwnCloud.h"
#include<QLineEdit>

Application::Application(int argc, char **argv) : QApplication(argc, argv) {
    setApplicationName("PlACloud");
}

QString Application::getOwnCloudUserName() {
    return toQString(cnf.getValue("ownCloudUserName"));
}

QString Application::getOwnCloudServer() {
    return toQString(cnf.getValue("ownCloudServer"));
}

QString Application::getOwnCloudPort() {
    return toQString(cnf.getValue("ownCloudPort"));
}

void Application::setOwnCloudUserName() {
    QLineEdit* edit = qobject_cast<QLineEdit*>(sender());
    if (edit) {
        cnf.setValue("ownCloudUserName", fromQString(edit->text()));
    } else {
        kDebug() << "Problem with changing ownCloud user name";
    }
}

void Application::setOwnCloudServer() {
    QLineEdit* edit = qobject_cast<QLineEdit*>(sender());
    if (edit) {
        cnf.setValue("ownCloudServer", fromQString(edit->text()));
    } else {
        kDebug() << "Problem with changing ownCloud server";
    }
}

void Application::setOwnCloudPort(QString port) {
    cnf.setValue("ownCloudPort", fromQString(port));
}

void Application::openFilesInProgram() {
    foc.openFilesInDolphin(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort"));
}

QString Application::toQString(std::string const &s) {
    return QString::fromUtf8(s.c_str());
}

std::string Application::fromQString(QString const &s) {
    return std::string(s.toUtf8().data());
}

Application::~Application() {
}

