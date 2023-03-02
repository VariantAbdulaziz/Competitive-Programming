class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        def _decodeString(s, j):
            sum = ''
            if j >= len(s):
                return sum, j
            if s[j].isdecimal():
                start = j
                while j < len(s) and s[j] != '[':
                    j += 1
                mul = eval(s[start:j])
                start = j+1
                result, j = _decodeString(s, j+1)
                sum += result
                nex_result, j = _decodeString(s, j+1)
                return (sum * mul + nex_result), j
            
            while j < len(s) and s[j] != ']':
                if s[j].isdecimal():
                    result, j = _decodeString(s, j)
                    sum += result
                else:
                    sum += s[j]
                    j += 1
            return sum, j
        
        result, j = _decodeString(s, 0)
        
        return result
            
        

            