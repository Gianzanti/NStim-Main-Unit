/**
 * Author: Fabio Gianzanti (pardal@hotmail.com)
 * Revisor: 
 * 
 * General System Configuration
 * 
 * At the e2prom level, the started (null) value will be FF. So we need to 
 * write all e2prom addresses at the build level with all FF.
 * 
 */

#include <Arduino.h>
#include <EEPROM.h>
#include "config.h"

# define OPERATION_MODE_E2PROM_ADDRESS 10
# define OPERATION_MODE_DEFAULT 1

# define LANGUAGE_E2PROM_ADDRESS 11
# define LANGUAGE_DEFAULT 1

uint8_t _operationMode = NULL;
uint8_t _language = NULL;

char *_firmware = "v.0.0.0";
char *_model = "NStim";

NStimConfig* setupConfig() {
    // config.model = "NStim";
    // config.firmware = "v.0.0.0";
    config.language = config_get(config.language, LANGUAGE_E2PROM_ADDRESS, LANGUAGE_DEFAULT);
    config.operationMode = config_get(config.operationMode, OPERATION_MODE_E2PROM_ADDRESS, OPERATION_MODE_DEFAULT);
    return &config;
}

uint8_t config_get(uint8_t currentValue, int address, uint8_t defaultValue) {
    if (currentValue == NULL) {
        int storedValue = EEPROM.read(address);
        if (storedValue !=0xFF) {
            return storedValue;
        }
        return defaultValue;
    }
    return currentValue;
}

// void config_setOperationMode(int8_t opMode) {
//     _operationMode = opMode;
//     EEPROM.write(OPERATION_MODE_E2PROM_ADDRESS, _operationMode);
// }


/**
 * Get the operation mode from E2PROM, if it is not already read.
 * 
 * If the E2PROM content is 0xFF it is considered NULL, so it returns
 * the default value, previously defined
 * 
 * @return 
 *      1 - Cortical Mode
 *      2 - Locate Mode
 *      3 - Mapping Mode
 */
uint8_t config_getOperationMode() {
    if (_operationMode == NULL) {
        int opMode = EEPROM.read(OPERATION_MODE_E2PROM_ADDRESS);
        if (opMode !=0xFF) {
            _operationMode = opMode;
        } else {
            _operationMode = OPERATION_MODE_DEFAULT;
        }
    }
    return _operationMode;
}

void config_setOperationMode(int8_t opMode) {
    _operationMode = opMode;
    EEPROM.write(OPERATION_MODE_E2PROM_ADDRESS, _operationMode);
}


/**
 * Get the menu language from E2PROM, if it is not already read.
 * 
 * If the E2PROM content is 0xFF it is considered NULL, so it returns
 * the default value, previously defined
 * 
 * @return 
 *      1 - English
 *      2 - Brazilian Portuguese
 */
uint8_t config_getLanguage() {
    if (_language == NULL) {
        int opMode = EEPROM.read(OPERATION_MODE_E2PROM_ADDRESS);
        if (opMode !=0xFF) {
            _language = opMode;
        } else {
            _language = OPERATION_MODE_DEFAULT;
        }
    }
    return _language;
}

void config_setLanguage(int8_t lang) {
    _language = lang;
    EEPROM.write(LANGUAGE_E2PROM_ADDRESS, _language);
}

/**
 * get the current firmware version
 * 
 */
char *config_getFirmware() {
    return _firmware;
}


/**
 * returns the board uptime
 * 
 * ** IMPORTANT **: it is needed to dealocate the result value (free it), after use
 */
char *config_getUptime() {
    int sec = millis() / 1000;
    int min = sec / 60;
    int hr = min / 60;
    char *tmp = (char *)malloc(12);
    snprintf(tmp, 12, "%02d:%02d:%02d", hr, min % 60, sec % 60);
    return tmp;
}
