#include "Storage.hpp"

Storage::Storage(double nId) {
	id = nId;
}
void Storage::setId(double newID) {
	id = newID;
}
void Storage::showStore() {
	for (Product i : store) {
		i.show();
	}
}

int Storage::getId() {
	return id;
}

nodeType Storage::getType() {
	return nodeType::STORAGE;
}
int Storage::recieve(Product recieved) {
	store.push_back(recieved);
	return 1;
}
