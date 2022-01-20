//
//  6118_hidePlay.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/09.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>



using namespace std;
#define INF 1e9

int n, m;
int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };
int d[50001]; // 최단 거리 테이블

vector<pair<int, int>> map[50000];

void find_far_path(){
    int start = 1; // start node
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start)); //cost, node
    d[start] = 0;
    
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < map[now].size(); i++){
            int cost = dist + map[now][i].second;
            if(cost < d[map[now][i].first]) {
                d[map[now][i].first] = cost;
                pq.push(make_pair(-cost, map[now][i].first));
            }
        }
    }
}


int main(){
    cin >> n >> m;
    fill(d, d+50001, INF);
    
    for(int i =0; i < m; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back({b, 1});
        map[b].push_back({a, 1});
        
    }
    
    find_far_path();
    int result = 0;
    int cnt = 0;
    
    //최대 값 찾기
    for (int i = 1; i <= n; i++)
    {
        if(d[i] > result){
            result = d[i];
        }
    }
    
    // 개수 count
    for (int i = 1; i <= n; i++)
    {
        if(result == d[i]){
            cnt++;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(result == d[i]){
            cout << i  << " " << d[i] << " " << cnt << '\n';
            break;
        }
    }

    return 0;
}
