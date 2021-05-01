//
//  1937_selfishPanda.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[501][501];
int N;
int dp[501][501];

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

int find_max_life(int i, int j){
    if(dp[i][j] > 0){
        //cout << "here " << dp[i][j] << '\n';
        return dp[i][j];
    }
    
    dp[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int nextX = i + dx[k];
        int nextY = j + dy[k];
        //cout << "next 1 " << nextX << " " << nextY<< '\n';
        //예외처리
        if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
        if(arr[i][j] >= arr[nextX][nextY]) continue;
        //기존 값과 다음 먹이 찾으러 움직였을때 중의 최대값
        //cout << "next 2 " << nextX << " " << nextY<< '\n';
        dp[i][j] = max(dp[i][j], find_max_life(nextX, nextY) + 1);
    }
    
    //cout << "here2 : " << dp[i][j] << '\n';
    return dp[i][j];
}

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            dp[i][j] = 0;
        }
    }
//input 확인용
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < N; j++){
//            cout << arr[i][j] << " ";
//        }
//        cout << '\n';
//    }
    
    int maxRice = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //cout << "i j is " << i << " " << j << " ->" << find_max_life(i, j) << '\n';
           maxRice = max(maxRice, find_max_life(i, j));
        }
        cout << '\n';
    }
    
    cout << maxRice <<'\n';
    
  
    return 0;
}
