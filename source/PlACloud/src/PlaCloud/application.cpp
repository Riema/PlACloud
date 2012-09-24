#include "application.h"
#include "configurator.h"
#include "fileOwnCloud.h"
#include "kConfigOwnCloud.h"

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
    FileOwnCloud foc ("riema", "cloud.dejvino.com", 80);
    //foc.openFilesInDolphin();
    //KConfigOwnCloud kcoc ("riema", "cloud.dejvino.com", 80);
}

Application::~Application() {
}

