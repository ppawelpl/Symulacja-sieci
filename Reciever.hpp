#ifndef RECIEVER_HPP_
#define RECIEVER_HPP_
#include "Product.hpp"
#include "Link.hpp"

enum nodeType
{
	RAMP=0,
	WORKER=1,
	STORAGE=2
};
class Reciever
{
public:
    virtual void receive(Product& product)=0;
    virtual double getid()=0;
    virtual nodeType getType(); // jedyny b��d jaki si� pojawia, nie umiem go naprawi�
};


#endif // RECIEVER_HPP_

