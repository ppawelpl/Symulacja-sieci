
#ifndef WORKER_HPP_
#define WORKER_HPP_
#include <cstdlib>
#include "Link.hpp"
#include "Product.hpp"
#include "Reciever.hpp"
#include "Sender.hpp"
#include "Queue.hpp"
#include<vector>
#include<map>
#include <ctime>

class Worker: public Sender, public Reciever {
private:
	double id;
	bool processingNow;
	TimeOffset processing_time;
	Time timeLeft;
	queueType queue_type;
    Queue *_queue; //pointer tylko on musi byæ inicjaizowany w konstruktorze
	std::vector<Product> currentProcessing; //lepiej vector bo mo¿e mieæ puste pole
	std::vector<Link> links;
	std::map<int, Product> buffour;
	int setAllProbability();
	double chooseReciever();

public:
	Worker() = delete;
	Worker(double nId, TimeOffset nprocessing_time,queueType nqueue_type);

	Worker(const Worker& W) = delete;
	//operator= te¿ zabroniæ nie wiem jak
	void process();
	void setId(double newID);
	void setprocessing_time(TimeOffset givenTime);
	void setqueue_type(queueType givenType);
	int getId();
	nodeType getType();
	TimeOffset getprocessing_time();
	Time gettimeLeft();
	bool getStatus();
	queueType getqueue_type();
	void showLinks();
	void addLink(Link newLink);
	int send(double destId);
	int recieve(Product recieved);

};



#endif /* WORKER_HPP_ */
