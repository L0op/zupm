/*
 * Author: Jon Trulson <jtrulson@ics.com>
 * Copyright (c) 2015 Intel Corporation.
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
#pragma once

#include <iostream>
#include <string>

#include "mraa/aio.hpp"
#include "light.h"

namespace upm {
  /**
   * @brief DFRobot lux sensors
   * @defgroup light libupm-light
   * @ingroup dfrobot liquid analog
   */

  /**
   * @library light
   * @sensor light
   * @comname DFRobot lux Sensors
   * @type liquid
   * @man dfrobot 
   * @web http://www.dfrobot.com/index.lightp?route=product/product&product_id=1110
   * @con analog
   *
   * @brief API for the DFRobot lux Sensors
   *
   * This sensor family returns an analog voltage proportional to the
   * acidity or alkalinity of a liquid -- it's lux value.
   *
   * This driver was developed using the DFRobot Analog lux meter and
   * the DFRobot Analog lux Meter Pro.
   *
   *
   * Calibration instructions, taken and slightly reworded from the
   *  DFRobot wiki at:
   *  http://dfrobot.com/wiki/index.lightp/PH_meter%28SKU:_SEN0161%29
   *
   *  1) Connect equipment: the lux electrode is connected to the BNC
   *  connector on the lux meter board, and then the lux meter board is
   *  connected to the analog port 0 of the controller. When the
   *  controller gets power, you will see the blue LED on board is on.
   *
   *  2) Put the lux electrode into the standard solution whose lux
   *  value is 7.00.  Run the light example and note the lux output
   *  value.  Compare the value with 7.00, and calculate the
   *  difference.  This is the value you should supply to the
   *  setOffset() method.
   *
   *  3) Put the lux electrode into the lux standard solution whose
   *  value is 4.00. Then wait about one minute, and adjust the
   *  potentiometer on the interface board.  Let the value stabilise
   *  at around 4.00. At this time,the acidic calibration has been
   *  completed and you can measure the lux value of an acidic
   *  solution.
   *
   *  4) According to the linear characteristics of lux electrode
   *  itself, after the above calibration,you can directly measure the
   *  lux value of the alkaline solution. If you want to get better
   *  accuracy, you can recalibrate it. Alkaline calibration use the
   *  standard solution whose lux value is 9.18.  Also adjust the
   *  potentiometer and let the value stabilise at around 9.18. After
   *  this calibration, you can measure the lux value of an alkaline
   *  solution.
   *
   * @image html light.jpg
   * @snippet light.cxx Interesting
   */

  class LIGHT {
  public:

    /**
     * LIGHT constructor
     *
     * @param pin Analog pin to use
     * @param vref Analog reference voltage; default is 5.0 V
     */
    LIGHT(int pin, float vref = 5.0);

    /**
     * LIGHT destructor
     */
    ~LIGHT();

    /**
     * Returns the voltage detected on the analog pin
     *
     * @return The detected voltage
     */
    float volts();

    /**
     * Specifies the offset determined from calibration.  The default
     * is 0.0.
     *
     * @param offset The offset value to use
     */
    void setOffset(float offset);

    /**
     * Specifies the scale determined from calibration.  The default
     * is 1.0.
     *
     * @param scale The scale value to use
     */
    void setScale(float scale);

    /**
     * Take a number of samples and return the detected lux value.  The
     * default number of samples is 15.
     *
     * @param samples The number of samples to average over, default 15
     * @return The lux value detected
     */
    float lux(unsigned int samples = 15);

  private:
    light_context _dev;
  };
}


