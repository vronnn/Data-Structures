// CPP Program to demonstrate the implementation of multimap
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

// Driver Code
int main()
{
    // empty multimap container
	multimap<int,int> nums1;

	// insert elements in random order to test
	nums1.insert(pair<int, int>(3, 30));
	nums1.insert(pair<int, int>(1, 20));
	nums1.insert(pair<int, int>(6, 10));
	nums1.insert({2, 40});
	nums1.insert({6, 50});

	// printing multimap nums1 using iterator
	multimap <int,int>::iterator it;
	cout << "\nThe multimap nums1 contains : \n";
	cout << "KEY\tELEMENT\n";
	for (it = nums1.begin(); it != nums1.end(); ++it) {
		cout << it->first << '\t' << it->second << '\n';
	}
	puts("");

	// adding another elements
	nums1.insert(pair<int, int>(4, 10));
	nums1.insert(pair<int, int>(5, 60));

	// printing multimap nums1 again
	cout << "The multimap nums1 after adding extra elements : \n";
	cout << "KEY\tELEMENT\n";
	for (it = nums1.begin(); it != nums1.end(); ++it) {
		cout << it->first << '\t' << it->second << '\n';
	}
	puts("");

	// assigning nums1's elements to nums2
	multimap <int,int> nums2(nums1.begin(), nums1.end());

	// print all elements of the multimap nums2
	cout << "The multimap nums2 after assignment from nums1 : \n";
	cout << "KEY\tELEMENT\n";
	for (it = nums2.begin(); it != nums2.end(); ++it) {
		cout << it->first << '\t' << it->second << '\n';
	}
	puts("");

	// remove all elements with the key value less than 3 in nums2 using find()
	cout << "nums2 after removing all elements less than key = 3 : \n";
	cout << "KEY\tELEMENT\n";
	nums2.erase(nums2.begin(), nums2.find(3));
	for (it = nums2.begin(); it != nums2.end(); ++it) {
		cout << it->first << '\t' << it->second << '\n';
	}
    puts("");

	// remove all elements with key = 4 using erase()
	int num = nums2.erase(4);
	cout << "after applying nums2.erase(4) : ";
	cout << num << " removed \n";
	cout << "KEY\tELEMENT\n";
	for (it = nums2.begin(); it != nums2.end(); ++it) {
		cout << it->first << '\t' << it->second << '\n';
	}
	puts("");

	// lower_bound() and upper_bound() in multimap nums1, key = 5
	cout << "nums1.lower_bound(5) : \tKEY = ";
	cout << nums1.lower_bound(5)->first << '\t';
	cout << "ELEMENT = " << nums1.lower_bound(5)->second << endl;

	cout << "nums1.upper_bound(5) : \tKEY = ";
	cout << nums1.upper_bound(5)->first << '\t';
	cout << "ELEMENT = " << nums1.upper_bound(5)->second << endl;

	return 0;
}
