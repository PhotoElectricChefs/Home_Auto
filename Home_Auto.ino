/*****************DEFINE GLOBAL VARIABLES HERE*****************************/

//TODO :include global variables used in your respective functions so that other functions can also use them. Example RTC.date

#include <LiquidCrystal.h>
#define OK_Button 2
#define Next_Button 3
#define Prev_Button 4
#define Esc_Button 5

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


/**************************************************************************/

/*****************FUNCTION DEFINITIONS*************************************/

//TODO: your actual functions defined here. We need the following

//RTC_update(If there is any update of time to be done in case of battery failures)
//RTC_check (to check if the time has reached for an action, and return the relay updated positions if any changes)
//Relay_update(if above function returns a positive,the affect the relays as required)

	/*****************LCD_FUNCTIONS*******************************************/
int Keyboard_Poll()
{
  int val=-1;
  if(digitalRead(Esc_Button)==LOW)
      {
        delay(50);
        if(digitalRead(Esc_Button)==LOW)
          val=0;
      }
  else if(digitalRead(Next_Button)==LOW)
      {
        delay(50);
        if(digitalRead(Next_Button)==LOW)
          val=1;
      }
  else if(digitalRead(Prev_Button)==LOW)
      {
        delay(50);
        if(digitalRead(Prev_Button)==LOW)
          val=2;
      }
  else if(digitalRead(OK_Button)==LOW)
      {
        delay(50);
        if(digitalRead(OK_Button)==LOW)
          val=3;
      }
   return val;
}
void LCD_Init()
{
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("PhotoElectricChefs ");
  pinMode(2, INPUT);
  digitalWrite(2,HIGH);
  pinMode(3, INPUT);
  digitalWrite(3,HIGH);
  pinMode(4, INPUT);
  digitalWrite(4,HIGH);
  pinMode(5, INPUT);
  digitalWrite(5,HIGH);
}
void LCD_Menu(int choice)
{
  static int i;
  switch(choice)
  {
    case 1:lcd.setCursor(0,0);
           lcd.print(" switch1");
           lcd.setCursor(8,0);
           lcd.print(" switch2");
           lcd.setCursor(0,1);
           lcd.print(" switch3");
           lcd.setCursor(8,1);
           lcd.print(" switch4");
           lcd.setCursor(0,0);
           lcd.cursor();
           lcd.blink();
           delay(1000); 
           break;
    default:break;
  }
  while(1)
  {
    switch(Keyboard_Poll())
    {
      case 0:return;
      case 1:if(choice==1)
             {
               i=((i+1)%4);
               switch(i)
               {
                 case 0:lcd.setCursor(0,0);break;
                 case 1:lcd.setCursor(8,0);break;
                 case 2:lcd.setCursor(0,1);break;
                 case 3:lcd.setCursor(8,1);break;
               }
               delay(500);
             }
             break;
      case 2:if(choice==1)
             {
               i=((4-i)%4);
               switch(i)
               {
                 case 0:lcd.setCursor(0,0);break;
                 case 1:lcd.setCursor(8,0);break;
                 case 2:lcd.setCursor(0,1);break;
                 case 3:lcd.setCursor(8,1);break;
               }
               delay(500);
             }
             break;
      case 3:LCD_Menu(choice+1);
             break;
      default:break;
    }
  }
}  
void LCD_Poll()
{
      lcd.setCursor(5,1);
      lcd.print("Time");
      if(Keyboard_Poll()==3)
      {
          LCD_Menu(1);
      }
      
}     
		/**************************************************LCD_FUNCTIONS  END***********************/
//Button_Interuppt(What to do when a button is pressed for the LCD)

/*****************MASTER SETUP FUNCTION***********************************/

void setup()
{
  //TODO : only main setups here.do not include your function setups.If the functions need to be setup here itself then just call the respective funtion to keep it clean.
  LCD_Init();
}

/****************MASTER LOOP FUNTION***************************************/
 void loop()
{
  //TODO: Just call your respective funtions here and update the global variables as and when required. That way its independant of each other's code.
     LCD_Poll();
}



//ASSUME constant values if the code for that part isn't updated yet.
