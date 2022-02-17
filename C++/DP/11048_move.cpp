//
//  11048_move.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N, M;
int arr[1001][1001];
int dp[1001][1001]; // i, j 까지 이동시 얻을 수 있는 사탕 최대 값

int dy[] = { 1, 0, 1 }; // down, right, digonal
int dx[] = { 0, 1, 1 }; //down left right

//bottom up
void move_dp(){
    dp[0][1] = dp[0][0] + arr[0][1];
    dp[1][0] = dp[0][0] + arr[1][0];
    for(int i = 1; i < N; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    
    for(int j = 1; j < M; j++){
        dp[0][j] = dp[0][j-1] + arr[0][j];
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + arr[i][j];
            //cout << "dp[" << i << "][" << j<< "] " << dp[i][j] << " ";
        }
        //cout << '\n';
    }
}

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> N >> M;
    for(int i =0; i < N; i ++){
        for(int j =0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    move_dp();
    cout << dp[N-1][M-1] << '\n';;
    return 0;
}
