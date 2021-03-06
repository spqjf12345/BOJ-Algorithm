//
//  2748_fibonacci2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/26.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
long long memo[100];

long long fibonacci2(long long n){
    if(n <= 1){
        return n; // 기저
    } else{
        if(memo[n] > 0) { // memo에 저장된 값이 있으면
            return memo[n];
        }
        memo[n] = fibonacci2(n -1) + fibonacci2(n -2);
        return memo[n];
    }
}

int main(){
    memset(memo, 0, sizeof(memo));
    long long n;
    cin >> n;
    cout << fibonacci2(n) << endl;
    return 0;
}
