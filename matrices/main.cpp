#include <iostream>
using namespace std;
const int rows=3 ,cols =3;//for addition
const int rows1=2,cols1=3,rows2=3,cols2=2;//for multiplying
const int rows3=4,cols3=4;//for printing
void add(int one[rows][cols],int two[rows][cols],int sum[rows][cols])
{
    for (int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
            sum[i][j]=one[i][j]+two[i][j];
    }
}
void print(int matrix[rows3][cols3])
{
    for (int i=0;i<rows3;++i)
    {
        for(int j=0;j<cols3;++j)
            cout<<" "<<matrix[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"__________\n";
}
void mult(int one[rows1][cols1],int two[rows2][cols2])
{
    int result[rows1][cols2]={};
    for (int i=0;i<rows1 ;i++)
    {
        for(int j =0 ;j<cols2;++j)
        {
            for(int s=0;s<cols1;++s)
                result[i][j]+=one[i][s]*two[s][j];
        }
    }
    for (int i=0;i<rows1;++i)
    {
        for(int j=0;j<cols2;++j)
            cout<<" "<<result[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"__________\n";
}
enum dir {RIGHT=0,LEFT,UP,DOWN,UPRIGHT,UPLEFT,DOWNRIGHT,DOWNLEFT};
int col[]={1,-1,0,0,1,-1,1,-1};
int row[]={0,0,-1,1,-1,-1,1,1};
void direction(int dir,int matrix[rows3][cols3],int r,int c)
{
    r+=row[dir];
    c+=col[dir];
    cout<<matrix[r][c];
}
int r=0,c=0;
void trans(int n,int len,int &r,int &c)
{
    r=n/len;
    c=n%len;
}
int snail(int matrix[rows3][cols3])
{
    cout<<matrix[r][c]<<"\n";
    for(int i=0;i<rows3-1;i++)
    {
        c++;//////////////////////////
        cout<<matrix[r][c]<<"\n";
    }
    int n=rows3-1;
    int a[]={rows3,-1,(-rows3),1};
    int p=0;
    for(int i=rows3;i>0;i--)//i >> number of moves
    {
        //cout<<"i "<<i<<"\n";
        for(int j=i-1;j>0;j--)
        {
            n+=a[p];
            trans(n,rows3,r,c);
            cout<<matrix[r][c]<<"\n";
        }
        p=(p+1)%4;
        for(int j=i-1;j>0;j--)
        {
            n+=a[p];
            trans(n,rows3,r,c);
            cout<<matrix[r][c]<<"\n";
        }
        p=(p+1)%4;
    }
}
int main()
{
    int a[rows3][rows3]={15,5,6,3,0,5,88,9,3,1,20,9,8,7,6,3};
    cout<<a[3][5];


    return 0;
}
