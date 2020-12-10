#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N = 1000;
    int n = 0, l = 0, firstn[N], secondn[N];
    string line, lett[N], pass[N];
    ifstream myfile("advent2.txt");
    if(myfile.is_open()){
        while(getline(myfile, line)) {
            firstn[l] = stoi(line);
            line.erase(0, to_string(firstn[l]).length() + 1);
            secondn[l] = stoi(line);
            line.erase(0, to_string(secondn[l]).length() + 1);
            lett[l] = line.substr(0, 1);
            line.erase(0, lett[l].length() + 2);
            pass[l] = line;
            l++;
        }
        myfile.close();
    }
    for(int i = 0; i < N; i++){
        if(pass[i].substr(firstn[i] - 1, 1) == lett[i] xor pass[i].substr(secondn[i] - 1, 1) == lett[i]){
            n++;
        }
    }
    cout << n;
    return 0;
}
