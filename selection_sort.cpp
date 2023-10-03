#include<bits/stdc++.h>
using namespace std;

bool ascending(int a, int b) {
    return a > b;
}

bool descending(int a, int b) {
    return a < b;
}

void selection_sort(int arr[], int size, bool(*comparison_func)(int, int)) {

    for(int i = 0; i < size - 1; i++) {
        int index = i;
        for(int j = i + 1; j < size; j++) {
            if(comparison_func(arr[index], arr[j])) index = j;
        }
        swap(arr[i], arr[index]);
    }
}
template<typename T>
void display(T arr, int size) {
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
}

int main() {
    int a[] = {1, 4, 2, 3, 6, 5, 8, 9, 7};
    //selection_sort(a, sizeof(a) / 4, ascending);
    vector<int> b = {1, 4, 2, 3, 6, 5, 8, 9, 7};
    sort(b.begin(), b.end(), [=](int x, int y) {
        return x < y;
    });
    display(b, sizeof(a) / 4);
    cout << endl;
    selection_sort(a, sizeof(a) / 4, descending);
    display(a, sizeof(a) / 4);
    return 0;
}