class Solution {
public:
    string reverseWords(string s) {
        // Remove extra spaces
        string result, word;
        vector<string> words;
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};





