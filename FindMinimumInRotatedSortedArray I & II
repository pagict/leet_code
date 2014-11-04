class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        if len(num) is 1:
            return num[0]
        for i in range(1,len(num)):
            if num[i-1] > num[i]:
                return num[i]
        if i is len(num)-1:
            return num[0]