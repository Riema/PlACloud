#include "primeWindow.h"
#include <QMessageBox>
#include <QCloseEvent>

primeWindow::primeWindow(Application* apps) {
    app = apps;
    widget.setupUi(this);

    setConnection();
    fillSettingsPage();
    QObject::connect(widget.dolphinButton, SIGNAL(clicked()), app, SLOT(openFilesInProgram()));
    widget.ownCloudStackedWidget->setCurrentIndex(3);
}

void primeWindow::enableClouding() {
    widget.fileButton->setEnabled(true);
    widget.configButton->setEnabled(true);
    widget.contactButton->setEnabled(true);
    widget.filePage->setEnabled(true);
    widget.configPage->setEnabled(true);
    widget.contactPage->setEnabled(true);
}

void primeWindow::disableClouding() {
    widget.fileButton->setEnabled(false);
    widget.configButton->setEnabled(false);
    widget.contactButton->setEnabled(false);
    widget.filePage->setEnabled(false);
    widget.configPage->setEnabled(false);
    widget.contactPage->setEnabled(false);
}

void primeWindow::fillSettingsPage() {
    widget.userNameLineEdit->setText(app->getOwnCloudUserName());
    widget.serverLineEdit->setText(app->getOwnCloudServer());
    widget.portSpinBox->setValue(app->getOwnCloudPort().toInt());
}

void primeWindow::setConnection() {
    //connection for button switching pages
    QObject::connect(widget.fileButton, SIGNAL(clicked()), this, SLOT(filePageSwitch()));
    QObject::connect(widget.configButton, SIGNAL(clicked()), this, SLOT(configPageSwitch()));
    QObject::connect(widget.contactButton, SIGNAL(clicked()), this, SLOT(contactPageSwitch()));
    QObject::connect(widget.settingsButton, SIGNAL(clicked()), this, SLOT(settingsPageSwitch()));

    //for changing ownCloud connection configuration
    QObject::connect(widget.userNameLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudUserName()));
    QObject::connect(widget.serverLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudServer()));
    QObject::connect(widget.portSpinBox, SIGNAL(valueChanged(QString)), app, SLOT(setOwnCloudPort(QString)));
}

void primeWindow::filePageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(0);
}

void primeWindow::configPageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(1);
}

void primeWindow::contactPageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(2);
}

void primeWindow::settingsPageSwitch() {
    widget.ownCloudStackedWidget->setCurrentIndex(3);
}

void primeWindow::closeEvent(QCloseEvent* event) {
    /*int res = QMessageBox::warning(this, windowTitle(), "Are you sure?",
                QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes)
        event->accept(); 
    else
        event->ignore(); */
}

primeWindow::~primeWindow() {
}
