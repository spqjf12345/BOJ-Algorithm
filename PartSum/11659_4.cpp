//
//  11659_4.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int n, Tcase;
int originalArr[100001];
int sumArr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> Tcase;
    originalArr[0] = 0;
    sumArr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> originalArr[i];
        sumArr[i] += originalArr[i] + sumArr[i - 1];
    }

//    for(int i = 1; i <= n; i++){
//        cout << "origin : " << originalArr[i] << '\n';
//        cout << "sum : " <<  sumArr[i] << '\n';
//    }
    
    for(int i =0; i < Tcase; i++){
        int k, l;
        cin >> k >> l;
        cout << sumArr[l] - sumArr[k - 1] << '\n';
    }
    
    return 0;
}
