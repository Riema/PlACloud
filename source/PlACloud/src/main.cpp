#include "PlaCloud/application.h"
#include "gui/primeWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    //Q_INIT_RESOURCE(primeWindow);
    //QApplication app(argc, argv);
    
    Application app(argc, argv);
  
    primeWindow mw(&app);

    mw.showMaximized();
 
    return app.exec();
}
