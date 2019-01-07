#-*- coding:utf-8 -*-
import datetime
class BFS(object):

    def __init__(self):
        self.num = 0

    def fun(self,s,m,n):
        stack=[[s,m]]
        stack_s =set()#用来存储字符串s的长度
        while True:
            if n in stack_s:
                break
            stack_temp=[]
            while stack:
                temp=stack.pop()
                temp_1=[2*temp[0],temp[0]]
                temp_2=[temp[0]+temp[1],temp[1]]
                
                stack_s.add(2 * temp[0])
                stack_s.add(temp[0]+temp[1])
                
                stack_temp.append(temp_1)
                stack_temp.append(temp_2)
            self.num+=1
            stack=stack_temp

if __name__=='__main__':
    n = input()
    i = datetime.datetime.now()
    bfs = BFS()
    bfs.fun(1, 1,n)
    j = datetime.datetime.now()
    print bfs.num
    print j - i
