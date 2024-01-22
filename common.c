// SugarCube: Raspberry Pi Pico W Micro-Console Software
// Copyright (C) 2024 Omar Huseynov
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "common.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

////////////////////////////////////////
bool common_init()
{
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("WIFI initialization failed\n");
        return false;
    }
    return true;
}

////////////////////////////////////////
void common_onboard_led_on()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}

////////////////////////////////////////
void common_onboard_led_off()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}
