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
    // creating directory ".conf-placloud", if it exists nothing happends
    QString dest = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud").arg(name, adress, port);
    KIO::mkdir(KUrl(dest));
}

void KConfigOwnCloud::uploadConfigutarion(QString name, QString adress, QString port) {
    createConfigDirectory(name, adress, port);
    
    // find out where the configuration is
    KStandardDirs ksd;
    kDebug() << ksd.localkdedir();
    
    // get current time for name of the directory
    std::stringstream ss;
    ss << time(NULL);    
    
    // upload destination string
    QString dest = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud/%4").arg(name, adress, port, QString::fromUtf8(ss.str().c_str()));
    
    // create destination directory
    KIO::mkdir(KUrl(dest));

    // create source string
    QString source = QString("file://%1").arg(ksd.locate("config",""));
    
    // upload
    KIO::copy(KUrl(source),KUrl(dest));
}

QStringList KConfigOwnCloud::getListOfDirectories(){
    QStringList datum;
    
    /*
    kDebug() << "Creating StringList";
    datum << "2013-01-01 17:39:17" <<  "2012-12-29 18:15:21" << "2012-12-26 15:56:24" << "2012-12-18 15:36:48";*/
    return datum;
}


KConfigOwnCloud::~KConfigOwnCloud() {
}

