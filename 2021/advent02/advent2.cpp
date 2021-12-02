#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    string line;
    vector<string> cmd;
    vector<int> val;
    ifstream adv2("advent2.txt");
    if(adv2.is_open()){
        while(getline(adv2, line)){
            val.push_back(stoi(line.substr(line.size() - 1, 1)));
            cmd.push_back(line.substr(0, line.size()- 2));
        }
        adv2.close();
    }
    int hor_pos = 0, dep = 0;
    for(int i = 0; i < val.size(); ++i){
        if(cmd[i] == "up"){
            dep -= val[i];
        } else if(cmd[i] == "down"){
            dep += val[i];
        } else {
            hor_pos += val[i];
        }
    }
    cout << "part 1: " << dep * hor_pos << endl;
    hor_pos = 0, dep = 0;
    int aim = 0;
    for(int j = 0; j < val.size(); ++j){
        if(cmd[j] == "up"){
            aim -= val[j];
        } else if(cmd[j] == "down"){
            aim += val[j];
        } else {
            hor_pos += val[j];
            dep += aim * val[j];
        }
    }
    cout << "part 2: " << dep * hor_pos;
    return 0;
}
