#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    const int OUTPUT = 19690720, MININPUT = 0, MAXINPUT = 99;
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
    for(int noun = MININPUT; noun <= MAXINPUT; ++noun){
        for(int verb = MININPUT; verb <= MAXINPUT; ++verb){
            k = 0;
            vector<int> temp(nump);
            temp[1] = noun, temp[2] = verb;
            bool flag = true;
            while(flag){
                flag = true;
                switch(temp[k]){
                    case 1: temp[temp[k + 3]] = temp[temp[k + 1]] + temp[temp[k + 2]]; break;
                    case 2: temp[temp[k + 3]] = temp[temp[k + 1]] * temp[temp[k + 2]]; break;
                    case 99: flag = false; break;
                }
                k += 4;
            }
            if(temp[0] == OUTPUT){
               cout << 100 * noun + verb;
               return 0;
            }
        }
    }
}
