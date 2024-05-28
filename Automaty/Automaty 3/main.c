#include "led.h"
#include "keyboard.h"

void Delay(int miliseconds){
	
	int iLoopCounter;
	for(iLoopCounter = 1; iLoopCounter <= miliseconds * 2200; iLoopCounter++){}	
}
enum LedState{LED_LEFT, LED_RIGHT,};
enum LedState eLedState = LED_LEFT;
unsigned char ucStepCounter = 0;

int main(){

	LedInt();
	KeyboardInit();
	
	while(1){
		switch(eLedState){
			case LED_LEFT:
			if(ucStepCounter < 3){
				LedStepLeft();
				ucStepCounter++;
			}
			else{
			eLedState = LED_RIGHT;
			}
			break;
			case LED_RIGHT:
			if(ucStepCounter < 6){
				LedStepRight();
				ucStepCounter++;
			}
			else{
				ucStepCounter = 0;
				eLedState = LED_LEFT;
			}

		}
		Delay (500);
	}
}
