class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    return (str1 + str2== str2 + str1) ? str1.substr(0, gcd(str1.length(), str2.length())): ""; 
    }
};