//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/17.
//

import Foundation
var n = Int(readLine()!)!
var crain: [Int] = readLine()!.split(separator: " ").map { Int($0)! }.sorted(by: > )
var m = Int(readLine()!)!
var box: [Int] = readLine()!.split(separator: " ").map { Int($0)! }.sorted(by: > )
var t = 0
var boxIndex = 0
var crainIndex = 0

func countBoxMove() -> Int {
    if(crain.first! < box.first!){
        return -1
    }
    
    while(!box.isEmpty){
        t += 1
        for i in 0..<n {
            for j in 0..<box.count {
                if(crain[i] >= box[j]){
                    box.remove(at: j)
                    break
                }
            }
        }
    }
    return t
    
}

print(countBoxMove())







