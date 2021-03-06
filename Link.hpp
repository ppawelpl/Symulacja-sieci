

#ifndef LINK_H
#define LINK_H
#include<iostream>
#include "Reciever.hpp"

using Time = int;
using TimeOffset = int;

enum queueType
{
	LIFO=0,
	FIFO=1
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
	void setReceiver(Reciever& Rec,float prob);
	void setProbability(float prob);
};


#endif
