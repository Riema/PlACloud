#include "PlACloud.h"
#include <QMessageBox>
#include <QCloseEvent>

PlACloud::PlACloud(Application* apps) {
    app = apps;
    // set up the widgets
    widget.setupUi(this);

    // filling the forms
    fillSettingsPage();

    // calling funcion for creating connections
    setConnection();
    connectFilePage();
    connectConfigPage();
    connectSettingsPage();

    // first page after start is page with User config
    widget.ownCloudStackedWidget->setCurrentIndex(2);

    // try network connection
    if (app->isNetworkConnection()) {
        enableClouding();
    } else {
        disableClouding();
    }
}

void PlACloud::connectFilePage() {
    // the Dolphin start button
    QObject::connect(widget.dolphinButton, SIGNAL(clicked()), app, SLOT(openFilesInProgram()));
}

void PlACloud::connectConfigPage() {
    // upload KConfig now
    QObject::connect(widget.saveConfButton, SIGNAL(clicked()), app, SLOT(saveKConfigNow()));
    // Toggle of automatic backup button
    QObject::connect(widget.configCheckBox, SIGNAL(toggled(bool)), app, SLOT(setOwnCloudAutoBackUp(bool)));
    // Restoring KConfig
    QObject::connect(widget.restoreLastConfigButton, SIGNAL(clicked()), this, SLOT(onRestoreLastKConfig()));
    QObject::connect(widget.restoreConfigButton,SIGNAL(clicked()), this, SLOT(onRestoreGivenKConfig()));
}

void PlACloud::connectSettingsPage() {
    //for changing ownCloud connection configuration
    QObject::connect(widget.userNameLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudUserName()));
    QObject::connect(widget.serverLineEdit, SIGNAL(editingFinished()), app, SLOT(setOwnCloudServer()));
    QObject::connect(widget.portSpinBox, SIGNAL(valueChanged(QString)), app, SLOT(setOwnCloudPort(QString)));
    QObject::connect(widget.testConnectionPushButton, SIGNAL(clicked()), this, SLOT(onConnectionButtonClick()));

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
    // filing form on User config page
    widget.userNameLineEdit->setText(app->getOwnCloudUserName());
    widget.serverLineEdit->setText(app->getOwnCloudServer());
    widget.portSpinBox->setValue(app->getOwnCloudPort().toInt());

    // automatic backup on KConfig page
    widget.configCheckBox->setChecked(app->isOwnCloudAutoBackUp());
    widget.spinBox->setEnabled(widget.configCheckBox->isChecked());

    // adding content of ListView on KConfig page
    app->fillModel(this);
}

void PlACloud::onListReturn(QStringList list) {
    kDebug() << "Setting new model";
    // adding content of ListView on KConfig page
    configModel = new QStringListModel(list);
    widget.configListView->setModel(configModel);
}

void PlACloud::setConnection() {
    //connection for button switching pages in UI
    QObject::connect(widget.fileButton, SIGNAL(clicked()), this, SLOT(filePageSwitch()));
    QObject::connect(widget.configButton, SIGNAL(clicked()), this, SLOT(configPageSwitch()));
    QObject::connect(widget.settingsButton, SIGNAL(clicked()), this, SLOT(settingsPageSwitch()));
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

void PlACloud::onConnectionButtonClick() {
    kDebug() << "Testing connection";
    // try network connection
    if (app->isNetworkConnection()) {
        kDebug() << "enabling";
        enableClouding();
    } else {
	kDebug() << "disabling";
        disableClouding();
    }
}

void PlACloud::onRestoreGivenKConfig() {
    if (widget.configListView->selectionModel()->hasSelection()){
	QModelIndexList in = widget.configListView->selectionModel()->selectedRows();
	QString dict = in.first().data().toString();
	dict = dict.split(" ")[2];
	dict = dict.split("(")[1];
	dict = dict.split(")")[0];
	kDebug() << dict;
	app->restoreKConfig(dict);
    }
}

void PlACloud::onRestoreLastKConfig() {  
    QModelIndex index = configModel->index(configModel->rowCount() -1, 0);
    QString dict = index.data().toString();
    dict = dict.split(" ")[2];
    dict = dict.split("(")[1];
    dict = dict.split(")")[0];
    kDebug() << dict;
    app->restoreKConfig(dict);
}

void PlACloud::closeEvent(QCloseEvent* event) {
    // only testing purpuse
    /*int res = QMessageBox::warning(this, windowTitle(), "Are you sure?",
                QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes)
        event->accept();
    else
        event->ignore(); */
}

PlACloud::~PlACloud() {
}
