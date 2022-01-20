//
//  1477_rest.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/05.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

//
//using namespace std;
//int already, will, dis;
//int min_num = 0;
//vector<int> v;
//
//void set_rest(){
//    
//    int tmp_min = 0, tmp_idx;
//    int tmp_tmp_idx = 0;
//    while(will--){
//        sort(v.begin(), v.end());
//        for(int i = 1; i < (int)v.size(); i++){
//            if(tmp_min < (v.at(i) - v.at(i - 1))){
//                tmp_min = v.at(i) - v.at(i - 1);
//                tmp_tmp_idx = v.at(i - 1) + v.at(i);
//                //cout << "tmp_min : " << tmp_min << "\n";
//            }
//        }
//        
//        tmp_idx = tmp_min / 2;
//        tmp_min = 0;
//        v.push_back(tmp_tmp_idx/2);
//        //cout << "tmp_tmp_idx : " << tmp_tmp_idx/2 <<"\n";
//    }
//    
//    //cout << "size : " << v.size() << "\n";
//    sort(v.begin(), v.end());
//    for(int i = 1; i < (int)v.size(); i++){
//        //cout << v.at(i - 1) << " ";
//        
//        if(min_num < (v.at(i) - v.at(i - 1))){
//            min_num = v.at(i) - v.at(i - 1);
//        }
//        cout << "min is " << min_num << "\n";
//    }//
//    
//}
//
//int main(){
//    cin >> already >> will >> dis;
//    v.push_back(0);
//    for(int i = 0; i < already; i++){
//        int temp;
//        cin >>temp;
//        v.push_back(temp);
//    }
//    v.push_back(dis);
//    set_rest();
//    return 0;
//}
