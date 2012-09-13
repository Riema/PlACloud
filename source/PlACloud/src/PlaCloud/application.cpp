/* 
 * File:   application.cpp
 * Author: riema
 * 
 * Created on 11. září 2012, 11:02
 */

#include "application.h"
#include "configurator.h"
#include "fileOwnCloud.h"

Application::Application(int argc, char **argv) : QApplication(argc,argv) {
    setApplicationName("PlACloud");

    /*Configurator cnf;
    cnf.setValue("a","b");
    std::string str = cnf.getValue("a");
    std::cout << "Obsah str: " <<  (str.empty() ? "NULL" : str) << std::endl;
    str = cnf.getValue("b");
    std::cout << "Obsah str: "  << (str.empty() ? "NULL" : str) << std::endl;
    cnf.setValue("b","ahoj");
    cnf.setValue("a","abac");
    std::cout << "Obsah str: " << cnf.getValue("a") << std::endl;
    str = cnf.getValue("b");
    std::cout << "Obsah str: "  << (str.empty() ? "NULL" : str) << std::endl;*/
    FileOwnCloud foc;
}

Application::~Application() {
}

