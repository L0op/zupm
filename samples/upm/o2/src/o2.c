/*
 * Author: Noel Eck <noel.eck@intel.com>
 * Copyright (c) 2016 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <unistd.h>
#include <signal.h>

#include "o2.h"
#include "upm_utilities.h"
#include "mraa.h"

bool shouldRun = true;

void sig_handler(int signo)
{
    if (signo == SIGINT)
        shouldRun = false;
}

int main()
{
    if (mraa_init() != MRAA_SUCCESS)
    {
        fprintf(stderr,"Failed to initialize mraa\n");
        return -1;
    }

    signal(SIGINT, sig_handler);

    //! [Interesting]

    // Instantiate a o2 sensor on analog pin A0
    o2_context sensor = o2_init(0);

    if (!sensor)
    {
        printf("o2_init() failed.\n");
        return -1;
    }

    // Every half a second, sample the sensor output
    while (shouldRun)
    {
        float raw_volts = 0.0;
        float o2_percent = 0.0;

        o2_get_raw_volts(sensor, &raw_volts);
        // d2000 needs extra delay for some reason
#if defined(CONFIG_BOARD_QUARK_D2000_CRB)
        upm_delay_ms(5);
#endif
        o2_get_value(sensor, &o2_percent);

#if defined(CONFIG_BOARD_QUARK_D2000_CRB)
        printf("O2 raw volts: %d mv, o2: %d \n",
                (int)(raw_volts*1000), (int)o2_percent);
#elif defined(CONFIG_BOARD_ARDUINO_101_SSS)
        printf("O2 raw volts: %0.03f v, o2: %0.03f %%\n",
                raw_volts, o2_percent);
#endif

        upm_delay_ms(500);
    }

    //! [Interesting]

    printf("Exiting\n");

    o2_close(sensor);

    return 0;
}
