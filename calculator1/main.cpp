#include <iostream>

using namespace std;

int main()
{
    cout<<"welcome to calculator \n";
    startpoint:
    cout<<"enter two numbers \n";
    double n1,n2;
    cin>> n1>>n2;
    if (cin.fail())
    {
     cout<<"please enter valid numbers \n";
     cin.clear()  ;
     cin.ignore(10000,'\n');
     goto startpoint;
    }
    cout<<"+ = 1 \n - = 2 \n * = 3 \n / = 4 \n";
    operatorpoint:
    short o ;
    cin>> o ;
    if(cin.fail())
    {
        cout<<"plese eneter a valid number \n";
        cin.clear();
        cin.ignore(10000,'\n');
        goto operatorpoint;

    }
    if (o==1)
        cout<<n1+n2 <<'\n';
    else if (o==2)
        cout<<n1-n2<<'\n';
    else if (o==3)
        cout << n1*n2<<'\n' ;
    else if (o==4)
    {
        if (n2==0.0)
        {
            cout<<"can't devide by zero \n enter another two numbers \n";
            goto startpoint;
        }
         else
            cout <<n2/n1<<'\n' ;
    }
    else
    {
        cout<<"enter number between 1-4";
        goto operatorpoint;
    }
    goto startpoint;
    return 0;
}
