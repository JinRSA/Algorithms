#include <iostream>
#include <time.h>
#define CACHE_LINE 32
//#define CACHE_LINE 64
//#define CACHE_ALIGN __declspec(align(CACHE_LINE))	// Only MS.
#define CACHE_ALIGN alignas(CACHE_LINE)	// C++11.

void BubbleSort(int*, const int);

int main()
{
	using namespace std;
	constexpr int Count = 100'000;
	CACHE_ALIGN int Arr[Count], Arr2[Count];
	srand(time(NULL));
	for (int i = 0; i < Count; ++i)
	{
		Arr[i] = Arr2[i] = rand() % Count + 1;
	}
	/*cout << "Sort: qsort.\n";
	qsort(Arr2, Count, 4, [](void const* L, void const* R) -> int
		{
			return *(int*)L - *(int*)R;
		});
	cout << "Complete.\n";*/
	cout << "Sort: BubbleSort.\n";
	BubbleSort(Arr, Count);
	cout << "Complete.\n";;
	return EXIT_SUCCESS;
}

void BubbleSort(int* Arr, const int Count/*, auto Cmp*/)
{
	if (Count == 1)
	{
		return;
	}
	for (int i = 0; i < Count; ++i)
	{
		bool WasSorted = true;
		for (int j = 1; j < Count - i; ++j)
		{
			if (Arr[j - 1] > Arr[j])
			{
				auto El = Arr[j];
				Arr[j] = Arr[j - 1];
				Arr[j - 1] = El;
				WasSorted = false;
			}
		}
		if (WasSorted)
		{
			break;
		}
	}
}
