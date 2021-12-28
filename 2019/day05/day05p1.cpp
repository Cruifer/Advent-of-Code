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
    int k = 0, input = 1, output;
    while(true){
        switch(nump[k]){
            case 1   : nump[nump[k + 3]] = nump[nump[k + 1]] + nump[nump[k + 2]]; k += 4; break;
            case 101 : nump[nump[k + 3]] = nump[k + 1]       + nump[nump[k + 2]]; k += 4; break;
            case 1001: nump[nump[k + 3]] = nump[nump[k + 1]] + nump[k + 2];       k += 4; break;
            case 1101: nump[nump[k + 3]] = nump[k + 1]       + nump[k + 2];       k += 4; break;
            case 2   : nump[nump[k + 3]] = nump[nump[k + 1]] * nump[nump[k + 2]]; k += 4; break;
            case 102 : nump[nump[k + 3]] = nump[k + 1]       * nump[nump[k + 2]]; k += 4; break;
            case 1002: nump[nump[k + 3]] = nump[nump[k + 1]] * nump[k + 2];       k += 4; break;
            case 1102: nump[nump[k + 3]] = nump[k + 1]       * nump[k + 2];       k += 4; break;
            case 3   : nump[nump[k + 1]] = input;                                 k += 2; break;
            case 4   : output            = nump[nump[k + 1]];                     k += 2; break;
            case 104 : output            = nump[k + 1];                           k += 2; break;
            case 99  : cout << output;                                                 return 0;
        }
    }
}

