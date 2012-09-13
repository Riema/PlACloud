#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <QMainWindow>
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(); 
 
private:
    void closeEvent(QCloseEvent* event); 
};

#endif	/* MAINWINDOW_H */

