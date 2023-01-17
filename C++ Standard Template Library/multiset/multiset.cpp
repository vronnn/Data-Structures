#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
	// empty multiset container
	multiset<int, greater<int> > nums1;

	// insert elements in random order
    for(int i=1; i<=5; i++){
        nums1.insert(10+(rand()%60));
    }

	// test by inserting the same 2 numbers
	nums1.insert(20);
	nums1.insert(20);

	// printing multiset nums1 using iterator
	multiset <int, greater<int> >::iterator itr;
	cout << "\nThe multiset nums1 contains : \n";
	for (itr = nums1.begin(); itr != nums1.end(); ++itr) {
		cout << *itr << " ";
	}
	puts("");

	// assigning nums1's elements to nums2
	multiset<int> nums2(nums1.begin(), nums1.end());

	// print multiset nums2
	cout << "\nThe multiset nums2 after assignment from nums1 : \n";
	for (itr = nums2.begin(); itr != nums2.end(); ++itr) {
		cout << *itr << " ";
	}
	puts("");

	// remove all elements with the value less than 39 in nums2 using find()
	cout << "\nnums2 after removing all elements less than 39 : \n";
	nums2.erase(nums2.begin(), nums2.find(39));
	for (itr = nums2.begin(); itr != nums2.end(); ++itr) {
		cout << *itr << " ";
	}
    puts("");

	// remove all elements with value 50 in nums2
	int num = nums2.erase(50);
	cout << "\nafter applying nums2.erase(50) : \n";
	cout << num << " removed \n";
	for (itr = nums2.begin(); itr != nums2.end(); ++itr) {
		cout << *itr << " ";
	}
	puts("");

	// lower_bound() and upper_bound() in multiset nums1
	cout << "\nnums1.lower_bound(40) : " << *nums1.lower_bound(40) << endl;
	cout << "nums1.upper_bound(40) : " << *nums1.upper_bound(40) << endl;
    puts("");

	// lower_bound() and upper_bound() in multiset nums2
	cout << "nums2.lower_bound(40) : " << *nums2.lower_bound(40) << endl;
	cout << "nums2.upper_bound(40) : " << *nums2.upper_bound(40) << endl;
    puts("");

	return 0;
}
