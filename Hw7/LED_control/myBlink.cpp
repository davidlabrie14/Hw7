//cpp to run my blink//
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "derek_LED.h"
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

 int main(int argc, char* argv[]){
   if(argc!=3){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   if(cmd=="on")LED(0).turnOn();
   else if(cmd=="off")LED(0).turnOff();
   else if(cmd=="flash")LED(0).flash("100"); //default is "50"
   else if(cmd=="status")LED(0).outputState();
   else if(cmd=="blink")LED(0).blink(atoi(argv[2])); 
   else{ cout << "Invalid command!" << endl;
   }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
