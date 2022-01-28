// // NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// // Released under the GPLv3 license to match the rest of the
// // Adafruit NeoPixel library

// #include <Arduino.h>
// #include <Adafruit_NeoPixel.h>

// #include "Neotimer.h"


// #define PIN       10 // On Trinket or Gemma, suggest changing this to 1
// #define NUMPIXELS 16 // Popular NeoPixel ring size

// Neotimer timer1 = Neotimer(); 
// Neotimer timer2 = Neotimer(); 


// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// int colorArray[16][3];
// int r = 16;
// int g = 16;
// int b = 16;

// int i = 0;
// int j = 10;

// #define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

// void setup() {
 

//   pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

//   timer1.set(100);
//   timer2.start();

//   for(int i = 0; i < NUMPIXELS; i++)
//   {
//     colorArray[i][0] = 0;
//     colorArray[i][1] = 0;
//     colorArray[i][2] = 0;

//   }
// }

// void loop() {

   
//   if(timer1.repeat()){
  
   
//    for(int j = 0; j < NUMPIXELS; j++)
//    {
     
//       for(int k = 0; k < NUMPIXELS; k++)
//       {
//         colorArray[k][0] = map(i,0,15,20,0);
//         colorArray[k][1] = map(i,0,15,20,0);
//         colorArray[k][2] = map(i,0,15,20,0);
//       }
      
//       pixels.setPixelColor(j, pixels.Color(colorArray[j][0],10,10));
//       //pixels.setPixelColor(i, pixels.Color(0,0,0));
    
//    }
    
//     pixels.show();   // Send the updated pixel colors to the hardware.
  

//     i++;

//    }
   
    
//   if(i == NUMPIXELS){
//     i=0;
//     timer1.reset();
//     pixels.clear(); // Set all pixel colors to 'off'
//   }
//   else
//   {
    
//   }
    
  
// }
