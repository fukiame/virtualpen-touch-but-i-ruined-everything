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
    if(accessoryEventData->action == ACTION_DOWN || accessoryEventData->action == ACTION_MOVE){
        if(accessoryEventData->action == ACTION_DOWN){
            send_uinput_event(fd, ET_KEY, EC_KEY_TOUCH, 1, err);
        }

        if(!isPenActive){
            send_uinput_event(fd, ET_KEY, EC_KEY_TOOL_PEN, 1, err);
            isPenActive = true;
        }

        int32_t x = 0;
        int32_t y = 0;

        x = displayScreenTranslator->getAbsXStretched(accessoryEventData);
        y = displayScreenTranslator->getAbsYStretched(accessoryEventData);

        send_uinput_event(fd, ET_ABSOLUTE, EC_ABSOLUTE_X, x, err);
        send_uinput_event(fd, ET_ABSOLUTE, EC_ABSOLUTE_Y, y, err);
    }
    else{
        send_uinput_event(fd, ET_KEY, EC_KEY_TOOL_PEN, 0, err);
        send_uinput_event(fd, ET_KEY, EC_KEY_TOUCH, 0, err);
        isPenActive = false;
    }

    send_uinput_event(fd, ET_SYNC, EC_SYNC_REPORT, 0, err);
    delete err;
}


void VirtualStylus::destroyStylus(){
    //ioctl(fd, UI_DEV_DESTROY);
    // ::pclose(fd);
}
