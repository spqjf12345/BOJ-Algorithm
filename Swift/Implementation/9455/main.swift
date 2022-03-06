//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/06.
//

import Foundation

var Tcase = Int(readLine()!)!
var m:Int = 0
var n:Int = 0
var distance: Int = 0
//input
for _ in 0..<Tcase {
    let line1 = readLine()?.split(separator: " ").map { Int($0)! }
    m = line1![0]
    n = line1![1]
    var arr: [[Int]] = []
    for _ in stride(from: 0, to: m, by: 1) {
        arr.append(readLine()!.split(separator: " ").map { Int(String($0))! })
    }

    distance = 0
    //move
    for i in stride(from: m-1, to: -1, by: -1){
        for j in stride(from: 0, to: n, by: 1){
            if arr[i][j] == 1 {
                var k = i + 1
                while(k < m){
                    if(arr[k][j] == 1){
                        //print(i, j, k, j, separator: " ")
                        distance += abs(k - i - 1)
                        let temp = arr[k-1][j]
                        arr[k-1][j] = arr[i][j]
                        arr[i][j] = temp
                        //arr.swapAt(arr[i][j], arr[k][j])
                        //print("distance 1 \(distance)")
                        break;
                    }else if(arr[k][j] == 0 && k == m - 1) {
                        //print(i, j, k, j, separator: " ")
                        distance += abs(k - i)
                        let temp = arr[k][j]
                        arr[k][j] = arr[i][j]
                        arr[i][j] = temp
                        //arr.swapAt(arr[i][j], arr[k][j])
                       // print("distance 2 \(distance)")
                    }
                    k+=1
                }
//                for k in stride(from: i+1, to: m, by: 1) {
//                    if arr[k][j] == 0 {
//                        print(i, j, k, j, separator: " ")
//                        arr.swapAt(arr[i][j], arr[k][j])
//                        distance += 1
//                    }
//                }
            }
        }
    }
    print(distance)

}

