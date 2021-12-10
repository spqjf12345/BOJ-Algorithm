//
//  1753_min_path.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/03/09.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

vector<pair<int, int>> vertex[100001];
int d[100001]; // 최단 거리 테이블

void find_min_path(int start){
    priority_queue<pair<int, int>>pq;
    //거리, 까지 정점
    pq.push(make_pair(0, start));
    d[start] = 0;
    
    while(!pq.empty()){
        //우선 순위 큐는 가장 큰 원소 top으로 놓으므로
        //거리 작은 정점부터 꺼내지도록 하기
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < vertex[now].size(); i++){
            //거쳐서 가는 노드의 비용을 계산
            int cost = dist + vertex[now][i].second;
            if(cost < d[vertex[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[vertex[now][i].first] = cost;
                pq.push(make_pair(-cost,vertex[now][i].first));
            }
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    int start;
    cin >> start;
    
    for(int i =0; i < e; i++){
        int in, to, w;
        cin >> in >> to >> w;
        vertex[in].push_back({to, w});
    }
    fill(d, d+100001, INF);
    find_min_path(start);
    
    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= v; i++)
    {
        // 도달할 수 없는 경우
        if (d[i] == INF) {
            cout << "INF" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }

    return 0;
}
