#include "fileOwnCloud.h"
#include <QProcess>
#include <QStringList>
#include <kio/job.h>
#include <kurl.h>
#include <kio/netaccess.h>

FileOwnCloud::FileOwnCloud() {
}

bool FileOwnCloud::testExistenceOfOwnCloud(QString userName, QString cloudAdress, QString port) {
    QString dest(QString("webdav://%1@%2:%3/files/webdav.php").arg(userName, cloudAdress, port));
    return KIO::NetAccess::exists(KUrl(dest), KIO::NetAccess::DestinationSide ,NULL);
}

void FileOwnCloud::openFilesInDolphin(QString userName, QString cloudAdress, QString port) {
    QString program = "dolphin";

    // string representation of koi slave for WebDAV connection to ownCLoud
    QStringList arguments(QString("webdav://%1@%2:%3/files/webdav.php").arg(userName, cloudAdress, port));

    // creates a process for Dolphin
    QProcess *myProcess = new QProcess(0);
    myProcess->startDetached(program, arguments);
}

FileOwnCloud::~FileOwnCloud() {
}

