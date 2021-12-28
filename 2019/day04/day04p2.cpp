#include <iostream>

using namespace std;

int main(){
    const int minin = 372037, maxin = 905157;
    int dig[6], k = 0;
    for(int i = minin; i <= maxin; ++i){
        int tmp = i;
        bool adj = false;
        for(int n = 5; n >= 0; --n){
            dig[n] = tmp % 10;
            tmp /= 10;
        }
        int j = 4;
        for(; j >= 0; --j){
            if(dig[j] > dig[j + 1]){
                break;
            } else if(j == 4 and dig[4] == dig[5] and dig[3] != dig[4] or
                      dig[j] == dig[j + 1] and dig[j + 2] != dig[j] and dig[j - 1] != dig[j]){
                adj = true;
            }
        }
        if(j == -1 and adj){
            ++k;
        }
    }
    cout << k;
    return 0;
}

