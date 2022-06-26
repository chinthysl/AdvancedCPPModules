#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;



//hash function
void GetIndex(unsigned long &ulIndex,  string zKey, int tableSize)
{
      ulIndex = 0;
      char *acIndex = (char*)&ulIndex;

      int i;
      for (i=0; zKey[i] != '\0'; i++)
      {
            int n = i % 4;
            acIndex[n] = acIndex[n] ^ zKey[i];
      }

      ulIndex = ulIndex % tableSize;
}




//class for store data
class LinkedHashEntry {
private:
      string key;
      int value;
      LinkedHashEntry *next;
public:
      LinkedHashEntry(string key, int value) 
      {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }
 
      string getKey() 
      {
            return key;
      }
 
      int getValue() 
      {
            return value;
      }
 
      void setValue(int value) 
      {
            this->value = value;
      }
 
      LinkedHashEntry *getNext() 
      {
            return next;
      }
 
      void setNext(LinkedHashEntry *next) 
      {
            this->next = next;
      }
};




//hash map implementation
class HashMap {
private:
      LinkedHashEntry **table;
public:
      HashMap(int tableSize) 
      {
            table = new LinkedHashEntry*[tableSize];
            for (int i = 0; i < tableSize; i++)
                  table[i] = NULL;
      }

 
      int get(string zKey, int tableSize) 
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey, tableSize);
            unsigned long hash = ulIndex;

            if (table[hash] == NULL)
            {     
                  cout<< "Hash entry empty"<< endl;
                  return -1;
            }

            else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry != NULL && zKey.compare(entry -> getKey()) != 0 )
                        entry = entry->getNext();
                  if (entry == NULL)
                  {
                        cout<<"key not found in the link list" << endl;
                        return -1;
                  }


                  else
                  {
                              cout<< "key found in the map"<< endl;
                        return entry->getValue();
                  }
            }
      }


 
      int put(string zKey, int value, int tableSize) 
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey, tableSize);
            unsigned long hash = ulIndex;


            if (table[hash] == NULL)
            {
                  table[hash] = new LinkedHashEntry(zKey, value);
                  return 0;
            }
            else 
            {
                  LinkedHashEntry *entry = table[hash];
                  table[hash] = new LinkedHashEntry(zKey, value); 
                  table[hash]->setNext(entry);
                  return 1;

            }


      }


 
      void remove(string zKey, int tableSize) 
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey, tableSize);
            unsigned long hash = ulIndex;

            if (table[hash] != NULL) 
            {
                  LinkedHashEntry *prevEntry = NULL;
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL && zKey.compare(entry -> getKey()) !=0) 
                  {
                        prevEntry = entry;
                        entry = entry->getNext();
                  }
                  if (zKey.compare(entry -> getKey()) ==0) 
                  {
                        if (prevEntry == NULL) 
                        {
                             LinkedHashEntry *nextEntry = entry->getNext();
                             delete entry;
                             table[hash] = nextEntry;
                        } 
                        else 
                        {
                             LinkedHashEntry *next = entry->getNext();
                              delete entry;
                             prevEntry->setNext(next);
                        }
                  }
            }
      }
 
 
      ~HashMap() {
            delete[] table;
      }
};






void pefTest(int tableSize)
{

      HashMap dicMap(tableSize);

      int numHashCol=0;
      int wordCount=0;
      string line;


      ifstream myfile ("dictionary.txt");
      if (myfile.is_open())
      {
            while ( getline (myfile,line) )
            {

                  numHashCol += dicMap.put(line,1, tableSize);
                  wordCount++;

            }
            myfile.close();
      }

      else cout << "Unable to open file";

      cout<< "Wordcount: "<< wordCount<< "\tTablesize: "<< tableSize<< "  \tHashCollissions: "<< numHashCol<< endl; 
}





int main(int argc, char const *argv[])
{
      



      pefTest(500);
      pefTest(1000);
      pefTest(10000);
      pefTest(50000);



      return 0;
}