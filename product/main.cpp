#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{


    string n1,n2;
    while(cin>>n1)
    {
        cin>>n2;
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        int a[600]={};
        for(int i=0;i<n1.length();i++)
        {
            for(int j=0;j<n2.length();j++)
            {
                a[i+j]+=(n1[i]-'0')*(n2[j]-'0');
            }
        }





        for(int i=0;i<600;i++)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }





        for(int i=599;i>=0;i--)
        {
            if(a[i]==0) continue;
            else
            {
                for(int j=i;j>=0;j--)
                    cout<<a[j];
                cout<<endl;
                break;
            }
        }
    }


    return 0;
}
