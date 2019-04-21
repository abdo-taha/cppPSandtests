#include<iostream>
using namespace std;
class bankaccount
{
private:
    double balance,interest_rate ;
public:
    void setb(int dollars, int cents,double interest)
    {
        balance = dollars + 0.01 * cents;
        interest_rate = interest;
    }
    void update( )
    {
        balance = balance +((interest_rate/100)*balance);
    }
    double get_balance( )
    {
        return balance;
    }
    double get_rate( )
    {
        return interest_rate;
    }
};

int main( )
{
    bankaccount account1;
    account1.setb(100, 50 , 2);
    cout <<"balance :"<<account1.get_balance()<<endl;
    cout<<"interest rate:"<<account1.get_rate()<<endl;
    account1.update( );
    cout << "balance:"<<account1.get_balance()<<endl;
    return 0 ;
}
