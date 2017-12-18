#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <vector>
#include "time.h"
using namespace std;


// find top k implement by STL
// reference: https://jinfagang.gitlab.io/2017/09/04/C++_%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E9%9B%86%E9%94%A6_%E4%BA%8C/
vector<int>::iterator find_k(vector<int>::iterator begin, vector<int>::iterator end, int k) {
    vector<int>::difference_type n = k;
    if (end - begin <= k) {
        return end;
    }
    auto left = begin;
    auto right = end - 1;
    srand(time(NULL));
    int index = (int) rand() % n;
    iter_swap(begin, begin + index);
    while (left < right) {
        // traverse right than left
        while (*right <= *left && left < right) {
			right--;
		}
		
        if (left < right) {
			iter_swap(left, right);
		}
		
        while (*left > *right && left < right) { 
			left++; 
		}
        
		if (left < right) {
			iter_swap(left, right);
		}
    }
    n = left - begin;
    if (n + 1 >= k ) {
        // if left element more than k, find from left
        // TODO: why left + 1?
        return find_k(begin, left + 1, k);
    } else {
        // if left element less than k, find the rest k-n
        return find_k(left + 1, end, k - n - 1);
    }
}
int main()
{
    vector<int> a = {3, 56, 7, 89, 34, 12, 56, 39};
    auto it_r = find_k(a.begin(), a.end(), 5);
    for (auto it = a.begin(); it < it_r; it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
} 

