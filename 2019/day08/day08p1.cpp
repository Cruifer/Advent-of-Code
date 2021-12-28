#include <iostream>
#include <fstream>
//#include <algorithm> // implementare COUNT e min

using namespace std;

int main(){
    const int H = 6, L = 25;
    string line;
    ifstream d8("day08.txt");
    if(d8.is_open()){
        getline(d8, line);
        d8.close();
    }
    const int N = line.length() / (H * L);
    string layers[N];
    layers[0] = line.substr(0, H * L);
    int k = 0;
    for(int j = 0; j < H * L; ++j){
        if(layers[0][j] == '0'){
            ++k;
        }
    }
    int nmin = k, imin = 0;
    for(int i = 1; i < N; ++i){
        k = 0;
        layers[i] = line.substr(i * H * L, H * L);
        for(int j = 0; j < H * L; ++j){
            if(layers[i][j] == '0'){
                ++k;
            }
        }
        if(k < nmin){
            nmin = k;
            imin = i;
        }
    }
    int cont = 0;
    for(int h = 0; h < layers[imin].length(); ++h){
        if(layers[imin][h] == '2'){
            ++cont;
        }
    }
    cout << cont * (H * L - cont - nmin);
    return 0;
}
