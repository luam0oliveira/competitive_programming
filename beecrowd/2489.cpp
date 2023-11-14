#include <iostream>
#include <cmath>

using namespace std;

double solve(double altura, double distance, double angle)
{
    double toy = altura + tan((angle - 90) * (M_PI / 180)) * distance;
    return toy;
}

int main()
{
    double altura, distance, angle, answer;
    while (scanf("%lf %lf %lf", &altura, &distance, &angle) == 3)
    {
        answer = solve(altura, distance, angle);

        printf("%.4f\n", answer);
        // cout << setprecision(4) << solve(altura, distance, angle) << endl;
    }

    return 0;
}
