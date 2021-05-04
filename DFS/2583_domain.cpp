//
//  2583_domain.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/20.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>

#define MAX 101

bool map[MAX][MAX];
int cmap[MAX][MAX];
bool visit[MAX][MAX];
int M, N, K;

using namespace std;


int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };
int dfs(pair<int, int> start){
    int count = 1;
    visit[start.first][start.second] = true;
    stack<pair<int, int>> s;
    s.push(make_pair(start.first, start.second));
    while(!s.empty()){//stack s가 비어 있지 않을 동안
        int x = s.top().first;
        int y = s.top().second;
        // << x << " " << y << endl;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < M && ny < N){
                if(visit[nx][ny] == false && cmap[nx][ny] == 0){ // 방문하지 않았고 갈 수 있는 길이라면
                    visit[nx][ny] = true; // 방문한 것을 판별
                    count++;
                    s.push(make_pair(nx, ny));
                }
            }
        }
    }
    return count;
    
}

  
void dfsAll(){
    vector<int> ans;
    memset(visit, false, sizeof(visit));
    
    pair<int, int> start;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if (cmap[i][j] == 0 && visit[i][j] == false){
                start = make_pair(i, j);
                int cnt = dfs(start);
                ans.push_back(cnt);
            
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << endl;

    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans.at(i) << " ";
    }
    
}
    


int main(){

    int x, y;
    cin >> M >> N >> K;
    vector<pair<int, int>> temp[K];
    
    for(int i = 0; i < K; i++){
        for(int j = 0; j < 2; j++){
            cin >> x >> y;
            temp[i].push_back(make_pair(M - y, x));
        }
    }
    
//    for(int i = 0; i < K; i++){
//        for(int j = 0; j < (int)temp[i].size(); j++){
//            cout << temp[i][j].first << " " << temp[i][j].second << " ";
//        }
//        cout<< endl;
//    }
    
    //map 초기화
    for(int i =0; i < M + 1; i++){
        for(int j = 0; j < N + 1; j++){
            map[i][j] = 0;
        }
    }
    
    for(int i = 0; i < K; i++){ //3
        pair<int, int> leftEnd = temp[i][0];
        pair<int, int> rightTop = temp[i][1];
        
        int nx = leftEnd.first;
        while(nx > rightTop.first){
            int ny = leftEnd.second;
            while(ny < rightTop.second){
                map[nx][ny] = 1;
                if (ny < rightTop.second){
                    ny+= 1;
                    //cout << nx << " " << ny << endl;
                }
            }
            ny--;
            map[nx--][ny]= 1;
        }
    }
    
        for(int i =1; i < M + 1; i++){
            for(int j = 0; j < N; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    
        
    for(int i =1; i < M + 1; i++){
        for(int j = 0; j < N; j++){
            cmap[i-1][j] = map[i][j];
        }
    }
    
//    for(int i = 0; i < M; i++){
//        for(int j = 0; j < N; j++){
//            cout << cmap[i][j] <<" " ;
//        }
//        cout << endl;
//    }
    


    dfsAll();

    return 0;
    
}
