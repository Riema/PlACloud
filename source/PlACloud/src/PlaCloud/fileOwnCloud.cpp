#include "fileOwnCloud.h"
#include <QProcess>
#include <QStringList>
#include <kio/job.h>
#include <kurl.h>

FileOwnCloud::FileOwnCloud() {
}

bool FileOwnCloud::testExistenceOfOwnCloud(QString userName, QString cloudAdress, QString port) {
    /*std::stringstream ss;
    ss << "webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php/.conf";
    KIO::StatJob sj = KIO::stat(KUrl(ss.str().c_str()));*/
    return true;
}

void FileOwnCloud::openFilesInDolphin(QString userName, QString cloudAdress, QString port) {
    QString program = "dolphin";
    QStringList arguments(QString("webdav://%1@%2:%3/files/webdav.php").arg(userName, cloudAdress, port));
    QProcess *myProcess = new QProcess(0);
    myProcess->startDetached(program, arguments);
}

FileOwnCloud::~FileOwnCloud() {
}

