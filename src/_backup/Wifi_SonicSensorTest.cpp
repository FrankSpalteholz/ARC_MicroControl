// /*
// * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
// *
// * by Dejan Nedelkovski,
// * www.HowToMechatronics.com
// *
// */
// // defines pins numbers

// #include <Arduino.h>

// const int trigPin = 1;
// const int echoPin = 0;
// float maxDistance = 200;
// // defines variables
// long duration;
// int distance;
// float soundVelocity = 340;

// float rangingTimeOut = 2 * maxDistance / 100 / soundVelocity * 1000000;

// float getDistance();

// void setup() 
// {
//     pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
//     pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//     Serial.begin(9600); // Starts the serial communication
// }

// void loop() {
   

//     distance= getDistance();
//     // Prints the distance on the Serial Monitor
//     Serial.print("Distance: ");
//     Serial.println(distance);

//     delay(50);
// }


// float getDistance() {

//   unsigned long pingTime;
//   float distance;


//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   pingTime = pulseIn(echoPin, HIGH, rangingTimeOut);

//   if (pingTime != 0) {
//     distance = pingTime * soundVelocity / 2 / 10000;
//     return distance;
//   }
//   else
//     return maxDistance;
// }
