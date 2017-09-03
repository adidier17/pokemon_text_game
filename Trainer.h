#ifndef TRAINER_H
#define TRAINER_H

#include "Pokeball.h"
#include "Boost.h"
#include "Pokemon.h"
#include <string>
#include <iostream>

using namespace std; 

class Trainer {
protected:
	Pokeball *Collection;
	Boost *BoosterTypes;

public:
	//constructor
	Trainer() {}
	Trainer(string name, string residency) {}

	//variables
	string name, residency;

	//functions
	virtual void capturePokemon(string filepath);
	virtual void setupBooster();
	Boost* getBoosterSetting();
	virtual Pokemon* getNxtPokemon(int, int, int, PokemonType, PokemonType);
	virtual Pokemon* selectFirstPokemon();

	//destructor
	//This doesn't do what I want yet. This should call the Pokeball class destructor so that the each pokemon is deleted
	//then we want to delete all the pokeballs, then the boosters
	virtual ~Trainer() { }
	
};
	
class Trainer2 : public Trainer {
	private:
		int ID[2];
		PokemonType settype(string attribute);
		void insert(Pokeball *pb);
		void insert_helper(Pokeball *type, Pokeball *pb);
		Pokeball *type1[15]; //array of pointers to order pokemon by attribute. 
							//Each element number corresponds to a Pokemon type by enum. 
							//eg type[0] is the head for a list of all NORMAL pokemon
	public:
		//constructor 
		Trainer2(string name, string residency);

		//functions
		virtual void capturePokemon(string filepath);
		virtual void setupBooster();
		Boost* getBoosterSetting();

		Pokemon* getNxtPokemon(int opponentHealth, int opponentSpeed, int opponentStrength,
			PokemonType attribute1, PokemonType attribute2);
		Pokemon* selectFirstPokemon();
	};

#endif TRAINER_H


