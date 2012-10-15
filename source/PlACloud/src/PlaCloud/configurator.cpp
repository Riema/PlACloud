#include <fstream>
#include "configurator.h"

using namespace libconfig;

Configurator::Configurator() {

    // Path to home directory and to the conf file
    path = new char[256];
    strcpy(path, getenv("HOME"));
    strcat(path, "/.placloud");

    // Does the conf  exists?
    if (!(access(path, F_OK) != -1)) {
        kDebug() << "Config doesn't exist. Creating empty one.";
        std::ofstream newFile(path);
        newFile.close();
    }
    
    //reading the configuration
    try {
        cnf.readFile(path);
    } catch (const FileIOException ex) {
        kDebug() << "I/O error while reading config file.";
        throw;
    } catch (const ParseException ex) {
        kDebug() << "Parse error at " << ex.getFile() << ":" << ex.getLine() << " - " << ex.getError();
        throw;
    }
}

Configurator::~Configurator() {
}

std::string Configurator::getValue(std::string key) {
    std::string value = "";
    cnf.lookupValue(key, value);
    return value;
}

void Configurator::setValue(std::string key, std::string value) {
    if (value != "" && key != "") {
        if (!cnf.exists(key)) {
            Setting &set = cnf.getRoot();
            set.add(key, Setting::TypeString) = value;
        } else {
            Setting &set = cnf.lookup(key);
            set = value;
        }

        try {
            cnf.writeFile(path);
            kDebug() << "New configuration " << key.c_str() << "->" << value.c_str() <<"successfully written to: " << path;
        } catch (const FileIOException &fioex) {
            kDebug() << "I/O error while writing file: " << path;
            throw;
        }
    }
}

