#include "Link.hpp"


double Link::getdest_id(){
	return dest_id;
}

float Link::getProbability(){
	return probability;
}

nodeType Link::getDest_node_type(){
	return dest_nodetype;
}
void Link::setProbability(float prob){
	probability=prob;

}
void Link::showLink(){
	std::cout<< "Id: ";
	std::cout<< dest_id<<std::endl;

	std::cout<< "Probability: ";
	std::cout<< probability<<std::endl ;

	std::cout<<"nodeType: ";
	std::cout<< dest_nodetype <<std::endl;

}
void Link::setReceiver(Reciever& Rec,float prob){
		this->dest_id=Rec.getid();

}
