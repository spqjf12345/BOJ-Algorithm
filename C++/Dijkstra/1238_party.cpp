//
//  1238_party.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/03.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int N, M, X;
vector<pair<int, int>> arr[1001];
int d[1001]; // 최단 거리 테이블
#define INF 1e9

void party(int start){
    priority_queue<pair<int, int>>pq;
    //거리, 까지 정점
    pq.push(make_pair(0, start));
    d[start] = 0;
    
    while(!pq.empty()){
        //우선 순위 큐는 가장 큰 원소 top으로 놓으므로
        //거리 작은 정점부터 꺼내지도록 하기
        int time_t = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < arr[now].size(); i++){
            //거쳐서 가는 노드의 비용을 계산
            int cost = time_t + arr[now][i].second;
            if(cost < d[arr[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[arr[now][i].first] = cost;
                pq.push(make_pair(-cost, arr[now][i].first));
            }
        }
    }
}

void go_to_x_party(int goArr[]){
    for(int i = 1; i <= N; i++){
        fill(d, d+1001, INF);
        party(i);
        goArr[i] = d[X];
    }
}

int come_to_home(int goArr[]){
    fill(d, d+1001, INF);
    party(X);
    int maxPersopn = 0;
    for(int i = 1; i <= N; i++){

        goArr[i] += d[i];
        if(maxPersopn < goArr[i]){
            maxPersopn = goArr[i];
        }
    }
    return maxPersopn;
}

int main(){
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int start, end, time_t;
        cin >> start >> end >> time_t;
        arr[start].push_back({end, time_t});
    }
    
    int goArr[N+1];
    memset(goArr, 0, sizeof(goArr));
    
    go_to_x_party(goArr);
    int max = come_to_home(goArr);
    cout << max << '\n';

    
   
    return 0;
}
