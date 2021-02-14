//
//  1260_bfs_dfs.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/13.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std;
// dfs 에 들어오면 방문한 것으로 판단 방문 판단 여부가 반드시 들어가야 한다.
//recursion
/*void dfs(int start, vector<int> graph[], bool check[]){
    check [start] = true;
    cout << start;
    for(int i=0; i< graph[start].size(); i++){
        int next = graph[start][i];
        if(check[next] == false){
            dfs(next, graph, check); //recursion used
        }
    }
}
*/

void bfs(int start, vector<int> bgraph[], bool bcheck[]){
    queue<int> q;
    q.push(start);
    bcheck[start] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(int i=0; i<bgraph[tmp].size(); i++){
            // 방문하지 않았다면
            if(bcheck[bgraph[tmp][i]] == false){
                // 큐에 넣어주고 방문했음을 표시한다.
                q.push(bgraph[tmp][i]);
                bcheck[bgraph[tmp][i]] = true;
            }
        }
    }
}

//stack used
void dfs(int start, vector<int> graph[], bool check[]){
    stack<int> s;
    s.push(start);
    check[start] = true;
    cout << start<< ' ';
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i =0; i<graph[current_node].size();i++){
            int next_node = graph[current_node][i];
            if(check[next_node] == false){
                cout <<next_node << ' ';
                check[next_node] = true;
                //pop 했으므로 current_node 를 넣어주여아 햔다.
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }
}


int main(){
    int n, m, start;
    cin >> n >> m >> start;
    vector<int> graph[n+1];
    vector<int> regraph[n+1];
    bool check [n+1];
    bool recheck [n+1];
     // fill check ~ check+n index fill to check array
     fill(check, check+n+1, false);
     fill(recheck, recheck+n+1, false);
     for (int i =0; i< m; i++){
         int u,v;
         cin >> u >> v;
         graph[u].push_back(v);
         graph[v].push_back(u);
         regraph[u].push_back(v);
         regraph[v].push_back(u);
     }
     
     for(int i = 1; i<=n; i++){
         sort(graph[i].begin(), graph[i].end());
         sort(regraph[i].begin(), regraph[i].end());
     }
    
    dfs(start, graph, check);
    cout << '\n';
    int restart;
    restart = start;
    bfs(restart, regraph, recheck);
}

