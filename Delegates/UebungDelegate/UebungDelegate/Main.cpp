#include <iostream>
#include <functional>
#include <vector>

class Event {
public:
	using ListenerDelegate = std::function<void()>;

	void AddListener(ListenerDelegate listener)
	{
		listeners.push_back(listener);
	}

	void Invoke()
	{
		for (const auto& a : listeners)
		{
			a();
		}
	}


private:
	std::vector<ListenerDelegate> listeners;


};

void OnEvent1()
{
	std::cout << "Event 1 Aufgerufen!" << std::endl;
}

void OnEvent2()
{
	std::cout << "Event 2 Aufgerufen!" << std::endl;
}

int main()
{
	Event myEvent;

	myEvent.AddListener(OnEvent1);
	myEvent.AddListener(OnEvent2);


	myEvent.Invoke();


}