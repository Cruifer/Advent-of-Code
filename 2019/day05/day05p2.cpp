#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    vector<int> nump;
    string line;
    int tmp;
    ifstream d5("day05.txt");
    if(d5.is_open()){
        getline(d5, line);
        d5.close();
    }
    replace(line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    while(ss >> tmp){
        nump.push_back(tmp);
    }
    int k = 0, input = 5, output;
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
            case 99  : cout << output;                                                  return 0;
        }
    }
}


