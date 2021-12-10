//
//  7576_tomato.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/22.
//

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
int tomatoMap[1001][1001];
int M, N;
int tomatoCount;
int dfscount;
int visit[1001][1001] = {false, };

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> s;

void tomato_dfs(){
    while(!s.empty()){
        pair<int, int> cur = s.front();
        s.pop();
       
        for(int i = 0; i < 4; i++){
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
           
            if(nextX < N && nextY < M && nextX >= 0 && nextY >= 0 ){
                if(visit[nextX][nextY] == false && tomatoMap[nextX][nextY] == 0){
                    //cout << " next : " << nextX << " " << nextY << '\n';
                    visit[nextX][nextY] = true;
                    s.push({nextX, nextY});
                    dfscount++;
                    tomatoMap[nextX][nextY] = tomatoMap[cur.first][cur.second] + 1;
                }
            }
        }

    }
}

int main(){
    cin >> M >> N; // 6 4
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomatoMap[i][j];
            if(tomatoMap[i][j] == 0){ // tomato count
                tomatoCount++;
            }else if(tomatoMap[i][j] == 1){
                s.push({i,j});
                //startPoint = make_pair(i,j);
            }
        }
    }
    int max = 0;
    if(tomatoCount == 0){
        cout << "0" << '\n'; // 모든 토마토 익어있는 상태
        return 0;
    }else{
        tomato_dfs();
        if(tomatoCount - dfscount != 0){ // 토마토 다 익지 x
            cout << "-1" << '\n';
            return 0;
        }
        for(int i = 0; i < N; i++){ // 토마토 다 익힘
            for(int j = 0; j < M; j++){
                if(max < tomatoMap[i][j]){
                    max = tomatoMap[i][j];
                }
                    
            }
        }
        cout << max - 1 << '\n';

    }
    return 0;
}
