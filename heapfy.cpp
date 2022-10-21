#include<iostream>
using namespace std;
void heapfy(int a[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && a[largest]<a[left])
    {
        largest=left;
    }
    if(right<=n && a[largest]<a[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapfy(a,n,largest);
    }

}
void heapSort(int a[],int n)
{
    int size=n;
    while(size>1)
    {
        //case 1 SWAP
        swap(a[size],a[1]);
        size--;
        //case 2
        heapfy(a,size,1);
    }
}
int main()
{
    int a[]={-1,54,53,55,52,50};
    int n=5;
    //heap creatiion
    for(int i=n/2;i>0;i--)
    {
        heapfy(a,n,i);
    }
    cout<<"printing the array"<<endl;
    for(int i=1;i<=n;i++)
    {
   cout<<a[i]<<" ";
    }
    cout<<endl;
    heapSort(a,n);
    cout<<"printing the sorting array"<<endl;
    for(int i=1;i<=n;i++)
    {
   cout<<a[i]<<" ";
    }

}