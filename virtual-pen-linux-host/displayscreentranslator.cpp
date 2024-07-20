#include "displayscreentranslator.h"
#include "constants.h"

#include <qguiapplication.h>

DisplayScreenTranslator::DisplayScreenTranslator() {
    screen = QGuiApplication::primaryScreen();
}

int32_t DisplayScreenTranslator::getAbsXStretched(AccessoryEventData * accessoryEventData){
    return getStretchedSize(accessoryEventData->x, size_x);
}

int32_t DisplayScreenTranslator::getAbsYStretched(AccessoryEventData * accessoryEventData){
    return getStretchedSize(accessoryEventData->y, size_y);
}


int32_t DisplayScreenTranslator::getStretchedSize(int posOnDevice, int accessorySize){
    float accessorySizeFloat = accessorySize;
    return static_cast<int>((posOnDevice / accessorySizeFloat) * ABS_MAX_VAL);
}
