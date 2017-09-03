#include "Boost.h"
#include "Pokemon.h"
#include <string.h>
#include <iostream>

using namespace std;

class SpeedBoost : public Boost {

	public:
	//constructor
	SpeedBoost(string name, BoostType type, int slotConsumption):Boost(name,type,slotConsumption) {};

	int getBoostAmt(int maxHP, int speed, int attack, int defense) {
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
};