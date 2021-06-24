//
//  7562_night.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/24.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int Tcase;
int nightMove[8][2] = {{2, 1},{-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};


int night_move_bfs(pair<int, int> start, pair<int, int> desti,  int n){

    vector <vector <int> > v(n,vector <int>(n,0)); // 2차원 벡터 (n, n) 0으로 초기화
    bool visit[n][n];
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    
    visit[start.first][start.second] = true;
    q.push(start);
    
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        
        if(temp.first == desti.first && temp.second == desti.second) {
            return v[desti.first][desti.second];
        }
        
    
        for(int i =0; i < 8; i++){
            int nx = temp.first + nightMove[i][0];
            int ny = temp.second + nightMove[i][1];
            
            if(nx >= n || ny >= n || nx < 0 || ny < 0) continue; // index range
            if(visit[nx][ny] == true) continue;
            
            q.push({nx, ny});
            v[nx][ny] = v[temp.first][temp.second] + 1;
            visit[nx][ny] = true;
            
        }
    }
    
    return 0; //도달 불가
}

int main(){
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        int n;
        cin >> n;
        int sX, sY, dX, dY;
    
        cin >> sX >> sY;
        cin >> dX >> dY;

        pair<int, int> start = {sX, sY};
        pair<int, int> desti = {dX, dY};
        
        cout << night_move_bfs(start, desti, n) << '\n';
    }
    return 0;
}
