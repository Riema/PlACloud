#include "PlACloud.h"
#include <QMessageBox>
#include <QCloseEvent>

PlACloud::PlACloud(Application* apps) {
    app = apps;
    widget.setupUi(this);

    setConnection();
    fillSettingsPage();
    enableClouding();
    connectFilePage();
    connectConfigPage();
    connectSettingsPage();
    widget.ownCloudStackedWidget->setCurrentIndex(2);
}

void PlACloud::connectFilePage(){
    QObject::connect(widget.dolphinButton, SIGNAL(clicked()), app, SLOT(openFilesInProgram()));
}

void PlACloud::connectConfigPage(){
    QObject::connect(widget.saveConfButton, SIGNAL(clicked()), app, SLOT(safeKConfigNow()));
    QObject::connect(widget.configCheckBox, SIGNAL(toggled(bool)), app, SLOT(setOwnCloudAutoBackUp(bool)));
}

void PlACloud::connectSettingsPage(){

}

void PlACloud::enableClouding() {
    widget.fileButton->setEnabled(true);
    widget.configButton->setEnabled(true);
    widget.filePage->setEnabled(true);
    widget.configPage->setEnabled(true);
}

void PlACloud::disableClouding() {
    widget.fileButton->setEnabled(false);
    widget.configButton->setEnabled(false);
    widget.filePage->setEnabled(false);
    widget.configPage->setEnabled(false);
}

void PlACloud::fillSettingsPage() {
    widget.userNameLineEdit->setText(app->getOwnCloudUserName());
    widget.serverLineEdit->setText(app->getOwnCloudServer());
    widget.portSpinBox->setValue(app->getOwnCloudPort().toInt());
    widget.configCheckBox->setChecked(app->isOwnCloudAutoBackUp());
    widget.spinBox->setEnabled(widget.configCheckBox->isChecked());
}

void PlACloud::setConnection() {
    //connection for button switching pages
    QObject::connect(widget.fileButton, SIGNAL(clicked()), this, SLOT(filePageSwitch()));
    QObject::connect(widget.configButton, SIGNAL(clicked()), this, SLOT(configPageSwitch()));
    QObject::connect(widget.settingsButton, SIGNAL(clicked()), this, SLOT(settingsPageSwitch()));

    //for changing ownCloud connection configuration
    QObject::connect(widget.userNameLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudUserName()));
    QObject::connect(widget.serverLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudServer()));
    QObject::connect(widget.portSpinBox, SIGNAL(valueChanged(QString)), app, SLOT(setOwnCloudPort(QString)));
}

void PlACloud::filePageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(0);
}

void PlACloud::configPageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(1);
}

void PlACloud::settingsPageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(2);
}

void PlACloud::closeEvent(QCloseEvent* event) {
    /*int res = QMessageBox::warning(this, windowTitle(), "Are you sure?",
                QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes)
        event->accept(); 
    else
        event->ignore(); */
}

PlACloud::~PlACloud() {
}
