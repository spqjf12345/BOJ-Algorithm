//
//  10844_easyStair.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/23.
//

#include <iostream>
#define mod 1000000000

using namespace std;
int N, sum = 0;
int dp[101][10]; // 길이가 N이고 마지막 수 i가 올때 다음 올 수


int main(){
    cin >> N;
    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
    
    for(int k = 2; k <= N; k++){
        for(int i = 0; i < 10; i++){
            if(i == 0) {
                dp[k][0] = dp[k-1][1]; // 1만 올 수 있다.
            }else if(i == 9){
                dp[k][9] = dp[k-1][8];
            }else {
                dp[k][i] = (dp[k-1][i-1] + dp[k-1][i+1]) % mod;
            }
        }
    }
    
    for(int i = 1; i < 10; i++){
        sum = (sum + dp[N][i]) % mod;
    }
    cout << sum % mod << '\n';
   
    return 0;
}
