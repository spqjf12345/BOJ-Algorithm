//
//  16953_AtoB.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/05.
//

#include <iostream>
#include <algorithm>

using namespace std;
long n, m, answer = 10000000;

//long d[1000000000] = { 0, };

void dfs(long n, long depth){
    if(n > m) { return; }
    if(n == m) { answer = min(answer, depth); }
    dfs(n*2, depth+1);
    dfs(n*10 + 1, depth+1);
}

int main(){
    cin >> n >> m;
    dfs(n, 1);
    if(answer != 10000000){
        cout << answer << '\n';
    }else {
        cout << -1 << '\n';
    }
    return 0;
}

