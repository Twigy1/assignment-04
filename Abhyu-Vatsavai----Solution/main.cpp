#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int> & print) {

	for (int i = 0; i < print.size(); i++) {
		std::cout << print[i] << " ";



	}
}

void selection_sort(std::vector<int> & sort)
{
	for (int i = 0; i < sort.size(); i++)
	{
		for (int b = i; b < sort.size(); b++)
		{
			if (sort[i] > sort[b])
			{
				int t = sort[i];
				sort[i] = sort[b];
				sort[b] = t;
			}
		}
	}
}

std::vector<int> merge_sort(const std::vector<int> & sort_merge) {

	if (sort_merge.size() < 2) {
		return sort_merge;
	}
	else {
		std::size_t const half_size = sort_merge.size() / 2;
		std::vector<int> merge_sort_left(sort_merge.begin(), sort_merge.begin() + half_size);
		std::vector<int> merge_sort_right(sort_merge.begin() + half_size, sort_merge.end());

		merge_sort_left = merge_sort(merge_sort_left);
		merge_sort_right = merge_sort(merge_sort_right);
	
		std::vector<int> sorted;
		std::vector<int>::iterator l = merge_sort_left.begin();
		std::vector<int>::iterator r = merge_sort_right.begin();
		while (l != merge_sort_left.end() && r != merge_sort_right.end())
			if (*l < *r)
				sorted.push_back(*(l++));
			else
				sorted.push_back(*(r++));
		while (l != merge_sort_left.end())
			sorted.push_back(*(l++));
		while (r != merge_sort_right.end())
			sorted.push_back(*(r++));

		return sorted;
	}

}

int main() {
	std::vector<int> a = { 4,3,7,8,5,6,1,2 };
	print_vector(a);
	std::cout << std::endl;
	selection_sort(a);

	for (int i = 0; i < a.size(); i++)
	{

		std::cout << a[i] << " ";

	}
	std::cout << std::endl;
	std::vector<int> b = { 4,3,7,8,5,6,1,2 };
	print_vector(b);
	std::cout << std::endl;
	merge_sort(b);
	
	
	for (int i = 0; i < a.size(); i++)
	{

		std::cout << a[i] << " ";

	}
	std::cout << std::endl;

	system("pause");
	return 0;



