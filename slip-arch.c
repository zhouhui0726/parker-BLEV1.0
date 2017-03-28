/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *VEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/**
 * \addtogroup cc26xx-char-io
 * @{
 *
 * \file
 * Arch-specific SLIP functions for the CC13xx/CC26xx
 */
/*---------------------------------------------------------------------------*/
#include "contiki-conf.h"
#include "dev/cc26xx-uart.h"
#include "dev/slip.h"
/*---------------------------------------------------------------------------*/
/**
 * \brief Write a byte over SLIP
 * \param c the byte
 */
void
slip_arch_writeb(unsigned char c)
{
  cc26xx_uart_write_byte(c);
}
/*---------------------------------------------------------------------------*/
/**
 * \brief Initialise the arch-specific SLIP driver
 * \param ubr Ignored for the cc26xx
 */
void
slip_arch_init(unsigned long ubr)
{
  /*
   * Enable an input handler. In doing so, the driver will make sure that UART
   * RX stays operational during deep sleep
   */
  cc26xx_uart_set_input(slip_input_byte);
}
/*---------------------------------------------------------------------------*/

/** @} */
