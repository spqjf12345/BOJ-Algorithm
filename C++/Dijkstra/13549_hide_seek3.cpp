//
//  13549_hide_seek3.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//


#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int N, K;
int moving[3] = { - 1, 1, 2}; //walk, jump

int d[100001]; // 최단 시간 테이블
int n_now; // 다음 위치
int n_t; // 다음 위치시의 시간

void hide_seek_minTime() {
    priority_queue<pair<int, int>> pq; //시간, 위치
    pq.push({0, N});
    d[N] = 0;
    
    while(!pq.empty()){
        int t = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < 3; i++){
            if(i == 2) {
                n_now = moving[i] * now;
                n_t = t;
            }else {
                n_now = moving[i] + now;
                n_t = t + 1;
            }
            
            if(n_now < 0 || n_now > 100000) continue; // 범위
            
            if(d[n_now] == -1 || d[n_now] > n_t) { // 가지 않은 길 or 더 시간 적다면
                d[n_now] = n_t;
                pq.push({-n_t, n_now});
            }
        }
        
    }
    
}

int main(){
    cin >> N >> K;
    memset(d, -1, sizeof(d));
    
    hide_seek_minTime();
    cout << d[K] << '\n'; // K위치까지 업데이트된 시간
    return 0;
}
