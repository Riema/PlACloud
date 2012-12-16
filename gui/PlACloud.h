#ifndef _PLACLOUD_H
#define	_PLACLOUD_H

#include "ui_PlACloud.h"
#include "../src/application.h"

class PlACloud : public QMainWindow {
    Q_OBJECT
public:
    PlACloud(Application *apps);
    virtual ~PlACloud();
    void enableClouding();
    void disableClouding();
private slots:
    void filePageSwitch();
    void configPageSwitch();
    void contactPageSwitch();
    void settingsPageSwitch();
private:
    Ui::PlACloud widget;
    Application* app;
    void closeEvent(QCloseEvent* event); 
    void setConnection();
    void fillSettingsPage();
};

#endif	/* _PLACLOUD_H */