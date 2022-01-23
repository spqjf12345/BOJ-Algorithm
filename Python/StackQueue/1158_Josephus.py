n, k = map(int, input().split())
queue = [i for i in range(1, n+1)]

print('<', end='')
idx = 0
while queue:
    if(len(queue) == 1):
        print(queue[0], end= '')
        break
    idx = (idx + (k-1)) % len(queue)
    print(queue[idx], end=', ')
    queue.pop(idx)


print('>', end='')





