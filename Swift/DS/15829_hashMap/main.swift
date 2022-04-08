//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation

//make hashMap
var map: [Character: Int] = [:]
let mod = 1234567891

for i in 0..<26 {
    let e = Character(UnicodeScalar(97 + i)!)
    map[e] = i+1
}

readLine()

var str = Array(readLine()!)
var answer = 0
var r = 31
var m = 1
for idx in str {
    let a = map[idx]!
    answer = (answer + a * m) % mod
    m = (r * m) % mod
}
print(answer)
