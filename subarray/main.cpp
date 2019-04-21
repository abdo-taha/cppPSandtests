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
void solve(string text)
{
    int size =siz(text);
    for(int i=0;i<size;i++)
    {
        string print="";
        for(int j=i;j<size;j++)
        {
            print+=text[j];
            cout<<print<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    solve("123a");
    return 0;
}
