#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    vector<int> nump;
    string line;
    int tmp, k = 0;
    ifstream d2("day02.txt");
    if(d2.is_open()){
        getline(d2, line);
        d2.close();
    }
    replace(line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    while(ss >> tmp){
        nump.push_back(tmp);
    }
    nump[1] = 12, nump[2] = 2;
    while(true){
        switch(nump[k]){
            case 1: nump[nump[k + 3]] = nump[nump[k + 1]] + nump[nump[k + 2]]; break;
            case 2: nump[nump[k + 3]] = nump[nump[k + 1]] * nump[nump[k + 2]]; break;
            case 99: cout << nump[0]; return 0;
        }
        k += 4;
    }
}
