//
//  14502_lab.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/07.
//

#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;
int arr[8][8];
int c_arr[8][8];
int N, M;
int zero_cnt;
int ans;
bool check[64]; //벽(1)을 만들어 봤는지 아닌지 검사
bool visit[8][8]; //바이러스(2)를 만들어 봤는지 아닌지 검사

vector<pair<int, int>> virusArr;
vector<pair<int, int>> emptyArr;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void make_map(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            //cout << arr[i][j] << " ";
            if(arr[i][j] == 0){//빈칸
                emptyArr.push_back(make_pair(i, j)); // 0 좌표
            }else if(arr[i][j] == 2){//바이러스
                virusArr.push_back(make_pair(i,j)); // 2 좌쵸
            }
        }
    }
    zero_cnt = (int)emptyArr.size();
    //cout << "zero_cnt : " << zero_cnt << endl;
}

void make_cmap(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            c_arr[i][j] = arr[i][j];
        }
    }
}

void make_BFS(int x, int y){
    queue<pair<int, int>> virusQ;
    virusQ.push(make_pair(x, y)); // 처음 위치의 바이러스를 집어 넣음
    visit[x][y] = true;
    while(virusQ.empty() == 0){
        //not empty 일 경우 아직 방문하지 않은 노드가 있는 것이므로 2로 만들어 줘야 함
        int x = virusQ.front().first;
        int y = virusQ.front().second;
        virusQ.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(visit[nx][ny] == false && c_arr[nx][ny] == 0){ // 방문 x이고 0(빈칸)이라면
                    c_arr[nx][ny] = 2; // 바이러스를 넣어줌
                    visit[nx][ny] = true;
                    virusQ.push(make_pair(nx, ny));
                }
            }
        }
        
    }
    
}

int safe_area(){
    int cnt = 0;
    for(int i =0; i <N; i++){
        for(int j = 0; j <M; j++){
            if(c_arr[i][j] == 0) cnt++;
        }
    }
    return cnt;
}


void bfs_mk_virus(){
    int count = 0;
    make_cmap();
    memset(visit, false, sizeof(visit));//visit 배열을 false로 모두 초기화
    
    //초기 작업 - 벽 1을 세워줌
    for(int i = 0; i< zero_cnt; i++){
        if(count == 3) {
            //cout << "get break" << endl;
            break;
        }
        if(check[i] == true){ //1이 있는 곳이라면
            int x = emptyArr[i].first;
            int y = emptyArr[i].second;
            c_arr[x][y] = 1;// c_arr 에 1 세움
            count ++;
        }
    }
    
    for(int i = 0; i < (int)virusArr.size(); i++){ // 바이러스 갯수만큼
        int x = virusArr[i].first;
        int y = virusArr[i].second;
        make_BFS(x, y); //바이러스 있는 위치에서 바이러스를 퍼트린다.
    }
    
    int temp_ans = safe_area();
    ans = max(ans, temp_ans);
    
}

void dfs_mk_wall(int index, int count){ // brute force
    if(count == 3){// 벽 3개를 다 만들면
        bfs_mk_virus();
        //cout << "made wall " << index << endl;
        return;
    }
    for(int i = index; i < zero_cnt; i++){// 0이 있는 만큼 반복하여 벽(1)을 세운다.
        if(check[i] == true){ //벽을 세웠던 곳이라면
            continue; // 걍 넘김
        }
        check[i] = true;
        dfs_mk_wall(i, count + 1); // dfs로 벽을 세운다
        check[i] = false; // 막혔을 경우 되돌아 온다.
    }
}


int main(){
    make_map();
    dfs_mk_wall(0,0); //{0,0}위치 부터 1로 벽 세우기
    cout << ans << endl;
    return 0;
}
