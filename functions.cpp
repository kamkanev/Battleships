#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

vector<int> getCoords(string coord){

string Ys;
string Xs;
int X;
int Y;

for(int i=0; i<coord.length(); i++){
    if(coord[i]>='0' && coord[i]<='9'){
        Ys+=coord[i];
    }else if((coord[i]>='A' && coord[i]<='Z') || (coord[i]>='a' && coord[i]<='z')){
        Xs+=coord[i];
    }
}
//cout<<"Test: -----   "<<Xs<<" "<<Ys<<endl;

X = toupper(Xs[0]) - 'A';

//cout<<"TestX: -----   "<<X<<" "<<Ys<<endl;
stringstream ss;

ss<<Ys;
ss>>Y;

//cout<<"TestY: -----   "<<X<<" "<<Y<<endl;

vector<int> coords(2);
coords[0] = X;
coords[1] = Y-1;

//cout<<"TestCoords: -----   "<<coords[0]<<" "<<coords[1]<<endl;

return coords;

}
