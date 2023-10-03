"""
Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
"""

def is_anagram(s:str, t:str) -> bool:
    return sorted(s) == sorted(t)

if __name__ == "__main__":
    s = "car"
    t = "rca"
    print(is_anagram(s, t))