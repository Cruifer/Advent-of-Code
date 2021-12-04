#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int bin_to_dec(string bin){
    int dec = 0;
    for(int t = 0; t < bin.size(); ++t){
        dec += stoi(bin.substr(bin.size() - t - 1, 1)) * pow(2, t);
    }
    return dec;
}

bool one_most_comm(vector<string> vect, int p){
    int k = 0;
    for(int j = 0; j < vect.size(); ++j){
        if(vect[j].substr(p, 1) == "1"){
            ++k;
        }
    }
    if(k == vect.size() / 2.0){
        ++k;
    }
    return k > vect.size() / 2.0;
}

int main(){
    string line;
    vector<string> report;
    ifstream adv3("advent3.txt");
    if(adv3.is_open()){
        while(getline(adv3, line)){
            report.push_back(line);
        }
        adv3.close();
    }
    string gamma = "", epsilon = "";
    for(int i = 0; i < line.size(); ++i){
        if(one_most_comm(report, i)){
            gamma.push_back('1');
            epsilon.push_back('0');
        } else {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }
    cout << "part 1: " << bin_to_dec(gamma) * bin_to_dec(epsilon) << endl;
    vector<string> oxy_cand = report;
    for(int n = 0; n < line.size(); ++n){
        if(one_most_comm(oxy_cand, n)){
            for(int a = 0; a < oxy_cand.size(); ++a){
                if(oxy_cand[a].substr(n, 1) == "0"){
                    oxy_cand.erase(oxy_cand.begin() + a);
                    --a;
                }
            }
        } else {
            for(int b = 0; b < oxy_cand.size(); ++b){
                if(oxy_cand[b].substr(n, 1) == "1"){
                    oxy_cand.erase(oxy_cand.begin() + b);
                    --b;
                }
            }
        }
    }
    vector<string> co2_cand = report;
    for(int m = 0; m < line.size(); ++m){
        if(one_most_comm(co2_cand, m)){
            for(int c = 0; c < co2_cand.size(); ++c){
                if(co2_cand[c].substr(m, 1) == "1"){
                    co2_cand.erase(co2_cand.begin() + c);
                    --c;
                }
            }
        } else {
            for(int d = 0; d < co2_cand.size(); ++d){
                if(co2_cand[d].substr(m, 1) == "0"){
                    co2_cand.erase(co2_cand.begin() + d);
                    --d;
                }
            }
        }
    }
    cout << "part 2: " << bin_to_dec(co2_cand[0]) * bin_to_dec(oxy_cand[0]);
    return 0;
}
