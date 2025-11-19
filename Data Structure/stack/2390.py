class Solution:
    def removeStars(self, s: str) -> str:
        stk = []

        for ch in s:
            if ch == "*":
                if stk:
                    stk.pop()
            else:
                stk.append(ch)

        return "".join(stk)
