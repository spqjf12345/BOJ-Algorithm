//
//  11660_5.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int N, Tcase;
int originalArr[1025][1025];
int sumArr[1025][1025];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Tcase;
    
    // sum 초기화
    for(int i = 0; i <= N; i++){
        sumArr[i][0] = sumArr[0][i] = 0;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> originalArr[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        sumArr[1][i] = originalArr[1][i] + sumArr[1][i-1];
        sumArr[i][1] = originalArr[i][1] + sumArr[i-1][1];
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 2; j<=N; j++){
            //구간합, 구간합, 새로운 값, 중복되는 부분 제거
            sumArr[i][j] = sumArr[i-1][j] + sumArr[i][j-1] + originalArr[i][j] - sumArr[i-1][j-1];
        }
    }
    
//
//    for(int i = 1; i <= N; i++){
//        for(int j = 1; j<=N; j++){
//            cout << sumArr[i][j] << " ";
//        }
//        cout << '\n';
//    }
//
    for(int i = 0; i < Tcase; i++){
        pair<int, int> start; pair<int, int> end;
        cin >> start.first >> start.second >> end.first >> end.second;
        int ret = sumArr[end.first][end.second] - sumArr[start.first -1][end.second] - sumArr[end.first][start.second -1] + sumArr[start.first -1][start.second -1];
        cout << ret << '\n';
    }
    
    
    return 0;
}
