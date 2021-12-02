#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    vector<int> vect;
    int k = 0, p = 0;
    string line;
    ifstream adv1("advent1.txt");
    if(adv1.is_open()){
        while(getline(adv1, line)){
            vect.push_back(stoi(line));
        }
        adv1.close();
    }
    for(int i = 0; i < vect.size() - 1; ++i){
       if(vect[i + 1] > vect[i]){
            ++k;
       }
    }
    cout << "part 1: " << k << endl;
    for(int j = 0; j < vect.size() - 3; ++j){
        if(vect[j + 3] > vect[j]){
            ++p;
        }
    }
    cout << "part 2: " << p;
    return 0;
}
