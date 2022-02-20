//
//  11724.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>


using namespace std;
int N, M;
int cnt = 0;
vector<int> v[1000001];
bool visit[1000001];
stack<int> s;

//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };

void dfs_component(int start){
    s.push(start);
    visit[start] = true;
    
    while(!s.empty()){
        int current = s.top();
        s.pop();
        for(int i = 0; i < v[current].size(); i++){
            if(visit[v[current][i]] == false) {
                visit[v[current][i]] = true;
                s.push(v[current][i]);
            }
        }
    }
}

void dfs_all(){
    for(int i = 1; i <= N; i++){
        if(visit[i] == false){
            dfs_component(i);
            cnt++;
        }
    }
}

int main(){
    cin >> N >> M;
    memset(visit, false, sizeof(visit));
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs_all();
    cout << cnt << '\n';
    return 0;
}
