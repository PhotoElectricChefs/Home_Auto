/*	PhotoElectricChefs	*/
/*    photoelectricchefs.org	*/

/************Public Includes************************/
#include <EEPROM.h>
//Define number of switches controlled by the node
#define N 4
//Defining pins on Arduino through which switches are controlled

/*
#define SWITCH1_PIN 8
#define SWITCH2_PIN 9
#define SWITCH3_PIN 10
#define SWITCH4_PIN 11
*/

const unsigned short int switch_pins[N]={8,9,10,11};	//for 4 switch node

/* Defining starting addresses in EEPROM where each of the switches' state and/or other properties are stored.
   Assuming 20 bytes would suffice for each switch data. Can extend if needed.
   Here addresses 20-39 : SWITCH1, 40-59 : SWITCH2, 60-79 : SWITCH3, 80-99 : SWITCH4 	*/

/*
#define SWITCH1_EEPROM_START_ADDR 20
#define SWITCH2_EEPROM_START_ADDR 40
#define SWITCH3_EEPROM_START_ADDR 60
#define SWITCH4_EEPROM_START_ADDR 80
*/

const unsigned short int switch_addr[N]={20,40,60,80};	//for 4 switch node 

/***************************************************/
/************Private Variables**********************/

unsigned short int i;					//index variable

//Every switch has a pin,state and EEPROM start address associated with it
struct switches
{
unsigned short int pin;
boolean state;						//true=ON, false=OFF
byte addr;
};
struct switches S[N];					// switches: S[0],S[1],S[2],...S[N-1]

/***************************************************/
/************Private Function Declarations**********/
void Node_Init();
void Read_EEPROM();

/***************************************************/
/***********Function Defintions*********************/
void Node_Init()
{	for(i=0;i<N;i++)
	S[i].pin=switch_pins[i];		//
	
	for(i=0;i<N;i++)
	S[i].addr=switch_addr[i];

	for(i=0;i<N;i++)
	pinMode(S[i].pin, OUTPUT);

//Read EEPROM to determine previous states and properties of the switches
	Read_EEPROM(); 		   

//restore switches to previous state
	for(i=0;i<N;i++)
	status_update(i,S[i].state); 
	//ping to master to be added
}

void Read_EEPROM()
{
	//TODO:add code here to read previous state from eeprom
	for(i=0;i<N;i++)	
	S[i].state = EEPROM.read(S[i].addr);
//	S[i].id = EEPROM.read(S[i].addr+1); //illustration to read more info abt a particular switch
//	To add if anything more is to be read. Likely one: Node ID.
}



void status_update(unsigned short int switch_number, boolean switch_state)
{
/*Usage Example: status_update(0, true) to turn ON switch S0*/
	
		 digitalWrite(S[switch_number].pin, (switch_state==true)?HIGH:LOW);	//send control signal to switch ON/OFF a switch
		 S[switch_number].state=switch_state;					//update state in switch's element in structure
		 EEPROM.write(S[switch_number].addr, S[switch_number].state);		//update state in EEPROM
		 /*Illustration to write another info regarding S1, say ID into EEPROM:
		 EEPROM.write(S[switch_number].addr+1, S[switch_number].id); 
		 assuming id is an element of switches structure and is defined/passed*/
		
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
