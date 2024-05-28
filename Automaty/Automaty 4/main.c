#include "led.h"
#include "keyboard.h"

void Delay(int miliseconds){
	
	int iLoopCounter;
	for(iLoopCounter = 1; iLoopCounter <= miliseconds * 2200; iLoopCounter++){}	
}
enum LedState{LED_RIGHT,LED_STOP};
enum LedState eLedState = LED_STOP;
unsigned char ucStepCounter = 0;

int main(){

	LedInt();
	KeyboardInit();
	
	while(1){
		switch(eLedState){
			case LED_RIGHT:
				ucStepCounter++;
			if(ucStepCounter > 3){
				ucStepCounter = 0;
				eLedState = LED_STOP;
			}
			else{
				LedStepRight();
				eLedState = LED_RIGHT;
			}
			break;
			
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_0){
					ucStepCounter = 0;
					eLedState = LED_RIGHT;
				}
			}
		Delay (500);
	}
}
