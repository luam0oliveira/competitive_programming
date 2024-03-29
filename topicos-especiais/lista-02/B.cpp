#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> numbers;


	int num, tam = 0, sum, middle;

	while (cin >> num)
	{
		numbers.push_back(num);
		tam += 1;

		middle = tam / 2;
		nth_element(numbers.begin(), numbers.begin() + middle, numbers.end());
		sum = numbers[middle];
		if (tam % 2 == 0)
		{
			nth_element(numbers.begin(), numbers.begin() + middle - 1, numbers.end());
			sum = (sum + numbers[middle-1])/2;
		}

		cout << sum << endl;
	}

	return 0;
}
