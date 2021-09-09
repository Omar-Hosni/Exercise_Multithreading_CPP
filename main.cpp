#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//Captain, Engine Crew, Cleaning Crew
//Captain is going to be represented as main() thread
//Captain can issue 3 commands

/*
Captain can order cleaning crew to clean. And captain
does not have to wait on this command until it's done

Now two commands are full speed ahead and stop the 
engine commands. Captain has to wait until enginer crew
to finish these commands to proceed to the next command
*/

/*
Write a small program which takes input from console
and execute these commands. Input is an integer
which represent above commands.
1 is for cleaning
2 is for full speed 
3 is for stop
100 is to exit program

If any other number you have to print "Invalid order" to console
*/

//let's try using RAII

class T_Class {
	thread& T;

public:
	explicit T_Class(thread& t) : T(t) {}

	~T_Class() {
		if (T.joinable()) {
			T.join();
		}
	}

	T_Class(T_Class& const) = delete;
	T_Class& operator=(T_Class& const) = delete;

	
};

void clean() {
	cout << "Cleaning crew is cleaning" << endl;
}

void engine() {
	cout << "Crew engine is speeding up" << endl;
}

void stop() {
	cout << "Ship is stopping" << endl;
}

int main() {
	

	int input = 0;

	while (input != 100) {
		cout << "enter the number of your order (1-2-3-100): ";
		cin >> input;

		if (input == 1) {
			thread t1(clean);
			T_Class obj1(t1);
		}
		else if (input == 2) {
			thread t2(engine);
			T_Class obj2(t2);
		}
		else if (input == 3) {
			thread t3(stop);
			T_Class obj3(t3);
		}
	}
}
