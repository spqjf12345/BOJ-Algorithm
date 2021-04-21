//
//  1987_DFS.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/04.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

bool visit[26];
char arr[20][20];
int C, R;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int answer;

void DFS(int x, int y, int cnt){
    answer = max(answer, cnt);
    for(int i =0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < R && ny < C){
            if(visit[arr[nx][ny] - 'A'] == false){
                visit[arr[nx][ny] - 'A'] = true;
                DFS(nx, ny, cnt + 1); // 방문했으므로 cnt + 1
                visit[arr[nx][ny] - 'A'] = false; //재귀적으로 다 돌고 왔을 때 다시 시작 노드의 인접 노드 방문 위해서
            }
        }
    }
}

int main(){
    
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
    
    visit[arr[0][0] - 'A'] = true;
    DFS(0,0,1);
    cout << answer << endl;
    return 0;
}
