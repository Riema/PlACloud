#include "mainWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
 
MainWindow::MainWindow() : QMainWindow(NULL)
{

}
 
void MainWindow::closeEvent(QCloseEvent* event) 
{
    int res = QMessageBox::warning(this, windowTitle(), "Are you sure?",
                QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes)
        event->accept(); 
    else
        event->ignore(); 
}
