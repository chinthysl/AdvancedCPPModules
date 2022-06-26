#include <iostream>
#include <map>
#include <list>

using namespace std;


class MapList
{
	private:
		map<char, int> c_Map;   //map for the direct access values usign the key
		list<int*> c_List;		//list containing pointers to the  elements in the map fot ordered access

	public:
		MapList()
		{

		}
		~MapList()
		{
			
		}


		void InsertVal(char ch, int val)
		{
			c_Map[ch]=val;
			c_List.push_back(&c_Map[ch]);
			cout<< "Value " << val << " pushed into the map"<< endl;
		}


		int MapFind(char ch)
		{
			if(c_Map.find(ch) == c_Map.end())
			{
				cout<< ch << " Key- is not in the map!"<<endl;
				return 0;
			}
			else
			{
				cout<< ch<< " key- value is: "<< c_Map[ch] <<endl;
				return c_Map[ch];
			}

		}

		int FindListIter(int possition)
		{
			if(possition> c_List.size())
			{
				cout<< "Possition "<< possition<< " is greater than the # of data inserted"<< endl;
				return 0;
			}
			else
			{
				list<int*>::iterator it=c_List.begin();
				for(int i=1; i<possition; i++)
					it++;

				cout<< "Val at the possition "<< possition<< " is:"<< *(*it)<< endl;
				return *(*it);
			}
		}




};


int main(int argc, char const *argv[])
{
	/* code */

	MapList newML;
	newML.InsertVal('a',10);
	newML.InsertVal('b',20);
	newML.InsertVal('c',30);

	newML.MapFind('a');
	newML.MapFind('d');

	newML.FindListIter(1);
	newML.FindListIter(3);
	newML.FindListIter(4);

	return 0;
}