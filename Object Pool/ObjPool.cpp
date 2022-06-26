#include <iostream>
#include <stack> 

#define SIZE 10

using namespace std;



class Resource
{
    private:
            int value;

    public:
        Resource()
        {
            value = 0;
        }

        void Reset()
        {
            value = 0;
        }

        int GetValue()
        {
            return value;
        }

        void SetValue(int number)
        {
            value = number;
        }
};





class ObjectPool
{
    private:
        stack<Resource*> ResStack;
        
    
    public:

        ObjectPool(int c_Size) 
        {
            Resource* c_Res;

            for(int i=0; i<c_Size; i++)
            {
                c_Res= new Resource();
                ResStack.push(c_Res);
            } 
        }


    

        Resource* GetResource()
        {
            if (ResStack.empty())
            {
                cout << "Resource Stack empty creating new pool and returning obj." << endl;
                Resource* c_Res;

                for(int i=0; i<SIZE; i++)
                {
                    c_Res= new Resource();
                    ResStack.push(c_Res);
                }

            }
            else
               cout << "Reusing existing." << endl;

            Resource* temp= ResStack.top();
            ResStack.pop();                 
            return temp;

        }            



        void ReturnResource(Resource* object)
        {
            cout<< "Value of the returned Object =" << object->GetValue() << endl;
            object->Reset();
            ResStack.push(object);
        }
};




int main()
{
    ObjectPool pool(1);
    ObjectPool* Ppool=&pool;
    Resource* one;
    Resource* two;


    one = Ppool->GetResource();
    one->SetValue(10);
    std::cout << "one = " << one->GetValue() << " [" << one << "]" << std::endl;

    two = Ppool->GetResource();
    two->SetValue(20);
    std::cout << "two = " << two->GetValue() << " [" << two << "]" << std::endl;
    std::cout << "one = " << one->GetValue() << " [" << one << "]" << std::endl;


    Ppool->ReturnResource(one);
    Ppool->ReturnResource(two);


    one = Ppool->GetResource();
    std::cout << "one = " << one->GetValue() << " [" << one << "]" << std::endl;

    two = Ppool->GetResource();
    std::cout << "two = " << two->GetValue() << " [" << two << "]" << std::endl;


   
    return 0;
}