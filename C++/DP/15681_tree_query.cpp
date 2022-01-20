//
//  15681_tree_query.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int n, root, query;
vector<int> node[100001];
int dp[100001];
int visit[100001];

int dfs(int now){
    
    if(visit[now] == true) { return dp[now]; }
    visit[now] = true;
    
    for(int i = 0; i < node[now].size(); i++){
        int next = node[now][i];
        if(visit[next] == true){ continue; }
        dp[now] = dp[now] + dfs(next); //자기 + 하위값
    }
    
    return dp[now];
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> root >> query;
    for(int i =0; i < n-1; i++){
        int start, end;
        cin >> start >> end;
        node[start].push_back(end);
        node[end].push_back(start);
    }

    memset(visit, false, sizeof(visit));
    for(int i =0; i <= n; i++){
        dp[i] = 1;
    }
    dfs(root);
    
    for(int i = 0; i < query; i++){
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
    
    return 0;
}
