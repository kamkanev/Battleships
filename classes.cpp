#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<sstream>
#include "functions.cpp"

using namespace std;

class Player
{
public:
    string Name;
    int to4ki = 0;
    vector<vector<int> > pole;
    vector<vector<int> > hitPole;
    Player(string name, int X, int Y)
    {
        Name = name;
        pole.resize(Y, vector<int>(fabs(X)));
        hitPole.resize(Y, vector<int>(fabs(X)));
    }
    void showPole()
    {
        cout<<"    ";
        for (int i=0; i<pole[0].size(); i++)
        {
            char k = 'A'+i;
            cout<<k<<" ";
        }
        cout<<endl;
        cout<<"    ";
        for (int i=0; i<pole[0].size(); i++)
        {
            cout<<"_ ";
        }
        cout<<endl;
        for (int i=0; i<pole.size(); i++)
        {
            for (int j=0; j<pole[i].size(); j++)
            {
                if(j == 0)
                {
                    if(i>=9)
                    {
                        cout<<i+1<<" |";
                    }
                    else if(i<9)
                    {
                        cout<<i+1<<"  |";
                    }
                }
                if(pole[i][j] == 0)
                {
                    cout<<"~ ";
                }
                else if(pole[i][j] == 1)
                {
                    cout<<"# ";
                }
            }
            cout<<endl;
        }

    }
    void showTarget(){
        cout<<"    ";
        for (int i=0; i<hitPole[0].size(); i++)
        {
            char k = 'A'+i;
            cout<<k<<" ";
        }
        cout<<endl;
        cout<<"    ";
        for (int i=0; i<hitPole[0].size(); i++)
        {
            cout<<"_ ";
        }
        cout<<endl;
        for (int i=0; i<hitPole.size(); i++)
        {
            for (int j=0; j<hitPole[i].size(); j++)
            {
                if(j == 0)
                {
                    if(i>=9)
                    {
                        cout<<i+1<<" |";
                    }
                    else if(i<9)
                    {
                        cout<<i+1<<"  |";
                    }
                }
                if(hitPole[i][j] == 0 || hitPole[i][j] == 1)
                {
                    cout<<"~ ";
                }
                else if(hitPole[i][j] == -1)
                {
                    cout<<"X ";
                }else if(hitPole[i][j] == 2){
                    cout<<"O ";
                }else{
                    cout<<"# ";
                }
            }
            cout<<endl;
        }
    }

    bool makeGuess(string c){
        vector<int> coords = getCoords(c);
        if(hitPole[coords[1]][coords[0]] == 1){
            hitPole[coords[1]][coords[0]] = 2;
            to4ki++;
            return true;
        }else{
            hitPole[coords[1]][coords[0]] = -1;
            return false;
        }
    }

    void setShips()
    {
        bool error = false;
        int malki = 4, dvoini = 3, troini = 2, golemi = 1, br=10;
        while(br>0)
        {
            int len;
            string side;
            string coords;
            cout<<"Imash "<<malki<<" edinichni koraba, "<<dvoini<<" dvoini, "<<troini<<" troini i "<<golemi<<" 4voren."<<endl;
            cin>>len>>side>>coords;
            len = fabs(len);
            if(len == 1 && malki>0)
            {

                vector<int> coord = getCoords(coords);
                //cout<<coord[0]<<"     "<<coord[1]<<endl;
                if(pole[coord[1]][coord[0]] == 0)
                {
                    pole[coord[1]][coord[0]] = 1;
                    br--;
                    malki--;
                }
                else
                {
                    error = true;
                }
            }
            else if(len == 2 && dvoini>0)
            {
                vector<int> coord = getCoords(coords);

                if(side == "up")
                {
                    for(int i = coord[1]; i<coord[1]+len; i++)
                    {
                        if(coord[1]+len<=pole.size())
                        {
                            if(pole[i][coord[0]] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }
                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]+1][coord[0]] = 1;
                        br--;
                        dvoini--;
                    }
                }
                else if(side == "side")
                {
                    for(int i = coord[0]; i<coord[0]+len; i++)
                    {
                        if(coord[0]+len<=pole[0].size())
                        {
                            if(pole[coord[1]][i] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }

                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]][coord[0]+1] = 1;
                        br--;
                        dvoini--;
                    }
                }
                else
                {
                    error = true;
                }

            }else if(len == 3 && troini>0){

                vector<int> coord = getCoords(coords);

                if(side == "up")
                {
                    for(int i = coord[1]; i<coord[1]+len; i++)
                    {
                        if(coord[1]+len<=pole.size())
                        {
                            if(pole[i][coord[0]] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }
                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]+1][coord[0]] = 1;
                        pole[coord[1]+2][coord[0]] = 1;
                        br--;
                        troini--;
                    }
                }
                else if(side == "side")
                {
                    for(int i = coord[0]; i<coord[0]+len; i++)
                    {
                        if(coord[0]+len<=pole[0].size())
                        {
                            if(pole[coord[1]][i] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }

                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]][coord[0]+1] = 1;
                        pole[coord[1]][coord[0]+2] = 1;
                        br--;
                        troini--;
                    }
                }
                else
                {
                    error = true;
                }

            }else if(len == 4 && golemi>0){


                vector<int> coord = getCoords(coords);

                if(side == "up")
                {
                    for(int i = coord[1]; i<coord[1]+len; i++)
                    {
                        if(coord[1]+len<=pole.size())
                        {
                            if(pole[i][coord[0]] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }
                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]+1][coord[0]] = 1;
                        pole[coord[1]+2][coord[0]] = 1;
                        pole[coord[1]+3][coord[0]] = 1;
                        br--;
                        golemi--;
                    }
                }
                else if(side == "side")
                {
                    for(int i = coord[0]; i<coord[0]+len; i++)
                    {
                        if(coord[0]+len<=pole[0].size())
                        {
                            if(pole[coord[1]][i] == 1)
                            {
                                error = true;
                            }
                        }
                        else
                        {
                            error = true;
                        }
                    }

                    if(!error){
                        pole[coord[1]][coord[0]] = 1;
                        pole[coord[1]][coord[0]+1] = 1;
                        pole[coord[1]][coord[0]+2] = 1;
                        pole[coord[1]][coord[0]+3] = 1;
                        br--;
                        golemi--;
                    }
                }
                else
                {
                    error = true;
                }


            }
            if(!error)
            {
                showPole();
            }
            else
            {
                cout<<"Incorect input! Try again: "<<endl;
            }

            error = false;
        }
    }
};


