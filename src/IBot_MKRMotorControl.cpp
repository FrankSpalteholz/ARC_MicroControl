#include <Arduino.h>
#include <MKRMotorCarrier.h>

#define INTERRUPT_PIN 6

//Variable to store the battery voltage
static int batteryVoltage;

//Variable to change the motor speed and direction
static int duty = 0;

// M1 = right Motor M2 = left Motor


const unsigned int dataCount = 4;

// 0;1 = Direction M1;M2 
// 2;3 = Speed M1;M2 

int dataIn[4] = {0, 0, 0, 0}; 

char startMarker = '<';
char endMarker = '>';
char seperator = ':';
boolean newData = false;
const byte numChars = 30;
char receivedChars[30] ={};
char tempChars[30];

void reveiceData();
void sendData();
void parseData();
void receiveMotorControlData(uint32_t interval, bool isLog);

////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{

  
  //Serial port initialization
  Serial.begin(9600);
  Serial1.begin(9600);
  
  // while (!Serial);

  //Establishing the communication with the motor shield
  if (controller.begin()) 
    {
      Serial.print("MKR Motor Shield connected, firmware version ");
      Serial.println(controller.getFWVersion());
    } 
  else 
    {
      Serial.println("Couldn't connect! Is the red led blinking? You may need to update the firmware with FWUpdater sketch");
      while (1);
    }

  // Reboot the motor controller; brings every value back to default
  Serial.println("reboot");
  //controller.reboot();
  delay(500);
  
  //Take the battery status
  float batteryVoltage = (float)battery.getConverted();
  Serial.print("Battery voltage: ");
  Serial.print(batteryVoltage);
  Serial.print("V, Raw ");
  Serial.println(battery.getRaw());

  //M1.setDuty(0);
  //M2.setDuty(0);

}


void loop() {

  //Take the battery status
  float batteryVoltage = (float)battery.getConverted();
  
  uint32_t interval = 10;
  receiveMotorControlData(interval, true);

  //Reset to the default values if the battery level is lower than 11V
  if (batteryVoltage < 11) 
  {
    Serial.println(" ");
    Serial.println("WARNING: LOW BATTERY");
    Serial.println("ALL SYSTEMS DOWN");
    
    M1.setDuty(0);
    M2.setDuty(0);

    while (batteryVoltage < 11) 
    {
      batteryVoltage = (float)battery.getConverted();
    }
  }
  else
  {
   
      if(dataIn[0] == 1 && dataIn[1] == 1 || dataIn[0] == -1 && dataIn[1] == -1)
      {
    
        M1.setDuty(int(map(dataIn[2],0,200,0,80*dataIn[0]*-1)));  // M1 = left motor
        M2.setDuty(int(map(dataIn[3],0,220,0,80*dataIn[1])));     // M2 = right motor
      
      }else
      {
        
        M1.setDuty(int(map(dataIn[2],0,200,0,60*dataIn[0])));
        M2.setDuty(int(map(dataIn[3],0,230,0,60*dataIn[1]*-1)));

      }
    
    
    //Keep active the communication MKR1000 & MKRMotorCarrier
    //Ping the samd11
    controller.ping();
    //wait
    //delay(10);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void receiveMotorControlData(uint32_t interval, bool isLog)
{

  reveiceData();

  if(newData)
  {
    parseData();  

    if(isLog)
    {
      Serial.print("Data received: ");
      for(int i = 0; i < dataCount; i++)
      {
        Serial.print(dataIn[i]);
        Serial.print(":");
      }

      Serial.println();
    }
    newData = false;  
  }
  delay(interval);

}


void reveiceData() 
{

  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;
  int index = 0;

  while (Serial1.available() > 0 && newData == false) 
  {
    rc = Serial1.read();
    //Serial.print(rc);
    
    if (recvInProgress == true) 
    {
      if (rc != endMarker) 
      {
        receivedChars[ndx] = rc;
        index++;
        ndx++;
        if (ndx >= numChars) 
        {
          ndx = numChars - 1;
        }
      }
      else 
      {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) 
    {
      recvInProgress = true;
    }
  }
}

void parseData() 
{                                       // split the data into its parts

  strcpy(tempChars, receivedChars);

  char * strtokIndx;                       // this is used by strtok() as an index
  strtokIndx = strtok(tempChars, ":");     // get the first part - the string
  dataIn[0] = atoi(strtokIndx);

  for(int i = 1; i < dataCount; i++)
  {
    strtokIndx = strtok(NULL, ":");
    dataIn[i] = atoi(strtokIndx);
  }
}

// void sendData() {
//   for(int i = 1; i < 32; i++)
//       Wire.write(tmp_data[i]);
  
// }
