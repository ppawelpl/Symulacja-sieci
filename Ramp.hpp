#ifndef RAMP_HPP_
#define RAMP_HPP_
#include "Link.hpp"
#include "Product.hpp"
#include "Reciever.hpp"
#include "Sender.hpp"
#include<vector>
#include<map>
#include<cstdlib>
#include <ctime>

class Ramp: public Sender, public Reciever //musi te¿ otrzymywaæ
{
private:
	double id;
	bool processingNow;
	TimeOffset delivery_interval;
	Time timeLeft;
	bool ready2recieve;
	std::vector<Product> currentProcessing;
	std::vector<Link> links;
	std::map<int, Product> buffour;
	int setAllPropability();

	double chooseReciever();

public:
	Ramp() = delete;
	Ramp(double nId, TimeOffset ndelivery_interval);
	Ramp(const Ramp& W) = delete;
	//operator= te¿ zabroniæ nie wiem jak
	Ramp& operator=(const Ramp &W) = delete;
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
	int send(double destID);
	int recieve(Product recieved);

};



#endif /* RAMP_HPP_ */
