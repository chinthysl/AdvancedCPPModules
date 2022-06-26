#include <iostream>

using namespace std;

template <typename T>
class CirArray
{
private:
	int SIZE;
	int Index;
	T* Array;
	int latestPos;

public:
	CirArray()
	{
		SIZE=1000;
		Index=0;
		Array= new T[1000]; 
	}

	CirArray(int size)
	{
		SIZE=size;
		Index=0;
		Array= new T[SIZE]; 
	}


	~CirArray()
	{

	}

	void Insert(T Element)
	{	
		if(Index==SIZE)
			Index=0;

		Array[Index]=Element;
		Index++;
		cout<<"Element "<< Element << " inserted"<< endl;
		
	}

	T GetElement(int givenIndex)
	{
		return Array[(Index+givenIndex)%SIZE];
	}



};



int main(int argc, char const *argv[])
{
	CirArray<int> Array1(10);

	for(int i=0; i<14; i++)
		Array1.Insert(i+1);
	
	for(int i=0; i<10; i++)
		cout<<Array1.GetElement(i)<<endl;


	return 0;
}