/** check numbers less than the root if they're primes
 *remove the multiplies of them
 */

#include <iostream>
#include <math.h>
using namespace std;
void primes()
{
    cout<<"enter number :  ";
    int n;
    cin>>n;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    cout<<"\n";
    int primes_array[n];
    int root=sqrt(n);
    if (root!=sqrt(n))
        root++;
    for(int s=1;s<n;++s)//make them all 1
        primes_array[s]=1;
    primes_array[0]=0;
    for(int i =1;i<=root;i++)
    {
        if(primes_array[i]==1)//>>>primary
        {
            for(int j=2*(i+1);j<=n;j+=(i+1))
            {
                primes_array[j-1]=0;
            }
        }
    }
    for(int s=1;s<n;++s)
    {
        if(primes_array[s]==1)
            cout<<s+1<<"\n";
    }

}
int main()
{
    while (true)
       primes();


    return 0;
}
