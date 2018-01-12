#include "Ramp.hpp"


int Ramp::setAllPropability() {
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
double Ramp::chooseReciever() {
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

Ramp::Ramp(double nId, TimeOffset ndeliveryinterval)
	: id(nId), delivery_interval(ndeliveryinterval) {}

void Ramp::process() {
	if (ready2recieve == 1) {
		ready2recieve = 0;
		timeLeft = delivery_interval;
		currentProcessing.clear();
	}
	else
		timeLeft--;
	if (timeLeft == 0)
		ready2recieve = 1;
	if (currentProcessing.empty() == 0) {
		double chosen_ID = chooseReciever();
		if (chosen_ID == 0) {
			std::cout << std::endl << "nie udalo sie wybrac odbiorcy, przerywam"
				<< std::endl;
			timeLeft = 1;
			processingNow = 1;
		}
		send(chosen_ID); //mielismy referencje, czy mozemy podac wskaznik?
	}
}
void Ramp::setId(double newID) {
	id = newID;
}
void Ramp::setdelivery_interval(TimeOffset givenTime) {
	delivery_interval = givenTime;
}
int Ramp::getId() {
	return id;
}
nodeType Ramp::getType() {
	return nodeType::RAMP;
}
TimeOffset Ramp::getdelivery_interval() {
	return delivery_interval;
}
Time Ramp::gettimeLeft() {
	return timeLeft;
}
bool Ramp::getStatus() {
	if (ready2recieve == 0)
		return 0;
	else
		return 1;
}
void Ramp::showLinks() {
	for (Link i : links)
		i.showLink();
}
void Ramp::addLink(Link newLink) {
	int destinationId;
	int otherId;
	destinationId = newLink.getdest_id();
	for (Link i : links) {
		otherId = i.getdest_id();
		if (destinationId == otherId) {
			std::cout << std::endl << "ID zajete, nadpisuje polaczenie"
				<< std::endl;
			i = newLink;
			setAllPropability();
			return;
		}
		else;
	}
	links.push_back(newLink);
	setAllPropability();
}
int Ramp::send(double destID) {
	int check;
	//nie spradzam czy mam co, a check niepotrzebny
	if (currentProcessing.empty() == 1)
		check = 0;
	if (check == 0)

	{
		std::cout << std::endl << "Blad, nie wys³ano" << std::endl;
		return 0;
	}
	buffour.insert(std::pair<int, Product>(destID, currentProcessing[0]));
	currentProcessing.erase(currentProcessing.begin());
	return 1;
}
int Ramp::recieve(Product recieved) {
	if (currentProcessing.empty() == 0) {
		return 0;
	}
	currentProcessing[0] = recieved;
	return 1;
}


