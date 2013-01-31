/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n < 2) {
        std::cout << '0';
        return 0;
    }

    vector<long> data;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(data));

    sort(data.begin(), data.end());

    int count = 0;
    vector<long>::iterator first = data.begin(), second = data.begin() + 1;

    while (second != data.end()) {
        if (*second - *first == k) {
            ++count;
            ++second;
        } else if (*second - *first > k) {
            ++first;
        } else {
            ++second;
        }
    }

    cout << count;
}
