#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int H = 6, L = 25, D = H * L;
    string line;
    ifstream d8("day08.txt");
    if(d8.is_open()){
        getline(d8, line);
        d8.close();
    }
    const int N = line.length() / D;
    string layers[N], res;
    for(int i = 0; i < N; ++i){
        layers[i] = line.substr(i * D, D);
    }
    for(int j = 0; j < D; ++j){
        for(int m = 0; m < N; ++m){
            char pixel = layers[m][j];
            if(pixel != '2'){
                if(pixel == '0'){
                    res.append(1, ' ');
                } else {
                    res.append(1, '#');
                }
                break;
            }
        }
    }
    for(int h = 0; h < H; h++){
        cout << res.substr(h * L, L) << endl;
    }
    return 0;
}

