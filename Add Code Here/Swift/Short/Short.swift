import Foundation

var names = ["Mahmud", "Rosidi", "Fara", "Raka", "Cabul"]
names.sort()

struct User {
    var firstName: String
}

var users = [
    User(firstName: "Mahmud"),
    User(firstName: "Rosidi"),
    User(firstName: "Fara"),
    User(firstName: "Raka"),
    User(firstName: "Cabul")
]

users.sort {
    $0.firstName < $1.firstName
}

let sortedUsers = users.sorted {
    $0.firstName < $1.firstName
}


print("hasil short = \(names)")