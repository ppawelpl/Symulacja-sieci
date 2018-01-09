#ifndef RAMP_HPP_
#define RAMP_HPP_
#include "Link.hpp"
#include "Product.hpp"

class Ramp: public Sender, public Reciever //musi te¿ otrzymywaæ
{
private:
	double id;
	TimeOffset delivery_interval;
	Time timeLeft;
	bool ready2recieve;
	std::vector<Product> currentProcessing;
	std::vector<Link> links;
	int setAllPropability();

	int chooseReciever();

public:
	Ramp() = delete;
	Ramp(double nId, TimeOffset ndelivery_interval);

	Ramp(const Ramp& W) = delete;
	//operator= te¿ zabroniæ nie wiem jak
	Ramp& Ramp::operator=(const Ramp &W) = delete;
	void process();
	void setId(double newID);
	void setdelivery_interval(TimeOffset givenTime);
	int getId();
	nodeType getType();
	TimeOffset getdelivery_interval();
	Time gettimeLeft();
	bool getStatus();
	void showLinks();
	void addLink(Link newLink);
	int send(Receiver& destination);
	int recieve(Product recieved);

};



#endif /* RAMP_HPP_ */
