class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        B = []
        for x in A:
            if x is 1 or x is -1:
                continue
            else:
                
        if len(B) is 0:
            count = 0
            for x in A:
                if x is -1:
                    count = count + 1
            if count % 2:
                return -1
            else:
                return 1
                
        A = B       
        max = -99999
        for start in range(len(A)):
            prod = 1
            for i in range(start,len(A)):
                prod = prod * A[i]
                if prod > max:
                    max = prod
        return max
            

s = Solution()
s.maxProduct([3,-1,4])
