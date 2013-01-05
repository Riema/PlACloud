#include "kConfigOwnCloud.h"
#include <kstandarddirs.h>
#include <kio/job.h>
#include <kio/copyjob.h>
#include <kurl.h>
#include <sstream>
#include <ctime>

KConfigOwnCloud::KConfigOwnCloud() {    
}

void KConfigOwnCloud::createConfigDirectory(QString name, QString adress, QString port) {
    QString dest = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud").arg(name, adress, port);
    KIO::mkdir(KUrl(dest));
}

void KConfigOwnCloud::uploadConfigutarion(QString name, QString adress, QString port) {
    createConfigDirectory(name, adress, port);
    
    KStandardDirs ksd;
    kDebug() << ksd.localkdedir();
    
    std::stringstream ss;
    ss << time(NULL);    
    
    QString dest = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud/%4").arg(name, adress, port, QString::fromUtf8(ss.str().c_str()));

    KIO::mkdir(KUrl(dest));

    QString source = QString("file://%1").arg(ksd.locate("config",""));
    
    KIO::copy(KUrl(source),KUrl(dest));
}

QStringList KConfigOwnCloud::getListOfDirectories(){
    QStringList datum;
    kDebug() << "Creating StringList";
    datum << "2013-01-01 17:39:17" <<  "2012-12-29 18:15:21" << "2012-12-26 15:56:24" << "2012-12-18 15:36:48";
    return datum;
}


KConfigOwnCloud::~KConfigOwnCloud() {
}

