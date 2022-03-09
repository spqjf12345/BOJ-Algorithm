//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/09.
//

import Foundation
var n: Int = Int(readLine()!)!

var distance = readLine()!.split(separator: " ").map { Int($0)! }
var price = readLine()!.split(separator: " ").map { Int($0)! }

var curP = price[0]
var sum = 0

for i in 1..<n {
    if curP > price[i] {
        sum += curP * distance[i-1]
        curP = price[i]
    }else {
        sum += curP * distance[i-1]
    }
}
print(sum)



