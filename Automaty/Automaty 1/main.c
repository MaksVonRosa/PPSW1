#include "led.h"
#include "keyboard.h"

void Delay(int miliseconds){
	
	int iLoopCounter;
	for(iLoopCounter = 1; iLoopCounter <= miliseconds * 2200; iLoopCounter++){}	
}
enum LedState{LED_LEFT, LED_RIGHT};
enum LedState eLedState = LED_LEFT;

int main(){

	LedInt();
	KeyboardInit();
	while(1){
		switch(eLedState){
			
			case LED_LEFT:
				LedStepLeft();
				eLedState = LED_RIGHT;
			break;
			
			case LED_RIGHT:
				LedStepRight();
				eLedState = LED_LEFT;
			break;
		}
		Delay (1000);
	}
}
