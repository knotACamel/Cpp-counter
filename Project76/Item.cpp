#include "Item.h"

Item::Item() : itemName(""), frequency(0) {} //default constructor, needed for map value object instantiations
Item::Item(const std::string& itemName, int frequency)
	: itemName(itemName), frequency(frequency) {}  //intended constructor for all instantiated objects

//accessors
const std::string& Item::getItemName() const {
	return itemName;
}

int Item::getFrequency() const {
	return frequency;
}

//mutator
void Item::incrementFrequency() {
	frequency += 1;
}