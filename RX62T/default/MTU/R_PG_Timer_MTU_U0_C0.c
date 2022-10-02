/******************************************************************************
* DISCLAIMER

* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized.

* This software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.

* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.

* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

* Renesas reserves the right, without notice, to make changes to this 
* software and to discontinue the availability of this software.  
* By using this software, you agree to the additional terms and 
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_Timer_MTU_U0_C0.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 10.06.2022 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_Timer_MTU_U0_C0.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Set_MTU_U0_C0(void)
*
* Function Name: R_PG_Timer_Set_MTU_U0_C0
*
* Description  : Set up the MTU
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_Create
*                   : R_MTU3_Create_load_defaults
*                   : R_MTU3_Set
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Set_MTU_U0_C0(void)
{
	bool res;
	R_MTU3_Create_structure create_params;

	R_MTU3_Create_load_defaults( &create_params );

	create_params.data2 = PDL_MTU3_MODE_PWM1;
	create_params.data3 = PDL_MTU3_CLK_ICLK_DIV_64 | PDL_MTU3_CLK_RISING | PDL_MTU3_CLEAR_TGRA;
	create_params.data5 = PDL_MTU3_BUFFER_BD_ENABLE | PDL_MTU3_BUFFER_BD_TCNT_CLR;
	create_params.data6 = PDL_MTU3_A_OC_LOW_CM_HIGH | PDL_MTU3_B_OC_LOW;
	create_params.data10 = 24999;
	create_params.data11 = 1250;
	create_params.data12 = 0;
	create_params.data13 = 1250;
	create_params.data14 = 0;
	create_params.data15 = 0;
	create_params.func1 = s1Func;
	create_params.data20 = 10;

	res = R_MTU3_Set( PDL_MTU3_PIN_0A_A );

	if( !res ){
		return res;
	}

	return R_MTU3_Create(
		0,
		&create_params
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StartCount_MTU_U0_C0(void)
*
* Function Name: R_PG_Timer_StartCount_MTU_U0_C0
*
* Description  : Start the MTU count
*
* Arguments    : None
*
* Return Value : true  : Resuming count succeeded.
*              : false : Resuming count failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StartCount_MTU_U0_C0(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_START;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_MTU_U0_C0(void)
*
* Function Name: R_PG_Timer_HaltCount_MTU_U0_C0
*
* Description  : Halt the MTU count
*
* Arguments    : None
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_HaltCount_MTU_U0_C0(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_STOP;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_MTU_U0_C0(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_MTU_U0_C0
*
* Description  : Acquire the MTU counter value
*
* Arguments    : uint16_t * counter_val : The address of storage area for the counter value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterValue_MTU_U0_C0(uint16_t * counter_val)
{
	if( counter_val == 0 ){ return false; }

	return R_MTU3_ReadChannel(
		0,
		PDL_NO_PTR,
		counter_val,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_MTU_U0_C0(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_MTU_U0_C0
*
* Description  : Set the MTU counter value
*
* Arguments    : uint16_t counter_val : Value to be set to the counter.
*
* Return Value : true  : Setting of the counter value succeeded.
*              : false : Setting of the counter value failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCounterValue_MTU_U0_C0(uint16_t counter_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_COUNTER;
	parameters.data4 = counter_val;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetTGR_MTU_U0_C0(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
*
* Function Name: R_PG_Timer_GetTGR_MTU_U0_C0
*
* Description  : Acquire the MTU general register value
*
* Arguments    : uint16_t * tgr_a_val : The address of storage area for the general register A value
*              : uint16_t * tgr_b_val : The address of storage area for the general register B value
*              : uint16_t * tgr_c_val : The address of storage area for the general register C value
*              : uint16_t * tgr_d_val : The address of storage area for the general register D value
*              : uint16_t * tgr_e_val : The address of storage area for the general register E value
*              : uint16_t * tgr_f_val : The address of storage area for the general register F value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetTGR_MTU_U0_C0(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
{
	uint16_t * local_a = PDL_NO_PTR;
	uint16_t * local_b = PDL_NO_PTR;
	uint16_t * local_c = PDL_NO_PTR;
	uint16_t * local_d = PDL_NO_PTR;
	uint16_t * local_e = PDL_NO_PTR;
	uint16_t * local_f = PDL_NO_PTR;

	if( tgr_a_val ){
		local_a = tgr_a_val;
	}
	if( tgr_b_val ){
		local_b = tgr_b_val;
	}
	if( tgr_c_val ){
		local_c = tgr_c_val;
	}
	if( tgr_d_val ){
		local_d = tgr_d_val;
	}
	if( tgr_e_val ){
		local_e = tgr_e_val;
	}
	if( tgr_f_val ){
		local_f = tgr_f_val;
	}

	return R_MTU3_ReadChannel(
		0,
		PDL_NO_PTR,
		PDL_NO_PTR,
		local_a,
		local_b,
		local_c,
		local_d,
		local_e,
		local_f
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_A_MTU_U0_C0(uint16_t tgr_a_val)
*
* Function Name: R_PG_Timer_SetTGR_A_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRA)
*
* Arguments    : uint16_t tgr_a_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_A_MTU_U0_C0(uint16_t tgr_a_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = tgr_a_val;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_B_MTU_U0_C0(uint16_t tgr_b_val)
*
* Function Name: R_PG_Timer_SetTGR_B_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRB)
*
* Arguments    : uint16_t tgr_b_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_B_MTU_U0_C0(uint16_t tgr_b_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRB;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = tgr_b_val;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_C_MTU_U0_C0(uint16_t tgr_c_val)
*
* Function Name: R_PG_Timer_SetTGR_C_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRC)
*
* Arguments    : uint16_t tgr_c_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_C_MTU_U0_C0(uint16_t tgr_c_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRC;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = tgr_c_val;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_D_MTU_U0_C0(uint16_t tgr_d_val)
*
* Function Name: R_PG_Timer_SetTGR_D_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRD)
*
* Arguments    : uint16_t tgr_d_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_D_MTU_U0_C0(uint16_t tgr_d_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRD;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = tgr_d_val;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_E_MTU_U0_C0(uint16_t tgr_e_val)
*
* Function Name: R_PG_Timer_SetTGR_E_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRE)
*
* Arguments    : uint16_t tgr_e_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_E_MTU_U0_C0(uint16_t tgr_e_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRE;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = tgr_e_val;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_F_MTU_U0_C0(uint16_t tgr_f_val)
*
* Function Name: R_PG_Timer_SetTGR_F_MTU_U0_C0
*
* Description  : Set the MTU general register value (TGRF)
*
* Arguments    : uint16_t tgr_f_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_F_MTU_U0_C0(uint16_t tgr_f_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRF;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = tgr_f_val;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_MTU_U0_C0(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
*
* Function Name: R_PG_Timer_GetRequestFlag_MTU_U0_C0
*
* Description  : Acquire and clear the MTU interrupt flag
*
* Arguments    : bool * cm_ic_a : The address of storage area for the compare match/input capture A flag.
*              : bool * cm_ic_b : The address of storage area for the compare match/input capture B flag.
*              : bool * cm_ic_c : The address of storage area for the compare match/input capture C flag.
*              : bool * cm_ic_d : The address of storage area for the compare match/input capture D flag.
*              : bool * cm_e : The address of storage area for the compare match/input capture E flag.
*              : bool * cm_f : The address of storage area for the compare match/input capture F flag.
*              : bool * ov : The address of storage area for the overflow flag.
*              : bool * un : The address of storage area for the underflow flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_MTU_U0_C0(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
{
	uint8_t data;
	bool res;

	res = R_MTU3_ReadChannel(
		0,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( cm_ic_a ){
		*cm_ic_a = data & 0x01;
	}
	if( cm_ic_b ){
		*cm_ic_b = (data >> 1) & 0x01;
	}
	if( cm_ic_c ){
		*cm_ic_c = (data >> 2) & 0x01;
	}
	if( cm_ic_d ){
		*cm_ic_d = (data >> 3) & 0x01;
	}
	if( cm_e ){
		*cm_e = (data >>4) & 0x01;
	}
	if( cm_f ){
		*cm_f = (data >> 5) & 0x01;
	}
	if( ov ){
		*ov = (data >> 6) & 0x01;
	}
	if( un ){
		*un = 0x00;
	}

	return res;
}



