#include <AP_RPM/AP_RPM.h>
#include <AP_PH/AP_PH.h>

void setup();
void loop();

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

static AP_PH PH;


void setup()
{
    hal.console->printf("APM PH library test\n\n\n");
    PH.init();
}

void loop(void)
{
    hal.console->printf("ph value: %.2f  ", PH.read_ph_pin());

    hal.scheduler->delay(100);

    hal.console->printf("\n");
}

AP_HAL_MAIN();
