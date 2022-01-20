//
//  5567_wedding.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/07.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int N;
int Tcase;
int result = 0;
vector<int> friends[501];
int check[501];
queue<pair<int, int>> q;

void find_real_friends(){
    while(!q.empty()){
        int next;
        if(q.front().first == 1){
            next = q.front().second; // 친구
        }else{
            next = q.front().first; // 친구
        }
      
        check[next] = true;
         
        for(int i = 0; i < friends[next].size(); i++){ // 친구의 친구
            if(check[friends[next][i]] == false){
                check[friends[next][i]] = true;
                result++;
            }
        }
        q.pop();
    }
}

int main(){
    cin >> N;
    cin >> Tcase;
    memset(check, false, sizeof(check));
    for(int i = 1; i <= Tcase; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1 || b == 1){
            q.push({a, b}); // 내 친구들만 push
            check[a] = check[b] = true;
            result++;
        }
        
        friends[a].push_back(b);
        friends[b].push_back(a);
 
        
    }

    find_real_friends();
    cout << result << '\n';
    return 0;
}
