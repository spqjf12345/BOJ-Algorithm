//
//  2178_miro.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/13.
//

#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100

int visit[MAX][MAX];
bool map[MAX][MAX];

int N, M;
int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

int miro_bfs(pair<int, int> start){
    //memset(visit, false, sizeof(visit));
    visit[start.second][start.first] = true;

    queue<pair<int,int>>q;
    q.push(make_pair(start.second, start.first));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << " " << x << endl;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && ny < N && nx < M){
                if(visit[ny][nx] == false && map[ny][nx]){ // 방문 x 이고 갈 수 있는 길이면
                    visit[ny][nx] = visit[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return visit[N-1][M-1];
}



int main(){
    cin >> N >> M;
    //cout << N << M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int a;
            scanf("%1d", &a);

            if(a == 1){
                map[i][j] = true;
            }
        }
    }
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < M; j++){
//            cout << map[i][j] << " " ;
//        }
//        cout << endl;
//    }


    pair<int, int> start = make_pair(0, 0);

    cout << miro_bfs(start) << endl;

    return 0;
}



