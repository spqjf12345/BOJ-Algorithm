//
//  1969_DNA.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/16.
//

#include <iostream>
#include <unordered_map>
using namespace std;
int N, cnt;

unordered_map<char, int> map;
int result_sum = 0;

int main(){
    cin >> N >> cnt;
    string s = "";
    string word[N];
    
    for(int i = 0; i < 26; i++){ //initial
        map['A' + i] = 0;
    }
    
    for(int i =0; i < N; i++){
        cin >> word[i];
    }
    
    for(int i =0; i < cnt; i++){ // 한 줄
        for(int j = 0; j < N; j++){
            map[word[j][i]]++;
        }
        
        int max_count = 0; int max_index = 0;
        
        for(int j = 0; j < 26; j++){
            if(map[j+'A'] > max_count) {
                max_count = map[j+'A'];
                max_index = j;
                cout << "max_count " << max_count << '\n';
            }
        }

        result_sum += N - max_count;
        s += max_index + 'A';
        
        map.clear();

        
    }
    
    cout << s << '\n';
    cout << result_sum << '\n';
    return 0;
}

