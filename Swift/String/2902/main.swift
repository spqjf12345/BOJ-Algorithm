//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

import Foundation
var line = readLine()!
var result: String = String(line[line.index(line.startIndex, offsetBy: 0)])

while true {
    if (line.range(of: "-") != nil) {
        let idx:Int = line.distance(from: line.startIndex, to: line.range(of: "-")!.lowerBound)
        result += String(line[line.index(line.startIndex, offsetBy: idx + 1)])
        line.remove(at: line.index(line.startIndex, offsetBy: idx))
    }else {
        break;
    }
}

print(result)
