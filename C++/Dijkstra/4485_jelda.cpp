//
//  4485_jelda.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/22.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int cnt = 1;
int map[125][125];
int d[125][125];
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


priority_queue<pair<int, pair<int, int>>> pq;

void find_jelda(int cnt){
    d[0][0] = map[0][0];
    pq.push(make_pair(-map[0][0], make_pair(0, 0))); // cost, x, y;
    
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int dist = -pq.top().first;
        
        pq.pop();
        
//        if(d[x][y] < dist) {
//            continue;
//        }
        
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            int cost = dist + map[nx][ny];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
            
            if(d[nx][ny] == -1 || cost < d[nx][ny]){
                d[nx][ny] = cost;
                pq.push({-cost, {nx, ny }});
            }
        }
    }

    
    cout << "Problem " << cnt << ": " << d[n-1][n-1] << '\n';
    
}

int main(){
    do {
        cin >> n;
        if(n == 0) {
            break;
        }
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                int value;
                cin >> value;
                map[i][j] = value;
                d[i][j] = -1;
            }
        }

        find_jelda(cnt);
        cnt++;
    }
    while(n != 0);
    return 0;
    
}
