#include <stdlib.h>
#include <stdio.h>

#include <wiringPi.h>
#include <pcf8574.h>

#define BASE_8574 0x70
#define ADDR_I2C_8574 0x38
#define NUM_IO_8574 8

int main(void)
{
    int cnt = 0;
    unsigned level = LOW;

    wiringPiSetupSys();
    pcf8574Setup(BASE_8574, ADDR_I2C_8574);

    for (cnt = 0; cnt < NUM_IO_8574; cnt++)
    {
        pinMode(BASE_8574 + cnt, OUTPUT);
    }

    for(;;)
    {
        level = LOW;
        for (cnt = 0; cnt < NUM_IO_8574; cnt++)
        {
            digitalWrite(BASE_8574 + cnt, level);
            if ((cnt + 1) % NUM_IO_8574 / 2 == 0)
            {
                level = (level == LOW) ? HIGH : LOW;
            }
        }
        delay(500);
    }

    return EXIT_SUCCESS;
}
