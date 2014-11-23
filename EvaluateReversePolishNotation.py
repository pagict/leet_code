class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        if len(tokens) is 0:
            return 0
        operand=['+', '-', '*', '/']
        num_stack = []
        
        for op in tokens:
            if op in operand:
                b = num_stack.pop()
                a = num_stack.pop()
                if op is '+':
                    value = a + b
                elif op is '-':
                    value = a - b
                elif op is '*':
                    value = a * b
                else:
                    value = abs(a) / abs(b)
                    if a*b < 0:
                        value = value * -1
                num_stack.append(value)
            else:
                num_stack.append(int(op))
                
        return num_stack[0]