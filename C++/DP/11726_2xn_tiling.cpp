//
//  11726_2xn_tiling.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/08/09.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int n;
int dp[1001];

int tiling_dp(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    if(dp[n] != 0){
        return dp[n];
    }
    
    return dp[n] = (tiling_dp(n-1) + tiling_dp(n-2)) % 10007;
}

int main(){
    cin >> n;
    cout << tiling_dp(n) << '\n';
    
    return 0;
}
