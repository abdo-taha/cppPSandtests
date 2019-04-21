//find number in array faster
//check if sum oftwo numbers in array equal value
#include <iostream>
#include <algorithm>
using namespace std;
bool solve(int arr[],int value,int size)
{
    sort(arr,arr+size);
    int s=0;
    int b=size-1;
    if(arr[b]==value||arr[s]==value)
        return true;
    for(int i=(s+b)/2;;i=(s+b)/2)
    {
        if(arr[i]!=value&&b-s==1)
            return false ;
        else if (arr[i]>value)
            b=i;
        else if(arr[i]<value)
            s=i;
        else if(arr[i]==value)
        return true;
    }
}
bool check(int arr[],int size,int value)
{
        sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        int sub=value-arr[i];
        int s=1,b=size-1;
        if(arr[s]==sub||arr[b]==sub)
            return true;
        for(int j=(s+b)/2;;j=(s+b)/2)
        {
            cout<<"a";
            if(arr[j]!=sub&&b-s==1)
            break ;
        else if (arr[j]>sub)
            b=j;
        else if(arr[j]<sub)
            s=j;
        else if(arr[j]==sub)
        return true;
        }

    }
    return false;
}
int main()
{
    int a[]={10,5,6,13,24,88,41,25,0,66,32,85,10,15,99,3,25,105,198};
    cout<<check(a,6,303);
    return 0;
}
