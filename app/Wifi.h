#ifndef WIFI_H
#define WIFI_H

#include "Sys.h"

typedef enum
{
    WIFI_MODE_NONE = 0,
    WIFI_MODE_PASSTHROUGH, //͸��ģʽ
    WIFI_MODE_COMMAND, //����ģʽ
    WIFI_MODE_NETCONFIG,
}WifiMode_t;

void WifiNetConfigStart(void);
WifiMode_t WifiGetWorkMode(void);
void WifiInitialize(void);
void WifiPoll(void);

#endif

