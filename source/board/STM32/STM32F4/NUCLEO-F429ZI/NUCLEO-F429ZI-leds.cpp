/**
 * \file
 * \brief Definition of LEDs for NUCLEO-F429ZI
 *
 * \author Copyright (C) 2016-2017 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "distortos/board/leds.hpp"

#ifdef CONFIG_BOARD_LEDS_ENABLE

#include "distortos/chip/ChipOutputPin.hpp"

namespace distortos
{

namespace board
{

/*---------------------------------------------------------------------------------------------------------------------+
| global objects
+---------------------------------------------------------------------------------------------------------------------*/

chip::ChipOutputPin leds[totalLeds]
{
#ifdef CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
		chip::ChipOutputPin{chip::Pin::pb0, false, chip::PinOutputSpeed::low, chip::PinPull::none, false, false},
#endif	// def CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
#ifdef CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
		chip::ChipOutputPin{chip::Pin::pb7, false, chip::PinOutputSpeed::low, chip::PinPull::none, false, false},
#endif	// def CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
#ifdef CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
		chip::ChipOutputPin{chip::Pin::pb14, false, chip::PinOutputSpeed::low, chip::PinPull::none, false, false},
#endif	// def CONFIG_CHIP_STM32_GPIOV2_GPIOB_ENABLE
};

}	// namespace board

}	// namespace distortos

#endif	// def CONFIG_BOARD_LEDS_ENABLE
