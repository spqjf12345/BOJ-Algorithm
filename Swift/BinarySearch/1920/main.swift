//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

import Foundation
var arrN: [Int] = []
var arrM: [Int] = []

func binearySearch(arrN:[Int], target: Int) -> Int {
    var lowerBound = 0
    var upperBound = arrN.count
    while(lowerBound < upperBound) {
        let midIndex = lowerBound + (upperBound - lowerBound) / 2
        if(arrN[midIndex] == target) {
            return 1
        }else if(arrN[midIndex] < target){
            lowerBound = midIndex + 1
        }else {
            upperBound = midIndex
        }
    }
    return 0
}


func Main(){
    let N = Int(readLine()!)!
    arrN = readLine()!.split(separator: " ").map { Int(String($0))! }


    let M = Int(readLine()!)!
    arrM = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    arrN = arrN.sorted()
    for i in arrM {
        print(binearySearch(arrN: arrN, target: i))
    }
}

Main()


