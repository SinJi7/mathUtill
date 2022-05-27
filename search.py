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

def dfs2(graph, start):
    print("DFS2: ", end="")
    visit = []
    
    dq = deque()
    visit.append(start)
    dq.append(start)
    VisNode = start
    
    print(VisNode, end=", ")
    
    while True:
        #다음 방문 노드, 탐색 성공여
        findNode = False
        #print("visNode: ", VisNode)
        #print(visit)
        
        for i in graph[VisNode]:
            #방문하지 않은 노드를 찾는다.
            if i not in visit:
                findNode = True 
                
                VisNode = i #다음 방문 노드
                
                visit.append(i) #방문한 노드에 i 추가 
                dq.append(i) #스택에 i추가 
                print(VisNode, end=", ")
                #찾을시 반복문 종료
                break

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
