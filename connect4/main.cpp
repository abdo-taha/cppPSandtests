#include <iostream>
using namespace std;
int game[6][7]={};//game structure
int rows[7]={5,5,5,5,5,5,5};//order of putting
int close=0; //for tie situation
void print()
{
    cout<<"\n0 1 2 3 4 5 6 \n_____________\n";
for(int r=0;r<6;++r)
{
    for (int c=0;c<7;++c)
    {
        cout<<game[r][c]<<" ";
    }
    cout<<"\n";
}
}
int check(int symbol, int col)
{
    int row =rows[col]+1;
    int r=row; int c=col;
    //check up and down
    while(r<6)
    {
        if (game[r+1][c]==symbol)
            r++;
        else
            break;
    }
    int four=0;
    for(int i=0;i<4;++i)
    {
        if(c<7&&r>=0&&c>=0&&r<6)
            {
        if(game[r][c]==symbol)
            four++;
        r--;
            }
    }
    if(four==4)
        return 1;
    r=row;c=col;four=0;
    //check right and left
    while(c<7)
    {
        if (game[r][c+1]==symbol)
            c++;
        else
            break;
    }
    for(int i=0;i<4;++i)
    {
        if(c<7&&r>=0&&c>=0&&r<6)
            {
        if(game[r][c]==symbol)
            four++;
        c--;
            }
    }
    if(four==4)
        return 1;
        //check  major axis
     r=row;c=col;four=0;
    while(c<7&&r>=0&&c>=0&&r<6)
    {
        if (game[r+1][c+1]==symbol)
        {
          c++;     r++;
        }
        else
            break;
    }
    for(int i=0;i<4;++i)
    {
        if(c<7&&r>=0&&c>=0&&r<6)
        {
        if(game[r][c]==symbol)
            four++;
        c--; r--;
        }
    }
    if(four==4)
        return 1;
     r=row;c=col;four=0;
     //check minor axis
    while(c<7&&r>=0&&c>=0&&r<6)
    {
        if (game[r+1][c-1]==symbol)
        {
          c--;     r++;
        }
        else
            break;
    }
    for(int i=0;i<4;++i)
    {
        if(c<7&&r>=0&&c>=0&&r<6)
        {
        if(game[r][c]==symbol)
            four++;
        c++; r--;
        }
    }
    if(four==4)
        return 1;
    return 0;

}
int put(int symbol,int col)
{
    int row=rows[col];
    if(row==-1)
    {
        cout<<"full position \n";
        return 0;
    }
    game[row][col]=symbol;
    rows[col]--;
    return 1;
}
void play()
{
while(true)
{
    close++;
    print();
    point1:
    int input;
    cout<<"\n player1 *7* : \n";
    while (true)
    {
    cin>>input;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    else if (input>6||input<0)
    {cout<<"enter valid position : \n";}
    else
        break;
    }
    int a=put(7,input);
    if(a==0)
        goto point1;
    int cc=check(7,input);
    if (cc==1)
    {
        print();
        cout<<"\n player 1 won \n";

        break;
    }

    print();
    cout<<"\n player2 *5* : \n";
    point2:
    while (true)
    {
    cin>>input;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    else if (input>6||input<0)
    {cout<<"enter valid position : \n";}
    else
        break;
    }
    int b=put(5,input);
    if(b==0)
        goto point2;
     cc=check(5,input);
    if (cc==1)
    {
        print();
        cout<<"\n player 2 won \n";
        break;
    }
    if (close==21)
    {
        print();

        cout<<"\n  it's tie \n";
        break;
    }
}


}
int main()
{
    play();

    return 0;
}
