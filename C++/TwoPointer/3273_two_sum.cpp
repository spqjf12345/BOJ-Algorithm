//
//  3273_two_sum.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> arr;
int x;
int cnt = 0;

void find_two_sum(){
    sort(arr.begin(), arr.end());
    int start = 0, end = N - 1;
    while(start< end){
        if(arr[start] + arr[end] == x){
            cnt++;
            start++;
            end--;
        }else if(arr[start] + arr[end] < x){
            start++;
        }else{
            end--;
        }
    }

}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    cin >> x;
    find_two_sum();
    cout << cnt << '\n';
    return 0;
}
