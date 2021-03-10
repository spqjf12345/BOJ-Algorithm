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

int d[101][100001]; // i번째 물건까지 사용하여 k 용량의 가방에 물건 채울때까지 최대 가치
int W[101]; //W - i 번째 물건의 무게
int V[101]; //V - i 번째 물건의 가치


int N, K;

//i 번째 물건 담은 경우 d[i-1][j-W[i]] + V[i]
//담지 않은 경우 d[i-1][j]
//모둔 j에 대해 max 찾기

void find_max_value(int N, int K){
   
    for(int i = 1; i <= N; i++){ // 배낭 물건 돌기
        for(int j = 1; j <= K; j++){
            d[i][j] = d[i-1][j];
            if(j - W[i] >= 0){ //무게가 남아서 돌 수 있을 때
                d[i][j] = max(d[i][j], d[i-1][j - W[i]] + V[i]);
                
            }
        }
        
    }
    cout << d[N][K] << '\n';
}


int main(){
            
    scanf("%d %d", &N, &K);
    memset(d, 0, sizeof(d));
    
    for(int i = 1; i <= N; i++){
        int weight, value;
        scanf("%d %d", &weight, &value);
        W[i] = weight;
        V[i] = value;
        
    }
    
    find_max_value(N, K);
    return 0;
}
