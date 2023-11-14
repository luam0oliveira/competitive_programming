#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14

double solve(double radius)
{
    return 2 * radius * PI;
}

int main()
{
    double radius;

    cin >> radius;

    printf("%.2f\n", solve(radius));

    return 0;
}