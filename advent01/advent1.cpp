#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N = 200;
    int a, b, c, l = 0;
    string line;
    int vect[N];
    ifstream myfile ("advent1.txt");
    if(myfile.is_open()){
        while(getline(myfile, line)) {
            vect[l] = stoi(line);
            l++;
        }
    myfile.close();
    }
    for(int k = 0; k < N; k++){
        for(int j = k; j < N; j++){
            for(int i = j; i < N; i++)
            if(vect[k] + vect[j] + vect[i] == 2020){
                cout << vect[k] * vect[j] * vect[i];
                return 0;
            }
        }
    }
}
