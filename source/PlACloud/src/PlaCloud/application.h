/* 
 * File:   application.h
 * Author: riema
 *
 * Created on 11. září 2012, 11:02
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <QApplication>

class Application : public QApplication {
public:
    explicit Application(int, char**);
    virtual ~Application();
private:

};

#endif	/* APPLICATION_H */

