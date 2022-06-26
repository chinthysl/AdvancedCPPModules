#include <iostream>
#include "Qwrap.h"


using namespace std;


int main(int argc, char const *argv[])
{
	
	Qwrap<int> q1;

	q1.Enque(1);
	q1.Enque(2);
	q1.Enque(3);
	q1.Enque(4);
	q1.Deque();
	q1.Deque();
//	q1.Deque();
//	q1.Deque();
//	q1.Deque();


	++q1;


	cout<<q1.Cursor->Item<<endl;

	q1.Printq();


	return 0;
}