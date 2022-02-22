//
//  7569_tomato_3d.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/22.
//

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int tomatoMap[101][101][101];
int visit[101][101][101];

int dx[6] = { -1, 1, 0, 0, 0, 0};
int dy[6] = { 0, 0, 1, -1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1};

int N, M, H;
int tomato = 0;
int day = 0;
queue<pair<pair<int, int>, int>> q;

void make_ripen_dfs(){
    
    while(!q.empty()){
        int size = (int)q.size();
        for(int i =0; i < size; i++){
            int z = q.front().first.first;
            int x = q.front().first.second;
            int y = q.front().second;
            
            q.pop();
            for(int i = 0; i < 6; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                int nz = dz[i] + z;
                if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H){ continue; }
                if(visit[nz][nx][ny]){ continue; }
                if(tomatoMap[nz][nx][ny] == 0){
                    q.push({{nz, nx}, ny});
                    visit[nz][nx][ny] = true;
                    tomato--;
                }
            }
        }
        day++;
    }
    
}

int main(){
    memset(visit, false, sizeof(visit));
    cin >> M >> N >> H;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> tomatoMap[k][i][j];
                if(tomatoMap[k][i][j] == 1){
                    q.push({{k, i}, j});
                    visit[k][i][j] = true;
                }
                if(tomatoMap[k][i][j] == 0){
                    tomato++;
                }
            }
        }
    }
    
    if(tomato == 0){
        cout << tomato << '\n';
        return 0;
    }
    
    make_ripen_dfs();
//    cout << " tomato " << tomato << '\n';
    if(tomato > 0){
        cout << -1 << '\n';
    }else {
        cout << day - 1 << '\n';
    }
   
    return 0;
}
