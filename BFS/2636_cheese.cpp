//
//  2636_cheese.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/01.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>


using namespace std;
int arr[101][101];
int visit[101][101];
int cheese_cnt = 0;
int ans = 1;
int M, N;

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

enum { CHEESE = 1, PREAIR, AIR};

bool melt_bfs(){
    bool cleared = true;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == PREAIR){
                arr[i][j] = AIR; // 공기로 바꿔줌
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == CHEESE){//치즈가 조금이라도 남았다면 false
                cleared = false;
            }
        }
    }
    return cleared;

    
}

bool find_air(){
  
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    memset(visit, false, sizeof(visit));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        
        arr[y][x] = AIR;
        q.pop();
        for(int i = 0; i < 4; i ++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= M || nx >= N || visit[ny][nx])
                continue;
            if(arr[ny][nx] == CHEESE){ // 근처 치즈를발견하면 preair로 넣어준다 ..!
                arr[ny][nx] = PREAIR;
                cheese_cnt++;
            }else if (arr[ny][nx] == 0 || arr[ny][nx] == AIR){
                q.push(make_pair(ny, nx)); // 공기에 대해 q에 넣어준다.
                visit[ny][nx] = true;
            }
            
        }
    }
    return melt_bfs();
}

int main(){
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        int s;
        for(int j = 0; j < N; j++){
            cin >> s;
            arr[i][j] = s;
        }
    }
    
//    for(int i = 0 ; i < M; i++){
//        for(int j = 0; j < N; j++){
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    while(1){
        cheese_cnt = 0;
        if(find_air())
            break;
        ans++;
    }
    
    cout << ans << '\n';
    cout << cheese_cnt << '\n';
    
    melt_bfs();
    
    
    return 0;
}
