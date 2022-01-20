//
//  9095_123plus.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/04.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int dp[11] = {0, };
int memo[11] = {0, };

int dp_plus(int n){
    if(memo[n] > 0){
        return memo[n];
    }else{
        memo[n] = dp_plus(n - 1) + dp_plus(n - 2) + dp_plus(n - 3);
        return memo[n];
    }
}

int main(){
    int TC;
    cin >> TC;
    memo[1] = 1; memo[2] = 2; memo[3] = 4;
    for(int i =0; i < TC; i++){
        int n;
        cin >> n;
        int dpResult = dp_plus(n);
        cout << dpResult << '\n';
    }
  
    return 0;
}
