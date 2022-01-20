//
//  2133_tileFill.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/08/08.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int n;
int dp[31];

int fill_dp(int x){
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 3;
    
    if(dp[x] !=0) return dp[x];
    int result = 3 * fill_dp(x - 2);
    for(int i = 3; i<= x; i++){
        if(i % 2 == 0){
            result += 2 * fill_dp(x - i);
        }
    }
    return dp[x] = result;
}

int main(){
    cin >> n;
    cout << fill_dp(n) << '\n';
    return 0;
}
