#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>

using namespace std;
typedef enum PokemonType {
	NONE = -1, NORMAL = 0, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON, GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON
} PokemonType;


class Pokemon {
private:
	//variables
	string name, move;
	PokemonType attribute1, attribute2;
	int maxHealth, currentHealth, speed, defense, strength;

public:
	//default constructor
	Pokemon() {};

	//constructor
	Pokemon(string name, string move, int maxHealth, int  speed, int defense, int strength, PokemonType attribute1, PokemonType attribute2) 
	{ this->name = name; this->move = move; this->maxHealth = maxHealth; this->currentHealth = maxHealth; this->speed = speed; 
	this->defense = defense; this->strength = strength; this->attribute1 = attribute1; this->attribute2 = attribute2;
	}

	//we need to set the attributes using id

	//functions
	string getName();
	bool fainted();
	int getMaxHealth();
	int getRemainingHealth();
	void damageTaken(int amount);
	int getSpeed();
	int getStrength();
	int getDefense();
	string attack();
	PokemonType getAttribute(int id);

};

#endif POKEMON_H


