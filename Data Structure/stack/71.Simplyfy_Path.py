class Solution(object):
    def simplifyPath(self, path):
        stk, tokens = [], path.split("/")

        for token in tokens:
            if token == "" or token == ".":
                continue

            if token == "..":
                if stk:
                    stk.pop()
            else:
                stk.append(token)

        return "/" + "/".join(stk)

