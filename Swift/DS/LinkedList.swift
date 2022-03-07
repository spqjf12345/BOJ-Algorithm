//
//  LinkedList.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/07.
//

import Foundation

public class Node {
    var value: String
    var next: Node?
    weak var previous: Node?
    init(value: String){
        self.value = value
    }
}

public class LinkedList {
  fileprivate var head: Node?
  private var tail: Node?

  public var isEmpty: Bool {
    return head == nil
  }

  public var first: Node? {
    return head
  }

  public var last: Node? {
    return tail
  }
    public func append(value: String){
        let newNode = Node(value: value)
        if let tailNode = tail {
            newNode.previous = tailNode
            tailNode.next = newNode
        }else {
            head = newNode
        }
        
        tail = newNode
        
    }
    
    public func nodeAt(index: Int) -> Node? {
        if index >= 0 {
            var node = head
            var i = index
            
            while node != nil {
                if i == 0 { return node } // index 횟수만큼 이동
                i -= 1
                node = node!.next
            }
        }
        return nil
    }
    
    //remove all node
    public func removeAll(){
        head = nil
        tail = nil
    }
    
    //remove particular node
    public func remove(node: Node) -> String {
      let prev = node.previous // node = 삭제하고자 하는 노드
      let next = node.next

      if let prev = prev { // 중간 노드라면 prev가 있을 것
        prev.next = next // 1
      } else {
        head = next // 2 else 앞노드일것
      }
      next?.previous = prev // 3

      if next == nil { // tail에 있는 노드 였을 것
        tail = prev // 4
      }

      // 5
      node.previous = nil // 해제
      node.next = nil
    return node.value
    }
}

extension LinkedList: CustomStringConvertible {
    public var description: String {
        var text = "["
        var node = head
        
        while node != nil {
            text += "\(node!.value)"
             node = node!.next
             if node != nil { text += ", " }
        }
        return text + "]"
    }
    
    
}


