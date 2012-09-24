#include "PlaCloud/application.h"
#include "gui/primeWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    //QApplication app(argc, argv);
    Application app(argc, argv);
        
    primeWindow mw;
    mw.show();   

    // create and show your widgets here

    return app.exec();
}
