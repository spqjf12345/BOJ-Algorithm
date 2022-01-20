//
//  2667_complex.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/14.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100
int n;
bool visit[MAX][MAX];
bool map [MAX][MAX];

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
        //cout << y << " " << x << endl;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                if(visit[nx][ny] == false && map[nx][ny]){ // 방문하지 않았고 갈 수 있는 길이라면
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
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == true && visit[i][j] == false){ // 아직 가지 않았지만 1인게 남아 있는 경우
                start = make_pair(i, j);
                int cnt = dfs(start);
                //cout << cnt << endl;
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << endl;

    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans.at(i) << endl;
    }
    
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            scanf("%1d", &a);
            if(a == 1){
                map[i][j] = true;
            }else{
                map[i][j] = false;
            }
        }
    }
    
    //    for(int i = 0; i < n; i++){
    //        for(int j = 0; j < n; j++){
    //
    //            cout << map[i][j] << " ";
    //        }
    //        cout << endl;
    //    }

    dfsAll();
    
    return 0;
}
