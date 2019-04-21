#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;
int sec(int arr[],int size)
{
        assert(size>=2);
        /*int first=arr[0]>arr[1]?arr[0]:arr[1];
        int secend=arr[1]<arr[0]?arr[1]:arr[0];*/
        int first=arr[0];
        int secend=arr[1];
        if (secend > first)
            swap(first,secend);
        for (int i=2;i<size;i++)
        {
            if (arr[i]>first)
            {
                secend=first;
                first=arr[i];
            }
            else if (arr[i]<first&&arr[i]>secend||arr[i]==first)
                secend=arr[i];
            else
                ;
        }
        return secend;

}
void test()
{

    const int size=10;
    int arr[size];
    for (int i=1;i<1000;i++)
    {
        for (int j=0; j<size;j++)
            arr[j]=rand()%100;
        int myanswer=sec(arr,size);
        sort(arr,arr+size);
        for(int a=0;a<size;a++)
        {
            cout<<arr[a]<<"\n";
        }
        cout<<myanswer<<arr[size-2];
        assert(myanswer==arr[size-2]);
    }
    cout<<"done";

}
int main()
{
    test();
    return 0;
}
