#include "AP_PH.h"

extern const AP_HAL::HAL &hal;

AP_PH::AP_PH() {
    if (_singleton){
        AP_HAL::panic("Too many PH sensors");
    }
    _singleton = this;
}

AP_PH *AP_PH::get_singleton() { return _singleton; }

void AP_PH::init() { _source = hal.analogin->channel(ANALOG_INPUT_NONE); }

float AP_PH::read_ph_pin(){
    _source->set_pin(0);
    return _source->voltage_average();
}

AP_PH *AP_PH::_singleton = nullptr;

namespace AP {

AP_PH *ph()
{
    return AP_PH::get_singleton();
}

};
