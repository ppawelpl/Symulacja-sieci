#ifndef LINK_H
#define LINK_H
#include<iostream>


using Time = int;
using TimeOffset = int;

enum EqueueType
{
	LIFO=0,
	FIFO=1
};

enum nodeType
{
	RAMP=0,
	WORKER=1,
	STORAGE=2
};

class Receiver{
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
	float getProbability();
	double getdest_id();
	nodeType getDest_node_type();
	void showLink();
	void setReceiver(Receiver& Rec,float prob);
	void setProbability(float prob);
};


#endif
