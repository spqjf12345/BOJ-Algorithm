//
//  11568_minguen.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//


#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int maxCount = 0;
int dp[1001] = {0, }; // i 번째 원소를 마지막으로 하는 LIS(가장 긴 증가하는 부분 수열)의 길이

void find_maxLength(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        int here = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                here = max(dp[j], here);
            }
        }
        dp[i] = here + 1;
        maxCount = max(maxCount, dp[i]);
    }
}

int main(){
    
    find_maxLength();
    cout << maxCount << '\n';
    return 0;
}
