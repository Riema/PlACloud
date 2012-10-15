#ifndef _PRIMEWINDOW_H
#define	_PRIMEWINDOW_H

#include "ui_primeWindow.h"
#include "../PlaCloud/application.h"

class primeWindow : public QMainWindow {
    Q_OBJECT
public:
    primeWindow(Application *apps);
    virtual ~primeWindow();
    void enableClouding();
    void disableClouding();
private slots:
    void filePageSwitch();
    void configPageSwitch();
    void contactPageSwitch();
    void settingsPageSwitch();
private:
    Ui::primeWindow widget;
    Application* app;
    void closeEvent(QCloseEvent* event); 
    void setConnection();
    void fillSettingsPage();
};

#endif	/* _PRIMEWINDOW_H */
