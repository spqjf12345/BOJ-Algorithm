//
//  18352_city_kDistance.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/02.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, X, M;
vector<pair<int, int>> node[300001]; // start, end, min_distance
queue<int> q;
bool visit[300001] = {false, };
vector<int> answer;

int cnt = 0;

//도시를 출력
void find_kDistance(){
    // x == start
    q.push(X);
    visit[X] = true;
    int depth = 0;
    
    while(!q.empty()){
        
        int sz = (int)q.size(); // 현재 depth -1에 해당하는 queue 원소 개수
        //cout << "sz " << sz <<'\n';
        while (sz-- > 0) {
            int next = q.front();
            q.pop();
            for (int i = 0; i < node[next].size(); i++) {
            
                if(visit[node[next][i].first] == false){
                    visit[node[next][i].first] = true;
                    q.push(node[next][i].first);
                    node[next][i].second = depth;
                }

            }
        }
        
        depth++;
        
        // 여기에서 q.push(...)로 들어간 원소는 depth에 해당한다.
        if(depth == K && !q.empty()) {
            priority_queue<int, vector<int>, greater<int>> pq;
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            while(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            return;
        }
        
       
    }
    cout << -1;
    return;
 
}

int main(){
    cin >> N >> M >> K >> X;
    
    for(int i = 0; i < M; i++){
        int A, B;
        //start -> end A, B, distance = 0
        cin >> A >> B;
        node[A].push_back({B, 0});
    }
    
    find_kDistance();
    return 0;
    
}
