#include "Trainer.h"
#include <string.h>

class Trainer {
protected:
	Pokeball *Collection;
	Boost *BoosterTypes;

public:
	//constructor
	Trainer() {}
	Trainer(string name, string residency) { this->name = name; this->residency = residency; Collection = NULL; }

	//variables
	string name, residency;

	//functions
	virtual void capturePokemon(string filepath);
	virtual void setupBooster();
	Boost* getBoosterSetting() { return BoosterTypes; }
	virtual Pokemon* getNxtPokemon(int, int, int, PokemonType, PokemonType);
	virtual Pokemon* selectFirstPokemon();
};


