#include <QGuiApplication>
#include <chrono>
#include "virtualstylus.h"
#include "error.h"
#include "uinput.h"
#include "constants.h"
#include "accessory.h"

using namespace std::chrono;

VirtualStylus::VirtualStylus(DisplayScreenTranslator * displayScreenTranslator){
    this->displayScreenTranslator = displayScreenTranslator;
}

void VirtualStylus::initializeStylus(){
    Error * err = new Error();
    const char* deviceName = "pen-emu";
    fd = init_uinput_stylus(deviceName, err);

}


void VirtualStylus::handleAccessoryEventData(AccessoryEventData * accessoryEventData){
    Error * err = new Error();

    send_uinput_event(fd, ET_ABSOLUTE, EC_ABSOLUTE_X, displayScreenTranslator->getAbsXStretched(accessoryEventData), err);
    send_uinput_event(fd, ET_ABSOLUTE, EC_ABSOLUTE_Y, displayScreenTranslator->getAbsYStretched(accessoryEventData), err);

    send_uinput_event(fd, ET_SYNC, EC_SYNC_REPORT, 0, err);
    delete err;
}


void VirtualStylus::destroyStylus(){
    //ioctl(fd, UI_DEV_DESTROY);
    // ::pclose(fd);
}
