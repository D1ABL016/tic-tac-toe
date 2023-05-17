#include <bits/stdc++.h>
#include "f1.cpp"

/*
may 11 15:20 
TIME COMPLEXITY -> O()
TIME COMPLEXITY -> O()
SPACE COMPLEXITY -> O(1)
*/

using namespace std;

int chance_counter=0;

int main(){
    string player1,player2;
    string x,y;
    int cord=0;
    
    name_taker(&player1,&player2);
    char grid[9]={'.','.','.','.','.','.','.','.','.'};
    bool winner=false;
    while(chance_counter!=9)
    {
        cout<<"horizontal -> x axis and vertical -> y axis "<<endl;
        grid_printer(grid);
        if (chance_counter%2==0)
        cout<<player1<<" turn '(X)'"<<endl;
        else
        cout<<player2<<" turn '(O)'"<<endl;
        cord=cord_taker(&x,&y,grid);
        // cout<<"x : "<<x<<endl;//
        // cout<<"y : "<<y<<endl;//
        // cout<<"cord : "<<cord<<endl;//
        cord_inserter(&cord,grid);
        if (chance_counter>=4)
        {if (evaluator(grid,x,y))
        {
            // cout<<"x in main"<<x<<endl;
            // cout<<"y in main"<<y<<endl;
            winner=true;
            if (chance_counter%2==0)
            {
                grid_printer(grid);
                cout<<player1<<" is the winner "<<endl;
                break;
            }
            else
            {
                grid_printer(grid);
                cout<<player2<<" is the winner "<<endl;
                break;
            }
        }}
        
        chance_counter++;
    }
    if (winner==false)
    {
        grid_printer(grid);
        cout<<"match is drawn "<<endl;
    }
    
    return 0;
}

void name_taker(string *s1,string *s2)
{
    cout<<"enter name of player 1 : ";
    cin>>*s1;
    cout<<"enter name of player 2 : ";
    cin>>*s2;
    while((*s1)==(*s2))
    {
        cout << "INSIDE\n";
        cout<<"enter valid name of player 1 : ";
        cin>>*s1;
        cout<<"enter valid name of player 2 : ";
        cin>>*s2;
    }
}

void grid_printer(char arr[])
{
    cout<<"\t\t"<<0<<"\t"<<1<<"\t"<<2<<endl;
    for (int i=0;i<9;i++)
    {
        
        if (i%3==0)
        {
            cout<<i/3<<"\t\t";
        }
        cout<<arr[i]<<"\t";
        if ((i+1)%3==0)
        {
            cout<<endl;
        }
    }
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
}

bool evaluator (char arr[],string x,string y)
{
    char k1='X';
    char k2='O';
    // cout<<"x in evaluator"<<x<<endl;
    // cout<<"y in evaluator"<<y<<endl;
    int y1=st_to_cord((y),"0");
    int x1=st_to_cord((x),"0");
    int c=st_to_cord((x),(y));
    // cout<<"x1 in evaluator"<<x1<<endl;
    // cout<<"y1 in evaluator"<<y1<<endl;
    // cout<<arr[y1]<<endl;
    // cout<<arr[y1+1]<<endl;
    // cout<<arr[y1+2]<<endl;
    // // cout<<arr[x1+1]<<endl;
    // // cout<<arr[y1]<<endl;
    // cout<<arr[x1]<<endl;
    // cout<<arr[x1+3]<<endl;
    // cout<<arr[x1+6]<<endl;
    if ((arr[x1]==k1 && arr[x1+3]==k1 && arr[x1+6]==k1)||(arr[x1]==k2 && arr[x1+3]==k2 && arr[x1+6]==k2))
    return true;
    else if ((arr[y1]==k1 && arr[y1+1]==k1 && arr[y1+2]==k1)||(arr[y1]==k2 && arr[y1+1]==k2 && arr[y1+2]==k2))
    return true;
    else if (c%4==0)
    {
        if ((arr[0]==k1 && arr[4]==k1 && arr[8]==k1)||(arr[0]==k2 && arr[4]==k2 && arr[8]==k2))
        return true;
    }
    else if (c%2==0)
    {
        if ((arr[2]==k1 && arr[4]==k1 && arr[6]==k1)||(arr[2]==k2 && arr[4]==k2 && arr[6]==k2))
        return true;
    }

    return false;
}

/*
3 jgh only 
*/
 
int cord_taker(string *x, string *y,char grid[])
{
    *y="";
    bool validity;
    cout<<"enter x coordinate : ";
    getline(cin,*x);
    if(*x=="")
    validity=false;
    else
    validity=valid_input(x,y,grid);
    
    while(validity==false)
    {
        cout<<"please enter a valid x coordinate : ";
        // cout<<*x<<"-> x , y -> "<<*y<<endl;//
        getline(cin,*x);
        if(*x=="")
        validity=false;
        else
        validity=valid_input(x,y,grid);
    }
    cout<<"enter y coordinate : ";
    getline(cin,*y);
    if(*y=="")
    validity=false;
    else
    validity=valid_input(x,y,grid);
    
    while(validity==false)
    {
        cout<<"please enter a valid y coordinate : ";
        getline(cin,*y);
        // cout<<x<<" "<<y<<endl;//
        if(*y=="")
        validity=false;
        else
        validity=valid_input(x,y,grid);
        
    }
    int cord=st_to_cord(*x,*y);
    return cord;
    
}

bool valid_input(string *x, string *y,char grid[])
{
    // int cord=(*x)+*y+*y+*y;
    string temp;
    for (int i=0;i<(*x).length();i++)
    {
        if ((*x)[i]!=' ')
        temp+=(*x)[i];
    }
    if (*x=="")
    *x="0";
    else
    *x=temp;
    
    // cout<<"valid input vala x : "<<*x<<endl;//
    temp="";
    for (int i=0;i<(*y).length();i++)
    {
        if (((*y)[i]!=' '))
        temp+=(*y)[i];
    }
    (*y)=temp;
    // cout<<y[0]<<endl;
    if ((*y)=="")
    {
        if ((*x).length()>1)
        return false;
    }
    else
    {
        if ((*y).length()>1)
        return false;
    }
    int x1=st_to_cord((*x),"0");
    int y1=st_to_cord((*y),"0");
    // cout<<"int vala x1 : "<<x1<<endl;//
    if (x1<0 || x1>3)
    return false;
    if ((*y)!="")
    {
        if (y1<0||y1>3)
        return false;
    }
    if ((*y)!="")
    {int cord=st_to_cord((*x),(*y));
    // cout<<"int vala cord : "<<cord<<endl;//
    if (cord<0 || cord>8)
    {
        return false;
    }
    else if (grid[cord]=='X' || grid[cord]=='O')
    {
        // cout<<"ss"<<endl;//
        return false;
    }}
    return true;
}

void cord_inserter(int *x, char arr[])
{
    if (chance_counter%2==0)
        arr[*x]='X';
    else
        arr[*x]='O';
}

int st_to_cord(string x,string y)
{

    char t1=x[0];
    int c1=t1-'0';
    char t2=y[0];
    int c2=t2-'0';
    if (y=="")
    {cout<<"hi"<<endl;
    c2=0;}
    
    int cord=c1+3*c2;
    return cord;
}

/*
not necessary : 
calculator '* / '
parnthesis
numtaker vala error

*/
