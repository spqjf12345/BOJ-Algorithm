import sys
stack = []
arr = sys.stdin.readline()
cnt = 0
i = 0
while i < len(arr):
    if(arr[i] == '('):
        stack.append('(')
    elif (arr[i] == ')'):
        if arr[i-1] == '(':
            stack.pop()
            cnt += len(stack)
        else:
            stack.pop()
            cnt += 1
    i += 1

print(cnt)