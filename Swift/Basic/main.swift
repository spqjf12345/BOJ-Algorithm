//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/07.
//

import Foundation
var n = Int(readLine()!)!
for _ in 0..<n {
    let line:[Int] = readLine()!.split(separator: " ").map { Int($0)! }
    let leg = line[0]
    let cnt = line[1]
    let not = cnt * 2 - leg
    let good = cnt - not
    print("\(not) \(good)")
}
