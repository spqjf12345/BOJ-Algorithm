//
//  11404_floyd.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/28.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int busCount;
int bus[101][101];
#define INF 10000001

void floyd(){
    int dp[N+1][N+1]; // 결과 배열
    //원본 bus 배열 copy
    for (int i = 1; i<= N; i++) {
        for(int j = 1; j <= N; j++){
            dp[i][j] = bus[i][j];
        }
    }
// 잘 들어갔나 확인용
//    for (int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    
    //k 거쳐가는 노드
    for(int k = 1; k <= N; k++){
        //i 출발 노드
        for(int i = 1; i <= N; i++){
            //j 도착 노드
            for(int j = 1; j <= N; j++){
                
                if(dp[i][k] + dp[k][j] < dp[i][j] ){ //거쳐 가는 길 있으면
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    
        for (int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++){
                if(dp[i][j] == INF){
                    dp[i][j] = 0; //그래도 길이 없는 길이면
                }
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
}

int main(){
    cin >> N;
    cin >> busCount;
    
    //bus 무한대로 초기화
    for (int i = 1; i<= N; i++) {
        for(int j = 1; j <= N; j++){
            bus[i][j] = INF;
        }
    }
    
    //가운데 0으로 초기화
    for (int i = 1; i<= N; i++) {
        bus[i][i] = 0;
    }
    
    for (int i = 1; i<= busCount; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        //작은 값만 push
        if(bus[start][end] != 0 && bus[start][end] != INF){
            int temp = bus[start][end];
            cost = min(cost, temp);
        }
        
        bus[start][end] = cost;
        
        
        
    }
    
    floyd();
    return 0;
}
