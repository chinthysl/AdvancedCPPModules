#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Qwrap
{

    struct Node {
        T Item;
        Node * Next;
    };



private:
	Node* Head;
	Node* Tail;

	

public:

	Node* Cursor;

	Qwrap()
	{
		Head=NULL;
		Tail=NULL;
		Cursor=NULL;
	}

	~Qwrap()
	{
		
	}

	void Enque(T value)

	{
		if(Tail==NULL)
		{
			Node* NewNode= new Node;
			NewNode->Item=value;
			NewNode->Next=NULL;
			Head=NewNode;
			Tail=NewNode;
			Cursor=Head;
			cout<< "First element-" << value << " inserted" <<endl;
		}
		else
		{
			Node* NewNode= new Node;
			NewNode->Item=value;
			NewNode->Next=NULL;


			Tail->Next=NewNode;
			Tail=NewNode;

			cout<< "Element-" <<value << " inserted" << endl;

		}
	}

	void Deque()
	{
		if(Tail==NULL)
			cout<< "Queue is Empty, Can't delete"<< endl;
		else if(Head==Tail)
		{
			delete Head;
			Head=NULL;
			Tail=NULL;
			Cursor=NULL;
			std::cout<< "Last element deleted"<< std::endl;

		}
		else
		{
			cout<< "Element " << Head->Item << " deleted" << endl;
			Node* Temp=Head->Next;
			if(Cursor==Head)
				Cursor==Temp;
			delete Head;
			Head= Temp;

		}
	}



	void Printq()
	{
		Node* Iterator=Head;
		
		if(Head==NULL)
			cout<<"Queue is empty"<<endl;
		else
		{
			while(Iterator!=NULL)
			{
				cout<<Iterator->Item<<endl;
				Iterator=Iterator->Next;
			}

		}

	}


	Qwrap operator++()
	{
		cout<<"********";
		//cout<< Head;
		if(this.Cursor==NULL)
		{
			cout<< "Queue end reached cant iterate"<< endl;
			return NULL;
		}
		else
		{
			this.Cursor=this.Cursor->Next;
				return this;
		}
		
			
	}


	

};