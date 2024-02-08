// lab8_starter.c
// David_Harris@hmc.edu and Josh Brake 11 October 2020
// Digital Level Starter Code

#include <stdint.h>
#include "EasyREDVIO.h"

/////////////////////////////////////////////////////////////////////
// SPI Functions
/////////////////////////////////////////////////////////////////////

void spiWrite(uint8_t address, uint8_t value) {
  uint8_t hi, lo;
  digitalWrite(2, 0); // pulse chip select
  hi = spiSendReceive(address);
  lo = spiSendReceive(value); 
  digitalWrite(2, 1); // release chip select
	// discard returned values on a write transaction
}

uint8_t spiRead(uint8_t address) {
  uint8_t hi, lo;
  digitalWrite(2, 0); // pulse chip select
  hi = spiSendReceive(address | 1 << 7); // set msb for reads
  lo = spiSendReceive(0x00);             // send dummy payload 
  digitalWrite(2, 1); // release chip select
  return lo;
}

/////////////////////////////////////////////////////////////////////
// Main Loop
/////////////////////////////////////////////////////////////////////

int main(void)
{		
	uint8_t debug;
	volatile int16_t x,y;

	//setup clocks and hardware
	spiInit(15, 0, 0); // Initialize SPI pins and clocks
	digitalWrite(2, 1); // Manually control LIS3DH Chip Select
	pinMode(2, OUTPUT); 
	
	
	// Check WHO_AM_I register. should return 0x33 = 51 decimal
	// Then do something with debug value to prevent compiler from
	// optimizing it away.
	debug = spiRead(0x0F);
	if (debug == 51) digitalWrite(2,1); 

	//Setup the LIS3DH for use
	spiWrite(0x20, 0x77); // highest conversion rate, all axis on
	spiWrite(0x23, 0x88); // block update, and high resolution
	

	//setup led
	pinMode(10, OUTPUT); 
	pinMode(11, OUTPUT); 
	pinMode(0, OUTPUT); 
	pinMode(1, OUTPUT); 
	pinMode(13, OUTPUT); 
	pinMode(21, OUTPUT); 
	pinMode(22, OUTPUT); 
	
	pinMode(9, OUTPUT); 
	//digitalWrite(1, 1);
	digitalWrite(9, 0);
	//resistor setup
	pinMode(17, OUTPUT); 
	pinMode(16, OUTPUT); 
	pinMode(20, OUTPUT); 
	pinMode(19, OUTPUT); 
	pinMode(18, OUTPUT); 
	pinMode(23, OUTPUT); 
	pinMode(12, OUTPUT); 
	//turn resistors to high except middle one
	digitalWrite(19, 0);
	digitalWrite(17, 1);
	digitalWrite(16, 1);
	digitalWrite(20, 1);
	digitalWrite(18, 1);
	digitalWrite(23, 1);
	digitalWrite(12, 1);





	while(1)
	{
		// Collect the X and Y values from the LIS3DH
		x = spiRead(0x28) | (spiRead(0x29) << 8);
		y = spiRead(0x2A) | (spiRead(0x2B) << 8);
		
		// Small delay to reduce flicker
		delay(100);
//row 4
		//if statements to turn on which led
		//d4
		if(x>700&&x<1200&&y>-600&&y<100){
		
			digitalWrite(19, 0);
			digitalWrite(10, 1);
			
		}
		//c4
		if(x<700&&x>200&&y>-600&&y<100){
			digitalWrite(23, 0);
			digitalWrite(10, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>-600&&y<100){
			digitalWrite(18, 0);
			digitalWrite(10, 1);
			
		}
		//a4
		if(x<-200&&y>-600&&y<100){
			digitalWrite(16, 0);
			digitalWrite(10, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>-600&&y<100){
			digitalWrite(12, 0);
			digitalWrite(10, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>-600&&y<100){
			digitalWrite(20, 0);
			digitalWrite(10, 1);
			
		}
		//g4
		if(x>2000&&y>-600&&y<100){
			digitalWrite(17, 0);
			digitalWrite(10, 1);
			
		}

//row 5
		//d5
		if(x>700&&x<1200&&y>-1500&&y<-600){
		
			digitalWrite(19, 0);
			digitalWrite(1, 1);
			
		}
		//c5
		if(x<700&&x>200&&y>-1500&&y<-600){
			digitalWrite(23, 0);
			digitalWrite(1, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>-1500&&y<-600){
			digitalWrite(18, 0);
			digitalWrite(1, 1);
			
		}
		//a4
		if(x<-200&&y>-1500&&y<-600){
			digitalWrite(16, 0);
			digitalWrite(1, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>-1500&&y<-600){
			digitalWrite(12, 0);
			digitalWrite(1, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>-1500&&y<-600){
			digitalWrite(20, 0);
			digitalWrite(1, 1);
			
		}
		//g4
		if(x>2000&&y>-1500&&y<-600){
			digitalWrite(17, 0);
			digitalWrite(1, 1);
			
		}

//row 6
		//d5
		if(x>700&&x<1200&&y>-2300&&y<-1500){
		
			digitalWrite(19, 0);
			digitalWrite(11, 1);
			
		}
		//c5
		if(x<700&&x>200&&y>-2300&&y<-1500){
			digitalWrite(23, 0);
			digitalWrite(11, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>-2300&&y<-1500){
			digitalWrite(18, 0);
			digitalWrite(11, 1);
			
		}
		//a4
		if(x<-200&&y>-2300&&y<-1500){
			digitalWrite(16, 0);
			digitalWrite(11, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>-2300&&y<-1500){
			digitalWrite(12, 0);
			digitalWrite(11, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>-2300&&y<-1500){
			digitalWrite(20, 0);
			digitalWrite(11, 1);
			
		}
		//g4
		if(x>2000&&y>-2300&&y<-1500){
			digitalWrite(17, 0);
			digitalWrite(11, 1);
			
		}
//row 7
		//d5
		if(x>700&&x<1200&&y<-2300){
		
			digitalWrite(19, 0);
			digitalWrite(0, 1);
			
		}
		//c5
		if(x<700&&x>200&&y<-2300){
			digitalWrite(23, 0);
			digitalWrite(0, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y<-2300){
			digitalWrite(18, 0);
			digitalWrite(0, 1);
			
		}
		//a4
		if(x<-200&&y<-2300){
			digitalWrite(16, 0);
			digitalWrite(0, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y<-2300){
			digitalWrite(12, 0);
			digitalWrite(0, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y<-2300){
			digitalWrite(20, 0);
			digitalWrite(0, 1);
			
		}
		//g4
		if(x>2000&&y<-2300){
			digitalWrite(17, 0);
			digitalWrite(0, 1);
			
		}
//row 3
		//if statements to turn on which led
		//d4
		if(x>700&&x<1200&&y>100&&y<700){
		
			digitalWrite(19, 0);
			digitalWrite(22, 1);
			
		}
		//c4
		if(x<700&&x>200&&y>100&&y<700){
			digitalWrite(23, 0);
			digitalWrite(22, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>100&&y<700){
			digitalWrite(18, 0);
			digitalWrite(22, 1);
			
		}
		//a4
		if(x<-200&&y>100&&y<700){
			digitalWrite(16, 0);
			digitalWrite(22, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>100&&y<700){
			digitalWrite(12, 0);
			digitalWrite(22, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>100&&y<700){
			digitalWrite(20, 0);
			digitalWrite(22, 1);
			
		}
		//g4
		if(x>2000&&y>100&&y<700){
			digitalWrite(17, 0);
			digitalWrite(22, 1);
			
		}	
//row 2
		//if statements to turn on which led
		//d4
		if(x>700&&x<1200&&y>700&&y<1500){
		
			digitalWrite(19, 0);
			digitalWrite(13, 1);
			
		}
		//c4
		if(x<700&&x>200&&y>700&&y<1500){
			digitalWrite(23, 0);
			digitalWrite(13, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>700&&y<1500){
			digitalWrite(18, 0);
			digitalWrite(13, 1);
			
		}
		//a4
		if(x<-200&&y>700&&y<1500){
			digitalWrite(16, 0);
			digitalWrite(13, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>700&&y<1500){
			digitalWrite(12, 0);
			digitalWrite(13, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>700&&y<1500){
			digitalWrite(20, 0);
			digitalWrite(13, 1);
			
		}
		//g4
		if(x>2000&&y>700&&y<1500){
			digitalWrite(17, 0);
			digitalWrite(13, 1);
			
		}	
//row 1
		//d5
		if(x>700&&x<1200&&y>1500){
		
			digitalWrite(19, 0);
			digitalWrite(21, 1);
			
		}
		//c5
		if(x<700&&x>200&&y>1500){
			digitalWrite(23, 0);
			digitalWrite(21, 1);
			
		}
		//b4
		if(x<200&&x>-200&&y>1500){
			digitalWrite(18, 0);
			digitalWrite(21, 1);
			
		}
		//a4
		if(x<-200&&y>1500){
			digitalWrite(16, 0);
			digitalWrite(21, 1);
			
		}
		//e4
		if(x>1200&&x<1500&&y>1500){
			digitalWrite(12, 0);
			digitalWrite(21, 1);
			
		}
		//f4
		if(x>1500&&x<2000&&y>1500){
			digitalWrite(20, 0);
			digitalWrite(21, 1);
			
		}
		//g4
		if(x>2000&&y>1500){
			digitalWrite(17, 0);
			digitalWrite(21, 1);
			
		}

		delay(100);
		//power off
		digitalWrite(10, 0);
		digitalWrite(1, 0);
		digitalWrite(11, 0);
		digitalWrite(0, 0);
		digitalWrite(22, 0);
		digitalWrite(13, 0);
		digitalWrite(21, 0);

		//resistors off
		digitalWrite(19, 1);
		digitalWrite(12, 1);
		digitalWrite(23, 1);
		digitalWrite(16, 1);
		digitalWrite(18, 1);
		digitalWrite(20, 1);
		digitalWrite(17, 1);
		


		

	}	
}
