//
//  1463_makeOne.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/08/23.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int d[1000001] = {0, }; // 나눈 횟수가 저장됨

int dp(int n){
    int max = 1000001;
    d[2] = d[3] = 1;
    if(n == 1) { return 0;}
    
    if (d[n] > 0) return d[n];
    
    if(n % 3 == 0)  { max = min(dp(n/3) + 1, max); }
    if(n % 2 == 0) { max = min(dp(n/2) + 1, max); }
    max = min(dp(n-1) + 1, max); // dp(n-1);
    d[n] = max;
    
    return d[n];
}

int main(){
    int n;
    cin >> n;
    cout << dp(n) << '\n';
    return 0;
}
