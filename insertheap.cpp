#include<iostream>
using namespace std;
class heap
{
    public:
    int a[100];
    int size;
     heap()
     {
        a[0]=-1;
       size=0;
     }
     void insert(int val)
     {
        size=size+1;
        int index=size;
        a[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(a[parent]<a[index])
            {
                swap(a[parent],a[index]);
                parent=index;
            }
            else{
                return;
            }
        }
     }

     void print()
     {
        for(int i=1;i<=size;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
     }
     void deletefromHeap()
     {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        // step 1 SWAP FIRST NODE TO THE LAST NODE
        a[1]=a[size];
        // step 2  LAST NODE
        size--;
      // step 3 TAKE ROOT NODE TO ITS CORRECT POSITION 
        int i=1;
        while(i<size)
        {
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex<size && a[i]<a[leftindex])
            {
                swap(a[i],a[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && a[i]<a[rightindex])
            {
                swap(a[i],a[rightindex]);
                i=rightindex;
            }
            else
            {
                return;
            }
        }

     }
};
int main()
{
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    //h1.insert(25);
    h1.print();
   // cout<<endl;
    h1.deletefromHeap();
    h1.print();
}