//
//  12865_re_back.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/20.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int N, capacity;
int weight[100001];
int value[1001];
int dp[101][1001];
int Max(int A, int B) { if (A > B) return A; return B; }


// 가져갈 수 있을 때 가져가기, 가져 가지 않을 때
int knap_sack(int pos, int capacity){
    if(pos == N) return 0;
    int result = dp[pos][capacity];
       
    if(pos > N) return dp[pos][capacity];
    if(result != -1) return result;

    if(weight[pos] <= capacity){ // 가져갈 수 있을 때
        result = knap_sack(pos + 1, capacity - weight[pos]) + value[pos];
    }
    result = Max(result, knap_sack(pos + 1, capacity));
    dp[pos][capacity] = result;
    return dp[pos][capacity];
}

int main(){
    cin >> N >> capacity;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++){
        cin >> weight[i] >> value[i];
    }
    
    cout << knap_sack(0, capacity) << '\n';
    return 0;
}
