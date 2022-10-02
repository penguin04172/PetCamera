#include "setup.h"

extern uint8_t u2Tx, i2cTx, i2cRx;
extern uint16_t delay;

void delayMs(uint16_t time) {
	delay = 0;
	while (delay < time);
}

void wrReg (uint8_t reg, uint8_t val) {
	uint8_t out[2];
	out[0] = reg;
	out[1] = val;
	i2cTx = 1;
	R_PG_I2C_MasterSend_C0(0x42, out, 2);
	while (i2cTx);
	delayMs(100);
}

uint8_t rdReg(uint8_t reg) {
	uint8_t ret;
	i2cTx = 1;
	R_PG_I2C_MasterSendWithoutStop_C0(0x42, &reg, 1);
	while (i2cTx);
	i2cRx = 1;
	R_PG_I2C_MasterReceive_C0(0x42, &ret, 1);
	while (i2cRx);
	R_PG_I2C_GenerateStopCondition_C0();
	return ret;
}

void set_reg_Complex() {
	wrReg(0x12, 0x80);
	delayMs(1000);
	//Frame Rate Adjustment for 24Mhz input clock
	//30fps PCLK=24MHz
	wrReg(0x11, 0x81);//???????????0x80,??????0x00
	wrReg(0x6b, 0x0a);//PLL??,???????????0x0a,??????0x40,?PLL??????????
	wrReg(0x2a, 0x00);
	wrReg(0x2b, 0x00);
	wrReg(0x92, 0x00);
	wrReg(0x93, 0x00);
	wrReg(0x3b, 0x0a);

	//Output format
	wrReg(0x12, 0x04);//QVGA(320*240)?RGB

	//RGB555/565 option(must set COM7[2] = 1 and COM7[0] = 0)
	wrReg(0x40, 0x10);//RGB565,effective only when RGB444[1] is low
	wrReg(0x8c, 0x00);

	//Special effects - ?? 
	//normal
	wrReg(0x3a, 0x04);
	wrReg(0x67, 0xc0);
	wrReg(0x68, 0x80);

	//Mirror/VFlip Enable - ????/??????
	wrReg(0x1e, 0x37);//???????????????????

	//Banding Filter Setting for 24Mhz Input Clock - ?????
	//30fps for 60Hz light frequency
	//wrReg(0x13, 0xe7);//banding filer enable
	//wrReg(0x9d, 0x98);//50Hz banding filer
	//wrReg(0x9e, 0x7f);//60Hz banding filer
	//wrReg(0xa5, 0x02);//3 step for 50Hz
	//wrReg(0xab, 0x03);//4 step for 60Hz
	//wrReg(0x3b, 0x02);//select 60Hz banding filer

	//Simple White Balance - ???
	//wrReg(0x13, 0xe7);//AWB?AGC?AGC Enable and ...
	//wrReg(0x6f, 0x9f);//simple AWB

	//AWBC - ???????(Automatic white balance control) 
	//wrReg(0x43, 0x14);//????????????????(Reserved),???????
	//wrReg(0x44, 0xf0);
	//wrReg(0x45, 0x34);        
	//wrReg(0x46, 0x58);
	//wrReg(0x47, 0x28);
	//wrReg(0x48, 0x3a);

	//AWB Control
	//wrReg(0x59, 0x88);//????????????,???????
	//wrReg(0x5a, 0x88);        
	//wrReg(0x5b, 0x44);
	//wrReg(0x5c, 0x67);
	//wrReg(0x5d, 0x49);
	//wrReg(0x5e, 0x0e);

	//AWB Control
	//wrReg(0x6c, 0x0a);
	//wrReg(0x6d, 0x55);       
	//wrReg(0x6e, 0x11);
	//wrReg(0x6f, 0x9f);

	//AGC/AEC - Automatic Gain Control??????/Automatic exposure Control??????
	//wrReg(0x00, 0x00);
	//wrReg(0x14, 0x20);
	//wrReg(0x24, 0x75);
	//wrReg(0x25, 0x63);
	//wrReg(0x26, 0xA5);

	//AEC algorithm selection - AEC????    
	//wrReg(0xaa, 0x94);//??????AEC??Average-based AEC algorithm/??????AEC??Histogram-based AEC algorithm  

	//??????AGC/AEC???
	//wrReg(0x9f, 0x78);
	//wrReg(0xa0, 0x68);       
	//wrReg(0xa6, 0xdf);
	//wrReg(0xa7, 0xdf);
	//wrReg(0xa8, 0xf0);
	//wrReg(0xa9, 0x90);

	//Fix Gain Control - ??????    
	//wrReg(0x69, 0x5d);//Fix gain for Gr channel/for Gb channel/for R channel/for B channel

	//Color saturation ????? + 0
	wrReg(0x4f, 0x80);
	wrReg(0x50, 0x80);
	wrReg(0x51, 0x00);
	wrReg(0x52, 0x22);
	wrReg(0x53, 0x5e);
	wrReg(0x54, 0x80);
	wrReg(0x58, 0x9e);

	//Brightness - ?? + 0
	//wrReg(0x55, 0x00);

	//Contrast - ??? + 0
	//wrReg(0x56, 0x40);

	//Gamma Curve - ????
	//wrReg(0x7a, 0x20);
	//wrReg(0x7b, 0x1c);
	//wrReg(0x7c, 0x28);        
	//wrReg(0x7d, 0x3c);
	//wrReg(0x7e, 0x55);
	//wrReg(0x7f, 0x68);
	//wrReg(0x80, 0x76);
	//wrReg(0x81, 0x80);        
	//wrReg(0x82, 0x88);
	//wrReg(0x83, 0x8f);
	//wrReg(0x84, 0x96);
	//wrReg(0x85, 0xa3);
	//wrReg(0x86, 0xaf);        
	//wrReg(0x87, 0xc4);
	//wrReg(0x88, 0xd7);
	//wrReg(0x89, 0xe8);

	//Matrix Coefficient - ??????            
	//wrReg(0x4f, 0x80);
	//wrReg(0x50, 0x80);
	//wrReg(0x51, 0x00);
	//wrReg(0x52, 0x22);
	//wrReg(0x53, 0x5e);
	//wrReg(0x54, 0x80);

	//Lens Correction Option - ??????
	//wrReg(0x62, 0x00);       
	//wrReg(0x63, 0x00);
	//wrReg(0x64, 0x04);
	//wrReg(0x65, 0x20);        
	//wrReg(0x66, 0x05);
	//wrReg(0x94, 0x04);//effective only when LCC5[2] is high
	//wrReg(0x95, 0x08);//effective only when LCC5[2] is high


	//????????,?????,?????,?????????????????
	wrReg(0x17, 0x18);//??Horizontal Frame?????(????HREF[2:0])       
	wrReg(0x18, 0x06);//??Horizontal Frame?????(????HREF[5:3])
	wrReg(0x19, 0x02);//??Vertical Frame?????(????VREF[1:0])
	wrReg(0x1a, 0x7a);//??Vertical Frame?????(????VREF[3:2])
	wrReg(0x32, 0x24);//HREF
	wrReg(0x03, 0x0a);//VREF

	//????????,??????
	wrReg(0x15, 0x02);//??PCLK?HREF?VSYNC??

	//Automatic black Level Compensation - ???????
	wrReg(0xb0, 0x84);//??????????,????????,?????,?????,?????????????RSVD
	//wrReg(0xb1, 0x0c);
	//wrReg(0xb2, 0x0e);      
	//wrReg(0xb3, 0x82);
	//wrReg(0xb8, 0x0a);

	//SCALING_xx???
	wrReg(0x0c, 0x04);
	//wrReg(0x70, 0x00);
	//wrReg(0x71, 0x00);
	wrReg(0x72, 0x33);
	wrReg(0x73, 0xf3);
	wrReg(0x3e, 0x1b);

	//ADC
	//wrReg(0x37, 0x1d);//ADC??ADC Control
	//wrReg(0x38, 0x71);//ADC???????ADC and Analog Common Mode Control
	//wrReg(0x39, 0x2a);//ADC????ADC Offset Control

	//??????
	//wrReg(0x92, 0x00);//?????Dummy Line low 8 bits
	//wrReg(0xa2, 0x02);//??????
	//wrReg(0x0c, 0x0c);
	//wrReg(0x10, 0x00);
	//wrReg(0x0d, 0x01);
	//wrReg(0x0f, 0x4b);
	//wrReg(0x3c, 0x78);
	//wrReg(0x74, 0x19);

	//???????????????RSVD
	//wrReg(0x0e, 0x61);
	//wrReg(0x16, 0x02);
	//wrReg(0x21, 0x02);
	//wrReg(0x22, 0x91);
	//wrReg(0x29, 0x07);
	//wrReg(0x33, 0x0b);
	//wrReg(0x35, 0x0b);
	//wrReg(0x4d, 0x40);
	//wrReg(0x4e, 0x20);
	//wrReg(0x8d, 0x4f);
	//wrReg(0x8e, 0x00);
	//wrReg(0x8f, 0x00);
	//wrReg(0x90, 0x00);
	//wrReg(0x91, 0x00);
	//wrReg(0x96, 0x00);
	//wrReg(0x9a, 0x80);
}
