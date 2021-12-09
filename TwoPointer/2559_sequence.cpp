//
//  2559_sequence.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/09.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
int n, k;
vector<int> v;
int result = 0;
int nextValue = 0;
void initial(){
    for(int i =0; i < k; i++){
        result += v[i];
    }
}

int two_pointer(){
    nextValue = result;
    for(int i = 0; i < (v.size() - k); i++){
        int start = i;
        int end = i + k;
        nextValue = nextValue - v[start] + v[end];
//        cout << "start " << start << "end " << end <<'\n';
//        cout << "next " << nextValue << '\n';
        
        if(nextValue > result){
            result = nextValue;
        }
    }
   
    
    return result;
}

int main(){
    cin >> n >> k;
    for(int i =0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    initial();
    cout << two_pointer() << '\n';
    return 0;
}
