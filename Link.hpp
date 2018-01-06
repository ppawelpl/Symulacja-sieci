#ifndef LINK_H
#define LINK_H
#include<iostream>


using Time = int;
using TimeOffset = int;

enum queueType
{
	LIFO=0,
	FIFO=1
};

enum nodeType
{
	Ramp=0,
	Worker=1,
	Storage=2
};

class Receiver{   //tylko po to by bledy mi nie wyskakiwaly
	double id;
public:
	double getId();
};

class Link
{
private:
	double dest_id;
	nodeType dest_nodetype;
	float probability;
public:
	float getProbaility();
	double getDest_id();
	nodeType getDest_node_type();
	void showLink();
	void setReceiver(Receiver& Rec,float prob);////
};


#endif
