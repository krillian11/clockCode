/*
 * Calculator.cpp
 *
 *  Date: 11/13/2020
 *  Author: Kainan Woodard
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <winuser.h>
using namespace std;

void printTime(char MY_TIME[],char THIS_TIME[]){
	cout << endl;
	printf("%s\n", MY_TIME );
	printf("%s\n", THIS_TIME );
	fflush(stdout); //forces the output to the console otherwise it buffers because of sleep

}

int main(){
	string input = "";
	time_t t ;
	struct tm *tmp ;
	char MY_TIME[50];
	char THIS_TIME[50];
	bool cont = true;

	time( &t );
	tmp = localtime( &t );

	cout << "Hold shift to bring up the menu" << endl;
	do{
		strftime(MY_TIME, sizeof(MY_TIME), "%I:%M:%S %p", tmp); //12 hour format
		strftime(THIS_TIME, sizeof(THIS_TIME), "%H:%M:%S", tmp);//24 hour format
		printTime(MY_TIME,THIS_TIME);
		if(GetKeyState(VK_SHIFT) & 0x8000){
			cout << "Do you want to add an hour, minute, or second? Or you can enter \'exit\' to quit." << endl;
			cin >> input;
			do{
				if(input == "minute"){
					cont = false;
					tmp->tm_min += 1;
					strftime(MY_TIME, sizeof(MY_TIME), "%I:%M:%S %p", tmp);
					strftime(THIS_TIME, sizeof(THIS_TIME), "%H:%M:%S", tmp);
					printTime(MY_TIME,THIS_TIME);
				}else if(input == "second"){
					cont = false;
					tmp->tm_sec += 1;
					strftime(MY_TIME, sizeof(MY_TIME), "%I:%M:%S %p", tmp);
					strftime(THIS_TIME, sizeof(THIS_TIME), "%H:%M:%S", tmp);
					printTime(MY_TIME,THIS_TIME);
				}else if(input == "hour"){
					cont = false;
					tmp->tm_hour += 1;
					strftime(MY_TIME, sizeof(MY_TIME), "%I:%M:%S %p", tmp);
					strftime(THIS_TIME, sizeof(THIS_TIME), "%H:%M:%S", tmp);
					printTime(MY_TIME,THIS_TIME);
				}else if(input == "exit"){
					break;
				}else{
					cont = true;
					cout << "Enter a valid option." << endl;
					cin >> input;
				}
			}while(cont);
		}
		tmp->tm_sec += 1; //increments time by 1 second; every second
		if(tmp->tm_sec == 60){ //checks if one minute has passed
			tmp->tm_min += 1;
			tmp->tm_sec = 0;
		}if(tmp->tm_min == 60){ //checks if one hour has passed
			tmp->tm_hour += 1;
			tmp->tm_min = 0;
			}
		sleep(1); // 1 second sleep
		system("CLS"); // should clear the console; but in eclipse it doesn't work
			}while(input !="exit");
			cout << "Program Closed";

	return 0;
}
