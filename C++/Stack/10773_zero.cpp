//
//  main.cpp
//  temp
//
//  Created by JoSoJeong on 2021/02/24.
//

#include <iostream>
#include <stack>

using namespace std;
int main(int argc, const char * argv[]) {
    stack<int> s;
    int N;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        if(num != 0){
            s.push(num);
        }else{
            s.pop();
        }
    }
    
    int sum = 0;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        sum += temp;
    }
    cout << sum << endl;
    
    return 0;
}
