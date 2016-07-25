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

#include <iostream>

#include "o2.hpp"

using namespace upm;

O2::O2(int pin, float vref) : _dev(o2_init(pin)) {}

O2::~O2()
{
    o2_close(_dev);
}

void O2::setOffset(float offset)
{
    o2_set_offset(_dev, offset);
}

void O2::setScale(float scale)
{
    o2_set_scale(_dev, scale);
}

float O2::counts(unsigned int samples)
{
    float raw_avg = 0.0;

    // Read at least 1 sample
    if (samples == 0) samples = 1;

    float raw = 0.0;
    while (samples-- > 0)
    {
        o2_get_value(_dev, &raw);
        raw_avg += raw;
    }

    return raw_avg/samples;
}
