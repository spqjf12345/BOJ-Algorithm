//
//  3190_snake.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/30.
//

#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int n, apple, mv;
char mv_pair[10001] = {'A', };
bool arr[101][101] = {false, };
bool Is_There_Snake[101][101] = {false, };

void search_snake(){
    int cnt = 0;
    queue<pair<int,int>> snake;
    snake.push({1, 1}); // 뱀의 처음 위치
    Is_There_Snake[1][1] = true; // 뱀의 몸통 위치
    int direction = 0;
    while(1) {
        cnt++;
        int nextColumn = snake.back().first + dy[direction];
        int nextRow = snake.back().second + dx[direction];
        if(nextColumn > n || nextRow > n || nextColumn < 1 || nextRow < 1){
            break; // 벽에 부딪치면 종료
        }
        snake.push({ nextColumn, nextRow });
        
        //방향 변경
        if (mv_pair[cnt] == 'D') { // right
            direction += 1;
            if (direction == 4) direction = 0;
        }else if (mv_pair[cnt] == 'L') { // left
            direction -= 1;
            if (direction == -1) direction = 3;
        }
        
        if(arr[nextColumn][nextRow]){ // 사과 있다면
            arr[nextColumn][nextRow] = false; // 사과 먹음
        }else {
            if (Is_There_Snake[nextColumn][nextRow] == true) break;
            //사과 없다면 꼬리 없애고, 머리 늘림
            Is_There_Snake[snake.front().first][snake.front().second] = false;
            snake.pop();
        }
        //snake 위치 증가
        Is_There_Snake[nextColumn][nextRow] = true;
    }
    
    cout << cnt << '\n';

}

int main(){
    cin >> n;
    cin >> apple;
    
    for(int i = 0; i < apple; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = true; // 사과 있는곳
    }
    
    cin >> mv;
    for(int i = 0; i < mv; i++){
        int time; char direction;
        cin >> time >> direction;
        mv_pair[time] = direction;
    }
    search_snake();
    
    return 0;
}
