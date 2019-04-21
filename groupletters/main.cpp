//group letters aabbb550 > aa bbb 55 0
#include <iostream>

using namespace std;
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
string solve(string text)
{
    int size=siz(text);
    char n =text[0];
    string output;
    output+=n;
    for(int i=1;i<size;i++)
    {
        if (text[i]==n)
            output+=n;
        else
        {
            output+=" ";
            n=text[i];
            output+=n;
        }
    }
    return output;
}
int main()
{
    string test="aaaggb55$$$$;";
    cout<<solve(test);

    return 0;
}
