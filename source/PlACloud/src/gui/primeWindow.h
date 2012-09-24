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
private:
    Ui::primeWindow widget;
};

#endif	/* _PRIMEWINDOW_H */
