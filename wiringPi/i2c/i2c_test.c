#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

#define BASE_8574 0x70
#define ADDR_I2C_8574 0x38

int main(void)
{
    int fd = -1;
    int value = 0;

    if ((fd = wiringPiI2CSetup(ADDR_I2C_8574)) < 0)
    {
        return EXIT_FAILURE;
    }

    /* determine original value of outputs */
    value = wiringPiI2CRead(fd);

    /* all outputs LOW */
    wiringPiI2CWrite(fd, 0xff);

    delay(1000);

    /* all outputs back to original value */
    wiringPiI2CWrite(fd, value);

    return EXIT_SUCCESS;
}
