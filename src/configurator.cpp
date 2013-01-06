#include "configurator.h"
#include <kglobal.h>
#include <QStringList>
#include <kconfiggroup.h>

Configurator::Configurator() {
    config = KSharedConfig::openConfig("placloudrc");

    /*foreach (const QString& group, config->groupList() ){
        kDebug() << "next group" << group;
    }*/
}

Configurator::~Configurator() {
}

QString Configurator::getValue(QString key) {
    KConfigGroup ownCloudGroup(config, "ownCloud");
    return ownCloudGroup.readEntry(key, "");
}

void Configurator::setValue(QString key, QString value) {
    if (value != "" && key != "") { // ignoring empty strings
        KConfigGroup ownCloudGroup(config, "ownCloud");
        ownCloudGroup.writeEntry(key, value);
        // write the changes to file
        ownCloudGroup.sync();
    }
}

