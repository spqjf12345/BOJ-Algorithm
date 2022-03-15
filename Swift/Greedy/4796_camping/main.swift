//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/15.
//

import Foundation
var line = readLine()!.split(separator: " ").map{ Int($0)! }
var cnt = 1
var result = 0

while(line[0] != 0 && line[1] != 0 && line[2] != 0) {
    result = ((line[2] / line[1]) * line[0]) + min(line[2] % line[1], line[0])
    print("Case \(cnt): \(result)")
    cnt += 1
    line = readLine()!.split(separator: " ").map{ Int($0)! }
}
