#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N = 1000, J = 25;
    int l = 0, n;
    string line;
    long long int vect[N], minn, maxn, sum;
    ifstream adv9("advent9.txt");
    if(adv9.is_open()){
        while(getline(adv9, line)) {
            vect[l] = stoll(line);
            l++;
        }
        adv9.close();
    }
    bool flag;
    for(int i = J; i < N; i++){
        flag = true;
        for(int k = i - J; k < J + i and flag; k++){
            for(int h = k; h < J + i and flag; h++){
                if(vect[k] + vect[h] == vect[i]){
                    flag = false;
                }
            }
        }
        if(flag){
            n = i;
            cout << "p1: " << vect[n] << endl;
            break;
        }
    }
    for(int u = 0; u < n; u++){
        maxn = vect[u];
        minn = vect[u];
        sum = vect[u];
        for(int v = u + 1; v < n; v++){
            if(vect[v] > maxn){
                maxn = vect[v];
            } else if(vect[v] < minn){
                minn = vect[v];
            }
            sum += vect[v];
            if(sum == vect[n]){
                cout << "p2: " << maxn + minn;
                return 0;
            }
        }
    }
}
