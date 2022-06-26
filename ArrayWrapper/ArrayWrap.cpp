#include <iostream>
#include "ArrayW.h"


int main(int argc, char const *argv[])
{
	ArrayW<int> array1;

	array1.GetLength();
	array1.insert(0,1);
	array1.insert(1,2);
	array1.insert(2,3);
	array1.insert(3,4);
	array1.insert(4,5);
	array1.print();
	array1.GetLength();

	array1.insert(5,6);
	array1.GetLength();
	array1.print();

	return 0;
}