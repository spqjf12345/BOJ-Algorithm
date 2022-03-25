//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/17.
//
import Foundation

var height = [140, 21, 21, 32]
var width = [2, 1, 3, 7]

var max = height.max()
var min = height.min()
var index = 0
var s = 0
for idx in 0..<height.count {
    if height[idx] == max {
        s = height[idx] * width[idx]
    }
    if height[idx] == min{
        height[idx] = 0
        width[idx] = 0
    }
}

func updateS() {
    
}
print(s)
print(height)
print(width)
