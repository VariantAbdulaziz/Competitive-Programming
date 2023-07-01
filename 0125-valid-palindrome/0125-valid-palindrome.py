class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1
        
        while l < r:
            if not s[l].isalnum():
                r += 1
            elif not s[r].isalnum():
                l -= 1
            elif s[r].lower() != s[l].lower():
                return False
            
            
            l += 1
            r -= 1
        return True