#include <iostream>

using namespace std;
string win()
{
    int n;
    string winner ;
    cin>>n;
    cin>>winner;
    int anton =0;
    int danik=0;
    for (int i=0;i<n;i++)
    {
        if(winner[i]=='a')
            anton++;
        else
        danik++;
    }
    if (anton > danik)
        return "anton";
    else if (anton < danik)
        return "danik";
    else
    return "friendship";
}

int main()
{
    cout<<win();
    return 0;
}
