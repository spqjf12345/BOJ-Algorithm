//
//  n-queen.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int N;
int result = 0;
int col[16];

bool check(int level){
    for(int i = 0; i <level; i++){ // X-A = Y-B (대각선 검사)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i){
            return false;
        }
    }
    return true;
}

void nqueen(int x){
    if(x == N){
        result++;
    }else {
        for(int i = 0; i < N; i++){
            col[x] = i; /// 퀸 배치
            if(check(x)){ /// 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
                nqueen(x+1);
            }
            ///유효하지 않다면 반복문을 통해 퀸 재배치 
        }
    }
}
int main(){
    cin >> N;
    nqueen(0);
    cout << result << '\n';
    return 0;
}
