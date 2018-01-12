#include "Worker.hpp"

int Worker::setAllProbability() {
	if (links.empty() == 1) {
		std::cout << std::endl << "klasa nie posiada polaczen z odbiorcami"
			<< std::endl;
		return 0;
	}
	if (links.size() == 1)
		return 1; //prawdopodobieñstwo 1 jest zachowywane, ale nale¿y pamiêtaæ ¿eby sprawdzaæ przy choosereciever
	if (links.size() == 2) //osobny przypadek
	{
		links[0].setProbability(1 - links[1].getProbability()* links[0].getProbability());
		links[1].setProbability(1 - links[0].getProbability());
		return 1;
	}
	float sum = 0;
	for (Link i : links) // mamy wektor obiektow Link
	{
		if (i.getdest_id() != links.back().getdest_id()) {
			i.setProbability(1 - links.back().getProbability()* i.getProbability());
			sum = sum + i.getProbability();
		}
	}
	links.back().setProbability(1 - sum);
	return 1;
}

double Worker::chooseReciever() {
	auto sum = 0;
	if (links.empty() == 1)
		return 0;
	if (links.size() == 1)
		return links[0].getdest_id();
	int randomNumber;
	srand(time(0));
	randomNumber = rand() % 100 + 1;
	//const auto& entry : probMap
	for (Link i : links) {
		//entry.second
		sum = sum + 100 * i.getProbability();
		if (sum >= randomNumber)
			return i.getdest_id();
	}
	std::cout << std::endl << "Nieznany blad" << std::endl;
	return 0;
}

Worker::Worker(double nId, TimeOffset nprocessing_time, queueType nqueue_type)
	: id(nId), processing_time(nprocessing_time), queue_type(nqueue_type) {}

void Worker::process() {
	if (processingNow == 0) {
		if (currentProcessing.empty() == 1) {
			if (_queue->ifempty() == 1)
				return;
			currentProcessing[0] = _queue->pull();
		}
		processingNow = 1;
		timeLeft = processing_time;

	}
	timeLeft--; //cojeslijakisczas
	if (timeLeft == 0)
		processingNow = 0;
	double chosen_ID = chooseReciever();
	if (chosen_ID == 0) {
		std::cout << std::endl << "nie udalo sie wybrac odbiorcy, przerywam"
			<< std::endl;
		timeLeft = 1;
		processingNow = 1;
	}
	send(chosen_ID); //mielismy referencje, czy mozemy podac wskaznik?
}

void Worker::setId(double newID) {
	id = newID;
}
void Worker::setprocessing_time(TimeOffset givenTime) {
	processing_time = givenTime;
}
void Worker::setqueue_type(queueType givenType) {
	queue_type = givenType;
}

int Worker::getId() {
	return id;
}
nodeType Worker::getType() {
	return nodeType::WORKER;
}
TimeOffset Worker::getprocessing_time() {
	return processing_time;
}
Time Worker::gettimeLeft() {
	return timeLeft;
}
bool Worker::getStatus() {
	if (processingNow == 0)
		return 0;
	else
		return 1;
}
queueType Worker::getqueue_type() {
	return queue_type;
}
void Worker::showLinks() {
	for (Link i : links)
		i.showLink();
}
void Worker::addLink(Link newLink) {
	int destinationId;
	int otherId;
    destinationId = newLink.getdest_id();
	for (Link i : links) {
		otherId = i.getdest_id();
		if (destinationId == otherId) {
			std::cout << std::endl << "ID zajete, nadpisuje polaczenie"
				<< std::endl;
			i = newLink;
			setAllProbability();
			return;
		}
		else;
	}
	links.push_back(newLink);
	setAllProbability();
}
int Worker::send(double destId) {
	int check;
	//nie spradzam czy mam co, a check niepotrzebny
	if (currentProcessing.empty() == 1)
		check = 0;
	if (check == 0);
	{
		std::cout << std::endl << "Blad, nie wys³ano" << std::endl;
		return 0;
	}
	buffour.insert(std::pair<double, Product>(destId, currentProcessing[0]));
	if (_queue->ifempty() != 1)
		currentProcessing[0] = _queue->pull();
	else
		currentProcessing.clear();
	return 1;
}
int Worker::recieve(Product recieved) {
	int check = 1;
	_queue->push(recieved);
	return check;
}

