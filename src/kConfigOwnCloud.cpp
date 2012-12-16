#include "../commons.h"
#include "kConfigOwnCloud.h"
#include <kstandarddirs.h>
#include <kio/job.h>
#include <kio/copyjob.h>
#include <kurl.h>
#include <sstream>
#include <ctime>

KConfigOwnCloud::KConfigOwnCloud(std::string name, std::string adress, int ports) {
    userName = name;
    cloudAdress = adress;
    this->port = ports;

    createConfigDirectory();
    uploadConfigutarion();
}

void KConfigOwnCloud::createConfigDirectory() {
    std::stringstream ss;
    ss << "webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php/.conf";
    KIO::mkdir(KUrl(ss.str().c_str()));
}

void KConfigOwnCloud::uploadConfigutarion() {
    KStandardDirs ksd;
    kDebug() << ksd.localkdedir();
    std::stringstream ss;
    ss << "webdav://" << userName << "@" << cloudAdress << ":"
            << port << "/files/webdav.php/.conf/" << time(NULL);
    std::string dest = ss.str();

    KIO::mkdir(KUrl(dest.c_str()));

    ss.str("");
    ss.clear();
    
    ss << "file://" << ksd.locate("config","").toStdString();
    KIO::copy(KUrl(ss.str().c_str()),KUrl(dest.c_str()));
}

KConfigOwnCloud::~KConfigOwnCloud() {
}

