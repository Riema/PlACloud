/* 
 * File:   primeWindow.h
 * Author: riema
 *
 * Created on 18. září 2012, 14:32
 */

#ifndef _PRIMEWINDOW_H
#define	_PRIMEWINDOW_H

#include "ui_primeWindow.h"

class primeWindow : public QMainWindow {
    Q_OBJECT
public:
    primeWindow();
    virtual ~primeWindow();
public slots:
    void filePageSwitch();
    void configPageSwitch();
    void contactPageSwitch();
    void setPageSwitch();
private:
    Ui::primeWindow widget;
    void closeEvent(QCloseEvent* event); 
};

#endif	/* _PRIMEWINDOW_H */
