#ifndef POKEBALL_H
#define POKEBALL_H
//class dependency declaration
#include "Pokemon.h"

class Pokeball {
public:
	Pokeball(Pokemon *content) { this->content = content; this->next = NULL; };
	Pokemon *content;
	Pokeball *next;

	//destructor
	virtual ~Pokeball() { delete content; }
};
#endif POKEBALL_H
