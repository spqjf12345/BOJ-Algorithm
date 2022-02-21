//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/21.
//

import Foundation

var line = readLine()!
var isMinus = false
var num: String = ""
var answer = 0

for (idx, i) in line.enumerated() {
    if(i == "-" || i == "+" || idx == line.count) {
        if(isMinus){
            answer -= Int(num)!
        }else{
            answer += Int(num)!
        }
        num = ""
    }else { // 숫자 누적
        num += "\(i)"
    }
    if(i == "-"){
        isMinus = true
    }
}

if(isMinus){
    answer -= Int(num)!
}else{
    answer += Int(num)!
}


print(answer)
