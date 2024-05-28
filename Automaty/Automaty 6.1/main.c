#include "led.h"
#include "keyboard.h"

void Delay(int miliseconds){
	
	int iLoopCounter;
	for(iLoopCounter = 1; iLoopCounter <= miliseconds * 2200; iLoopCounter++){}	
}
enum LedState{LED_LEFT,LED_RIGHT,LED_STOP,LED_STAN1,LED_STAN2, LED_STAN3};
enum LedState eLedState = LED_RIGHT;

int main(){

	unsigned int uiStanCounter;
	LedInt();
	KeyboardInit();
	uiStanCounter = 0;
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
			else if(eKeyboardRead() == BUTTON_3){
				eLedState = LED_STAN1;
			}
			else{
				LedStepLeft();
				eLedState = LED_LEFT;
			}	
			break;
			
			case LED_STAN1:
				LedOn(4);
				uiStanCounter++;
				if(uiStanCounter == 20){
					uiStanCounter = 0;
					eLedState = LED_STAN2;
				}
				break;
			case LED_STAN2:
				LedOn(1);
				if(eKeyboardRead() == BUTTON_2){
					eLedState = LED_STAN3;
				}
			break;
			case LED_STAN3:
				uiStanCounter++;
				if(uiStanCounter == 30){
					uiStanCounter = 0;
					eLedState = LED_RIGHT;
				}
			break;
				
			case LED_STOP:
				if(eKeyboardRead() == BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else if(eKeyboardRead() == BUTTON_0){
					eLedState = LED_LEFT;
				}
			break;
			}
		Delay (100);
	}
}
