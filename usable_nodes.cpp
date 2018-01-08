class Worker : public Sender, public Reciever
{
	private:
		double id;
		bool processingNow;
		TimeOffset processing_time;
		Time timeLeft;
		queueType queue_type;
		Queue queue;//pointer tylko on musi byæ inicjaizowany w konstruktorze 
		std::vector<Product> currentProcessing;//lepiej vector bo mo¿e mieæ puste pole
		std::vector<Link> links;
		int setAllPropability()
		{
			if (links.empty() == 1)
			{
				std::cout << std::endl << "klasa nie posiada polaczen z odbiorcami" << std::endl;
				return 0;
			}
			if (links.size() == 1)
				return 1;//prawdopodobieñstwo 1 jest zachowywane, ale nale¿y pamiêtaæ ¿eby sprawdzaæ przy choosereciever
			if (links.size == 2) //osobny przypadek
			{
				links[0].probability = (1 - links[1].probability)*links[0].probability;
				links[1].probability = (1 - links[0].probability);
				return 1;
			}
			float sum = 0;
			float end = links.size - 1;
			for (int i : links)
			{
				if (i != end)
				{
					links[i].probability = (1 - links[end].probability)*links[i].probability;
					sum = sum + links[i].probability;
				}
			}
			links[end].probability = 1 - sum;
			return 1;
		}
		int chooseReciever()
		{
				sum = 0;
				// #include <cstdlib>
				if(links.size==1)
					return links[0].getDestId();
				int randomNumber;
				float randomNumberFloat;
				srand(time(0));
				randomNumber = rand() % 100 + 1;
				randomNumberFloat = randomNumber;
				//const auto& entry : probMap
				for (int i : links)
				{
					//entry.second
					sum = sum + 100 * links[i].probability;
					if (sum >= randomNumber)
						return links[i].getDestId();
				}
				std::cout << std::endl << "Nieznany blad" << std::endl;
				return 0;
			}
	public:
		Worker() = delete;
		Worker(double nId, TimeOffset nprocessing_time; queueType nqueue_type)
		{
			id = nId;
			processing_time = nprocessing_time; //czy mo¿na tak rzutowaæ typy
			queue_type = nqueue_type;
			currentProcessing = std::vector<Product> cP;
			links = std::vector<Link> l;
			//czy trzeba deklarowaæ wektory i tablice?
		}
		Worker(const Worker& W) = delete;
		//operator= te¿ zabroniæ nie wiem jak
		Worker& Worker::operator=(const Worker &W) = delete;
		void process()
		{
			if (processingNow == 0)
			{
				if (currentProcessing.empty() == 1)
				{
					if (queue.empty()==1)
						return;
					currentProcessing[0] = queue.pull();
				}
				processingNow = 1;
				timeLeft = processing_time;
				
			}
			timeLeft--;//cojeslijakisczas
			if (timeLeft == 0)
				processingNow = 0;
			chosen_ID = chooseReciever;
			if (chosen_ID == 0)
			{
				std::cout << std::endl << "nie udalo sie wybrac odbiorcy, przerywam" << std::endl;
				timeLeft = 1;
				processingNow = 1;
			}
			std::unique_ptr<Reciever> chosen = std::make_unique<Reciever>(chooseReciever());//jak z samego destid zrobiæ recievera?
			send(*chosen.get());//mielismy referencje, czy mozemy podac wskaznik?
		}
		void setId(double newID)
		{
			id = newID;
		}
		void setprocessing_time(TimeOffset givenTime)
		{
			processing_time = givenTime;
		}
		void setqueue_type(queueType givenType)
		{
			queue_type=givenType
		}
		int getId()
		{
			return id;
		}
		nodeType getType()
		{
			return Worker;
		}
		TimeOffset getprocessing_time()
		{
			return processing_time;
		}
		Time gettimeLeft()
		{
			return timeLeft
		}
		bool getStatus()
		{
			if (processingNow == 0)
				return 0;
			else
				return 1;
		}
		queueType getqueue_type()
		{
			return queue_type;
		}
		void showLinks()
		{
			for (int i : links)
				links[i].showLink;
		}
		void addLink(Link newLink)
		{
			int destinationId;
			int otherId
			destinationId = newLink.getdest_id;
			for (int i : links)
			{
				otherId = links[i].getdest_id;
				if (destinationId == otherId)
				{
					std::cout << std::endl << "ID zajete, nadpisuje polaczenie" << std::endl;
					links[i] = newLink;
					setAllPropability();
					return;
				}
				else;
			}
			links.push_back(newLink);
			setAllPropability();
		}
		int send(Reciever& destination)
		{
			int check;
			//nie spradzam czy mam co, a check niepotrzebny
			if (currentProcessing.empty() == 1)
				check = 0;
			if (check == 0);
			{
				std::cout << std::endl << "Blad, nie wys³ano" << std::endl;
				return 0;
			}
			destination.recieve(currentProcessing[0])
			if(queue.empty()!=1)
				currentProcessing[0] = queue.pull();
			else
				currentProcessing.clear()
			return 1;
		}
		int recieve(Product recieved)
		{
			int check=1;
			queue.push(recieved);
			return check;
		}
};


class Ramp : public Sender, public Reciever //musi te¿ otrzymywaæ
{
private:
	double id;
	TimeOffset delivery_interval;
	Time timeLeft;
	bool ready2recieve;
	std::vector<Product> currentProcessing;
	std::vector<Link> links;
	int setAllPropability()
	{
		if (links.empty() == 1)
		{
			std::cout << std::endl << "klasa nie posiada polaczen z odbiorcami" << std::endl;
			return 0;
		}
		if (links.size() == 1)
			return 1;//prawdopodobieñstwo 1 jest zachowywane, ale nale¿y pamiêtaæ ¿eby sprawdzaæ przy choosereciever
		if (links.size == 2) //osobny przypadek
		{
			links[0].probability = (1 - links[1].probability)*links[0].probability;
			links[1].probability = (1 - links[0].probability);
			return 1;
		}
		float sum = 0;
		float end = links.size - 1;
		for (int i : links)
		{
			if (i != end)
			{
				links[i].probability = (1 - links[end].probability)*links[i].probability;
				sum = sum + links[i].probability;
			}
		}
		links[end].probability = 1 - sum;
		return 1;
	}
	int chooseReciever()
	{
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
		for (int i : links)
		{
			//entry.second
			sum = sum + 100 * links[i].probability;
			if (sum >= randomNumber)
				return links[i].getDestId();
		}
		std::cout << std::endl << "Nieznany blad" << std::endl;
		return 0;
	}
public:
	Ramp() = delete;
	Ramp(double nId, TimeOffset ndelivery_interval)
	{
		id = nId;
		delivery_interval = ndelivery_interval;
		currentProcessing = std::vector<Product> cP;
		links = std::vector<Link> l;
		//czy trzeba deklarowaæ wektory i tablice?
	}
	Ramp(const Ramp& W) = delete;
	//operator= te¿ zabroniæ nie wiem jak
	Ramp& Ramp::operator=(const Ramp &W) = delete;
	void process()
	{
		if (ready2recieve == 1)
		{
			ready2recieve = 0;
			timeLeft = delivery_interval;
			currentProcessing.clear();
		}
		else
			timeLeft--;
		if (timeLeft == 0)
			ready2recieve = 1;
		if (currentProcessing.empty() == 0)
		{
			chosen_ID = chooseReciever();
			if (chosen_ID == 0)
			{
				std::cout << std::endl << "nie udalo sie wybrac odbiorcy, przerywam" << std::endl;
				timeLeft = 1;
				processingNow = 1;
			}
			std::unique_ptr<Reciever> chosen = std::make_unique<Reciever>(chooseReciever());//jak z samego destid zrobiæ recievera?
			send(*chosen.get());//mielismy referencje, czy mozemy podac wskaznik?
		}
	}
	void setId(double newID)
	{
		id = newID;
	}
	void setdelivery_interval(TimeOffset givenTime)
	{
		delivery_interval = givenTime;
	}
	int getId()
	{
		return id;
	}
	nodeType getType()
	{
		return Ramp;
	}
	TimeOffset getdelivery_interval()
	{
		return delivery_interval;
	}
	Time gettimeLeft()
	{
		return timeLeft
	}
	bool getStatus()
	{
		if (ready2recieve == 0)
			return 0;
		else
			return 1;
	}
	void showLinks()
	{
		for (int i : links)
			links[i].showLink;
	}
	void addLink(Link newLink)
	{
		int destinationId;
		int otherId
			destinationId = newLink.getdest_id;
		for (int i : links)
		{
			otherId = links[i].getdest_id;
			if (destinationId == otherId)
			{
				std::cout << std::endl << "ID zajete, nadpisuje polaczenie" << std::endl;
				links[i] = newLink;
				setAllPropability();
				return;
			}
			else;
		}
		links.push_back(newLink);
		setAllPropability();
	}
	int send(Reciever& destination)
	{
		int check;
		//nie spradzam czy mam co, a check niepotrzebny
		if (currentProcessing.empty() == 1)
			check = 0;
		if (check == 0);
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
	int recieve(Product recieved)
	{
		if (currentProcessing.empty() == 0)
		{
			return 0;
		}
		currentProcessing[0]=recieved;
		return 1;
	}
};


class Storage : public Reciever
{
private:
	double id;
	std::vector<Product> store;
public:
	Storage() = delete;
	Storage(double nId)
	{
		id = nId;
		store= std::vector<Product> s;
		//czy trzeba deklarowaæ wektory i tablice?
	}
	Storage(const Storage& W) = delete;
	~Storage()//nie wiem
	//operator= te¿ zabroniæ nie wiem jak
	void setId(double newID)
	{
		id = newID;
	}
	void showStore()
	{
		for (int i : store)
		{
			store[i].show();
		}
	}
	int getId()
	{
		return id;
	}
	nodeType getType()
	{
		return Storage;
	}
	int recieve(Product recieved)
	{
		store.pushback(recieved);
		return 1;
	}
};