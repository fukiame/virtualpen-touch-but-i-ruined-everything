#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <string>
#include <array>
using namespace std;

typedef struct _accessoryEventData{
    int action;
    int x;
    int y;
} AccessoryEventData;
void printRawInputData(array<string, 3> * strs);
array<string, 3> readUntilDelimiter(unsigned char* a, int size);

#endif // ACCESSORY_H
