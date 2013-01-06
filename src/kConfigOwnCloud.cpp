#include "kConfigOwnCloud.h"
#include <kstandarddirs.h>
#include <kio/copyjob.h>
#include <kurl.h>
#include <sstream>
#include <ctime>
#include <QDateTime>

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

void KConfigOwnCloud::getListOfDirectories(QString name, QString adress, QString port, void *gui, ListReturnWithParamIntf* facade) {
    ListJobRunner *jr = new ListJobRunner(gui, facade, this);
    jr->runJob(name, adress, port);
}

void KConfigOwnCloud::returnListOfDirectories(QStringList list, void* gui, ListReturnWithParamIntf* facade) {
    kDebug() << "in KConfig";
    facade->onListReturnWithParam(list, gui);
}

void KConfigOwnCloud::restoreKConfigDirectory(QString name, QString adress, QString port, QString directory) {
    // find out where the configuration is
    KStandardDirs ksd;
    kDebug() << ksd.localkdedir();

    // download destination string
    QString source = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud/%4").arg(name, adress, port, directory);

    // create destination string
    QString dest = QString("file://%1").arg(ksd.locate("config",""));

    // download
    KIO::copy(KUrl(source),KUrl(dest));
}

KConfigOwnCloud::~KConfigOwnCloud() {
}

ListJobRunner::ListJobRunner(void *gui, ListReturnWithParamIntf *facade, KConfigOwnCloud *owner) {
    this->gui = gui;
    this->facade = facade;
    this->owner = owner;
}

ListJobRunner::~ListJobRunner() {
}

void ListJobRunner::runJob(QString name, QString adress, QString port) {
    QString dest = QString("webdav://%1@%2:%3/files/webdav.php/.conf-placloud").arg(name, adress, port);
    KIO::ListJob *job = KIO::listDir(KUrl(dest));

    connect(job, SIGNAL(entries(KIO::Job*,KIO::UDSEntryList)), this, SLOT(jobDone(KIO::Job*,KIO::UDSEntryList)));
}

void ListJobRunner::jobDone(KIO::Job* job, const KIO::UDSEntryList& list) {
    QStringList stringList;

    // iterate the result for right directories
    KIO::UDSEntryList::ConstIterator it = list.begin();
    const KIO::UDSEntryList::ConstIterator end = list.end();
    for (; it != end; ++it) {
        const KIO::UDSEntry& entry = *it;
        QString name = entry.stringValue( KIO::UDSEntry::UDS_NAME );
        bool isDir = entry.isDir();
        if (isDir) { // check only directories
            if (name != ".") { // not the parental directory
		long i = name.toLong();
		QDateTime dt = QDateTime::fromTime_t(i);
                stringList.append(QString("%1 (%2)").arg(dt.toString("yyyy-MM-dd hh:mm:ss"), name));
            }
        }
    }

    owner->returnListOfDirectories(stringList, this->gui, this->facade);
    // clean up
    delete this;
}


