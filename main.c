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

int main()
{
    if (common_init()) {
        const uint blue_led = 15;

        gpio_init(blue_led);
        gpio_set_dir(blue_led, GPIO_OUT);

        for (uint i = 0; i < 5; ++i) {
            common_onboard_led_on();
            gpio_put(blue_led, 0); 
            sleep_ms(500);

            common_onboard_led_off();
            gpio_put(blue_led, 1);
            sleep_ms(500);

            // printf("Hello buddy!\n");
        }
        gpio_put(blue_led, 0);
    }
}
