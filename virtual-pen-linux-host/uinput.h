#ifndef UINPUT_H
#define UINPUT_H
#include "error.h"
extern "C" int init_uinput_stylus(const char* name, Error* err);
extern "C" void send_uinput_event(int device, int type, int code, int value, Error* err);
#endif // UINPUT_H
