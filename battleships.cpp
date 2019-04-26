#include <iostream>
#include "classes.cpp"

using namespace std;

int main(){

/// set players
int X, Y;
cout<<"Vuvedi kolko da e golqmo poleto: ";
cin>>X>>Y;
cout<<"Enter Player's 1 name: ";
string name;
cin>>name;
Player p1(name, X, Y);
cout<<"Enter Player's 2 name: ";
cin>>name;
Player p2(name, X, Y);

///set ships

cout<<p1.Name<<" set your ships:"<<endl<<endl;
p1.showPole();
cout<<"Vuvedi golemina na korab ot 1 - 4 i nakude sochi: up or side i cordinati:"<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
p1.setShips();

cout<<p2.Name<<" set your ships:"<<endl<<endl;
p2.showPole();
cout<<"Vuvedi golemina na korab ot 1 - 4 i nakude sochi: up or side i cordinati:"<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
p2.setShips();

//set attack pole's
p1.hitPole = p2.pole;
p2.hitPole = p1.pole;

//attacking
bool error = false, win = false;
int playerTurn = 1;

while (!win)
{
    if (playerTurn == 1)
    {
        string coord;
        p1.showTarget();
        cout<<p1.Name<<" is guessing: ";
        cin>>coord;
        if(!p1.makeGuess(coord)){
            playerTurn = 2;
        }

    }else if (playerTurn == 2)
    {
        string coord;
        p2.showTarget();
        cout<<p2.Name<<" is guessing: ";
        cin>>coord;
        if(!p2.makeGuess(coord)){
            playerTurn = 1;
        }

    }
    if(p1.to4ki >= 20){
        win = true;
        playerTurn = 1;
    }else if(p2.to4ki >= 20){
        win = true;
        playerTurn = 2;
    }

}

if(playerTurn == 1){
    cout<<p1.Name<<" won the game!!!"<<endl;
}else{
    cout<<p2.Name<<" won the game!!!"<<endl;
}


return 0;
}
