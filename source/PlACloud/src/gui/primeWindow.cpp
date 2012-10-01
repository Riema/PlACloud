/*
 * File:   primeWindow.cpp
 * Author: riema
 *
 * Created on 18. září 2012, 14:32
 */

#include "primeWindow.h"
#include <QMessageBox>
#include <QCloseEvent>

primeWindow::primeWindow() {
    widget.setupUi(this);
    QObject::connect(widget.fileButton, SIGNAL(clicked()), this, SLOT(filePageSwitch()));
    QObject::connect(widget.configButton, SIGNAL(clicked()), this, SLOT(configPageSwitch()));
    QObject::connect(widget.contactButton, SIGNAL(clicked()), this, SLOT(contactPageSwitch()));
    QObject::connect(widget.settingsButton, SIGNAL(clicked()), this, SLOT(setPageSwitch()));
}

void primeWindow::filePageSwitch(){
    widget.ownCloudStackedWidget->setCurrentIndex(0);
}

void primeWindow::configPageSwitch(){
    widget.ownCloudStackedWidget->setCurrentIndex(1);
}

void primeWindow::contactPageSwitch(){
    widget.ownCloudStackedWidget->setCurrentIndex(2);
}

void primeWindow::setPageSwitch(){
    widget.ownCloudStackedWidget->setCurrentIndex(3);
}

void primeWindow::closeEvent(QCloseEvent* event) 
{
    int res = QMessageBox::warning(this, windowTitle(), "Are you sure?",
                QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes)
        event->accept(); 
    else
        event->ignore(); 
}

primeWindow::~primeWindow() {
}
