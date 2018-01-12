#include "Queue.hpp"

bool Queue::ifempty()
    {
    if(kolejka.empty()==true) return 1;
    else return 0;
    }
void Queue::push(Product& product)
    {
    kolejka.push_back(product);
    }

Product Lifo::pull()
    {
    Product temp=kolejka.back();
    kolejka.pop_back();
    return temp;
    }

Product Fifo::pull()
    {
    Product temp=kolejka.front();
    kolejka.pop_front();
    return temp;
    }

void Queue::view()
    {
    for(unsigned int i=0;i<kolejka.size();i++)
        {
        Product temp=kolejka.at(i);
        temp.show();
        }
    std::cout<<std::endl;
    }

