// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=297
// Apenas aplicação convex hull (comentários foram do livro halim 3)

#include <bits/stdc++.h>

#define EPS 1e-9
#define PI 3.14159265359

using namespace std;

typedef long long ll;

struct point
{
	ll x, y;
	int r;
	point() { x = y = 0; }
	point(ll _x, ll _y) : x(_x), y(_y) {}

	bool operator<(const point &other) const
	{
		if (abs(x - other.x) > EPS)
		{
			return x < other.x;
		}
		return y < other.y;
	}

	bool operator==(const point &other) const
	{
		return x == other.x && y == other.y;
	}
};

point nextToTop(stack<point> &S)
{
	point p = S.top();
	S.pop();
	point res = S.top();
	S.push(p);
	return res;
}

point pivot;

struct vec
{
	double x, y; // name: ‘vec’ is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{
	// convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
bool collinear(point p, point q, point r)
{
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

double dist(point p1, point p2)
{
	// Euclidean distance
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool angleCmp(point a, point b)
{
	// angle-sorting function
	if (collinear(pivot, a, b))
		// special case
		return dist(pivot, a) < dist(pivot, b);
	// check which one is closer
	// return sign(cross(pivot, a, b)) == 1
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> &points)
{
	// Find the bottommost point
	int n = points.size();

	if (n < 3)
	{
		sort(points.begin(), points.end(), angleCmp);
		return points;
	}

	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		// Pick the bottom-most or choose the left
		// most point in case of tie
		if ((y < ymin) || (ymin == y &&
											 points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	// Place the bottom-most point at first position
	swap(points[0], points[min]);

	// Sort n-1 points with respect to the first point.
	// A point p1 comes before p2 in sorted output if p2
	// has larger polar angle (in counterclockwise
	// direction) than p1
	pivot = points[0];
	sort(++points.begin(), points.end(), angleCmp);

	// If two or more points make same angle with p0,
	// Remove all but the one that is farthest from p0
	// Remember that, in above sorting, our criteria was
	// to keep the farthest point at the end when more than
	// one points have same angle.
	int m = 1; // Initialize size of modified array
	for (int i = 1; i < n; i++)
	{
		// Keep removing i while angle of i and i+1 is same
		// with respect to p0
		while (i < n - 1 && collinear(pivot, points[i],
																	points[i + 1]))
			i++;

		points[m] = points[i];
		m++; // Update size of modified array
	}

	// If modified array of points has less than 3 points,
	// convex hull is not possible
	if (m < 3)
		return points;

	// Create an empty stack and push first three points
	// to it.
	stack<point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Process remaining n-3 points
	for (int i = 3; i < m; i++)
	{
		// Keep removing top while the angle formed by
		// points next-to-top, top, and points[i] makes
		// a non-left turn
		while (S.size() > 1 && !ccw(nextToTop(S), S.top(), points[i]))
			S.pop();
		S.push(points[i]);
	}

	points.clear();

	// Now stack has the output points, print contents of stack
	while (!S.empty())
	{

		point p = S.top();
		S.pop();
		// cout << p.x << endl;
		points.push_back(p);
	}

	return points;
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b)
{ // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool inPolygon(point pt, const vector<point> &P)
{
	if ((int)P.size() < 3)
		return false;
	double sum = 0;
	// assume the first vertex is equal to the last vertex
	for (int i = 0; i < (int)P.size(); i++)
	{
		point next;
		if (pt == P[i])
			return true;

		if (i + 1 == P.size())
			next = P[0];
		else
			next = P[i + 1];

		if (ccw(pt, P[i], next) || collinear(pt, P[i], next))
		{
			sum += angle(P[i], pt, next);
		}
		// left turn/ccw
		else
			sum -= angle(P[i], pt, next);
	}
	// right turn/cw
	// cout << sum<<endl;
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

int main()
{
	int cases = 1;
	while (1)
	{
		int c, r, p;

		cin >> c >> r >> p;

		if (c == 0 && r == 0 && p == 0)
			break;

		vector<point> cops(c);
		vector<point> robbers(r);
		vector<point> citzen(p);

		for (int i = 0; i < c; i++)
			cin >> cops[i].x >> cops[i].y;

		for (int i = 0; i < r; i++)
			cin >> robbers[i].x >> robbers[i].y;

		for (int i = 0; i < p; i++)
			cin >> citzen[i].x >> citzen[i].y;

		vector<point> hul_cops = CH(cops);
		vector<point> hul_robbers = CH(robbers);

		reverse(hul_cops.begin(), hul_cops.end());
		reverse(hul_robbers.begin(), hul_robbers.end());

		// cout << hul_cops.size()<<endl;
		cout << "Data set " << cases++ << ":" << endl;
		for (int i = 0; i < p; i++)
			if (inPolygon(citzen[i], hul_cops))
				cout << "     Citizen at (" << citzen[i].x << "," << citzen[i].y << ") is safe." << endl;
			else if (inPolygon(citzen[i], hul_robbers))
				cout << "     Citizen at (" << citzen[i].x << "," << citzen[i].y << ") is robbed." << endl;
			else
				cout << "     Citizen at (" << citzen[i].x << "," << citzen[i].y << ") is neither." << endl;
		cout << endl;
	}
}
