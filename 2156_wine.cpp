//
//  2156_wine.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/20.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    int arr[10003] = {0, };
    int dp[10003] = {0, };
    int temp = 0;
    for(int i=3; i<m+3; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    //if(m == 1) dp[2] = arr[1] +arr[2];
    for(int i=3; i<m+3; i++){
        dp[i] = max(dp[i-2]+arr[i], dp[i-3] +arr[i-1] + arr[i]);
        dp[i] = max(dp[i], dp[i-1]);
        temp = max(temp,dp[i]);
    }
    cout<< temp <<endl;
    return 0;
    
}

