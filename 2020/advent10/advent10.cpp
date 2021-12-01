#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    const int N = 93;
    int l = 1, vect[N + 1], t1 = 0, t3 = 1;
    long long int seq[N + 1];
    fstream adv10("advent10.txt");
    string line;
    vect[0] = 0;
    if(adv10.is_open()){
        while(getline(adv10, line)){
            vect[l] = stoi(line);
            l++;
        }
        adv10.close();
    }
    sort(&vect[0], &vect[N + 1]);
    for(int h = 0; h < N; h++){
        if(vect[h + 1] - vect[h] == 1){
            t1++;
        } else if(vect[h + 1] - vect[h] == 3){
            t3++;
        }
    }
    cout << "p1: " << t1 * t3;
    seq[0] = 1;
    seq[1] = 1;
    for(int i = 2; i <= N + 1; i++){
        seq[i] = seq[i - 1];
        if(vect[i] - vect[i - 2] == 2){
            seq[i] += seq[i - 2];
            if(vect[i - 2] != 0 and vect[i] - vect[i - 3] == 3){
                seq[i] += seq[i - 3];
            }
        }
    }
    cout << endl << "p2: " << seq[N + 1];
    return 0;
}
