#include <iostream>

using namespace std;

int main()
{
    cout<<"\t\t\t\t\t\t welcom in my game\n\t\t\t\t\t\t   kayles game";
    string y= "12345678901234567890";
    int x=0,a,player_1,player_2;

     while(x<20)
     {
        cout<<"\nplayer 1";
        cout<<"\nhow many numbers you want to choose 1 or 2?";
        cin>>a;

        if (a==1)
        {
            cout<<"choose 1 number from"<<y;
            cout<<"==>";
            cin>>player_1;
            y[player_1-1]='_';
            x++;
            cout<<y;
        }
        else
        {

            cout<<"choose 2 number from "<<y;
            cout<<"==>";
            cin>>player_1;
            y[player_1-1]='_';
            cout<<"==>";
            cin>>player_1;
            y[player_1-1]='_';
            x=x+2;
            cout<<y;
        }
        if(x==20)
        {
            cout<<"\n\t\tpalyer 2 is loser\n\t\t   game over :(";
                break;
        }
        cout<<"\nplayer 2\n how manu numbers you want to choose 1 or 2?!";
        cin>>a;
        if(a==1)
        {
            cout<<"choose 1 number from"<<y;
            cout<<"==>";
            cin>>player_2;
            y[player_2-1]='_';
            x++;
            cout<<y;
        }
        else
        {
            cout<<"choose 2 number from"<<y;
            cout<<"==>";
            cin>>player_2;
            y[player_2-1]='_';
            cin>>player_2;
            y[player_2-1]='_';
            x=x+2;
            cout<<y;
        }
        if(x==20)
        {
            cout<<"\n\t\tplaye 1 is loser\n\t\t   game over :(";
              break;
     }



    }


    return 0;
}
