//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/26.
//

import Foundation
var A = 0
var B = 0
var C = 0

var input = readLine()!.split(separator: " ").map { Int($0)! }
A = input[0]
B = input[1]
C = input[2]

print((A+B) % C)
print(((A%C) + (B%C))%C)
print((A*B)%C)
print(((A%C) * (B%C))%C)



