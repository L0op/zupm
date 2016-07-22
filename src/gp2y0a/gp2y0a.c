/*
 * Author: Jon Trulson <jtrulson@ics.com>
 *         Abhishek Malik <abhishek.malik@intel.com>
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
#include "gp2y0a.h"

typedef struct _gp2y0a_context {
    mraa_aio_context            aio;
    uint8_t                     pin;
    int                         a_res;
} *gp2y0a_context;

#if defined(CONFIG_BOARD_ARDUINO_101) || defined(CONFIG_BOARD_ARDUINO_101_SSS) || defined(CONFIG_BOARD_QUARK_D2000_CRB)
DEFINE_MEM_MAP(UPM_GP2Y0A_MAP, 1, sizeof(struct _upm_gp2y0a));
const kmemory_map_t UPM_GP2Y0A_MEM_MAP;
#elif defined(linux)
#define UPM_GP2Y0A_MEM_MAP 0
#endif

gp2y0a_context gp2y0a_init(uint8_t pin, float a_ref){
    gp2y0a_context dev =
      (gp2y0a_context) upm_malloc(UPM_GP2Y0A_MEM_MAP,
                                  sizeof(struct _gp2y0a_context));

    if(dev->aio == NULL){
        return NULL;
    }
    dev->pin = pin;
    dev->aio = mraa_aio_init(dev->pin);
    dev->a_res = (1 << mraa_aio_get_bit(dev->aio));

    return dev;
}

void gp2y0a_close(gp2y0a_context dev){
    upm_free(UPM_GP2Y0A_MEM_MAP, dev);
}

upm_result_t gp2y0a_get_value(gp2y0a_context dev, float a_ref,
                              uint8_t samples, float* value){
    int val;
    int sum = 0;
    int i = 0;

    if (samples <= 0)
      samples = 1;

    for(i=0; i<samples; i++) {
        val = mraa_aio_read(dev->aio);
        sum += val;
    }
    val = sum/samples;
    float volts = (float)(val * a_ref) / (float)dev->a_res;
    *value = volts;

    return UPM_SUCCESS;
}
