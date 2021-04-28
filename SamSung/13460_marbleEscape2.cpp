//
//  13460_marbleEscape2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/22.
//

/// - BFS 문제 -
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

char map[11][11];
bool visit[11][11][11][11] = {false, };


int N, M;

pair<int, int> redStart;
pair<int, int> blueStart;
pair<int, int> holeStart;

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

int find_hole_bfs(){
    queue<pair<pair<int, int>, pair<int, int>>>q; // red꺼, blue꺼
    q.push({redStart, blueStart}); // 큐에 red blue꺼 x, y 순으로 push
    visit[redStart.first][redStart.second][blueStart.first][blueStart.second] = true;
    int result = 0; //답
    
    if(result == 10){
        return -1;
    }
    
    while(!q.empty()){
        int size = (int)q.size();
        while(size--){

        pair<pair<int, int>, pair<int, int>> cur = q.front();
        q.pop();
        
        int redX = cur.first.first;
        int redY = cur.first.second;
        int blueX = cur.second.first;
        int blueY = cur.second.second;
        
        if(map[redX][redY] == 'O' && map[redX][redY] != map[blueX][blueY]){ // 구멍을 찾으면 근데 같이 통과하지 않으면
            return result;
        }
            
        
        // 움직이자
        for(int i =0; i < 4; i++){
            int nextRedX = redX;
            int nextRedY = redY;
            int nextBlueX = blueX;
            int nextBlueY = blueY;

            while(map[nextRedX + dx[i]][nextRedY + dy[i]] != '#' && map[nextRedX][nextRedY] != 'O'){
                nextRedX += dx[i];
                nextRedY += dy[i];
            }
            
            while(map[nextBlueX + dx[i]][nextBlueY + dy[i]] !='#' && map[nextBlueX][nextBlueY] != 'O'){
                nextBlueX += dx[i];
                nextBlueY += dy[i];
            }
    
            if(map[nextBlueX][nextBlueY] == 'O') // 파란 공이 먼저 도착했을 경우 예외처리!! 이부분 안해서 틀렸다.
            {
                continue;
            }
            
            if(nextRedX == nextBlueX && nextRedY == nextBlueY){ // 두 공의 위치가 같다면
                //움직인 거리로 누가 뒤에 갈지 판별
                if(map[nextRedX][nextRedY] == 'O')
                {
                    continue;
                }
                
                if(abs(nextRedX- redX) + abs(nextRedY - redY) < abs(nextBlueX - blueX) + abs(nextBlueY - blueY)){
                    nextBlueX -= dx[i];
                    nextBlueY -= dy[i];
                }else{
                    nextRedX -= dx[i];
                    nextRedY -= dy[i];
                }
            }
            
            if (visit[nextRedX][nextRedY][nextBlueX][nextBlueY]) continue; // 방문 했다면 무시
            visit[nextRedX][nextRedY][nextBlueX][nextBlueY] = true; // 방문 표시
            q.push({ {nextRedX,nextRedY}, {nextBlueX, nextBlueY}});
        }
    }
    if (result >= 10) return -1; // 문제 조건
    result++;
        
        
        
    }
    
    return -1; // queue가 비어있을때
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<= N; i++){
        for(int j = 1; j<= M; j++){
            char temp;
            cin >> temp;
            if(temp == 'R'){
                redStart = make_pair(i, j); // 빨간 구슬 시작 위치 기록
            }else if(temp == 'B'){
                blueStart = make_pair(i, j);
            }else if(temp == 'O'){
                holeStart = make_pair(i, j);
            }
            map[i][j] = temp;
        }
    }
    
//    for(int i = 1; i<= N; i++){
//        for(int j = 1; j<= M; j++){
//            cout << map[i][j] << " ";
//        }
//        cout <<'\n';
//    }
    
    cout << find_hole_bfs() << '\n';
    
    return 0;
}
