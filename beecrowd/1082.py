from collections import deque

class Node:
	def __init__(self, letter):
		self.letter = letter
		self.relations = []

	def add_rel(self, node):
		self.relations.append(letter)

def bfs(node, visited):
	fila = deque([node])
	connected = {}

	while len(fila) != 0:
		actual = fila.popleft()
		connected[actual.letter] = True
		visited[actual.letter] = True
		for i in actual.relations:
			if not visited[i.letter]:
				fila.append(i)
	return list(connected.keys())

def main():
	cases = int(input())
	cont = 1

	while cases:
		v,e = map(int,input().split())

		graph = {}
		visited = {}

		for i in range(v):
			letter = chr(i + ord('a'))
			graph[letter] = Node(letter)
			visited[letter] = False

		for i in range(e):
			orig, cheg = input().split()
			graph[orig].relations.append(graph[cheg])
			graph[cheg].relations.append(graph[orig])

		connections = []
		for i in graph:
			if not visited[i]:
				connected = bfs(graph[i], visited)
				connected.sort()
				connections.append(connected)

		print("Case #" + str(cont) + ":")
		for i in connections:
			for j in i:
				print(j + ",", end="")
			print()

		print(str(len(connections)) + " connected components\n")
		cont += 1
		cases -= 1

if __name__ == "__main__":
	main()