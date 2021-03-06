//
//  2617_ㅡmarble.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/11.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

#define MAX 101
int n, N;
bool visit[2][MAX];
vector<int> light[MAX];
vector<int> heavy[MAX];
bool check[MAX];
int cnt = 0;

int find_marble_dfs(int start, vector<int> graph[MAX], int row){//row 로 graph == heavy, light 인지 판별
    int Lank = 1; // 현재 순위
    for(int i = 0; i < (int)graph[start].size(); i++){
        if(visit[row][graph[start][i]] == false){
            visit[row][graph[start][i]] = true; // dfs 돌 수록 비교할 구슬이 많다는 것 따라서 순위 크기가 증가 (ex> 1 -> 8)
            Lank += find_marble_dfs(graph[start][i], graph, row);
        }
    }
    return Lank;
}

/* - using stack -
    stack<int> s;
    s.push(start);

    cout << start << " ";

    while(!s.empty()){

        int current_node = s.top();
        //s.pop();
        for(int i=0; i < (int)graph[current_node].size(); i++){//인접 노드에 대해서
            if( graph[current_node][i] !=0 && !visit[i]){
                current_node = i;
                s.push(current_node);
                visit[current_node] = true;
                cout << current_node << " " ;
                break;
            }
            else if(i == (int)graph[current_node].size() - 1){
                s.pop();//연결된 정점이 없거나 정점 중 방문할 정점이 없는 경우
            }
        }
    }
                
            int next_node = graph[current_node][i];

            if(visit[next_node] == false){
                printf("%d ", next_node);
                visit[next_node] = true;
                // pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
                s.push(current_node);
                s.push(next_node);
                break;
            }
}
}

    return cnt;
}*/


int main(){
    int n, N;
    cin >> n >> N;

    for(int i = 0; i< N; i++){
        int m1, m2; //m1 > m2
        cin >> m1 >> m2;
        light[m1].push_back(m2);
        heavy[m2].push_back(m1);
    }

    for (int i = 1; i <= n; i++) { // n = 구슬 번호 1 ~ n
        memset(visit, false, sizeof(visit));
        visit[0][i] = visit[1][i] = true;

        int h_rank = find_marble_dfs(i, heavy, 0);
        int l_Lank = find_marble_dfs(i, light, 1);

        if (h_rank > (n + 1) / 2 || l_Lank > (n + 1) / 2){ // 중간이 아닌 구슬들 check
            check[i] = true;
        }
    }

    for (int i = 0; i <= n; i++){
        if (check[i] == true){
            cnt++; //
        }
    }

    cout << cnt << endl;
        return 0;
}
