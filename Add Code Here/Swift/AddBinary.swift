class AddBinary {
    func addBinary(_ a: String, _ b: String) -> String {
        let a = Array(a), b = Array(b)
        var res = "", carry = 0, i = a.count - 1, j = b.count - 1

        while i >= 0 || j >= 0 || carry > 0 {
            var sum = carry

            if i >= 0 {
                sum += Int(String(a[i]))!
                i -= 1
            }
            if j >= 0 {
                sum += Int(String(b[j]))!
                j -= 1
            }

            res = "\(sum % 2)" + res
            carry = sum / 2
        }

        return res
    }
}
