# https://judge.beecrowd.com/pt/problems/view/2562
# Aqui é a simples utilização de dfs num grafo direcionado (repare no enunciado)

import sys
input = sys.stdin.readline
print = sys.stdout.write

def dfs(u, visited, rels):
	cont = 1
	visited[u]= True
	for rel in rels[u]:
		if (not visited[rel]):
			cont += dfs(rel, visited, rels)
	return cont

def main():
	while(1):
		try:
			n, m = map(int, input().split())
		except Exception as e:
			break
		visited = [False]* (n+1)
		adjList = [[] for _ in range(n+1)]
		for i in range(m):
			a, b = map(int, input().split())
			adjList[a].append(b)
		print(str(dfs(int(input()), visited, adjList))+"\n")
main()
	