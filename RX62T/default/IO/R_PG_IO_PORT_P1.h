/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_IO_PORT_P1.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 10.06.2022 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_io_port.h"
#include "r_pdl_io_port_RX62TxFM.h"

bool R_PG_IO_PORT_Set_P1(void);
bool R_PG_IO_PORT_Set_P10(void);
bool R_PG_IO_PORT_Read_P1(uint8_t * data);
bool R_PG_IO_PORT_Read_P10(uint8_t * data);
bool R_PG_IO_PORT_Read_P11(uint8_t * data);
bool R_PG_IO_PORT_Write_P1(uint8_t data);
bool R_PG_IO_PORT_Write_P10(uint8_t data);



