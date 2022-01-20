//
//  1939_restrictWeight.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/29.
//


///BFS with twoPointer
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>


using namespace std;
#define MAX 100001
int maxCost = 0;
vector<pair<int, int>> arr[MAX];
int N, M;
bool visit[MAX];
int result_start, result_end;

bool make_bfs(int mid_cost){
    // 1-> 2 : 2
    // 1-> 3 : 3
    // 2 -> 3 : 2
    queue<int> q;
    q.push(result_start); //1
    visit[result_start] = true;
    
    while(q.size() != 0){
        int now = q.front();
        q.pop();
        
        if(now == result_end) { //3
            return true;
        }

        for(int i =0; i < arr[now].size(); i++){
            int next = arr[now][i].first;
            int nextCost = arr[now][i].second;
            if(visit[next] == false && mid_cost <= nextCost){
                visit[next] = true;
                q.push(next);
            }
        }
        
    }
    
    return false;
}

void bi_search(){
    int left = 1;
    int right = maxCost; //3
    
    while(left <= right){
        memset(visit, false, sizeof(visit));
        int mid = (left + right) / 2;
        if(make_bfs(mid) == true){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << right << '\n';
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        arr[start].push_back({end, weight}); //양방향 o
        arr[end].push_back({start, weight});
        maxCost = max(maxCost, weight);
    }

    cin >> result_start >> result_end;
    
    bi_search();
    return 0;
}
