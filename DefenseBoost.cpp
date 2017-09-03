#include "Boost.h"
#include "Pokemon.h"
#include <string.h>
#include <iostream>

using namespace std;

class DefenseBoost : public Boost {

public:
	DefenseBoost() {}
	DefenseBoost(string name, BoostType type, int slotConsumption) {};

	int getBoostAmt(int maxHP, int speed, int attack, int defense)
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
};

