//
//  1949_greatVilliage.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/09.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int W[10001];
vector<vector<int>> arr;
int visit[10001] = { false, };
int dp[10001][2];
// dp[i][0] - i번째 마을이 일반 마을일때 i번째 노드를 루트 노드로 하는 서브 트리 우수 마을 인구수의 최대 값
// dp[i][1] - i번째 마을이 우수 마을일 때 i번째 노드를 루트 노드로 하는 서브 트리 우수 마을 인구수의 최대 값

void dfs(int cur){
    if(visit[cur]) { return; }
    dp[cur][0] = 0;
    dp[cur][1] = W[cur];
    visit[cur] = true;

    for(int i = 0; i < arr[cur].size(); i++){
        int next = arr[cur][i];
        if(visit[next] == true) { continue; } // 방문한 노드는 건너 뜀
       
        dfs(next);

        //leaf node 도달 이후
        // * 참고 *
        // 일반 마을은 자식 마을이 우수거나, 자식 마을이 일반 마을이다.
        // 더 큰 쪽을 선택한다. 3번 조건은 여기서 해결이 된다.
        //cout << "cur " << cur << " arr[cur][i] " << next <<'\n';
        dp[cur][0] = dp[cur][0] + max(dp[next][0], dp[next][1]);

        // 현재 마을이 우수 마을이면, 자식은 반드시 일반 마을이어야 한다.
        dp[cur][1] = dp[cur][1] + dp[next][0];
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> W[i];
    }
    arr.resize(N + 1);
    for(int i =0; i < N-1; i++){
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }


    dfs(1); // set root node 1

    cout << max(dp[1][0], dp[1][1]);
    return 0;
}


