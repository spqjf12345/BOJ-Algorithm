//
//  9095_123plus.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/04.
//

#include <iostream>
using namespace std;
int memo[11] = {0, }; // n 숫자를 더하는 방법의 수
int dp[11] = {0, };
int Tcase;
int a;

int find_dp(int num) {
    if(memo[num] > 0){
        return memo[num];
    }else {
        memo[num] = find_dp(num - 1) + find_dp(num - 2) + find_dp(num - 3);
        return memo[num];
    }
    
}

int main(){
    memo[1] = 1; memo[2] = 2; memo[3] = 4;
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        cin >> a;
        cout <<find_dp(a) << '\n';
    }
    return 0;
}
