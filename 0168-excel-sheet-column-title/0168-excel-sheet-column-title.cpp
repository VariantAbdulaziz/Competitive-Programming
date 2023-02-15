class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;
        while (columnNumber) {
            int next = (columnNumber - 1) / 26;
            title.push_back((columnNumber - 1) % 26 + 'A');
            columnNumber = next;
        }
        reverse(begin(title), end(title));
        return title;
    }
};