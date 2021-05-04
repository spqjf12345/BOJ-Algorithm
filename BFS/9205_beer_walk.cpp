//
//  9205_beer_walk.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/17.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;
#define MAX 100
int N, c_store;
vector<pair<int, int>> v;

void beer_walk_bfs(int _first, int _second){

    bool visit[c_store + 2];
    memset(visit, false, sizeof(visit));

    queue<pair<int, int>> q;
    q.push(make_pair(_first, _second)); //첫번째 즉 집 q에 넣어줌
    visit[0] = true; // 집 넣어줌

//    for(int i = 0; i < c_store + 2; i++){
//        cout << "v: " << v[i].first << " " << v[i].second << endl;
//    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        for(int i = 1; i < (int)v.size(); ++i){
            int nx = v[i].first;
            int ny = v[i].second;
            
            // 다음 곳 방문하지 않았고 && 맨허튼 거리로 1000미만인 경우 방문할 수 있으므로
            if(visit[i] == false && (abs(nx - x) + abs(ny - y)) <= 1000 ){
                q.push(make_pair(v[i].first, v[i].second));
                visit[i] = true;
            }
        }
    }

    if (visit[c_store + 1] == true){
        cout << "happy\n";
    }else{
        cout << "sad\n";
    }

}

int main(){
    int x, y;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> c_store;
        v.clear();
        for(int j = 0; j < c_store + 2; j++){
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        
        beer_walk_bfs(v[0].first, v[0].second);
    }

    return 0;
}
