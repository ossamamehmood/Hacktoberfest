#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

void generateCodes(char ch, string code, unordered_map<char, string> &codes);

string huffmanCoding(string text)
{
    unordered_map<char, int> frequency;
    for (char ch : text)
        frequency[ch]++;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    for (auto it = frequency.begin(); it != frequency.end(); it++)
        pq.push(make_pair(it->second, it->first));

    while (pq.size() > 1)
    {
        pair<int, char> min1 = pq.top();
        pq.pop();
        pair<int, char> min2 = pq.top();
        pq.pop();

        pq.push(make_pair(min1.first + min2.first, '\0'));

        // Combine the two minimum frequency characters using a special character '\0' as the parent
    }

    unordered_map<char, string> codes;
    string code;

    if (!pq.empty())
    {
        code = "";
        generateCodes(pq.top().second, code, codes);
    }

    string encodedText = "";
    for (char ch : text)
        encodedText += codes[ch];

    return encodedText;
}

void generateCodes(char ch, string code, unordered_map<char, string> &codes)
{
    if (ch != '\0')
        codes[ch] = code;

    if (ch == '\0')
    {
        generateCodes(ch, code + "0", codes);
        generateCodes(ch, code + "1", codes);
    }
}

int main()
{
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    string encodedText = huffmanCoding(text);

    cout << "Encoded text: " << encodedText << endl;

    return 0;
}
