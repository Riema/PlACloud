#include <fstream>
#include <kglobal.h>
#include <QStringList>
#include <kconfiggroup.h>
#include "configurator.h"

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
    if (value != "" && key != "") {
        KConfigGroup ownCloudGroup(config, "ownCloud");
        ownCloudGroup.writeEntry(key, value);
        ownCloudGroup.sync();
    }
}

