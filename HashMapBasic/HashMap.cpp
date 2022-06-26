#include <iostream>
#include <fstream>
#include <string.h>

#define TABLE_SIZE 500

using namespace std;



//hash function
void GetIndex(unsigned long &ulIndex,  string zKey)
{
      ulIndex = 0;
      char *acIndex = (char*)&ulIndex;

      int i;
      for (i=0; zKey[i] != '\0'; i++)
      {
            int n = i % 4;
            acIndex[n] = acIndex[n] ^ zKey[i];
      }

      ulIndex = ulIndex % TABLE_SIZE;
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
      HashMap() 
      {
            table = new LinkedHashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

 
      int get(string zKey) 
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey);
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


 
      void put(string zKey, int value) 
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey);
            unsigned long hash = ulIndex;


            if (table[hash] == NULL)
                  table[hash] = new LinkedHashEntry(zKey, value);
            else 
            {
                  LinkedHashEntry *entry = table[hash];
                  table[hash] = new LinkedHashEntry(zKey, value); 
                      table[hash]->setNext(entry);
            }

//            cout<< zKey<< ": Inserted"<< endl;
      }


 
      void remove(string zKey)
      {

            unsigned long ulIndex;
            GetIndex(ulIndex, zKey);
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
 
 
      ~HashMap() 
      {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) 
                  {
                        LinkedHashEntry *prevEntry = NULL;
                        LinkedHashEntry *entry = table[i];
                        while (entry != NULL) 
                        {
                             prevEntry = entry;
                             entry = entry->getNext();
                             delete prevEntry;
                        }
                  }
            delete[] table;
      }
};






int main(int argc, char const *argv[])
{
      
      HashMap dicMap;


      string line;
      int wordCount=0;



//*********reading the dictionary and storing in the map**********
      ifstream myfile ("dictionary.txt");
      if (myfile.is_open())
      {
            while ( getline (myfile,line) )
            {

                  dicMap.put(line,1);
                  wordCount++;

            }
            myfile.close();
      }

      else cout << "Unable to open file";
      cout<< "wordcount: "<< wordCount<< endl; 




//******geting the key values*************************************

      string testStr= "aahing";
      cout<< dicMap.get(testStr) << endl;


      testStr= "abaahome";
      cout<< dicMap.get(testStr) << endl;



      return 0;
}