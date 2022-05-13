//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/13.
//

import Foundation

var n = Int(readLine()!)!
var line = [(Int, Int)]()
for _ in 0..<n {
    let l = readLine()!.split(separator: " ").map { Int($0)! }
    line.append((l[0], l[1]))
}

line.sort(by: {left, right in
    left.0 < right.0
})
print(line)
let target = line.map { $0.1 }
var d = Array(repeating: 0, count: target.count)
print(target)

//LIS
var max = 0
for i in 0..<target.count {
    d[i] = 1
    for j in 0..<i {
        if target[j] < target[i] && d[j] + 1 > d[i] {
            d[i] = d[j] + 1
            if(max < d[i]) { max = d[i] }
        }
    }
}

print(n - max)
