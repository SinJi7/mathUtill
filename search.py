# -*- coding: utf-8 -*-
"""
Created on Fri May 27 01:20:59 2022

@author: Administrator
"""

from collections import deque

def dfs(graph, start): #dict, int

    print("DFS: ")
    vist = []
    dq = deque()
    
    dq.append(start)
    
    visNode = start
    
    while True:
        ap = 0
        if visNode not in vist:
            print(visNode, end=", ")
            vist.append(visNode)
        
        for i in graph[visNode]:
            if i not in vist:
                vist.append(visNode)
                visNode = i
                ap += 1
                dq.append(i)
                break
        
        #print("ap", ap)
        if ap == 0:
            visNode = dq.pop()
            #print("pop", visNode)
        #print(dq)
        
        if not dq : break
    print("")
    
    return

def bfs(graph, start):
    print("BFS: ", end="")
    vist = []
    dq = deque()
    
    dq.append(start)
    
    while True:
        visNode = dq.popleft()
        vist.append(visNode)
        print(visNode, end=", ")
            
        for i in graph[visNode]:  
            if i not in vist:
                dq.append(i)
                vist.append(i)
            
        if not dq : break
    return 

my_graph = {
    1 : [2, 3],
    2 : [1, 4, 5],
    3 : [1, 6 ,7],
    4 : [2, 8],
    5 : [2, 8],
    6 : [3, 8],
    7 : [3, 8],
    8 : [4, 5, 6, 7]
}

bfs(my_graph, 1)
