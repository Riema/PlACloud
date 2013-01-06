#ifndef _PLACLOUD_H
#define	_PLACLOUD_H

#include "ui_PlACloud.h"
#include "../src/application.h"
#include <QStringListModel>

/**
 * Class that is wrapped aroud the PlACloud.ui.
 * It is used to make connection between slot 
 * and signals and takes care of working part of
 * code.  
 */
class PlACloud : public QMainWindow, public ListReturnIntf {
    Q_OBJECT //signal and slots usage
public:
    /**
     * Creates a new PlACloud main window.
     * @param apps Application that is used for communication with backend.
     */
    PlACloud(Application *apps);
    
    /**
     * Destroyes the PlaCloud.
     */
    virtual ~PlACloud();
    
    /**
     * Enables parts of UI when internet connection is on
     * and the configuration for connection to cloud is right. 
     */
    void enableClouding();
    
    /**
     * Disables parts of UI whet internet connection failes
     * or user confuguration isn't checked or is wrong.
     */
    void disableClouding();
    
    virtual void onListReturn(QStringList list);
private slots:
    /**
     * Slot for switching page in StackedWidget to File page
     */
    void filePageSwitch();
    
    /**
     * Slot for switching page in StackedWidget to KConfig page
     */
    void configPageSwitch();
    
    /**
     * Slot for switching page in StackedWidget to User config page
     */
    void settingsPageSwitch();
private:
    /**
     * Widget with is interface to UI componets
     */
    Ui::PlACloud widget;
    
    /**
     * Application interface to backend
     */
    Application* app;
    
    /**
     * Model for KConfig Listview
     */
    QStringListModel * configModel;
    
    /**
     * Handels event od closing the main window
     * @param event Close event
     */
    void closeEvent(QCloseEvent* event);
    
    /**
     * Creates connections between componets in Main Window 
     */
    void setConnection();
    
    /**
     * On startup of the window fills forms acording to backend configuration 
     */
    void fillSettingsPage();
    
    /**
     * Creates connection between StackedWidget File page and backend.
     */
    void connectFilePage();
    
    /**
     * Creates connection between StackedWidget KConfig page and backend.
     */
    void connectConfigPage();
    
    /**
     * Creates connection between StackedWidget User config page and backend.
     */
    void connectSettingsPage();
};

#endif	/* _PLACLOUD_H */
