#include <iostream>

const int* BSearch(const int*, const int, const int);

int main()
{
	using namespace std;
	constexpr int Count = /*100'000*/101;
	int Arr[Count];

	for (int i = 0; i < Count; ++i)
	{
		Arr[i] = i + 1;
	}
	//for (/*const */int& A : Arr)	// Output.
	//{
	//	cout << A << "\t";
	//}
	// Binary search.
	for (unsigned i = 0; i < Count + 2; ++i)
	{
#pragma region Inline.
		int L = NULL, R = Count - 1, Mid, Key = i;
		while (L < R)
		{
			Mid = (L + R) / 2;
			if (Arr[Mid] > Key)
			{
				R = Mid/* - 1*/;
			}
			else
			{
				L = Mid + 1;
			}
		}
		R--;
		if (Arr[R] == Key)
		{
			cout << Key << " = " << Arr[R] << "\t\t";
		}
		else
		{
			cout << Key << " not found!\t\t";
		}
#pragma endregion

#pragma region STD.
		auto stdbsearch = (int*)bsearch(&Key, Arr, Count, 4, [](void const* L, void const* R) -> int
		{
			return *(int*)L - *(int*)R;
		});
		if (stdbsearch != nullptr)
		{
			cout << Key << " & " << *stdbsearch << "\t\t";
		}
		else
		{
			cout << Key << " not found!\t\t";
		}
#pragma endregion

#pragma region Function.
		auto SearchValue = BSearch(Arr, Count, Key);
		if (SearchValue != nullptr)
		{
			cout << Key << " & " << *SearchValue << "\n";
		}
		else
		{
			cout << Key << " not found!\n";
		}
#pragma endregion
	}

	system("pause");
	return EXIT_SUCCESS;
}

// Log(n).
const int* BSearch(const int* Arr, const int Count, const int Key)
{
	alignas(64) int L = 0;
	int R = Count - 1, Mid;
	while (L <= R)
	{
		Mid = (L + R) / 2;
		if (Arr[Mid] > Key)
		{
			R = Mid - 1;
		}
		else
		{
			L = Mid + 1;
		}
	}
	//std::cout << std::endl << L << "\t" << Mid << "\t" << R << std::endl;
	return Arr[R/* - 1*/] == Key ? Arr + R/* - 1*/ : nullptr;
}
