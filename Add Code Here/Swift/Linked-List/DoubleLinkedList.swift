//
//  DoubleLinkedList.swift
//  DoubleLinkedList
//
//  Created by Stevhen on 14/10/22.
//

import Foundation

public class Student {
    var id: String
    var name: String
    var age: Int
    
    init(id: String, name: String, age: Int){
        self.id = id
        self.name = name
        self.age = age
    }
}

//To create Node property
public class Node<T> {
    var value: T
    
    init(value: T){
        self.value = value
    }
    
    var next: Node<T>?
    weak var prev: Node<T>?
}

//Data Structure logics
public class DoubleLinkedList<T> {
    fileprivate var head: Node<T>?
    private var tail: Node<T>?
    
    public var isEmpty: Bool {
        return head == nil
    }
    
    public var first: Node<T>? {
        return head;
    }
    
    public var last: Node<T>? {
        return tail
    }
    
    public func push(value: T) {
        
        let curr = Node(value: value)
        
        if let tailNode = tail {
            curr.prev = tailNode
            tailNode.next = curr
        } else {
            head = curr
        }
        
        tail = curr
    }
    
    public func getNode(index: Int) -> Node<T>? {
        
        if index >= 0 {
            var curr = head
            var i = index
            
            while curr != nil {
                if i == 0 { return curr }
                i -= 1
                curr = curr!.next
            }
        }
        
        return nil
    }
    
    public func getSize() -> Int{
        var curr = head
        var  i: Int = 0
        
        while curr != nil {
            i += 1
            curr = curr!.next
        }
        
        return i
    }
    
    public func pop(curr: Node<T>) -> T {
        let prev = curr.prev
        let next = curr.next
        
        if let prev = prev {
            prev.next = next
        } else {
            head = next
        }
        
        next?.prev = prev
        
        if next == nil {
            tail = prev
        }
        
        curr.prev = nil
        curr.next = nil
        
        return curr.value
    }
    
    public func popAll() {
        head = nil
        tail = nil
    }
}

//Main Program
public func addStudent(){
    print("Enter Student id: ", terminator: "")
    let id: String? = readLine()
    print("Enter Student name: ", terminator: "")
    let name: String? = readLine()
    print("Enter Student age: ", terminator: "")
    let age: Int? = Int(readLine()!)
    
    list.push(value: Student(id: id!, name: name!, age: age!))
}

public func clrScr(){
    for _ in 1...25 {
        print("")
    }
}

public func separatorBar(){
    for _ in 1...45 {
        print("=", terminator: "")
    }
    print("")
}

public func showStudent(){
    
    if list.isEmpty {
        print("No data yet")
    }
    else{
        separatorBar()
        print(String(format: "| %-4s | %-12s | %-12s | %-4s |", ("No" as NSString).utf8String!,("ID" as NSString).utf8String!, ("Name" as NSString).utf8String!, ("Age" as NSString).utf8String!))
        separatorBar()
        for i in 0..<list.getSize() {
            let curr = list.getNode(index: i)
            print(String(format: "| %-4d | %-12s | %-12s | %-4d |", i+1, (curr!.value.id as NSString).utf8String!, (curr!.value.name as NSString).utf8String!, curr!.value.age))
        }
        separatorBar()
    }
    
}

public func removeStudent(){
    if list.isEmpty {
       print("No data yet")
   }
   else{
        var pos: Int! = -1

        print("Remove Student")
        showStudent()

        print("")
        print("Enter number to remove: ", terminator: "")
        
        repeat {
            if let str = readLine(){
                pos = Int(str)!
            }
        } while pos < 1 || pos > list.getSize();
        pos -= 1

        let student = list.pop(curr: list.getNode(index: pos)!)

        print("Student with ID: \(student.id) removed")
    }
}

public func removeAllStudent(){
    list.popAll()
    print("All Student removed")
}

let list = DoubleLinkedList<Student>()

//Dummy data
list.push(value: Student(id: "1234567891", name: "Andy", age: 19))
list.push(value: Student(id: "1234567892", name: "Clarissa", age: 20))
list.push(value: Student(id: "1234567893", name: "Robert", age: 19))

while true {
    
    clrScr()
    var choose: Int! = 0;
    
    print("Students List Program")
    print("=====================")
    print("Menu")
    print("1. Add")
    print("2. Show")
    print("3. Remove")
    print("4. Remove All")
    print("5. Exit")
    
    repeat {
        print("Input: ", terminator: "")
        if let str = readLine(){
         choose = Int(str)
        }
    } while choose < 1 || choose > 5;
    
    switch choose {
        case 1:
            addStudent()
        case 2:
            showStudent()
        case 3:
            removeStudent()
        case 4:
            removeAllStudent()
        case 5:
            print("Thank you for using this program :)")
        default:
            print("")
    }
    
    _ = readLine()

    if choose == 5 {
        break
    }
}
