import sys

num = int(sys.stdin.readline())

stack = []
for i in range(num):
    command = sys.stdin.readline().split()
    operator = command[0]
    if(len(command) == 2):
        operand = command[1]

    if operator == 'push':
        stack.append(operand)
    elif operator == 'pop':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif operator == 'size':
        print(len(stack))
    elif operator == 'empty':
        if len(stack)==0:
            print(1)
        else:
            print(0)
    elif operator == 'top':
        if len(stack)==0:
            print(-1)
        else:
            print(stack[-1])
