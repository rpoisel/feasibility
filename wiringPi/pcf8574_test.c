#include <stdlib.h>
#include <stdio.h>

#include <wiringPi.h>
#include <pcf8574.h>

#define BASE_8574 0x70
#define ADDR_8574 0x38
#define NUM_IO_8574 8

int main(void)
{
    int cnt = 0;

    wiringPiSetupSys();
    pcf8574Setup(BASE_8574, ADDR_8574);

    for (cnt = 0; cnt < NUM_IO_8574; cnt++)
    {
        pinMode(BASE_8574 + cnt, OUTPUT);
    }

    digitalWrite(BASE_8574, HIGH);

    return EXIT_SUCCESS;
}
