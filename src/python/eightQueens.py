#! /usr/bin/env python
# -*- coding:utf-8 -*-

# 问题：在一个8*8棋盘上，每一行放置一个皇后旗子，且它们不冲突。冲突定义：同一列不能有两个皇后，每一个对角线也不能有两个皇后。

# 解法1
#冲突检查，在定义state时，采用state来标志每个皇后的位置，其中索引用来表示横坐标，基对应的值表示纵坐标，例如： state[0]=3，表示该皇后位于第1行的第4列上
def conflict(state, nextX):
    nextY = len(state)
    for i in range(nextY):
        #如果下一个皇后的位置与当前的皇后位置相邻（包括上下，左右）或在同一对角线上，则说明有冲突，需要重新摆放
        if abs(state[i]-nextX) in (0, nextY-i):
            return True
    return False

#采用生成器的方式来产生每一个皇后的位置，并用递归来实现下一个皇后的位置。
def queens(num, state=()):
    for pos in range(num):
        if not conflict(state, pos):
            #产生当前皇后的位置信息
            if len(state) == num-1:
                yield (pos, )
            #否则，把当前皇后的位置信息，添加到状态列表里，并传递给下一皇后。
            else:
                for result in queens(num, state+(pos,)):
                    yield (pos, ) + result

def printSolution(solution):
    length = len(solution)
    for pos in solution:
        print('. ' * (pos) + 'x ' + '. '*(length-pos-1))

#风格1
def queen1(solution, cur=0):
    if cur==len(solution):
        print(solution)
        printSolution(solution)
    else:
        for col in range(len(solution)):
            solution[cur] = col #表示把第cur行的皇后放在col列上
            ok = True
            for r in range(cur):
                if solution[r]==col or r-solution[r]==cur-solution[cur] or r+solution[r]==cur+solution[cur]:#判断是否跟前面的皇后冲突
                    ok = False
                    break
            if ok:
                queen1(solution, cur+1)

#风格2
def queen2(solution, cur=0):
    if cur==len(solution):
        print(solution)
        printSolution(solution)
    else:
        for col in range(len(solution)):
            solution[cur] = col #表示把第cur行的皇后放在col列上
            for r in range(cur):
                if solution[r]==col or r-solution[r]==cur-solution[cur] or r+solution[r]==cur+solution[cur]:#判断是否跟前面的皇后冲突
                    break
            else:
                queen2(solution, cur+1)

#风格3
def queen3(solution, cur=0):
    if cur==len(solution):
        print(solution)
        printSolution(solution)
    else:
        for col in range(len(solution)):
            solution[cur] = col #表示把第cur行的皇后放在col列上
            if all(solution[r]!=solution[cur] and r-solution[r]!=cur-solution[cur] and r+solution[r]!=cur+solution[cur] for r in range(cur)):#判断是否跟前面的皇后冲突
                queen3(solution, cur+1)

if __name__ == "__main__":
    # printSolution(list(queens(8))[0])
    queen1([None] * 8)
    pass