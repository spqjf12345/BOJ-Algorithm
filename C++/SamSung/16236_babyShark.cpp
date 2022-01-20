//
//  16236_babyShark.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/05.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int arr[21][21];
int n;
int visit[21][21];
int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

using namespace std;

struct fish
{
    int dist;
    int y;
    int x;
};

struct compare
{
    bool operator()(fish a, fish b)
    {
        if (a.dist == b.dist)
        {
            if (a.y == b.y)
            {
                return a.x > b.x;
            }
            return a.y > b.y;
        }
        return a.dist > b.dist;
    }
};

void eat_fish_bfs(pair<int, int> start){
    //memset(visit, false, sizeof(visit));
    queue<fish> q;
    q.push({0, start.first, start.second});
    
    int weight = 2; //현재 상어 몸무게
    int dist = 0; // 이동 거리
    int eatCount = 0; // 먹은 물고기 수
    
    while(true){
        priority_queue<fish, vector<fish>, compare> pq; // 조건에 맞게 물고기를 정렬한 우선 순위 큐
        
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int curDist = q.front().dist;
            q.pop();
            for(int i = 0; i <4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(arr[ny][nx] > weight || visit[ny][nx]) {
//                    cout << "continue cur Dist nx ny " << curDist << " " << nx << " " << ny <<'\n';
                    continue;
                }
                cout << "cur Dist nx ny " << curDist << " " << nx << " " << ny <<'\n';
                q.push({curDist + 1, ny, nx});
                visit[ny][nx] = true;
                
                if(arr[ny][nx] < weight && arr[ny][nx] != 0){
                    cout << "-----cur Dist nx ny----" << curDist << " " << nx << " " << ny <<'\n';
                    pq.push({curDist + 1, ny, nx});
                }
            }
        }
        
        memset(visit, false, sizeof(visit));
        if(!pq.empty()){ // 먹을 물고기 남아 있다면
            int fishX = pq.top().x;
            int fishY = pq.top().y;
            int fishDist = pq.top().dist;
            pq.pop();
            
            arr[fishY][fishX] = 0;
            eatCount++;
            dist = fishDist;
            q.push({dist, fishY, fishX}); //상어 움직임
            visit[fishY][fishX] = true;
        }else{
            cout << dist << '\n';
            break;
        }
        
        if(eatCount == weight){
            weight++;
            eatCount = 0;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    pair<int, int> start;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                start = {i, j};
                arr[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }
    
    eat_fish_bfs(start);
    
    return 0;
}

