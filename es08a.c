/*
 * Author: Abhishek Malik <abhishek.malik@intel.com>
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
	mraa_pwm_context	pwm;
	uint16_t 			servo_pin;
	uint32_t			max_pulse_width;
	uint32_t			min_pulse_width;
};

void* upm_get_function_table(upm_sensor_types sensor_type){
	if(sensor_type == UPM_SERVO){
		struct _upm_servo_ft *ft = malloc(sizeof(*ft));
		ft->upm_servo_set_angle = upm_es08a_set_angle;
		return ft;
	}
	return NULL;
}

//void* upm_es08a_init(int32_t pin, int32_t min_pulse_width, int32_t max_pulse_width){
void* upm_sensor_init(int num,...){
	UpmES08A dev = (UpmES08A) malloc(sizeof(struct _upm_es08a));
	//
	va_list pin_list;

	//
	va_start(pin_list, num);

	// first argument is the pin number
	dev->servo_pin = va_arg(pin_list, int);
	// second is the min pulse width
	dev->min_pulse_width = va_arg(pin_list, int);
	// third is the max pulse width
	dev->max_pulse_width = va_arg(pin_list, int);
	if(dev == NULL){
		printf("Unable to assign memory to the Servo motor structure");
		return NULL;
	}

	va_end(pin_list);

	dev->pwm = mraa_pwm_init(dev->servo_pin);
	if(dev->pwm == NULL){
		printf("Unable to initialize the PWM pin");
	}

	upm_es08a_set_angle(dev, 0);
	return dev;
}

upm_result_t upm_sensor_close(void* dev){
	UpmES08A device = (UpmES08A) dev;
	mraa_result_t ret = mraa_pwm_enable(device->pwm, 0);
	if(ret == MRAA_SUCCESS)
		return UPM_SUCCESS;
	else
		return UPM_ERROR_UNSPECIFIED;
}

upm_result_t upm_sensor_write (void* dev, void* data, int len){
	UpmES08A device = (UpmES08A) dev;
	servo_data_struct str = *(servo_data_struct*) data;
	if(UPM_ES08A_MAX_ANGLE < str.angle || str.angle < 0){
		printf("The angle specified is either above the max angle or below 0");
		return UPM_ERROR_UNSPECIFIED;
	}
	printf("setting angle to: %d\n", str.angle);

	mraa_pwm_enable(device->pwm, 1);
	mraa_pwm_period_us(device->pwm, UPM_ES08A_PERIOD);
	int32_t val = 0;

	upm_es08a_calc_pulse_travelling(dev, &val, str.angle);
	mraa_pwm_pulsewidth_us(device->pwm, val);

	upm_delay_seconds(1);
	mraa_pwm_enable(device->pwm, 0);

	return UPM_SUCCESS;
	//return upm_es08a_set_angle(device, angle);
}

upm_result_t upm_es08a_set_angle(void* dev, int32_t angle){
	UpmES08A device = (UpmES08A) dev;
	servo_data_struct data_str = {angle};
	upm_sensor_write(device, &data_str, 0);
	return UPM_SUCCESS;
}

upm_result_t upm_es08a_calc_pulse_travelling(void* dev, int32_t* ret_val, int32_t value){
	UpmES08A device = (UpmES08A) dev;
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
	UpmES08A device = (UpmES08A) dev;
	device->min_pulse_width = width;
}

void upm_es08a_set_max_pulse_width (void* dev, int width){
	UpmES08A device = (UpmES08A) dev;
	device->max_pulse_width = width;
}

int upm_es08a_get_min_pulse_width (void* dev){
	UpmES08A device = (UpmES08A) dev;
	return device->min_pulse_width;
}

int upm_es08a_get_max_pulse_width (void* dev){
	UpmES08A device = (UpmES08A) dev;
	return device->max_pulse_width;
}

void UpmES08AGetSensorInfo(){
	printf("this is a servo motor: ES08A");
}
