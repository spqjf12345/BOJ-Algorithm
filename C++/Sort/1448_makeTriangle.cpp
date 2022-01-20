//
//  1448_makeTriangle.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/10.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> arr;

int find_max_traingle(){
    for(int i = (int)arr.size() - 1; i > 1; i--){
        int a = arr[i]; int b = arr[i - 1]; int c = arr[i - 2];
        if(a < b + c) {
            return a + b + c;
        }
    }
    return -1;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    cout << find_max_traingle() << '\n';
    return 0;
}
