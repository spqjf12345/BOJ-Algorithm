//
//  14921_ synthesize.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> solution;
int min_sol = 0;
void find_min_synthesize(){
    int left = 0;
    int right = N - 1;
    sort(solution.begin(), solution.end());
    min_sol = 1000000000;
    
    while(left < right){
        int sum = solution[left] + solution[right];
        //cout << sum << '\n';
        if(abs(min_sol) > abs(sum)){
            min_sol = sum;
        }
        
        if(sum > 0){
            right--;
        }else {
            left++;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int sol;
        
        cin >> sol;
        solution.push_back(sol);
    }
    
    find_min_synthesize();
    
    cout << min_sol << '\n';
    return 0;
}
