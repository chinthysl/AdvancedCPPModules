#include <vector>
#include <iostream>

using namespace std;



enum EventType {A, B, C};


class EventCallback
{
	public:
		virtual void OnEventA()=0;
		virtual void OnEventB()=0;
		virtual void OnEventC()=0;

		bool SubEvents[3];

};


class SubX : public EventCallback
{

	
	public:
		SubX()
		{
			SubEvents[0]=true;
			SubEvents[1]=true;
			SubEvents[2]=true;

		}
		~SubX()
		{

		}

		void OnEventA()
		{
			cout<< "SubX got Event A" << endl;
		}
		void OnEventB()
		{
			cout<< "SubX got Event B" << endl;
		}
		void OnEventC()
		{
			cout<< "SubX got Event C" << endl;
		}
};


class SubY : public EventCallback
{

	public:
		SubY()
		{
			SubEvents[0]=true;
			SubEvents[1]=false;
			SubEvents[2]=true;

		}

		~SubY()
		{

		}
		void OnEventA()
		{
			cout<< "SubY got Event A" << endl;
		}
		void OnEventC()
		{
			cout<< "SubY got Event C" << endl;
		}
		void OnEventB()
		{

		}
};




class EventManager
{
	private:
			vector<EventCallback*> EventVec;
	// a container to hold event subscribers

	public:
	void Register(EventCallback* pCB)
			{
				EventVec.push_back(pCB);
			}


	void ProcessEvent(EventType Etype)
			{
				int i;
				if(Etype==A)
					i=0;
				else if(Etype==B)
					i=1;
				else
					i=2;


	  			for (vector<EventCallback*>::iterator it = EventVec.begin() ; it != EventVec.end(); ++it)
	  			{
	  				if((*it)->SubEvents[i]==true)
						if(Etype==A)
							(*it)->OnEventA();
						else if(Etype==B)
							(*it)->OnEventB();
						else if(Etype==C)
							(*it)->OnEventC();
		
	 			}

			}

};




int main(int argc, char const *argv[])
{
	SubX subx1;
	SubY suby1;

	EventManager evm1;

	evm1.Register(&suby1);
	evm1.Register(&subx1);

	evm1.ProcessEvent(A);

	return 0;
}