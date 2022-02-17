//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

import Foundation

let input = readLine()!
let inputArr = Array(input)
var s = 0

var arr : [Int] = Array(repeating: -1, count: 26)

for i in inputArr {
    let idx = (Character(extendedGraphemeClusterLiteral: i).unicodeScalars.first?.value)! - 97
    
    if let rangeS = input.range(of: "\(i)") {
        s = input.distance(from: input.startIndex, to: rangeS.lowerBound)
    }
    arr[Int(idx)] = s
}
for i in arr {
    print(i, terminator: " ")
}

