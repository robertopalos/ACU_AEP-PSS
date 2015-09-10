#include "typedefs.h"

#define Active 1
#define Inactive 1
#define Open 0
#define TRUE 1
typedef enum{
	Fastened = 0,
	Unfastened
}SeatBeltStatus;

typedef enum{
	Euro_1 = 0,
	Euro_2,
	Euro_3
}UnfastenedStatus;

UnfastenedStatus state;
SeatBeltStatus bucked;
T_UBYTE TelltaleTimerFlag = 0;
T_UBYTE TelltaleTimer = 0;
T_UBYTE ChimeTimerFlag = 0;
T_UBYTE PowerUpTimer = 0;
T_UBYTE Cluster_Delay_Expired = 0;
T_UBYTE Time_4s = 4;
T_UBYTE Time_100s = 100;
T_UBYTE PreviousState = 100;
T_UBYTE DriverDoor = 0;
T_UBYTE VehicleSpeed = 20;
T_UBYTE EngineRunActve = 0;
T_UBYTE Distance = 0;


void TelltaleModingEuroReminder(void){
	switch(bucked){
		case Fastened:
			chime_off_msg();
			telltale_off_msg();
			TelltaleTimerFlag = 0;
			ChimeTimerFlag = 0;
			break;
		case Unfastened:
			switch(state){
				case Euro_1:
					chime_off_msg();
					if(PowerUpTimer == Cluster_Delay_Expired || TelltaleTimer == Time_4s){
						telltale_continuous_msg();
					}
					else{
						telltale_off_msg();
						TelltaleTimerFlag = Active;
					}
					break;
				case Euro_2:
					chime_off_msg();
					telltale_flashing_msg();
					if(TelltaleTimer == Time_100s){
						telltale_continuous_msg();
					}
					break;
				case Euro_3:
					if(ChimeTimerFlag == Inactive){
						chime_type2_on();
						ChimeTimerFlag = Active;
					}
					else{
						if(ChimeTimerFlag == Time_100s){
							chime_off_msg();
						}
					}
					if(TelltaleTimerFlag == Inactive){
						telltale_flashing_msg();
						TelltaleTimerFlag = 1;
					}
					else{
						if(TelltaleTimer == Time_100s){
							telltale_continuous_msg();
						}
					}
					break;
			}
			break;
	}
}

void EuroUnfastenedState(void){
	if(PreviousState == Euro_1 && EngineRunActve == TRUE){
		PreviousState = state;
		state = Euro_2;
	}
	else if(PreviousState == Euro_2 && (VehicleSpeed > 22 || Distance > 250)){
		PreviousState = state;
		state = Euro_3;
	}
	else if(PreviousState == Euro_3 && DriverDoor == Open && VehicleSpeed < 22){
		PreviousState = state;
		state = Euro_1;
	}
	else if(PreviousState == Euro_1 && (VehicleSpeed > 22 || Distance > 250)){
		PreviousState = state;
		state = Euro_3;
	}
	else if(PreviousState == Euro_2 && DriverDoor == Open && VehicleSpeed < 22){
		PreviousState = state;
		state = Euro_1;
	}
	else{
		PreviousState = state;
	}
}