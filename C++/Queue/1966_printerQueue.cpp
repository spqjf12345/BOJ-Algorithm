//
//  1966_printerQueue.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/01.
//

#include <iostream>
#include <queue>

using namespace std;

int Tcase;

int main(){
    cin >> Tcase;
    for(int i =0; i < Tcase; i++){
        int n, top;
        cin >> n >> top;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            pq.push(a); // num, index
            q.push({a, j});
        }
        int answer = 0;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            if(pq.top() == cur.first){
                pq.pop();
                answer++;
                if(cur.second == top){ // 원하는 index의 문서라면 answer 출력
                    break;
                }
            }else {
                q.push(cur);
            }
            
        }
        cout << answer << '\n';
        
        
        
    }
    
    
    return 0;
}
