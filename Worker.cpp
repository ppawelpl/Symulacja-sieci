
#include "link.cpp"
#include "product.cpp"
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
		links[0].probability = (1 - links[1].probability)
				* links[0].probability;
		links[1].probability = (1 - links[0].probability);
		return 1;
	}
	float sum = 0;
	float end = links.size() - 1;
	for (int i : links) // mamy wektor obiektow Link
	{
		if (i != end) {
			links[i].probability = (1 - links[end].probability)
					* links[i].probability;
			sum = sum + links[i].probability;
		}
	}
	links[end].probability = 1 - sum;
	return 1;
}

int Worker::chooseReciever() {
	sum = 0;
	// #include <cstdlib>
	if (links.size() == 1)
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

Worker::Worker(double nId, TimeOffset nprocessing_time, queueType nqueue_type)
{

	id = nId;
	processing_time = nprocessing_time; //czy mo¿na tak rzutowaæ typy
	queue_type = nqueue_type;
	currentProcessing = std::vector<Product> cP;
	links = std::vector<Link> l;
	//czy trzeba deklarowaæ wektory i tablice?

}

void Worker::process() {
	if (processingNow == 0) {
		if (currentProcessing.empty() == 1) {
			if (queue.empty() == 1)
				return;
			currentProcessing[0] = queue.pull();
		}
		processingNow = 1;
		timeLeft = processing_time;

	}
	timeLeft--; //cojeslijakisczas
	if (timeLeft == 0)
		processingNow = 0;
	chosen_ID = chooseReciever;
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
	return Worker;
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
	for (int i : links)
		links[i].showLink;
}
void Worker::addLink(Link newLink) {
	int destinationId;
	int otherId
	destinationId = newLink.getdest_id;
	for (int i : links) {
		otherId = links[i].getdest_id;
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
int Worker::send(Reciever& destination) {
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
	destination.recieve(currentProcessing[0])
	if (queue.empty() != 1)
		currentProcessing[0] = queue.pull();
	else
		currentProcessing.clear();
	return 1;
}
int Worker::recieve(Product recieved) {
	int check = 1;
	queue.push(recieved);
	return check;
}
