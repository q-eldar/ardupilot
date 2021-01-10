#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_Param/AP_Param.h>
#include <AP_Math/AP_Math.h>

class AP_PH {
public:
    AP_PH();

    AP_PH(const AP_PH& other) = delete;
    AP_PH &operator=(const AP_PH&) = delete;
    static AP_PH *get_singleton();
    void init();
    float read_ph_pin();
private:
    static AP_PH *_singleton;
    AP_HAL::AnalogSource *_source;
};

namespace AP {
    AP_PH *ph();
};

