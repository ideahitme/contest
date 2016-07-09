#!/bin/python

import sys


N = int(raw_input().strip())
a = map(int,raw_input().strip().split(' '))

poles = {
	1: [],
	2: [],
	3: [],
	4: []
}

for i in range(len(a)-1,-1,-1):
	poles[a[i]].append(i+1)

initial = {
	1: [N-i for i in range(N)],
	2: [],
	3: [],
	4: []
}

def stacks_to_string(stacks):
	res = ''
	for key in stacks:
		for val in stacks[key]:
			res += str(val) + ':'
		res += ','
	return res

def string_to_stacks(string):
	it = string.split(',')
	stacks = {}
	for i in range(4):
		stacks[i+1] = [int(val) for val in it[i].split(':') if len(val) > 0]
	return stacks

visited = {}
goal = stacks_to_string(initial)

class Node:
	def __init__(self, val, prev=None):
		self.prev = prev
		self.val = val

def neighbours(string):
	neighbours = []
	stacks = string_to_stacks(string)
	for i in range(1, 5):
		for j in range(1, 5):
			if j != i and len(stacks[i]) > 0 :
				copy = {
					1: stacks[1][:],
					2: stacks[2][:],
					3: stacks[3][:],
					4: stacks[4][:]
				}
				if len(copy[j]) == 0 or copy[i][-1] < copy[j][-1]:
					copy[j].append(copy[i].pop())
					neibhour = stacks_to_string(copy)
					neighbours.append(neibhour)
	return neighbours

def find_path():
	root = Node(stacks_to_string(poles))
	stack = [root]
	while stack:
		vertex = stack.pop(0)
		if vertex.val == goal: 
			return vertex
		if vertex.val not in visited:
			v_ns = neighbours(vertex.val)
			for neighbour in v_ns:
				if neighbour not in visited:
					 v = Node(neighbour, vertex)
					 stack.append(v)
			visited[vertex.val] = 1

def solution():
	end_node = find_path()
	depth = 0
	while end_node.prev:
		end_node = end_node.prev
		depth += 1
	print depth

solution()

