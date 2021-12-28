#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

struct Wire_Seg{
    int xa, xb, ya, yb;
};

int main(){
    vector<Wire_Seg> vert, oriz;
    vector<int> cross;
    string line, tmp;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x, y;
    ifstream d3("day03.txt");
    if(d3.is_open()){
        getline(d3, line);
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        while(ss >> tmp){
            switch(tmp[0]){
                case 'R': {
                    x = stoi(tmp.substr(1, tmp.length() - 1));
                    struct Wire_Seg seg = {x1, x1 + x, y1, y1};
                    oriz.push_back(seg);
                    } x1 += x; break;
                case 'L': {
                    x = stoi(tmp.substr(1, tmp.length() - 1));
                    struct Wire_Seg seg = {x1 - x, x1, y1, y1};
                    oriz.push_back(seg);
                    } x1 -= x; break;
                case 'U': {
                    y = stoi(tmp.substr(1, tmp.length() - 1));
                    struct Wire_Seg seg = {x1, x1, y1, y1 + y};
                    vert.push_back(seg);
                    } y1 += y; break;
                case 'D': {
                    y = stoi(tmp.substr(1, tmp.length() - 1));
                    struct Wire_Seg seg = {x1, x1, y1 - y, y1};
                    vert.push_back(seg);
                    } y1 -= y; break;
            }
        }
        getline(d3, line);
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss2(line);
        while(ss2 >> tmp){
            switch(tmp[0]){
                case 'R': {
                    x = stoi(tmp.substr(1, tmp.length() - 1));
                    for(Wire_Seg i : vert){
                        if(i.xa > x2 and i.xa < x2 + x and y2 > i.ya and y2 < i.yb ){
                            cross.push_back(abs(i.xa) + abs(y2));
                        }
                    }
                    } x2 += x; break;
                case 'L': {
                    x = stoi(tmp.substr(1, tmp.length() - 1));
                    for(Wire_Seg i : vert){
                        if(i.xa > x2 - x and i.xa < x2 and y2 > i.ya and y2 < i.yb ){
                            cross.push_back(abs(i.xa) + abs(y2));
                        }
                    }
                    } x2 -= x; break;
                case 'U': {
                    y = stoi(tmp.substr(1, tmp.length() - 1));
                    for(Wire_Seg i : oriz){
                        if(x2 > i.xa and x2 < i.xb and y2 + y > i.ya and y2 < i.ya){
                            cross.push_back(abs(x2) + abs(i.ya));
                        }
                    }
                    } y2 += y; break;
            case 'D': {
                y = stoi(tmp.substr(1, tmp.length() - 1));
                for(Wire_Seg i : oriz){
                    if(x2 > i.xa and x2 < i.xb and y2 > i.ya and y2 - y < i.ya){
                        cross.push_back(abs(x2) + abs(i.ya));
                    }
                }
                } y2 -= y; break;
            }
        }
        d3.close();
    }
    cout << *min_element(cross.begin(), cross.end());
    return 0;
}
