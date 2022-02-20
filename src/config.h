/**
 * Author: Fabio Gianzanti (pardal@hotmail.com)
 * Revisor: 
 * 
 * General System Configuration
 * 
 */

#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <Arduino.h>

struct NStimConfig {
    uint8_t operationMode;
    uint8_t language;
    char firmware;
    char model;
} config;

uint8_t config_get(uint8_t currentValue, int address, uint8_t defaultValue);

uint8_t config_getOperationMode();
void config_setOperationMode(uint8_t opMode);

uint8_t config_getLanguage();
void config_setLanguage(uint8_t lang);

NStimConfig* setupConfig();

char *config_getFirmware();
char *config_getModel();
char *config_getUpTime();
char *config_getUptime();

void config_clearCache();

#endif