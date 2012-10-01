#include "PlaCloud/application.h"
#include "gui/primeWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    
    //Q_INIT_RESOURCE(primeWindow);

    //QApplication app(argc, argv);
    Application app(argc, argv);
        
    primeWindow mw;
    mw.showMaximized();

    // create and show your widgets here

    return app.exec();
}
