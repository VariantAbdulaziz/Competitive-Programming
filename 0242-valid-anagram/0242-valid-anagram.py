class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        slist = sorted(s)
        tlist = sorted(t)
        return len(s) == len(t) and all([ti == si for ti, si in zip(tlist, slist)])
    