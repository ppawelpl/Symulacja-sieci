#ifndef RECIEVER_HPP_
#define RECIEVER_HPP_
#include "Product.hpp"
#include "Link.hpp"

class Reciever
{
public:
    virtual void receive(Product& product)=0;
    virtual double getid()=0;
    virtual nodeType getType()=0; // jedyny b³¹d jaki siê pojawia, nie umiem go naprawiæ
};

#endif // RECIEVER_HPP_

