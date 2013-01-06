#include "application.h"
#include "kConfigOwnCloud.h"
#include<QLineEdit>

Application::Application(int argc, char **argv) : QApplication(argc, argv) {
    setApplicationName("PlACloud");
}

QString Application::getOwnCloudUserName() {
    return cnf.getValue("ownCloudUserName");
}

QString Application::getOwnCloudServer() {
    return cnf.getValue("ownCloudServer");
}

QString Application::getOwnCloudPort() {
    return cnf.getValue("ownCloudPort");
}

bool Application::isOwnCloudAutoBackUp() {
    QString result = cnf.getValue("ownCloudAutoBackUp");
    if (result == "true") {
        return true;
    }

    return false;
}

void Application::onListReturnWithParam(QStringList list, void* param) {
    kDebug() << "In facade";
    ListReturnIntf *dest = (ListReturnIntf*) param;
    dest->onListReturn(list);
}

void Application::setOwnCloudUserName() {
    // get the content from QLineEdit
    QLineEdit* edit = qobject_cast<QLineEdit*>(sender());
    if (edit) {
        cnf.setValue("ownCloudUserName", edit->text());
    } else {
        kDebug() << "Problem with changing ownCloud user name";
    }
}

void Application::setOwnCloudServer() {
    // get the content from QLineEdit
    QLineEdit* edit = qobject_cast<QLineEdit*>(sender());
    if (edit) {
        cnf.setValue("ownCloudServer", edit->text());
    } else {
        kDebug() << "Problem with changing ownCloud server";
    }
}

void Application::setOwnCloudPort(QString port) {
    cnf.setValue("ownCloudPort", port);
}

void Application::setOwnCloudAutoBackUp(bool checked) {
    if (checked) {
        cnf.setValue("ownCloudAutoBackUp","true");
    } else {
        cnf.setValue("ownCloudAutoBackUp","false");
    }
}

void Application::openFilesInProgram() {
    foc.openFilesInDolphin(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort"));
}

void Application::saveKConfigNow() {
    kc.uploadConfigutarion(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort"));
}

void Application::fillModel(ListReturnIntf *gui) {
    kc.getListOfDirectories(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort"), gui, this);
}

void Application::restoreKConfig(QString directory){
    kc.restoreKConfigDirectory(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort"), directory);
}

bool Application::isNetworkConnection() {
    QNetworkConfigurationManager ncm;
    kDebug() << ncm.isOnline(); // QNetworkConfigurationManager doesn't work 
    return (/*ncm.isOnline() &&*/ foc.testExistenceOfOwnCloud(cnf.getValue("ownCloudUserName"), cnf.getValue("ownCloudServer"), cnf.getValue("ownCloudPort")));
}

QString Application::toQString(std::string const &s) {
    return QString::fromUtf8(s.c_str());
}

std::string Application::fromQString(QString const &s) {
    return std::string(s.toUtf8().data());
}

Application::~Application() {
}

