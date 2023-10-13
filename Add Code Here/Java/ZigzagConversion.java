/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"


Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I


Example 3:

Input: s = "A", numRows = 1
Output: "A" 
 */

public class ZigzagConversion {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s; // No need to convert if numRows is 1
        }
        
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }
        
        int direction = -1; // Initialize the direction to move (up or down)
        int currentRow = 0;
        
        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);
            
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction *= -1; // Change direction at the first and last rows
            }
            
            currentRow += direction;
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        
        return result.toString();
    }
}
