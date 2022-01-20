//
//  11779_min_cost2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/03/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

vector<pair<int, int>>vertex[1001];
int d[100001]; // 최단 거리 테이블
int t[100001];

void min_bus(int start, int end){
    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < vertex[now].size(); i++){
            
            int cost = dist + vertex[now][i].second;
            if(cost < d[vertex[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[vertex[now][i].first] = cost;
                t[vertex[now][i].first] = now; // 부모 노드가 그 전 노드 가지고 있도록 하기
                
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
    
    vector<int>route;
    
    int temp_end = end;
    
    while (temp_end)
    {
        route.push_back(temp_end);
        temp_end = t[temp_end];
    }
    cout << route.size() << endl;
    for (int i = ((int)route.size()) - 1; i >= 0; i--) cout << route[i] << " ";
    cout << endl;

    return 0;
}

