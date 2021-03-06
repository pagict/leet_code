class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = s.strip()
        if len(s) is 0:
            return s
            
        words = s.split(' ')
        ret = ''
        for i in reversed(words):
            if i is '' or i is ' ':
                continue
            ret = ret + ' ' + i

        return ret.strip()