//
//  20500_ezreal.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/07.
//

#include <iostream>

int d[1515][2];
int N;
using namespace std;
long long a[1516];
long long b[1516];
long long c[1516];

int main(){
    cin >> N;
    a[0] = 1; a[1] = 0;
    b[0] = 0; b[1] = 1;
    c[0] = 0; c[1] = 1;
    for(int i = 2; i < N; i++){
        a[i] = (c[i-1] + b[i-1]) % 1000000007;
        b[i] = (a[i-1] + c[i-1]) % 1000000007;
        c[i] = (b[i-1] + a[i-1]) % 1000000007;
    }
    cout << b[N-1] << '\n';
    return 0;
}
