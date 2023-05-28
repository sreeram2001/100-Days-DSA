class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        op = []
        map = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]

        def recurs_comb(digits, ind, newcombo):
            if(ind >= len(digits)):
                if len(newcombo) > 0:
                    op.append(newcombo)
                return

            mapi = map[int(digits[ind]) - 2]

            for i in range(0,len(mapi)):
                recurs_comb(digits,ind+1,newcombo+mapi[i])

        recurs_comb(digits, 0, "")
        return op

            

            
