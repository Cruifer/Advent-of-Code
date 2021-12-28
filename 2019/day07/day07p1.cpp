#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int intcode(vector<int> nump, int input1, int input2){
    int k = 0, input = input1, output;
    bool flag = true;
    while(true){
        switch(nump[k]){
            case 1   : nump[nump[k + 3]] = nump[nump[k + 1]] + nump[nump[k + 2]];  k += 4; break;
            case 101 : nump[nump[k + 3]] = nump[k + 1]       + nump[nump[k + 2]];  k += 4; break;
            case 1001: nump[nump[k + 3]] = nump[nump[k + 1]] + nump[k + 2];        k += 4; break;
            case 1101: nump[nump[k + 3]] = nump[k + 1]       + nump[k + 2];        k += 4; break;
            case 2   : nump[nump[k + 3]] = nump[nump[k + 1]] * nump[nump[k + 2]];  k += 4; break;
            case 102 : nump[nump[k + 3]] = nump[k + 1]       * nump[nump[k + 2]];  k += 4; break;
            case 1002: nump[nump[k + 3]] = nump[nump[k + 1]] * nump[k + 2];        k += 4; break;
            case 1102: nump[nump[k + 3]] = nump[k + 1]       * nump[k + 2];        k += 4; break;
            case 3   : nump[nump[k + 1]] = input;                                  k += 2; break;
            case 4   : output            = nump[nump[k + 1]];                      k += 2; break;
            case 104 : output            = nump[k + 1];                            k += 2; break;
            case 5   : if(nump[nump[k + 1]] != 0) k = nump[nump[k + 2]];      else k += 3; break;
            case 105 : if(nump[k + 1] != 0)       k = nump[nump[k + 2]];      else k += 3; break;
            case 1005: if(nump[nump[k + 1]] != 0) k = nump[k + 2];            else k += 3; break;
            case 1105: if(nump[k + 1] != 0)       k = nump[k + 2];            else k += 3; break;
            case 6   : if(nump[nump[k + 1]] == 0) k = nump[nump[k + 2]];      else k += 3; break;
            case 106 : if(nump[k + 1] == 0)       k = nump[nump[k + 2]];      else k += 3; break;
            case 1006: if(nump[nump[k + 1]] == 0) k = nump[k + 2];            else k += 3; break;
            case 1106: if(nump[k + 1] == 0)       k = nump[k + 2];            else k += 3; break;
            case 7   : nump[nump[k + 3]] = nump[nump[k + 1]] < nump[nump[k + 2]];  k += 4; break;
            case 107 : nump[nump[k + 3]] = nump[k + 1] < nump[nump[k + 2]];        k += 4; break;
            case 1007: nump[nump[k + 3]] = nump[nump[k + 1]] < nump[k + 2];        k += 4; break;
            case 1107: nump[nump[k + 3]] = nump[k + 1] < nump[k + 2];              k += 4; break;
            case 8   : nump[nump[k + 3]] = nump[nump[k + 1]] == nump[nump[k + 2]]; k += 4; break;
            case 108 : nump[nump[k + 3]] = nump[k + 1] == nump[nump[k + 2]];       k += 4; break;
            case 1008: nump[nump[k + 3]] = nump[nump[k + 1]] == nump[k + 2];       k += 4; break;
            case 1108: nump[nump[k + 3]] = nump[k + 1] == nump[k + 2];             k += 4; break;
            case 99  : return output;
        }
        if(flag){input = input2; flag = false;}
    }
}

int main(){
    vector<int> nump, signals, pos;
    string line;
    int tmp;
    ifstream d7("day07.txt");
    if(d7.is_open()){
        getline(d7, line);
        d7.close();
    }
    replace(line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    while(ss >> tmp){
        nump.push_back(tmp);
    }
    for(int a = 0; a < 5; ++a){
        for(int b = 0; b < 5; ++b){if(b != a){
            for(int c = 0; c < 5; ++c){if(c != b and c != a){
                for(int d = 0; d < 5; ++d){if(d != c and d != b and d != a){
                    for(int e = 0; e < 5; ++e){if(e != d and e != c and e != b and e != a){
                        vector<int> temp = nump;
                        int output_a = intcode(temp, a, 0);
                        temp = nump;
                        int output_b = intcode(temp, b, output_a);
                        temp = nump;
                        int output_c = intcode(temp, c, output_b);
                        temp = nump;
                        int output_d = intcode(temp, d, output_c);
                        temp = nump;
                        signals.push_back(intcode(temp, e, output_d));
                    }}
                }}
            }}
        }}
    }
    cout << *max_element(signals.begin(), signals.end());
    return 0;
}
