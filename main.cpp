#include "src/application.h"
#include "gui/PlACloud.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    //Q_INIT_RESOURCE(primeWindow);
    //QApplication app(argc, argv);
    
    Application app(argc, argv);
  
    PlACloud mw(&app);

    mw.showMaximized();
 
    return app.exec();
}
