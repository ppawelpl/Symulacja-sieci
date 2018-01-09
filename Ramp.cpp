#include "Ramp.hpp"
#include "Link.hpp"

int Ramp::setAllPropability() {
	if (links.empty() == 1) {
		std::cout << std::endl << "klasa nie posiada polaczen z odbiorcami"
				<< std::endl;
		return 0;
	}
	if (links.size() == 1)
		return 1; //prawdopodobieñstwo 1 jest zachowywane, ale nale¿y pamiêtaæ ¿eby sprawdzaæ przy choosereciever
	if (links.size == 2) //osobny przypadek
			{
		links[0].probability = (1 - links[1].probability)
				* links[0].probability;
		links[1].probability = (1 - links[0].probability);
		return 1;
	}
	float sum = 0;
	float end = links.size - 1;
	for (int i : links) {
		if (i != end) {
			links[i].probability = (1 - links[end].probability)
					* links[i].probability;
			sum = sum + links[i].probability;
		}
	}
	links[end].probability = 1 - sum;
	return 1;
}
int Ramp::chooseReciever() {
	sum = 0;
	// #include <cstdlib>
	if (links.size == 1)
		return links[0].getDestId();
	int randomNumber;
	float randomNumberFloat;
	srand(time(0));
	randomNumber = rand() % 100 + 1;
	randomNumberFloat = randomNumber;
	//const auto& entry : probMap
	for (int i : links) {
		//entry.second
		sum = sum + 100 * links[i].probability;
		if (sum >= randomNumber)
			return links[i].getDestId();
	}
	std::cout << std::endl << "Nieznany blad" << std::endl;
	return 0;
}

Ramp::Ramp(double nId, TimeOffset ndeliveryinterval) {
	id = nId;
	delivery_interval = ndelivery_interval;
	currentProcessing = std::vector < Product > cP;
	links = std::vector < Link > l;
	//czy trzeba deklarowaæ wektory i tablice?
}

void Ramp::process() {
	if (ready2recieve == 1) {
		ready2recieve = 0;
		timeLeft = delivery_interval;
		currentProcessing.clear();
	} else
		timeLeft--;
	if (timeLeft == 0)
		ready2recieve = 1;
	if (currentProcessing.empty() == 0) {
		chosen_ID = chooseReciever();
		if (chosen_ID == 0) {
			std::cout << std::endl << "nie udalo sie wybrac odbiorcy, przerywam"
					<< std::endl;
			timeLeft = 1;
			processingNow = 1;
		}
		std::unique_ptr < Reciever > chosen = std::make_unique < Reciever
				> (chooseReciever()); //jak z samego destid zrobiæ recievera?
		send(*chosen.get()); //mielismy referencje, czy mozemy podac wskaznik?
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
	return Ramp;
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
	for (int i : links)
		links[i].showLink;
}
void Ramp::addLink(Link newLink) {
	int destinationId;
	int otherId;
	destinationId = newLink.getdest_id;
	for (int i : links) {
		otherId = links[i].(getdest_id());
		if (destinationId == otherId) {
			std::cout << std::endl << "ID zajete, nadpisuje polaczenie"
					<< std::endl;
			links[i] = newLink;
			setAllPropability();
			return;
		} else;
	}
	links.push_back(newLink);
	setAllPropability();
}
int Ramp::send(Receiver& destination) {
	int check;
	//nie spradzam czy mam co, a check niepotrzebny
	if (currentProcessing.empty() == 1)
		check = 0;
	if (check == 0)
		;
	{
		std::cout << std::endl << "Blad, nie wys³ano" << std::endl;
		return 0;
	}
	destination.receive(currentProcessing[0])
	if (queue.empty() != 1)
		currentProcessing[0] = queue.pull();
	else
		currentProcessing.clear();
	return 1;
}
int Ramp::recieve(Product recieved) {
	if (currentProcessing.empty() == 0) {
		return 0;
	}
	currentProcessing[0] = recieved;
	return 1;
}


