#include <iostream>

using namespace std;
void cycle(int arr[],int size)
{
    int test[size]={};
    for (int i=0;i<size;++i)
    {
        if(test[i]==1)
            continue;
        for(int j=i;;)
        {
        if(test[j]==1)
        {
            cout<<"__________ \n";
            break;
        }
        test[j]=1;
        cout<<j<<" : ";
        j=arr[j];
        cout<<j<<"\n";
        }
    }
}
int main()
{
    int test[11]={10,8,1,3,5,0,2,4,9,6,7};
    cycle(test,11);


    return 0;
}
