#ifndef CONFIGURATOR_H
#define	CONFIGURATOR_H

#include "../commons.h"
#include <kconfig.h>
#include <ksharedconfig.h>

/**
 * Class takes care of work with the configuration file.
 * It uses library KConfig.
 * @Author Marie Hrdinová
 */
class Configurator {
public:
    /**
     * Constructor. Prepare the configuration file to use.
     * The configuration file is a file located in standart KDE config directory. 
     * If the file exists configuration is opened and ready for use, otherwise an empty configuration file is created.
     */
    Configurator();

    /**
     * For a key finds an appropriate value.
     * @param key The key for which we are looking for value.
     * @return The value for key or empty string if key dooesn't exist.
     */
    QString getValue(QString key);

    /**
     * Saves to the specified key the given value.
     * If the key already exists, the value is updated.
     * @param key The key to which the value is given. Empty string is ignored.
     * @param value The value of the key. Empty string is ignored.
     */
    void setValue(QString key, QString value);
    
    /**
     * Destroy Configurator object.
     */
    ~Configurator();
private:
    /**
     * Object that manages the config file
     */
    KSharedConfigPtr config;
};

#endif	/* CONFIGURATOR_H */

