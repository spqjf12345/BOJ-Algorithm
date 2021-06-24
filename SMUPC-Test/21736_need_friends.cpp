//
//  21736_need_friends.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/13.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>


using namespace std;

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };
char campus[601][601];
int visit[601][601];
int N, M; // 가로, 세로
pair<int, int> me;
stack<pair<int, int>> s;

int find_friends_dfs(pair<int, int> me){
    int cnt = 0;
    visit[me.first][me.second] = true;
    s.push(me);
    
    while(!s.empty()){
        
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(visit[nx][ny] == true) continue;
            if(nx >= N || ny >= M || nx < 0 || ny < 0) continue;
            if(campus[nx][ny] == 'X'){
                visit[nx][ny] = true;
                continue;
            }
            
            if(campus[nx][ny] == 'P'){
                cnt++;
            }
            visit[nx][ny] = true;
            s.push({nx, ny});
        }
    }
    
    return cnt;
}

int main(){
    memset(visit, false, sizeof(visit));
    cin >> N >> M;
    
    for(int i =0; i <N; i++){
        for(int j = 0; j < M; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                me = {i , j};
            }
        }
    }
    
    int cnt = find_friends_dfs(me);
    cnt > 0 ? cout << cnt <<'\n' : cout << "TT" <<'\n';
    
    return 0;
}
