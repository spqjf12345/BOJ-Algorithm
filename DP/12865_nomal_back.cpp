//
//  12865_nomal_back.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/03/09.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
//DP - KnapSack

int dp[101][100001]; // i번째 물건까지 사용하여 k 용량의 가방에 물건 채울때까지 최대 가치
int weight[101]; //W - i 번째 물건의 무게
int value[101]; //V - i 번째 물건의 가치


int N, capacity;

//i 번째 물건 담은 경우 d[i-1][j-W[i]] + V[i]
//담지 않은 경우 d[i-1][j]
//모둔 j에 대해 max 찾기

void find_max_value(int N, int capacity){
    for(int i = 1; i <= N; i++){ // 배낭 물건 돌기
        for(int j = 1; j <= capacity; j++){
            dp[i][j] = dp[i-1][j];
            if(j - weight[i] >= 0){ //무게가 남아서 돌 수 있을 때
                cout << "j : " << j << " " << "weight : " << weight[i] << '\n';
                dp[i][j] = max(dp[i][j], dp[i-1][j - weight[i]] + value[i]);
                
            }
        }
        
    }
    cout << dp[N][capacity] << '\n';
}


int main(){
    cin >> N >> capacity;
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }
    
    find_max_value(N, capacity);
    return 0;
}

