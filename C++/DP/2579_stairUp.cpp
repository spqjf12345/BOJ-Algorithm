//
//  2579_stairUp.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/13.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int Tcase;
int stairArr[301] = {0, };
int d[10001] = {0, };

int find_best_DP(){
    int answer = 0;
    d[0] = stairArr[0];
    d[1] = stairArr[0] + stairArr[1];
    d[2] = max(stairArr[0], stairArr[1]) + stairArr[2];
    
    for(int i = 3; i < Tcase; i++){
        //전전전 계단까지 최대 값 + 전 계단 + 마지막 계단, 전전 계단까지의 최대 값 + 전 계단
        d[i] = max(d[i - 3] + stairArr[i - 1] + stairArr[i], d[i - 2] + stairArr[i]);
    }
    answer = d[Tcase - 1];
    return answer;
}

int main(){
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        cin >> stairArr[i];
    }
    
    cout << find_best_DP() << '\n';
    return 0;
}
