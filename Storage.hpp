#ifndef STORAGE_HPP_
#define STORAGE_HPP_
#include "Product.hpp"
#include "Link.hpp"
#include <vector>

class Storage: public Receiver {
private:
	double id;
	std::vector<Product> store;
public:
	Storage() = delete;
	Storage(double nId);
	Storage(const Storage& W) = delete;
	~Storage();//nie wiem
	//operator= te¿ zabroniæ nie wiem jak
	void setId(double newID);
	void showStore();
	int getId();
	nodeType getType();
	int recieve(Product recieved);

};


#endif /* STORAGE_HPP_ */
