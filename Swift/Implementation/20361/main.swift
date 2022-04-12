//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/12.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var x = line[1]
var k = line[2]
var answer = x

for _ in 0..<k {
    var line = readLine()!.split(separator: " ").map { Int(String($0))! }
    var l1 = line[0]
    var l2 = line[1]
    if(l1 == answer){
        answer = l2
    }else if(l2 == answer) {
        answer = l1
    }
}

print(answer)
