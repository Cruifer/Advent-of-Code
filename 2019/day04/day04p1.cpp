#include <iostream>

using namespace std;

int main(){
    const int minin = 372037, maxin = 905157;
    int dig[6], k = 0, j;
    for(int i = minin; i <= maxin; ++i){
        int tmp = i;
        dig[5] = i % 10;
        tmp /= 10;
        bool adj = false;
        for(j = 4; j >= 0; --j){
            dig[j] = tmp % 10;
            tmp /= 10;
            if(dig[j] == dig[j + 1]){
                adj = true;
            } else if(dig[j] > dig[j + 1]){
                break;
            }
        }
        if(j == -1 and adj){
            ++k;
        }
    }
    cout << k;
    return 0;
}
