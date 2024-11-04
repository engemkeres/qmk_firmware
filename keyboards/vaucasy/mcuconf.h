#pragma once

#include_next <mcuconf.h>
#include "config.h"

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_I2C_USE_I2C3
#define STM32_I2C_USE_I2C3 TRUE
