#include <iostream>
using namespace std;
int main()
{
   for (double a=1,b=1,temp=0,i=1;i<100;i++,temp=a+b,a=b,b=temp)
    {
    cout<<a;
    cout<<'\n';
    }

return 0;
}
