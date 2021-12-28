#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string line;
    int fuel, sfuel = 0;
    ifstream d1("day01.txt");
    if(d1.is_open()){
        while(getline(d1, line)){
            fuel = stoi(line) / 3 - 2;
            sfuel += fuel;
            while(fuel / 3 - 2 > 0){
                fuel = fuel / 3 - 2;
                sfuel += fuel;
            }
        }
    }
    cout << sfuel;
    return 0;
}
