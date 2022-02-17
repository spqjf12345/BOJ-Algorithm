//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

import Foundation
var N = Int(readLine()!)!
var list = [(Int, Int)]() // height, weight

for i in 0..<N {
    let line = readLine()!.split(separator: " ").map { Int($0)! }
    list.append((line[0], line[1]))
}

for i in 0..<N {
    var rank = 1
    for j in 0..<N {
        var target = list[i]
        if(target.0 < list[j].0 && target.1 < list[j].1) {
            rank += 1
        }
    }
    print(rank, terminator: " ")
    rank = 1
}
