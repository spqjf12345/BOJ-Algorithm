//
//  InsertionSort.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

import Foundation

func insertionSort(_ array: [Int]) -> [Int] {
    var sortedArray = array
    for index in 1 ..< sortedArray.count {
        var currentIdx = index
        while(currentIdx > 0 && sortedArray[currentIdx] < sortedArray[currentIdx - 1]){
            sortedArray.swapAt(currentIdx - 1, currentIdx)
            currentIdx -= 1
        }
    }
    return sortedArray
}


