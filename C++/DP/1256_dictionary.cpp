//
//  1256_dictionary.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/04.
//

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N, M, K;
int d[101][101];
string word;

//combination with dp
int dp(int n, int m){
    if(n == 0 || m == 0) { return 1; } // 기저
    int &result = d[n][m];
    if(result != -1) { return result; } //memozation
    result = 0x3f3f3f3f;
    result = min(result, dp(n-1,m) + dp(n,m-1));
    return result;
}

void makeWord(int n, int m, int k){
    if(n == 0) { //나머지 z 더해줌
        for(int i = 0; i < m; i++){ word += 'z'; }
        return;
    }
    
    if(m == 0) { //나머지 a 더해줌
        for(int i = 0; i < n; i++){ word += 'a'; }
        return;
    }
    
    int curSequence = dp(n-1,m);
    // a 맨 앞, 나머지 a-1, z로 만드는 경우의 수일 경우 이 경우에서 탐색
    if(k < curSequence){
        word += 'a';
        makeWord(n-1,m,k);
    }
    else{
        word+= 'z';
        makeWord(n,m-1,k-curSequence);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    memset(d, -1, sizeof(d));
    if(K > dp(N, M)) { cout << -1 << '\n'; }
    else {
        makeWord(N, M, K-1);
        cout << word << '\n';
    }
    return 0;
}
