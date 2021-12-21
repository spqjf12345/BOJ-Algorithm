//
//  2098_tsp.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/21.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

const int MAX = 1987654321;

using namespace std;

int n;
int dp[16][1<<16]; // now node를 시작으로 했을때 A = {() - now} 배열에 있는 노드 방문시의 최소값
int W[16][16]; // 비용 배열

int TSP(int now, int visited){
    
    int &ret = dp[now][visited];
    if(ret != -1) { // 값을 구해 놓았다면
        return ret;
    }
    
    if(visited == (1 << n) - 1) {  //모든 마을 방문시 n == 4 -> 0 ~ 15 -> 4개의 마을
        if(W[now][0] != 0) { // 0번 노드로 돌아갈수 있다면
            return W[now][0];
        }
        return MAX;
        
    }
    
    ret = MAX;
    
    for(int i = 0; i < n; i++){
        if(visited & (1 << i) || W[now][i] == 0) { continue; } // 방문했거나, 자기 자신일 경우
        ret = min(ret, W[now][i] + TSP(i, visited | (1 << i)));
    }
    return ret;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof((dp)));
    
    cout << TSP(0, 1) << '\n';
    return 0;
}
