#include <iostream>
#include <fstream>

using namespace std;

int digits(int n){
    int k = 1;
    while(n >= 10){
        n /= 10;
        k++;
    }
    return k;
}

int main(){
    const int N = 1000;
    int n = 0, firstn, secondn;
    string line, lett, pass;
    ifstream adv2("advent2.txt");
    if(adv2.is_open()){
        while(getline(adv2, line)) {
            firstn = stoi(line);
            line.erase(0, digits(firstn) + 1);
            secondn = stoi(line);
            line.erase(0, digits(secondn) + 1);
            lett = line.substr(0, 1);
            line.erase(0, 3);
            pass = line;
            if(pass.substr(firstn - 1, 1) == lett xor pass.substr(secondn - 1, 1) == lett){
                n++;
            }
        }
        adv2.close();
    }
    cout << n;
    return 0;
}
