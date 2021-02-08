//
//  10952.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/23.
//


#include <iostream>
#include <vector>


using namespace std;

int main (){
   
    vector<int> a;
    vector<int> b;
    int tempA = -1, tempB = -1,result = 0;
    
    while(tempA != 0 and tempB != 0){
        cin >> tempA >> tempB;
        a.push_back(tempA);
        b.push_back(tempB);
    }
    for(int i=0; i< a.size()-1; i++){
        result = a.at(i) + b.at(i);
        cout<< result << endl;
    }
    
}
