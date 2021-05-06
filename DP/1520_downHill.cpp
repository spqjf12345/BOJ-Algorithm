//
//  1520_downHill.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/05.
//

#include <stdio.h>
#include <iostream>
//#include <queue>
#include <string.h>


using namespace std;
int arr[501][501];
int n, m;
int dp[501][501];

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };


int find_route(int i, int j){
    
    if(i == n -1 && j == m -1) return 1;
    int memo = dp[i][j]; //memozation
    if(memo != -1) return memo;
    memo = 0;
    for(int s = 0; s < 4; s++){
        int nx = i + dx[s];
        int ny = j + dy[s];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(arr[nx][ny] >= arr[i][j]) continue;
        memo += find_route(nx, ny);
    }
    
    return memo;
    
}

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << find_route(0, 0) << '\n';
    
//    for(int i = 0; i < n; i++){
//        for(int j= 0; j < m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    return 0;
}
