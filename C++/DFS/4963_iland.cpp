//
//  4963_iland.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/02.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int arr[51][51];
int visit[51][51] = {false, };
int w, h;
int dx[] = { 0, 0, 1, -1, -1, 1, -1, 1 }; //up down left right
int dy[] = { 1, -1, 0, 0, -1, -1, 1, 1 };


void dfs(int i, int j){
    stack<pair<int, int>> s;
    s.push({i, j});
    visit[i][j] = true;
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        
        for(int i = 0; i < 8; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= h || ny >= w || nx < 0 || ny < 0) continue;
            if(arr[nx][ny] == 1 && visit[nx][ny] == false){
                //cout << "nx ny " << nx << " " << ny << '\n';
                s.push({nx, ny});
                visit[nx][ny] = true;
            }
            
        }
    }
    
}

void dfs_all(){
    int cnt = 0;
    for(int i =0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j] == 1 && visit[i][j] == false){
                dfs(i, j);
                //cout << i << " " << j << '\n';
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    
}



int main(){
   
    do {
        cin >> w >> h;
        if(w == 0 || h == 0) {
            break;
        }
        for(int i =0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
            }
        }
        
        //dfs
        dfs_all();
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
    }while(w !=0 || h !=0);
   
    return 0;
}
