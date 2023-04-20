class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        seen = ""
        count = 0

        for i in range(len(s)):

            if s[i] not in seen:
                seen = seen + s[i]
            else:
                seen = seen[seen.index(s[i])+1:] + s[i]

            count = max(count,len(seen))

        return count
