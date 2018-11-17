#include <iostream>
#include <fstream>

using namespace std;

bool isfound(string sub)
{
    ifstream file ;
    file.open("dictionaryEdit.txt",ios::in);
    if (file.fail())
    {
        cout<<"the file cant be opened"<<endl;
        return false;
    }

    bool a = false;
    string temp;

    while ( !file.eof() )
    {
        string temp;
        getline( file , temp );
        if( temp == sub )
        {
            return true;
        }
    }
    return a;
}

void sub_string( string x, int y = 0, string sub = "" )
{
    if ( y == x.length() )
    {
        if( isfound(sub) == true )
        {
            cout<<sub<<endl;
        }

    }
    else
    {
        sub_string( x, y+1, sub         );
        sub_string( x, y+1, sub + x[y]  );
    }
}

int main()
{
    string word;
    cout<<"enter the word : "<< endl;
    cin>>word;
    sub_string( word );

    return 0;
}
