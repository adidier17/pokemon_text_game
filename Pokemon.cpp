#include "Pokemon.h"
#include <string.h>

//function definitions
string Pokemon::getName() { return name; }

bool Pokemon::fainted() {
	if (currentHealth < 0 || currentHealth == 0)
		return true;
	else
		return false;
}

int Pokemon::getMaxHealth() { return maxHealth; }

int Pokemon::getRemainingHealth() { return currentHealth; }

void Pokemon::damageTaken(int amount) { currentHealth = currentHealth - amount; }

int Pokemon::getSpeed() { return speed; }

int Pokemon::getStrength() { return strength; }

int Pokemon::getDefense() { return defense; }

string Pokemon::attack() { cout << name << "attacks with" << move << endl;	return move; }

PokemonType Pokemon::getAttribute(int id) {
	if (id == 1) return attribute1;
	else if (id == 2) return attribute2;
	else {
		cout << "Error. Please enter a 1 or 2. " << endl;
		return NONE;
	}
	
}

