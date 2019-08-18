// Smooth - C++ framework for writing applications based on Espressif's ESP-IDF.
// Copyright (C) 2017 Per Malmberg (https://github.com/PerMalmberg)
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
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#ifndef ESP_PLATFORM
#include "mock/Output.h"
#else
#include <driver/gpio.h>

namespace smooth::core::io
{
    class Output
    {
        public:
            Output(gpio_num_t io, bool active_high, bool pull_up, bool pull_down, bool clear_on_creation = true);

            void set();

            void set(bool active);

            void clr();

            Output(const Output&) = delete;

            Output& operator=(const Output&) = delete;

        private:
            gpio_num_t io;
            bool active_high;
    };
}

#endif