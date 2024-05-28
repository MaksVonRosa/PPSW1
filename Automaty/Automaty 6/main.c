#include "led.h"
#include "keyboard.h"

void Delay(int miliseconds){
	
	int iLoopCounter;
	for(iLoopCounter = 1; iLoopCounter <= miliseconds * 2200; iLoopCounter++){}	
}
enum LedState{LED_LEFT,LED_RIGHT,LED_STOP};
enum LedState eLedState = LED_RIGHT;

int main(){

	LedInt();
	KeyboardInit();
	
	while(1){
		switch(eLedState){
			case LED_RIGHT:
			if(eKeyboardRead() == BUTTON_1){
				eLedState = LED_STOP;
			}
			else{
				LedStepRight();
				eLedState = LED_RIGHT;
			}
			break;
			
			case LED_LEFT:
			if(eKeyboardRead() == BUTTON_1){
				eLedState = LED_STOP;
			}
			else{
				LedStepLeft();
				eLedState = LED_LEFT;
			}			
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else if(eKeyboardRead() == BUTTON_0){
					eLedState = LED_LEFT;
				}
			}
		Delay (100);
	}
}
