#include "src/application.h"
#include "gui/PlACloud.h"

/**
 * Main function, entry point 
 */
int main(int argc, char *argv[]) {

    // Creates the Application to handle requests from GUI 
    Application app(argc, argv);
    
    // Creates the main window.
    // @param app The class that handles signals
    PlACloud mw(&app);

    // display main window
    mw.show();
 
    // start the program
    return app.exec();
}
