/*	PhotoElectricChefs	*/
/*    photoelectricchefs.org	*/

/************Public Includes************************/



/***************************************************/
/************Private Variables**********************/


/***************************************************/
/************Private Function Declarations**********/
void Node_Init();
void Read_EEPROM();

/***************************************************/
/***********Function Defintions*********************/
void Node_Init()
{
	Read_EEPROM(); //Read EEPROM to determine previous states and properties of the switches
}

void Read_EEPROM();
{
	//TODO:add code here to read previous state from eeprom
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
