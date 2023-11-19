#include <iostream>

using namespace std;

struct fraction
{
    int numerator, quotient;
};

int mdc(int a, int b)
{
    int aux = 0;
    while (b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void divide(int &a, int &b)
{
    int menor = min(a, b) + 1;

    while (--menor != 0)
    {
        if (a % menor == 0 && b % menor == 0)
        {
            a /= menor;
            b /= menor;
            break;
        }
        if (menor == 0)
            return;
    }
    return;
}

fraction add_fraction(int a, int b, int c, int d)
{
    int e, f;

    e = c * b + a * d;
    f = b * d;

    int mdc_result = 0;
    while (mdc_result != 1)
    {
        divide(e, f);
        mdc_result = mdc(max(e, f), min(e, f));
    }

    fraction frac;
    frac.numerator = e;
    frac.quotient = f;

    return frac;
}

int main()
{
    int a, b, c, d;

    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4)
        return 1;

    fraction frac = add_fraction(a, b, c, d);

    cout << frac.numerator << " " << frac.quotient;

    return 0;
}