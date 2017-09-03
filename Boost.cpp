#include "Pokemon.h"
#include <string.h>
#include <iostream>
#include "Boost.h"
using namespace std;

int DefenseBoost :: getBoostAmt(int maxHP, int speed, int attack, int defense)
{
	if (type == 2)
	{
		if (slotConsumption == 2)
			return 1;
		if (slotConsumption == 3)
			return 2;
		if (slotConsumption == 7)
			return 7;
	}
	else
		return 0;
}

int StrengthBoost :: getBoostAmt(int maxHP, int speed, int attack, int defense) {
	//this should probably go in a try-catch block
	if (slotConsumption == 2) return 1;

	else if (slotConsumption == 3) return 2;

	else if (slotConsumption == 6)
	{
		//need to access a Pokemon object
		if (defense < 50) return 5;
		else return 0;
	}
	else cout << "The current pokemon has an unrecognized slot consumption. " << endl; return 0;
}

int SpeedBoost :: getBoostAmt(int maxHP, int speed, int attack, int defense) {
	//this should probably go in a try-catch block
	if (slotConsumption == 2) return 2;

	else if (slotConsumption == 3) return 4;

	else if (slotConsumption == 6)
	{
		//need to access a Pokemon object
		if (maxHP<200) return 16;
		else return 0;
	}
	else cout << "The current pokemon has an unrecognized slot consumption. " << endl; return 0;
}