//Modified: Abhishek Malik <abhishek.malik@intel.com>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "moisture.h"

#include "upm_utilities.h"
#include "mraa.h"

int main()
{
    if (mraa_init() != MRAA_SUCCESS)
    {
        fprintf(stderr,"Failed to initialize mraa\n");
        return -1;
    }

    moisture_context dev = moisture_init(0);
    int val;
    while(1){
        if(moisture_get_moisture(dev, &val) != UPM_SUCCESS){
            printf("Failed to get any values from the sensor\n");
        }
        printf("Moisture Value: %d\n", val);
        upm_delay(1);
    }
    moisture_close(dev);

    return 0;
}
