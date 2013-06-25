/*	PhotoElectricChefs	*/
/*    photoelectricchefs.org	*/

/************Public Includes************************/
#include <EEPROM.h>

//Defining pins on Arduino through which switches are controlled

#define SWITCH1_PIN 8
#define SWITCH2_PIN 9
#define SWITCH3_PIN 10
#define SWITCH4_PIN 11

/* Defining starting addresses in EEPROM where each of the switches' state and/or other properties are stored.
   Assuming 20 bytes would suffice for each switch data. Can extend if needed.
   Here addresses 20-39 : SWITCH1, 40-59 : SWITCH2, 60-79 : SWITCH3, 80-99 : SWITCH4 	*/

#define SWITCH1_EEPROM_START_ADDR 20
#define SWITCH1_EEPROM_START_ADDR 40
#define SWITCH1_EEPROM_START_ADDR 60
#define SWITCH1_EEPROM_START_ADDR 80

/***************************************************/
/************Private Variables**********************/

//Every switch has a pin,state and EEPROM start address associated with it
struct switches
{
unsigned short int pin;
boolean state;
byte addr;
};
struct switches S1,S2,S3,S4;	

/***************************************************/
/************Private Function Declarations**********/
void Node_Init();
void Read_EEPROM();

/***************************************************/
/***********Function Defintions*********************/
void Node_Init()
{	S1.pin=SWITCH1_PIN;
	S1.addr=SWITCH1_EEPROM_START_ADDR;
	S2.pin=SWITCH2_PIN;
	S2.addr=SWITCH1_EEPROM_START_ADDR;
	S3.pin=SWITCH3_PIN;
	S3.addr=SWITCH1_EEPROM_START_ADDR;
	S4.pin=SWITCH4_PIN;
	S4.addr=SWITCH1_EEPROM_START_ADDR;

	pinMode(S1.pin, OUTPUT);
	pinMode(S2.pin, OUTPUT);
	pinMode(S3.pin, OUTPUT);
	pinMode(S4.pin, OUTPUT);
//Read EEPROM to determine previous states and properties of the switches
	Read_EEPROM(); 		   
//restore switches to previous state
	status_update(1,S1.state); 
	status_update(2,S2.state);
	status_update(3,S3.state);
	status_update(4,S4.state);
//ping to master to be added
}

void Read_EEPROM();
{
	//TODO:add code here to read previous state from eeprom
	S1.state = EEPROM.read(S1.addr);
	S2.state = EEPROM.read(S2.addr);
	S3.state = EEPROM.read(S3.addr);
	S4.state = EEPROM.read(S4.addr);
//	S4.id = EEPROM.read(S4.addr+1); //illustration to read more info abt a particular switch
//	To add if anything more is to be read. Likely one: Node ID.
}



void status_update(unsigned short int switch_number, boolean switch_state)
{
/*Usage Example: status_update(1, true) to turn ON switch S1*/
	
	switch(switch_number)
	{
		case 1 : digitalWrite(S1.pin, (switch_state==true)?HIGH:LOW);
			 S1.state=switch_state;
			 EEPROM.write(S1.addr, S1.state);
			 /*Illustration to write another info regarding S1, say ID into EEPROM:
			 EEPROM.write(S1.addr+1, S1.id); 
			 assuming id is an element of switches structure and is defined/passed*/
			 break;
		case 2 : digitalWrite(S2.pin, (switch_state==true)?HIGH:LOW);
			 S2.state=switch_state;
			 EEPROM.write(S2.addr, S2.state);
			 break;
		case 3 : digitalWrite(S3.pin, (switch_state==true)?HIGH:LOW);
			 S3.state=switch_state;
			 EEPROM.write(S3.addr, S3.state);
			 break;
		case 4 : digitalWrite(S4.pin, (switch_state==true)?HIGH:LOW);
			 S4.state=switch_state;
			 EEPROM.write(S4.addr, S4.state);
			 break;
	}
}

/***************************************************/


void setup() //Initialization
{
	Node_Init();	//Initialize node to previous state. 	
}

void loop()
{
		//Main Loop
}
