//
//  7579_app.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/20.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int N;
int need_Memory;
int app[101];
int extra[101];
int weight, value;
int dp[10001]; // j 비용 소모해 얻을 수 있는 최대 메모리
int sum = 0; //최대 비용

//일정 메모리를 60 이상 확보해도 된다.
int knap_sack_app(int N, int memory){
    for(int i = 0; i < N; i++){
        for(int j = sum; j >= extra[i]; j--){
            if(j - extra[i] >= 0){
                dp[j] = max(dp[j], dp[j - extra[i]] + app[i]);
            }
        }
    }
    int ans;
    for (int i = 0; ; i++) {
        if(dp[i] >= memory){
            ans = i;
            break;
        }
        
    }
    return ans;
    
}

int main(){
    cin >> N >> need_Memory;
    for(int i= 0; i < N; i++){
        cin >> app[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> extra[i];
        sum += extra[i];
    }
    
    cout << knap_sack_app(N, need_Memory) << '\n';
    
    return 0;
}
