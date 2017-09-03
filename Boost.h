#ifndef BOOST_H
#define BOOST_H

typedef enum BoostType { Speed, Attack, Defense }BoostType;

class Boost {
public:
	//constructor
	Boost() {};
	Boost(string name, BoostType type, int slotConsumption) { this->name = name; this->type = type; this-> slotConsumption = slotConsumption; }

	//variables
	string name;
	BoostType type;
	int slotConsumption;
	Boost *nextitem;

	//functions
	virtual int getBoostAmt(int maxHP, int speed, int attack, int defense);

};


class DefenseBoost : public Boost {

public:
	DefenseBoost() {}
	DefenseBoost(string name, int slotConsumption) :Boost(name, Defense, slotConsumption) {};

	int getBoostAmt(int maxHP, int speed, int attack, int defense);
};

class StrengthBoost : public Boost {

public:
	//constructor
	StrengthBoost(string name, int slotConsumption) :Boost(name, Attack, slotConsumption) {};

	int getBoostAmt(int maxHP, int speed, int attack, int defense);
};

class SpeedBoost : public Boost {

public:
	//constructor
	SpeedBoost(string name, int slotConsumption) :Boost(name, Speed, slotConsumption) {};

	int getBoostAmt(int maxHP, int speed, int attack, int defense);
};
#endif


