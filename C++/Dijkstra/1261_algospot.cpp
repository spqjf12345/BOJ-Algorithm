//
//  1261.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/27.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>



using namespace std;
int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;

int N, M;
int arr[101][101];
int dist[101][101];
#define INF 987654321

void find_and_break(){
    pair<int, int> start = make_pair(0, 0);
    q.push(start);
    //초기 거리값 0
    dist[start.first][start.second] = 0;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        int x = now.first;
        int y = now.second;
        q.pop();
        
        for(int i =0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny <0 || nx >= M || ny >= N) {
                continue;
            }
            //cout<< "nx : " << nx << " ny : " << ny << '\n';
            
            if(arr[nx][ny] == 0){ // 빈공간일때
                //cout << " 0 is " << dist[nx][ny] << " " << dist[x][y] << '\n';
                if(dist[nx][ny] > dist[x][y]){
                    dist[nx][ny]  = dist[x][y]; // 0을 넣어 벽을 깨지 않고 감을 나타냄
                    q.push({nx, ny});
                }
            }else if(arr[nx][ny] == 1) { // 벽일때
                //cout << " 1 is " << dist[nx][ny] << " " << dist[x][y] << '\n';
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1; // 한개를 뿌셨다.
                    q.push({nx, ny});
                }
                
            }
        
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i< M; i++)
    {
        for(int j= 0; j < N; j++){
            scanf("%1d", &arr[i][j]);
            dist[i][j] = INF;
        }
    }

    find_and_break();
    
//    for(int i = 0; i< M; i++)
//    {
//        for(int j= 0; j < N; j++){
//            cout << dist[i][j] << ' ';
//        }
//        cout << endl;
//    }
    
    cout << dist[M-1][N-1];
    return 0;
}
