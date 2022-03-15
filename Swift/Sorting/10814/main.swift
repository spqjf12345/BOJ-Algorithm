//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/16.
//

import Foundation
var n = Int(readLine()!)!
var pairDic = [(Int, String)]()
for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map { String($0) }
    let age = Int(line[0])!
    let name = line[1]
    pairDic.append((age, name))
}
pairDic.sort { (first, second) in
    if(first.0 == second.0) {
        return false
    }
    return first.0 < second.0
}

for i in pairDic {
    print("\(i.0) \(i.1)")
}
