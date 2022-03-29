//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

import Foundation

var n = Int(readLine()!)!
var tree: [String: Node<String>] = [:]

class Node<T: Comparable> {
    var left: T
    var right: T
    
    init(left: T, right: T){
        self.left = left
        self.right = right
    }
}

var preS = ""
var inS = ""
var postS = ""

func preOrder(value: String) {
    if(value == "."){
        return
    }
    preS += value
    preOrder(value: tree[value]!.left)
    preOrder(value: tree[value]!.right)
    
}

func inOrder(value: String){
    if(value == "."){
        return
    }
    inOrder(value: tree[value]!.left)
    inS += value
    inOrder(value: tree[value]!.right)
}

func postOrder(value: String){
    if(value == "."){
        return
    }
    postOrder(value: tree[value]!.left)
    postOrder(value: tree[value]!.right)
    postS += value
}

for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map{ String($0) }
    tree[line[0]] = Node(left: line[1], right: line[2])
}

preOrder(value: "A")
inOrder(value: "A")
postOrder(value: "A")

print(preS)
print(inS)
print(postS)
