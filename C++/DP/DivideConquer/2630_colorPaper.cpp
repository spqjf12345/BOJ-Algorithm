//
//  colorPaper.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/24.
//

#include <iostream>
#include <string.h>

using namespace std;
int map[129][129];
int N;
int w = 0, b = 0;

void make_count(int x, int y, int len){
    //cout << x << " " << y << " " << N << '\n';
    int temp = 0;
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(map[i][j]) { temp++; }
        }
    }
    if (!temp) { // 전체 다 흰색
        w++;
    }else if(temp == len * len) { // 전체 다 블루
        b++;
    }else {
        make_count(x, y, len / 2);
        make_count(x + len/2, y, len / 2);
        make_count(x, y + len/2 , len / 2);
        make_count(x + len/2, y + len/2 , len / 2);
    }
    return;
}

int main(){
    cin >> N;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >>map[i][j];
        }
    }
    
    make_count(0, 0, N);
    cout << w << '\n';
    cout << b << '\n';
    return 0;
}
