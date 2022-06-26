#pragma once
#include <iostream>
using namespace std; 

template <typename T>
class ArrayW
{
private:
    int ArryLength;
    int ArryIncLenght;
	T *Array;
 
public:
	ArrayW()
	{
		ArryLength=5;
		ArryIncLenght=3;

		Array= new T[ArryLength];
	}

 
    ArrayW(int InitLength, int IncLength)
    {
        ArryLength= InitLength;
		ArryIncLenght= IncLength;

		Array= new T[ArryLength];

    }
 
    ~ArrayW()
    {
        delete[] Array;
    }


 
    void insert(int Index, T data)
    {
		if(Index > ArryLength-1)
		{
			int Inc=((Index+1-ArryLength)/ArryIncLenght+1)*ArryIncLenght;
			
			T temp[ArryLength];
			for(int i=0; i<ArryLength; i++)
			{
				temp[i]=Array[i];
			}
			delete[] Array;


			int OldArryLength=ArryLength;
			ArryLength=ArryLength+Inc;
			Array= new T[ArryLength];
			for(int i=0; i<OldArryLength; i++)
			{
				Array[i]= temp[i];
			}


			Array[Index]= data;

						
		}
		else 
			Array[Index]= data;

    }
 

 
    void print()
    {

    	for(int i=0; i<ArryLength; i++)
    	{
    		cout<<Array[i]<<endl;

    	}

    }



    int GetLength()
	{
		cout<< "Array length=" << ArryLength <<endl;
		return 0;
	}
};

