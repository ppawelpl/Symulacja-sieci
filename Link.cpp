#include "Link.hpp"


double Link::getDest_id(){
	return dest_id;
}

float Link::getProbaility(){
	return probability;
}

nodeType Link::getDest_node_type(){
	return dest_nodetype;
}

void Link::showLink(){
	std::cout<< "Id: ";
	std::cout<< dest_id<<std::endl;

	std::cout<< "Probability: ";
	std::cout<< probability<<std::endl ;

	std::cout<<"nodeType: ";
	std::cout<< dest_nodetype <<std::endl;

}
//////////////////////////////////////////////////////////////////
void Link::setReceiver(Receiver& Rec,float prob){
		this->dest_id=Rec.getId();

}
