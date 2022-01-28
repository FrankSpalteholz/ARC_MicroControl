// #include <Arduino.h>
// #include <Wire.h>

// #define address 0x05

// const unsigned int dataCount = 4;
// int dataIn[4] = {0, 0, 0, 0};

// char startMarker = '<';
// char endMarker = '>';
// char seperator = ':';
// boolean newData = false;
// const byte numChars = 30;
// char receivedChars[30] ={};
// char tempChars[30];


// void reveiceData(int byteCount);
// void sendData();
// void parseData();
// void receiveMotorControlData(uint32_t interval, bool isLog);

// ///////////////////////////////////////////////////////////////////////////////////////


// void setup() {
  
//   Serial.begin(9600);
//   Wire.begin(address);
 
//   Wire.onReceive(reveiceData);
//   //Wire.onRequest(sendData);

//   Serial.println("Ready");
// }


// void loop() 
// {
//   uint32_t interval = 10;
//   receiveMotorControlData(interval, true);

// }

// ///////////////////////////////////////////////////////////////////////////////////////

// void receiveMotorControlData(uint32_t interval, bool isLog)
// {
//   if(newData)
//   {
//     parseData();  

//     if(isLog)
//     {
//       Serial.print("Data received: ");
//       for(int i = 0; i < dataCount; i++)
//       {
//         Serial.print(dataIn[i]);
//         Serial.print(":");
//       }

//       Serial.println();
//     }
//     newData = false;  
//   }
//   delay(interval);

// }


// void reveiceData(int byteCount) 
// {

//   static boolean recvInProgress = false;
//   static byte ndx = 0;
//   char rc;
//   int index = 0;

//   while (Wire.available()) 
//   {
//     rc = Wire.read();
//     //Serial.print(rc);
    
//     if (recvInProgress == true) 
//     {
//       if (rc != endMarker) 
//       {
//         receivedChars[ndx] = rc;
//         index++;
//         ndx++;
//         if (ndx >= numChars) 
//         {
//           ndx = numChars - 1;
//         }
//       }
//       else 
//       {
//         receivedChars[ndx] = '\0'; // terminate the string
//         recvInProgress = false;
//         ndx = 0;
//         newData = true;
//       }
//     }
//     else if (rc == startMarker) 
//     {
//       recvInProgress = true;
//     }
//   }
// }

// void parseData() 
// {                                       // split the data into its parts

//   strcpy(tempChars, receivedChars);

//   char * strtokIndx;                       // this is used by strtok() as an index
//   strtokIndx = strtok(tempChars, ":");     // get the first part - the string
//   dataIn[0] = atoi(strtokIndx);

//   for(int i = 1; i < dataCount; i++)
//   {
//     strtokIndx = strtok(NULL, ":");
//     dataIn[i] = atoi(strtokIndx);
//   }
// }

// // void sendData() {
// //   for(int i = 1; i < 32; i++)
// //       Wire.write(tmp_data[i]);
  
// // }