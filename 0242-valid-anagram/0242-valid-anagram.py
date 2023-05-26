class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        book = defaultdict(int)
        for i in range(len(s)):
            book[s[i]] += 1
        
        for i in range(len(t)):
            book[t[i]] -= 1
        
        return all([elem == 0 for elem in book.values()])
    