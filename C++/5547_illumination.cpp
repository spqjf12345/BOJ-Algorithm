//
//  5547_illumination.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/14.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#define MAX 100

using namespace std;


int N, M;
bool map[MAX][MAX];
bool visit[MAX][MAX];

//int dy[] = { 1, -1, 0, 0 }; //right left down up
//int dx[] = { 0, 0, 1, -1 };


int dx[] = {1, 0, -1, 1, 0, 1};
int dy[] = {-1, -1, 0, 0, 1, 1};




int  hexagon_dfs(pair<int, int> start){
    int length = 0;
    int cnt = 1; // 처음에 start가 1인 위치로부터 받아왔기 때문에 0이 아니라 1로 설정한다.
    visit[start.first][start.second] = true;
    
    stack<pair<int, int>> s;
    s.push(make_pair(start.first, start.second));
    
    while(!s.empty()){ // 대각선이라서 1,3 즉 arr로 1, 3d을 가져오지 못하는 구나
        int y = s.top().first;
        int x = s.top().second;
        
        
        cout << x << " " << y << endl;
        s.pop();
        for(int i = 0; i < 4; i++){
            int nx, ny;
            ny = y + dy[i];
            nx = x + dx[i];
            
//            if(x % 2 == 0){ // x(뒷 숫자)가 짝수라면
//                ny = y + dy[i];
//                nx = x + dx[i];
//            }else{ // 홀수 라면
//                ny = y + dy[i];
//                nx = x + dx[i];
//            }
            cout << " ny : " << ny << " nx : " << nx << endl;

            if(nx >= 0 && ny >= 0 && ny < N+1 && nx < M+1){
                if(visit[ny][nx] == false && map[ny][nx]){ // 방문하지 않았고 갈 수 있는 길이라면
                    visit[ny][nx] = true; // 방문한 것을 판별
                    cnt++;
                    //length += 6;
                    s.push(make_pair(ny, nx));
                }
            }
        }
    }
    return cnt;
    
  
    return 0;
}

void dfs_All(){
    memset(visit, false, sizeof(visit));
    pair<int, int> start = make_pair(1, 1); //starting point
    for(int i =1; i < M+1; i++){ //4
        for(int j = 1; j < N+1; j++){ //8
            if(map[i][j] == true && visit[i][j] == false){ // 아직 가지 않았지만 1인게 남아 있는 경우
                
                start = make_pair(i, j); // 1,2/ 1,4
                cout << "start " << start.first << " " << start.second << " " << endl;
                int cnt = hexagon_dfs(start);
                cout << cnt << endl;
            }
        }
    }
    
    
}

int main(){
    cin >> N >> M;
    for(int i = 1; i< M+1; i++){ //4 i
        for(int j = 1; j < N+1; j++){ // 8 j
            int a;
            cin >> a;
            if (a == 1){
                map[i][j] = true;
            }else{
                map[i][j] = false;
            }
        }
    }
    dfs_All();
    
    
    
    
//배열 확인용
//    for(int i = 0; i< M; i++){
//        for(int j = 0; j < N; j++){
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return 0;
}
