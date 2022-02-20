//
//  15650(2).cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int N, M;
int answer[10];
//조합
void make_backTracking(int level, int num){
    if(level == M){
        for(int i = 0; i < M; i++){
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = num; i <= N; i++){
        answer[level] = i;
        make_backTracking(level + 1, i + 1);
    }
}

int main(){
    cin >> N >> M;
    make_backTracking(0, 1);
    return 0;
}
