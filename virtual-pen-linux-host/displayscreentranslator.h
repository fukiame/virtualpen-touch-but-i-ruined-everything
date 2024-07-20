#ifndef DISPLAYSCREENTRANSLATOR_H
#define DISPLAYSCREENTRANSLATOR_H
#include "accessory.h"
#include <QScreen>

class DisplayScreenTranslator{
public:
    int size_x;
    int size_y;
    int32_t getAbsXStretched(AccessoryEventData * pos);
    int32_t getAbsYStretched(AccessoryEventData * pos);
    DisplayScreenTranslator();
private:
    QScreen *screen;
    int32_t getStretchedSize(int posOnDevice, int accessorySize);
};


#endif // DISPLAYSCREENTRANSLATOR_H
