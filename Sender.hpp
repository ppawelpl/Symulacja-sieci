#ifndef SENDER_HPP_
#define SENDER_HPP_
#include "Product.hpp"

class Sender
{
public:
    virtual void send(Product& product)=0;
};

#endif // SENDER_HPP_
