#-*- coding:utf-8 -*-
import datetime
class DFS(object):
    '''
        num:用于存储最后执行次数
        n:用于存储最后达到的字符串的长度
        flag:当达到输入字符串的长度时，flag置为1
    '''
    def __init__(self,n):
        self.num=0
        self.n=n
        self.flag=0

    def fun(self,s,m):
        self.fun_1(s,m)
        self.fun_2(s,m)
        #当未达到字符串长度时，回溯
        if self.flag==0:
            self.num-=1

    #fun_1:方法1
    def fun_1(self,s,m):
        #当达到字符串长度，直接返回
        if self.flag == 0:
            if self.n < s:
                return
            if self.n == s:
                self.flag = 1
                return
            else:
                m = s
                s += s
                self.num += 1
            #没达到字符串长度，继续递归
            self.fun(s, m)
        else:
            return

    # fun_2:方法2
    def fun_2(self,s,m):
        if self.flag == 0:
            if self.n<s:
                return
            if self.n==s:
                self.flag=1
                return
            else:
                s=s+m
                self.num+=1
            # 没达到字符串长度，继续递归
            self.fun(s,m)
        else:
            return
if __name__=='__main__':
    n=input()
    i=datetime.datetime.now()
    dfs=DFS(n)
    dfs.fun(1,1)
    j = datetime.datetime.now()
    print dfs.num
    print j-i
