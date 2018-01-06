#include "Product.hpp"

double Product::getId(){
	return id;
}

void Product::show(){
	std::cout<<"Product Id: ";
	std::cout<< id<< std::endl;
}
