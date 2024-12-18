#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item {
private:
	string itemName;
	int frequency;
public:
	Item(); //default constructor, needed for map value object instantiations
	Item(const string& itemName, int frequency);  //intended constructor for all instantiated objects

	//Accessors
	const string& getItemName() const;
	int getFrequency() const;

	//Mutator
	void incrementFrequency();

};

#endif