/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * 	   Sisinty Sasmita Patra <sisinty.s.patra@intel.com>
 *
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

#include<stdio.h>
#include <stdlib.h>

#include "rotary.h"

struct _upm_rotary{
    mraa_aio_context aio;
    float m_aRef;
    int16_t m_aRes;
};

const char upm_rotary_name[] = "Grove Rotary";
const char upm_rotary_description[] = "Analog Grove Rotary Sensor";
const upm_protocol_t upm_rotary_protocol[] = {UPM_ANALOG};
const upm_protocol_t upm_rotary_category[] = {UPM_VOLTAGE, UPM_ANGLE};

const upm_sensor_descriptor_t upm_rotary_get_descriptor(void* dev) {
    upm_sensor_descriptor_t usd;
    usd.name = upm_rotary_name;
    usd.description = upm_rotary_description;
    usd.protocol_size = 1;
    usd.protocol = upm_rotary_protocol;
    usd.category_size = 1;
    usd.category = upm_rotary_category;
    return usd;
}

const void* (*upm_get_ft) (upm_sensor_t sensor_type) = &upm_rotary_get_ft;

void* upm_rotary_get_ft(upm_sensor_t sensor_type) {

    if(sensor_type == UPM_SENSOR) {
        upm_sensor_ft *ft = malloc(sizeof(*ft));
        //ft->upm_sensor_init_name = upm_rotary_init_name;
        ft->upm_sensor_close = upm_rotary_close;
        ft->upm_sensor_read = upm_rotary_read;
        ft->upm_sensor_write = upm_rotary_write;
        return ft;
    }

    if(sensor_type == UPM_VOLTAGE) {
        struct _upm_voltage_ft *vft = malloc(sizeof(*vft));
        if(vft == NULL){
            printf("Unable to assign memory");
            return NULL;
        }
        vft->upm_voltage_get_value = upm_rotary_get_value_voltage;
        return vft;
    }

    if(sensor_type == UPM_ANGLE) {
        struct _upm_angle_ft *aft = malloc(sizeof(*aft));
        if(aft == NULL){
            printf("Unable to assign memory");
            return NULL;
        }
        aft->upm_angle_get_value = upm_rotary_get_value_angle;
        return aft;
    }
    return NULL;
}

//void* upm_rotary_init_name(...);

void* upm_rotary_init(int pin, float aRef)
{
    upm_rotary dev = (upm_rotary) malloc(sizeof(struct _upm_rotary));

    if(dev == NULL) return NULL;

    dev->aio = mraa_aio_init(pin);

    dev->m_aRef = aRef;

    // get adc bit range
    dev->m_aRes = (1 << mraa_aio_get_bit(dev->aio));

    if(dev->aio == NULL){
        free(dev);
        return NULL;
    }
    return dev;
}

void upm_rotary_close(void* dev)
{
    upm_rotary device = (upm_rotary) dev;
    mraa_aio_close(device->aio);
    free(dev);
}

upm_result_t upm_rotary_read (void* dev, void* value, int len)
{
    upm_rotary device = (upm_rotary) dev;

    *(float*)value = mraa_aio_read(device->aio);

    return UPM_SUCCESS;
}

upm_result_t upm_rotary_write(void* dev, void* value, int len)
{
    return  UPM_ERROR_NOT_SUPPORTED;
}

upm_result_t upm_rotary_get_value_voltage (void* dev, float* rotval, upm_voltage_u unit)
{
    upm_rotary device = (upm_rotary) dev;

    float val = 0.0;
    upm_rotary_read(device, &val, 0);

    if(unit == VOLTS) {
        *rotval = (val/device->m_aRes) * device->m_aRef;
    }
    return UPM_SUCCESS;
}

upm_result_t upm_rotary_get_value_angle (void* dev, float* rotval, upm_angle_u unit)
{
    upm_rotary device = (upm_rotary) dev;

    float val = 0.0;
    upm_rotary_read(device, &val, 0);

    if(unit == DEGREES) {
        *rotval = UPM_ROTARY_MAX_ANGLE * (val/device->m_aRes);
    }
    else if (unit == RADIANS){
        *rotval = UPM_ROTARY_MAX_ANGLE * (val/device->m_aRes) * M_PI/180.0;
    }
    return UPM_SUCCESS;
}
