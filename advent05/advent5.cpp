#include <iostream>
#include <fstream>

using namespace std;

const int A = 0, B = 127, C = 0, D = 7, N = 839;

int find_row(string seat){
    int a = A, b = B;
    for(int i = 0; i < seat.length() - 3; i++){
		if(seat.substr(i, 1) == "F"){
			b = (b + a) / 2;
		} else {
			a = (b + a) / 2 + 1;
		}
	}
	return a;
}

int find_col(string seat){
    int c = C, d = D;
    for(int i = 7; i < seat.length(); i++){
		if(seat.substr(i, 1) == "L"){
			d = (d + c) / 2;
		} else {
			c = (d + c) / 2 + 1;
		}
	}
	return c;
}

int main(){
    int l = 0;
    string line, seats[N];
    int col[N], row[N];
    ifstream adv5("advent5.txt");
    if(adv5.is_open()){
        while(getline(adv5, line)){
            seats[l] = line;
            col[l] = find_col(seats[l]);
            row[l] = find_row(seats[l]);
            l++;
        }
        adv5.close();
    }
    bool flag;
    for(int r = 1; r <= B; r++){
        cout << r << "\t";
        for(int k = 1; k <= D; k++){
            flag = false;
            for(int i = 0; i < N; i++){
                if(col[i] == k and row[i] == r){
                    cout << ".";
                    flag = true;
                }
            }
            if(not flag){
                cout << "_";
            }
        }
        cout << endl;
    }
    return 0;
}
