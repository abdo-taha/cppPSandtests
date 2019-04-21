#include <iostream>

using namespace std;
void factorial(int n)
{
    int arr[1000]={1};
    int len=1;

    for(int i =2;i<=n;++i)
    {

     for(int j=0;j<len;j++)
     {
         arr[j]*=i;

     }
     for(int j=0;j<len;j++)
     {
        if(j==len-1&&arr[j]/10!=0)
            len+=1;
        arr[j+1]+=arr[j]/10;
        arr[j]=arr[j]%10;


     }
    }
    for(int k=len-1;k>=0;--k)
        cout<<arr[k];
    cout<<"\n"<<len;
}

int main()
{
    factorial(100);

    return 0;
}
