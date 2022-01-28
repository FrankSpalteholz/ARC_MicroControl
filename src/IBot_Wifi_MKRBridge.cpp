// #include <Arduino.h>
// #include <Wire.h>
// #include "wiring_private.h"

// #include "CCom.h"

// CCom cCom = CCom();

// int radioDataIn[RADIO_DATA_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
// int motorDataOut[5] = {0, 0, 0, 0, 0};

// Uart Serial_2 (&sercom3, 1, 0, SERCOM_RX_PAD_1, UART_TX_PAD_0); // Create the new UART instance assigning it to pin 1 and 0


// void prepareMotorData(int dataIn[], int dataOut[], int dataOutCount);
// void SERCOM3_Handler();

// void setup() {
  
//   Serial.begin(9600);
//   Serial1.begin(9600);
//   Serial_2.begin(9600);
//   //while (!Serial);

//   pinPeripheral(1, PIO_SERCOM); //Assign RX function to pin 1
//   pinPeripheral(0, PIO_SERCOM); //Assign TX function to pin 0

//   Wire.begin(I2C_ADDRESS);
//   Wire.onReceive([] (int howMany) {cCom.reveiceDataI2C(howMany);});
//   Wire.onRequest([] () {cCom.sendDataI2C();});

//   Serial.println("================================================================");
//   Serial.println("[MKR Bridge Status] ... Ready");
// }


// void loop() 
// {
 
//   if(cCom.getIsNewData())
//   {   
//     cCom.parseData(RADIO_DATA_COUNT, radioDataIn);

//     cCom.setSendData(SEND_MOTOR_DATA_COUNT, motorDataOut);

//     prepareMotorData(radioDataIn, motorDataOut, SEND_MOTOR_DATA_COUNT);

//     cCom.sendDataUART(Serial1, SEND_MOTOR_DATA_COUNT, motorDataOut);
  
//     cCom.sendDataUART(Serial_2, SEND_MOTOR_DATA_COUNT, motorDataOut);

//     cCom.logData("[Data received] ", RADIO_DATA_COUNT, radioDataIn);
//     cCom.logData("[Data send] ", SEND_MOTOR_DATA_COUNT, motorDataOut);

//     delay((long)SEND_DELAY);
//   }

  
// }

// void prepareMotorData(int dataIn[], int dataOut[], int dataOutCount)
// {
//   for (int i = 0; i < dataOutCount; i++)
//       dataOut[i] = dataIn[i];
// }

// void SERCOM3_Handler()
// {

//   Serial_2.IrqHandler();
// }


