#include <iostream>
#include <vector>

using namespace std;

int get_digit(int num, int pos) {
    // 해당 자릿수의 숫자를 반환
    return (num / static_cast<int>(pow(10, pos))) % 10;
}

void radix_sort(vector<int> &arr) {
    int max_num = *max_element(arr.begin(), arr.end());
    int max_digit = log10(max_num) + 1;

    for (int pos = 0; pos < max_digit; pos++) {
        vector<vector<int>> arr_new(10);

        for (int num : arr) {
            int digit = get_digit(num, pos);
            arr_new[digit].push_back(num);
        }

        arr.clear();

        for (int i = 0; i < 10; i++) {
            for (int num : arr_new[i]) {
                arr.push_back(num);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radix_sort(arr);

    for (int num : arr) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}