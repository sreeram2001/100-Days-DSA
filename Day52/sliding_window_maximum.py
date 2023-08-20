class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if len(t) > len(s):
            return ""

        windDict = {}
        minLen = 10**6
        windStart = 0
        left = 0    #two pointer for start and end of the window
        count = 0

        #iterate from 0->len(t) to add freq of each item of s in map
        for i in range(len(t)):
            if t[i] not in windDict:
                windDict[t[i]] = 1
            else:
                windDict[t[i]] += 1

        #now we iterate from 0->len(s), string s to find our minim window subtring
        for right in range(0, len(s)):
            
            #if current char is a part of string t
            if (s[right] in windDict) and windDict[s[right]] > 0:
                count += 1

            #reduce the value of char from dict/map reduce the freqeuncy
            if s[right] in windDict: 
                windDict[s[right]] -= 1
            else:
                windDict[s[right]] = -1

            #check if our window has all elements of string t
            if(count == len(t)):

                #we move left/start pointer position as long as we don't need the letters
                #now we remove all unwanted letters of string s which is not part of s
                while(left < right and windDict[s[left]] < 0):
                    windDict[s[left]] += 1
                    left += 1

                if minLen > (right - left):
                    windStart = left
                    minLen = (right - left + 1)
                
                #now lets increase frequency of our left/start pointer index element
                #since we deleted it, and it was also part of string t
                windDict[s[left]] += 1
            
                #reduce the value of count as we move our left pointer to next item
                count -= 1
            
                #to slide the window increase left pointer to next index
                left += 1

        if minLen == 10**6:
            return ""

        return s[windStart : windStart + minLen]
