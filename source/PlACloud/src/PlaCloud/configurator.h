#ifndef CONFIGURATOR_H
#define	CONFIGURATOR_H

#include <libconfig.h++>
#include "../commons.h"

/**
 * Class takes care of work with the configuration file.
 * It uses a library libconfig.
 * @Author Marie Hrdinová
 * @see http://www.hyperrealm.com/libconfig/libconfig_manual.html
 */
class Configurator {
public:
    /**
     * Constructor. Prepare the configuration file to use.
     * The configuration file is a hidden file located in the user's home directory ie. "$ HOME / .placloud". 
     * If the file exists configuration is loaded and ready for use, otherwise an empty configuration file is created.
     * @throw FileIOException if config file can't be open and read from.
     * @throw ParseException if config file can't be parse
     */
    Configurator();

    /**
     * For a key finds an appropriate value.
     * @param key The key for which we are looking for value.
     * @return The value for key or empty string if key dooesn't exist.
     */
    std::string getValue(std::string key);

    /**
     * Saves to the specified key the given value.
     * If the key already exists, the value is updated.
     * @param key The key to which the value is given. Empty string is ignored.
     * @param value The value of the key. Empty string is ignored.
     * @throw FileIOException if config file can't be written to
     */
    void setValue(std::string key, std::string value);
    
    /**
     * Destroy Configurator object.
     */
    ~Configurator();
private:
    // konfiguration
    libconfig::Config cnf;
    // path to configuration
    char* path;

};

#endif	/* CONFIGURATOR_H */

