#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include<iostream>
#include<deque>
#include "Product.hpp"
#include "Link.hpp"
#include<deque>
class Queue
    {
    protected:
        std::deque<Product> kolejka;
    public:
        void push(Product& product);
        virtual Product pull()=0;
        bool ifempty();
        void view();  //deque
    };

class Lifo : public Queue
    {
    public:
        Product pull();
    };

class Fifo : public Queue
    {
    public:
        Product pull();
    };
#endif // QUEUE_HPP_
