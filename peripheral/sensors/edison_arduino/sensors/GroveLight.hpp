/*
 * Copyright (C) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GROVE_LIGHT_HPP
#define GROVE_LIGHT_HPP

#include <hardware/sensors.h>
#include "Sensor.hpp"
#include "grove.h"

struct sensors_event_t;

/**
 * GroveLight exposes the Grove Light sensor
 *
 * Overrides the pollEvents & activate Sensor methods.
 */
class GroveLight : public Sensor, public upm::GroveLight {
  public:

    /**
     * GroveLight constructor
     * @param pin number of the analog input
     */
    GroveLight(int pin);

    /**
     * GroveLight destructor
     */
    ~GroveLight() override;

    /**
     * Poll for events
     * @param data where to store the events
     * @param count the number of events returned must be <= to the count
     * @return 0 on success and a negative error number otherwise
     */
    int pollEvents(sensors_event_t* data, int count) override;

    /**
     * Activate the sensor
     * @param handle sensor identifier
     * @param enabled 1 for enabling and 0 for disabling
     * @return 0 on success and a negative error number otherwise
     */
    int activate(int handle, int enabled);

    /**
     * Data structure which describes the sensor type
     */
    static struct sensor_t const kSensorDescription;
};


#endif  // GROVE_LIGHT_HPP