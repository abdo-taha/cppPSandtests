//take number out of string
#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;
int num(char n)
{
    string letters="0123456789";
    int numbers[10]={0,1,2,3,4,5,6,7,8,9};
    for (int i=0;i<10;i++)
    {
        if(n==letters[i])
            return numbers[i];
    }
    return 10;
}
int siz(string text)
{
    string test;
    for (int i=0;;i++)
    {
        if (test==text)
            return i ;
        else
        test+=text[i];
    }
}
string revers(string text)
{
    int size=siz(text);
    string output;
    for (int i=size-1;i>=0;i--)
        output+=text[i];
    return output;
}
int solve(string text)
{
    text=revers(text);
    int size=siz(text);
    int result =0;
    for(int i=0;i<size;i++)
    {
        int number=num(text[i]);
        assert(number!=10);
        double add=number*pow(10,i);
        result+=add;
    }
    return result;
}
int main()
{
    cout<<solve("00056");
    return 0;
}
