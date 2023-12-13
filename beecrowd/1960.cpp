#include <iostream>

using namespace std;

string solve(int number)
{
    string roman_number = "";

    if (number > 900)
    {
        roman_number += "CM";
        number -= 900;
    }

    if (number >= 500)
    {
        roman_number += "D";
        number -= 500;
    }

    if (number > 400)
    {
        roman_number += "CD";
        number -= 400;
    }

    for (; number >= 100;)
    {
        roman_number += "C";
        number -= 100;
    }

    if (number > 90)
    {
        roman_number += "XC";
        number -= 90;
    }

    if (number >= 50)
    {
        roman_number += "L";
        number -= 50;
    }

    if (number > 40)
    {
        roman_number += "XL";
        number -= 40;
    }

    for (; number >= 10;)
    {
        roman_number += "X";
        number -= 10;
    }

    if (number == 9)
    {
        roman_number += "IX";
        number -= 9;
    }

    if (number >= 5)
    {
        roman_number += "V";
        number -= 5;
    }

    if (number == 4)
    {
        roman_number += "IV";
        number -= 4;
    }

    for (; number >= 1;)
    {
        roman_number += "I";
        number -= 1;
    }

    return roman_number;
}

int main()
{
    int number;

    scanf("%d", &number);

    cout << solve(number) << endl;
    return 0;
}
