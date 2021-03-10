//
//  1916_min_cost.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/03/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9 //1000000000

vector<pair<int, int>>vertex[1001];
int d[100001]; // 최단 거리 테이블

void min_bus(int start, int end){
    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while(!pq.empty()){
        //우선 순위 큐는 가장 큰 원소 top으로 놓으므로
        //거리 작은 정점부터 꺼내지도록 하기
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < vertex[now].size(); i++){
            int cost = dist + vertex[now][i].second;
            if(cost <d[vertex[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[vertex[now][i].first] = cost;
                pq.push(make_pair(-cost,vertex[now][i].first));
            }
        }
    }
    
}

int main(){
    int city;
    cin >> city;
    int bus;
    cin >> bus;
    for(int i = 0 ; i < bus; i++){
        int in, to, cost;
        cin >> in >> to >> cost;
        vertex[in].push_back({to, cost});
    }
    
    int start, end;
    cin >> start >> end;
    fill(d, d+100001, INF);
    min_bus(start, end);
    cout << d[end] << '\n';
    
    
    return 0;
}
