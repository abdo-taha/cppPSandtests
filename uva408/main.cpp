#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int n1,n2;

    while(cin>>n1>>n2)
    {
        string text="Good Choice\n\n";
        if(n1==1)
        {
            cout<<setw(10)<<n1<<setw(10)<<n2<<"    "<<text;
            continue;
        }
        if(n2==0||n2%n1==0)
        {
            text="Bad Choice\n\n";
            cout<<setw(10)<<n1<<setw(10)<<n2<<"    "<<text;
            continue;
        }

        int temp;
        for(int i=2;i<=sqrt(n1);i++)
        {
            if(n1%i==0)
            {
                temp=n1/i;
                if(n2%i==0||n2%temp==0)
                {

                    text="Bad Choice\n\n";
                }

            }
        }

            cout<<setw(10)<<n1<<setw(10)<<n2<<"    "<<text;
    }

return 0;
}
