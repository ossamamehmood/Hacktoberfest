from collections import Counter

class Solution:
    def equalFrequency(self, word: str) -> bool:
        # Step 1: Count the frequencies of each character using Counter.
        c = Counter(word)
        
        # Step 2: Extract the frequencies and sort them.
        freq = sorted([c[i] for i in c])
        
        # Step 3: Check if there's only one unique frequency.
        if len(freq) == 1:
            return True
        
        # Step 4: Check two conditions to determine if it's possible to make frequencies equal.
        # Condition 1: Minimum frequency is 1 and all other frequencies are the same.
        # Condition 2: All frequencies except the maximum one are the same, and max frequency is one greater.
        if (min(freq) == 1 and len(set(freq[1:])) == 1) or (len(set(freq[:-1])) == 1 and freq[-1] == freq[0] + 1):
            return True
        
        # Step 5: If none of the conditions are met, return False.
        return False
