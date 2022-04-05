//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/05.
//

import Foundation
var input: Int = -1
var line: [Int] = []
var bool: [Bool] = []
var inputArr: [Int] = []

//combination nC6
func backtracking_lotto(start: Int) {
    
    if(inputArr.count == 6){
        print(inputArr.map{String($0)}.joined(separator: " "))
    }
    
    for idx in start..<line.count {
        let i: Int = line[idx]
        if(!bool[idx]){ if(inputArr.contains(i)){ continue }
            bool[idx] = true
            inputArr.append(i)
            backtracking_lotto(start: idx)
            inputArr.removeLast()
            bool[idx] = false
        }
    }
    
    
}

while(input != 0){
    line = readLine()!.split(separator: " ").map { Int($0)! }

    if(line[0] == 0){ break }
    
    bool = Array(repeating: false, count: line[0])
    inputArr = []
    line.removeFirst()
    backtracking_lotto(start: 0)
    print()
    input = line[0]
}
