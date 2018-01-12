#include "Product.hpp"
#include <iostream>
double Product::getId(){
	return id;
}

void Product::show(){
	std::cout<<"Product Id: ";
	std::cout<< id<< std::endl;
}
