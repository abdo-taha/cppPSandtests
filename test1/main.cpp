#include <iostream>

using namespace std;

int main()
{
    int c=0;
    for (int x=1;x<=100;x++)
    {
        for (int y=(x>=70?x+1:70);y<=200;y++)
        if((x+y)%7==0)
         c++;
    }
    cout<<c;
    return 0;
}
