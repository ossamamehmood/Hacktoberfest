#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {

        vector<string> result;
        int i = 0;

        while (i < words.size())
        {

            int wordCount = 0, lineLen = 0;
            while (i + wordCount < words.size() &&
                   lineLen + words[i + wordCount].length() + wordCount <= maxWidth)
            {
                lineLen += words[i + wordCount].length();
                wordCount++;
            }

            string line;
            if (wordCount == 1 || i + wordCount == words.size())
            {
                for (int j = 0; j < wordCount; j++)
                {
                    line += words[i + j] + " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else
            {
                int spaces = (maxWidth - lineLen) / (wordCount - 1);
                int extra = (maxWidth - lineLen) % (wordCount - 1);
                for (int j = 0; j < wordCount; j++)
                {
                    line += words[i + j];
                    if (j != wordCount - 1)
                    {
                        line += string(spaces + (extra-- > 0 ? 1 : 0), ' ');
                    }
                }
            }
            result.push_back(line);
            i += wordCount;
        }
        return result;
    }
};

int main()
{
    // call the fn here
    return 0;
}