class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string result;
        int spacesIndex = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (spacesIndex < spaces.size() && i == spaces[spacesIndex]) {
                result += " ";
                spacesIndex++;
            }
            result += s[i];
        }
        while (spacesIndex < spaces.size()) {
            result += " ";
            spacesIndex++;
        }

        return result;
    }
};