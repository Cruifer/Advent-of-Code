#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    const int N = 786;
    int l = 0, x = 0, y = 0, a = 0, nums[N];
    fstream adv12("advent12.txt");
    string line;
    char c[N];
    if(adv12.is_open()){
        while(getline(adv12, line)){
                nums[l] = stoi(line.substr(1, line.length()));
                c[l] = line[0];
                switch(c[l]){
                    case 'N': y += nums[l]; break;
                    case 'S': y -= nums[l]; break;
                    case 'E': x += nums[l]; break;
                    case 'W': x -= nums[l]; break;
                    case 'R': a -= nums[l]; break;
                    case 'L': a += nums[l]; break;
                    default : x += (int) cos(a * M_PI / 180) * nums[l];
                              y += (int) sin(a * M_PI / 180) * nums[l];
                              break;
                }
                l++;
        }
        adv12.close();
    }
    cout << "p1: " << abs(x) + abs(y);
    int xw = 10, yw = 1, temp;
    x = 0, y = 0;
    for(int k = 0; k < N; k++){
        switch(c[k]){
            case 'N': yw += nums[k]; break;
            case 'S': yw -= nums[k]; break;
            case 'E': xw += nums[k]; break;
            case 'W': xw -= nums[k]; break;
            case 'R': temp = xw;
                      xw = xw * (int) cos(nums[k] * M_PI / -180) - yw * (int) sin(nums[k] * M_PI / -180);
                      yw = temp * (int) sin(nums[k] * M_PI / -180) + yw * (int) cos(nums[k] * M_PI / -180);
                      break;
            case 'L': temp = xw;
                      xw = xw * (int) cos(nums[k] * M_PI / 180) - yw * (int) sin(nums[k] * M_PI / 180);
                      yw = temp * (int) sin(nums[k] * M_PI / 180) + yw * (int) cos(nums[k] * M_PI / 180);
                      break;
            default : x += xw * nums[k];
                      y += yw * nums[k];
                      break;
        }
    }
    cout << endl << "p2: " << abs(x) + abs(y);
    return 0;
}
