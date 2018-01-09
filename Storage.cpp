#include "Storage.hpp"

Storage::Storage(double nId){
	id = nId;

			store= std::vector<Product> s;
			//czy trzeba deklarowaæ wektory i tablice?
}
void Storage::setId(double newID){
	id = newID;
}
void Storage::showStore()
	{
		for (int i : store)
		{
			store[i].show();
		}
	}

int Storage::getId()
	{
		return id;
	}

nodeType Storage::getType()
	{
		return Storage;
	}
int Storage::recieve(Product recieved)
	{
		store.push_back(recieved);
		return 1;
	}
