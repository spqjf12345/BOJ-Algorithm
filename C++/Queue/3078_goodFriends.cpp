//
//  3078_goodFriends.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
queue<int> q[21]; // 학생들 인덱스 저장
int N, K;
long long cnt = 0;

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        int idx = (int)s.length();
        
        while(!q[idx].empty() && i - q[idx].front() > K) {
            q[idx].pop(); // 친구 아님
        }
        
        cnt += q[idx].size();
        q[idx].push(i);
    }

    cout << cnt << '\n';
    return 0;
}
