//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

import Foundation
var line = readLine()!
print(line.sorted(by: >).map { String($0) }.joined(separator: ""))



