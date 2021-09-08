//
//  10026_blind.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;
int N;
char arr[101][101];
bool visit[101][101] = {false, };
bool blind_visit[101][101] = { false, };
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

void dfs(int i, int j){
    stack<pair<int, int>> s;
    s.push({ i, j});
    visit[i][j] = true;
    char nowColor = arr[i][j];
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) { continue;}
            if(arr[nx][ny] == nowColor && visit[nx][ny] == false){
                s.push({nx ,ny});
                visit[nx][ny] = true;
            }
            
        }
    }
    
}

void blind_dfs(int i, int j){
    stack<pair<int, int>> s;
    s.push({ i, j});
    visit[i][j] = true;
    char nowColor = arr[i][j];
    bool temp = false;
    
    if(nowColor == 'G' || nowColor == 'R') { temp = true; }
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) { continue;}
            if(temp){ // G || R 일때
                if((arr[nx][ny] == 'G' || arr[nx][ny] == 'R') && blind_visit[nx][ny] == false){
                    s.push({nx ,ny});
                    blind_visit[nx][ny] = true;
                }
            }else {
                //cout << arr[nx][ny] << '\n';
                if(arr[nx][ny] == nowColor && blind_visit[nx][ny] == false){
                    s.push({nx ,ny});
                    blind_visit[nx][ny] = true;
                }
            }
            
            
        }
    }
}

void dfs_all(){
    
    int person = 0;
    int blind_perspn = 0;
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visit[i][j] == false){
                dfs(i, j);
                person++;
            }
            
        }
    }
    
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(blind_visit[i][j] == false){
                blind_dfs(i, j);
                blind_perspn++;
            }
            
        }
    }
    cout << person << " " << blind_perspn << '\n';
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    dfs_all();

    return 0;
}
