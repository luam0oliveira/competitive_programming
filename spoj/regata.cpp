// https://br.spoj.com/problems/REGATA/
// Geometria

#include <bits/stdc++.h>
#define MAXX 1e8

using namespace std;

typedef long long ll;

struct Point
{
	int x, y;

	bool operator==(const Point &p) const
	{
		return x == p.x && y == p.y;
	}
};

struct Segment
{
	Point a, b;
};

vector<Segment> objetos;
vector<vector<pair<double, int>>> adjList;
vector<Point> vertices;
vector<double> dist;

bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			  (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0; // collinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2)
		return false;

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are collinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1))
		return true;

	// p1, q1 and q2 are collinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1))
		return true;

	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2))
		return true;

	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2))
		return true;

	return false; // Doesn't fall in any of the above cases
}

void addVertice(Point a){
	int u = adjList.size();
	adjList.push_back({});
	dist.push_back(MAXX);

	for (int i = 0; i < u; i++)
	{
		Point b = vertices[i];
		bool valido = true;

		for (int j = 0; j < objetos.size() && valido; j++){
			Segment obj = objetos[j];

			valido = !doIntersect(a, b, obj.a, obj.b);
		}

		if (valido){
			double distance = sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
			adjList[u].push_back({distance, i});
			adjList[i].push_back({distance, u});
		}
	}
	vertices.push_back(a);
};

int main(){
	int x1, x2, y1, y2, n;
	while (cin >> x1 >> y1 >> x2 >> y2 >> n && (x1 || y1 || x2 || y2 || n))
	{
		objetos.clear();
		vertices.clear();
		dist.clear();
		adjList.clear();

		for (int i = 0; i < n; i++){
			Point a, b;
			cin >> a.x >> a.y >> b.x >> b.y;
			objetos.push_back({a, b});
		}
		addVertice({x1, y1});
		for (int i = 0; i < n + 1; i++){
			addVertice(objetos[i].a);
			addVertice(objetos[i].b);
		}
		addVertice({x2, y2});

		priority_queue<pair<double, int>> pq;

		pq.push({0, 0});
		dist[0] = 0;
		while (!pq.empty()){
			auto top = pq.top(); pq.pop();
			int u = top.second;
			double d = top.first;
			if (d == dist[u])
				for (auto adj : adjList[u]){
					int v = adj.second;
					double cost = adj.first;
					if (dist[v] > d + cost)
					{
						dist[v] = d + cost;
						pq.push({dist[v], v});
					}
				}
		}

		printf("%.2f\n", dist[dist.size() - 1]);
	}
}