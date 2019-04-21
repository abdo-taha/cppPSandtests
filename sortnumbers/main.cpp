#include <iostream>

using namespace std;
void sorting(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        for(int n=0;n<i;n++)//if n<=i it will go to garbage and get wrong answer
        {
            if (arr[i-n-1]>arr[i-n])
            {
                swap(arr[i-n-1],arr[i-n]);
                //for (int k =0;k<5;k++)
                //cout<<arr[k]<<"\n";
                //cout<<"_________"<<"\n";
            }
            else
                break;
        }
        /*int cpy=arr[i];
        int j=i-1;
        for(;j>=0;--j)
        {
            if(arr[j]<cpy)
                break;
            arr[j+1]=arr[j];
        }
        arr[j+1]=cpy;*/
    }
}

int main()
{
    int a[2]={6,5};
    sorting(a,2);
    for (int i =0;i<2;i++)
        cout<<a[i]<<"\n";
    return 0;
}
