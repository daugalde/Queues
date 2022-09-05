#include "Node.h"
#include "Queue.h"
#include "StaticQueue.h"

using namespace std;

int main() {
	/*
	Queue queue;
	queue.Push(1);
	queue.Display();
	queue.Push(2);
	queue.Display();
	queue.Push(3);
	queue.Display();
	queue.Push(4);
	queue.Display();
	cout << nuevaCola.Pop() << endl;
	queue.Display();
	*/


	/// <summary>
	/// Static Queue
	/// </summary>
	/// <returns></returns>

	StaticQueue staticQueue;

	staticQueue.Push(2);
	staticQueue.Push(7);
	staticQueue.Push(9);
	staticQueue.Push(6);
	staticQueue.Push(8);
	staticQueue.Display();
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	staticQueue.Pop();
	staticQueue.Display();
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	//staticQueue.Push(8);
	staticQueue.Pop();
	staticQueue.Display();
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	staticQueue.Pop();
	staticQueue.Display();
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	staticQueue.Pop();
	staticQueue.Display();
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	staticQueue.Pop();
	staticQueue.Display();

	cin.get();

	return 0;
};
