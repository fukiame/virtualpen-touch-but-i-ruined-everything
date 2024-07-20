#ifndef VIRTUALSTYLUS_H
#define VIRTUALSTYLUS_H
#include "accessory.h"
#include "displayscreentranslator.h"
#include <QScreen>

class VirtualStylus
{
public:
    VirtualStylus(DisplayScreenTranslator * accessoryScreen);
    void handleAccessoryEventData(AccessoryEventData * accessoryEventData);
    void initializeStylus();
    void destroyStylus();

private:
    int fd;
    bool isPenActive;
    DisplayScreenTranslator * displayScreenTranslator;
};
#endif // VIRTUALSTYLUS_H
