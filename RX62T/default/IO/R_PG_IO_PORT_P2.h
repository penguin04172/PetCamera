/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_IO_PORT_P2.h
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

bool R_PG_IO_PORT_Set_P2(void);
bool R_PG_IO_PORT_Set_P22(void);
bool R_PG_IO_PORT_Set_P23(void);
bool R_PG_IO_PORT_Set_P24(void);
bool R_PG_IO_PORT_Read_P2(uint8_t * data);
bool R_PG_IO_PORT_Read_P22(uint8_t * data);
bool R_PG_IO_PORT_Read_P23(uint8_t * data);
bool R_PG_IO_PORT_Read_P24(uint8_t * data);
bool R_PG_IO_PORT_Write_P2(uint8_t data);
bool R_PG_IO_PORT_Write_P22(uint8_t data);
bool R_PG_IO_PORT_Write_P23(uint8_t data);
bool R_PG_IO_PORT_Write_P24(uint8_t data);



