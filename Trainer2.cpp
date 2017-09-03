#include "Trainer.h"
#include "Pokeball.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
Trainer2::Trainer2(string name, string residency) : Trainer(name, residency)
{
	Collection = NULL; type1[15] = { NULL };
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//captures the pokemon from a file and stores them in a pokeball. 
//Pokemon arranged according to attribute, and then strength
void Trainer2::capturePokemon(string filepath) {

	string line, name, move, attr1, attr2, temp;
	PokemonType attribute1, attribute2;
	int hp, strength, defense, speed;
	ifstream file(filepath);
	//need to set Collection to point to first pokeball, but Collection is private ??
	if (file.is_open())
	{
		getline(file, line); //ignore the first line

							 //getline returns true/false
		while (getline(file, line, '\n'))
		{
			Pokemon *Pm = NULL;
			Pokeball *Pb = NULL;
				istringstream iss(line); //pass in the line we just captured into the istringstream object iss
			getline(iss, name, ','); //store the first column in iss in name and stop reading at ','
			getline(iss, temp, ',');
				hp = stoi(temp);
			getline(iss, temp, ',');
				strength = stoi(temp);
			getline(iss, temp, ',');
				defense = stoi(temp);
			getline(iss, temp, ',');
				speed = stoi(temp);
			getline(iss, move, ',');
			getline(iss, attr1, ',');
				attribute1 = settype(attr1);
			getline(iss, attr2, ','); //will be an empty string if there is no attr2. 
				attribute2 = settype(attr2); //Reading from line instead of file protects us from reading the next line here.

			Pm = new Pokemon(name, move, hp, speed, defense,strength,attribute1,attribute2);
			Pb = new Pokeball(Pm);

			insert(Pb);
				
		}

		//set collection to point to the first non-NULL element of the array 
		int i = 0;
		while (type1[i] == NULL && i < size(type1))
			Collection = type1[i]; //What if there is nothing there?
	}
	else
	{
		cout << "Error. The file cannot be opened" << endl;
	}
}
//end capturePokemon /////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//string comparison of the attribute from the file to each of the kinds of attributes and returns the appropriate PokemonType
PokemonType Trainer2::settype(string attribute)
{
	//should do case-insensitive compare
	try {
		if (attribute.compare("Normal") == 0) { return NORMAL; }
		else if (attribute.compare("Fire") == 0) { return FIRE; }
		else if (attribute.compare("Water") == 0) { return WATER; }
		else if (attribute.compare("Electric") == 0) { return ELECTRIC; }
		else if (attribute.compare("Grass") == 0) { return GRASS; }
		else if (attribute.compare("Ice") == 0) { return ICE; }
		else if (attribute.compare("Fighting") == 0) { return FIGHTING; }
		else if (attribute.compare("Poison") == 0) { return POISON; }
		else if (attribute.compare("Ground") == 0) { return GROUND; }
		else if (attribute.compare("Flying") == 0) { return FLYING; }
		else if (attribute.compare("Psychic") == 0) { return PSYCHIC; }
		else if (attribute.compare("Bug") == 0) { return BUG; }
		else if (attribute.compare("Rock") == 0) { return ROCK; }
		else if (attribute.compare("Ghost") == 0) { return GHOST; }
		else if (attribute.compare("Dragon") == 0) { return DRAGON; }
		else { throw "Unrecognized Attribute type"; }
	}
	catch (char *se) {cout << se << endl; 
	return NONE;
	}
}
//end settype ///////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//insert the pokeball according to attribute 1 of the pokemon 
void Trainer2::insert(Pokeball *pb) {
	PokemonType type = pb->content->getAttribute(1);
	if (type == NORMAL) { insert_helper(type1[NORMAL], pb); }
	if (type == FIRE) { insert_helper(type1[FIRE], pb); }
	if (type == WATER) { insert_helper(type1[WATER], pb); }
	if (type == ELECTRIC) { insert_helper(type1[ELECTRIC], pb); }
	if (type == GRASS) { insert_helper(type1[GRASS], pb); }
	if (type == ICE) { insert_helper(type1[ICE], pb); }
	if (type == FIGHTING) { insert_helper(type1[FIGHTING], pb); }
	if (type == POISON) { insert_helper(type1[POISON], pb); }
	if (type == GROUND) { insert_helper(type1[GROUND], pb); }
	if (type == FLYING) { insert_helper(type1[FLYING], pb); }
	if (type == PSYCHIC) { insert_helper(type1[PSYCHIC], pb); }
	if (type == BUG) { insert_helper(type1[BUG], pb); }
	if (type == ROCK) { insert_helper(type1[ROCK], pb); }
	if (type == GHOST) { insert_helper(type1[GHOST], pb); }
	if (type == DRAGON) { insert_helper(type1[DRAGON], pb); }
}
//end insert /////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//inserts the pokemon lineup according to attribute1 and then strength- helper function
// type is a pointer from the array of pointers type1, which organizes the pokemon by type
// pb is the pokeball containing the pokemon to be inserted
void Trainer2::insert_helper(Pokeball *type, Pokeball *pb) {


	Pokeball *temp = type;
	//if the attribute list is empty
	if (type == NULL) {
		type = pb;
	}

	//insert at beginning
	if (pb->content->getStrength() > type->content->getStrength())
	{
		
		pb->next = type;
		type = pb;
	}


	else {
		//search list for insertion point
		Pokeball *ptra = type, *ptrb = type->next; //ptra holds the spot for insertion, ptrb makes comparison
		//advance	
		while (pb->content->getStrength() < ptrb->content->getStrength() && ptrb->next != NULL) {
			ptra = ptra->next;
			ptrb = ptrb->next;
		}
		//insert at end
		if (ptrb->next == NULL && pb->content->getStrength() < ptrb->content->getStrength())
		{
			ptrb->next = pb;
		}
		//insert in middle
		else {
			temp = ptrb;
			ptra->next = pb;
			pb->next = temp;
		}
	}
	
}
// end insert helper //////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
//creates linked list of boosters
void Trainer2::setupBooster() {
	Boost *boost1 = new Boost("defense7", Defense, 7);
	Boost *boost2 = new Boost("speed3", Speed, 3);
	Boost *boost3 = new Boost("attack2", Attack, 2);

	BoosterTypes = boost1;
	boost1->nextitem = boost2;
	boost2->nextitem = boost3;
}
//end setupBooster ////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
Pokemon* Trainer2::selectFirstPokemon() {
	Pokeball *fastest, *before_fastest, *ptra, *ptrb;
	//fastest stores the pokeball of the fastest pokemon found so far, before fastest stores the pokeball before it, 
	// which will be needed to relink the list when we return the fastest pokemon
	//ptra and ptrb are for searching. ptrb does comparison, ptra holds the pokeball one behind. 
	

	//assume the fastest pokemon is the first
	fastest = Collection;

	//traverse through the whole list to find the fastest pokemon
	for (int i = 0; i < size(type1); i++)
	{
		//makes sure the current element contains something
		if (type1[i] != NULL) {
			ptra = type1[i];

			// compare to first element ////////////////////////////////////////////////////////////////////////////////////
			//check if the first element is faster
			if (ptra->content->getSpeed() > fastest->content->getSpeed())
			{
				fastest = ptra;
				ptra = NULL;
			}
			//if the first element and fastest are different pokemon, but have the same speed, then choose the pokemon that is 
			//stronger or has more HP
			if (ptra->content->getSpeed() == fastest->content->getSpeed() &&
				ptra->content->getName() != fastest->content->getName()) {
				//if ptra is stronger, take that one
				if (ptra->content->getStrength() > fastest->content->getStrength())
				{
					before_fastest = NULL;
					fastest = ptra;
				}

				//if they have the same strength, take ptra if it has greater HP
				if (ptra->content->getStrength() == fastest->content->getStrength())
				{
					if (ptrb->content->getMaxHealth() > fastest->content->getMaxHealth())
					{
						before_fastest = NULL;
						fastest = ptra;
					}
				}
			
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////

			// compare to rest of attribute list ////////////////////////////////////////////////////////////////////
			//search through the attribute list as long as fastest is faster than the first element or 
			// is the same as the first element, provided that the current element isn't the last element.
			//then ptrb will compare with fastest, and ptra will be one behind 
			if ((fastest->content->getSpeed() > ptra->content->getSpeed() ||
				fastest->content->getName() == ptra->content->getName()) && ptra->next != NULL) {

				ptrb = ptra->next;
				//search within attribute
				while (fastest->content->getSpeed() > ptrb->content->getSpeed() && ptrb->next != NULL) {
					ptra = ptrb;
					ptrb = ptrb->next;
				}

				//cases:
				//ptrb contains a faster pokemon
				if (ptrb->content->getSpeed() > fastest->content->getSpeed())
				{
					before_fastest = ptra;
					fastest = ptrb;
				}

				//both pokemon are equally fast, then we choose whichever is stronger
				// or has greater HP if they are equally strong
				if (fastest->content->getSpeed() == ptrb->content->getSpeed())
				{
					//if ptrb is stronger, take that one
					if (ptrb->content->getStrength() > fastest->content->getStrength())
					{
						before_fastest = ptra;
						fastest = ptrb;
					}

					//if they have the same strength, take ptrb if it has greater HP
					if (ptrb->content->getStrength() == fastest->content->getStrength())
					{
						if (ptrb->content->getMaxHealth() > fastest->content->getMaxHealth())
						{
							before_fastest = ptra;
							fastest = ptrb;
						}
					}
					//otherwise, fastest stays the same and we compare in the next attribute list 
				}
				}

			}
		}
}

//select next pokemon based on opponent's attribute1
//Pokemon* Trainer2::getNxtPokemon(int opponentHealth, int opponentSpeed, int opponentStrength,
//	PokemonType attribute1, PokemonType attribute2) {
//	
//	//if opponent is NORMAL, pick a FIGHTING pokemon if it exists. Otherwise return the first pokemon that is not a ghost. 
//	if (attribute1 == NORMAL)
//	{
//		if (type1[FIGHTING] != NULL)
//		{
//			Pokeball *temp = type1[FIGHTING];
//			type1[FIGHTING] = type1[FIGHTING]->next;
//			return temp->content;
//		}
//
//		else {
//			//advance through list and pick first non null non ghost pokemon
//			}
//	}
//}



////////////////////////////////////////////////////////////////////////////////////////
Boost* getBoosterSetting() { return BoosterTypes; }