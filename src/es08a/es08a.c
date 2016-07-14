/*
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
 *         Abhishek Malik <abhishek.malik@intel.com>
 * Copyright (c) 2014 Intel Corporation.
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
#include "es08a.h"

struct _upm_es08a {
    mraa_pwm_context    pwm;
    uint16_t            servo_pin;
    uint32_t            max_pulse_width;
    uint32_t            min_pulse_width;
};

const char upm_es08a_name[] = "ES08A";
const char upm_es08a_description[] = "Grove Servo Motor";
const upm_protocol_t upm_es08a_protocol[] = {UPM_PWM};
const upm_sensor_t upm_es08a_category[] = {UPM_SERVO};

const upm_sensor_descriptor_t upm_es08a_get_descriptor (){
    upm_sensor_descriptor_t usd;
    usd.name = upm_es08a_name;
    usd.description = upm_es08a_description;
    usd.protocol_size = 1;
    usd.protocol = upm_es08a_protocol;
    usd.category_size = 1;
    usd.category = upm_es08a_category;
    return usd;
}

static const upm_sensor_ft ft =
{
    .upm_sensor_init_name = &upm_es08a_init_name,
    .upm_sensor_close = &upm_es08a_halt,
    .upm_sensor_read = &upm_es08a_read,
    .upm_sensor_write = &upm_es08a_write,
    .upm_sensor_get_descriptor = &upm_es08a_get_descriptor
};

static const upm_servo_ft sft =
{
    .upm_servo_set_angle = &upm_es08a_set_angle
};

const void* (*upm_get_ft) (upm_sensor_t sensor_type) = &upm_es08a_get_ft;

const void* upm_es08a_get_ft(upm_sensor_t sensor_type){
    if(sensor_type == UPM_SERVO){
        return &sft;
    }
    else if(sensor_type == UPM_SENSOR){
        return &ft;
    }
    return NULL;
}

void* upm_es08a_init_name(){
    return NULL;
}

void* upm_es08a_init(int32_t pin, int32_t min_pulse_width, int32_t max_pulse_width){
    upm_es08a dev = (upm_es08a) malloc(sizeof(struct _upm_es08a));
    dev->servo_pin = pin;
    // second is the min pulse width
    dev->min_pulse_width = min_pulse_width;
    // third is the max pulse width
    dev->max_pulse_width = max_pulse_width;
    if(dev == NULL){
        printf("Unable to assign memory to the Servo motor structure");
        return NULL;
    }

    dev->pwm = mraa_pwm_init(dev->servo_pin);
    if(dev->pwm == NULL){
        printf("Unable to initialize the PWM pin");
    }

    upm_es08a_set_angle(dev, 0);
    return dev;
}

void upm_es08a_halt(void* dev){
    upm_es08a device = (upm_es08a) dev;
    mraa_pwm_enable(device->pwm, 0);
    free(device);
}

upm_result_t upm_es08a_read (const void* dev, void* data, int len){
    return UPM_ERROR_NOT_IMPLEMENTED;
}

upm_result_t upm_es08a_write (const void* dev, void* data, int len){
    upm_es08a device = (upm_es08a) dev;
    uint32_t int_data = *((uint32_t *)data);
    if(UPM_ES08A_MAX_ANGLE < int_data || int_data < 0){
        printf("The angle specified is either above the max angle or below 0");
        return UPM_ERROR_UNSPECIFIED;
    }
    printf("setting angle to: %d\n", int_data);

    mraa_pwm_enable(device->pwm, 1);
    mraa_pwm_period_us(device->pwm, UPM_ES08A_PERIOD);
    int32_t val = 0;

    upm_es08a_calc_pulse_travelling(dev, &val, int_data);
    mraa_pwm_pulsewidth_us(device->pwm, val);

    upm_delay(1);
    mraa_pwm_enable(device->pwm, 0);

    return UPM_SUCCESS;
    //return upm_es08a_set_angle(device, angle);
}

upm_result_t upm_es08a_set_angle(void* dev, int32_t angle){
    upm_es08a device = (upm_es08a) dev;
    upm_es08a_write(device, &angle, 0);
    return UPM_SUCCESS;
}

upm_result_t upm_es08a_calc_pulse_travelling(const void* dev, int32_t* ret_val, int32_t value){
    upm_es08a device = (upm_es08a) dev;
    if (value > device->max_pulse_width) {
        return device->max_pulse_width;
    }

    // if less than the boundaries
    if (value  < 0) {
        return device->min_pulse_width;
    }

    *ret_val = (int) ((float)device->min_pulse_width + ((float)value / UPM_ES08A_MAX_ANGLE) * ((float)device->max_pulse_width - (float)device->min_pulse_width));
    return UPM_SUCCESS;
}

void upm_es08a_set_min_pulse_width (void* dev, int width){
    upm_es08a device = (upm_es08a) dev;
    device->min_pulse_width = width;
}

void upm_es08a_set_max_pulse_width (void* dev, int width){
    upm_es08a device = (upm_es08a) dev;
    device->max_pulse_width = width;
}

int upm_es08a_get_min_pulse_width (void* dev){
    upm_es08a device = (upm_es08a) dev;
    return device->min_pulse_width;
}

int upm_es08a_get_max_pulse_width (void* dev){
    upm_es08a device = (upm_es08a) dev;
    return device->max_pulse_width;
}

void upm_es08aGetSensorInfo(){
    printf("this is a servo motor: ES08A");
}
