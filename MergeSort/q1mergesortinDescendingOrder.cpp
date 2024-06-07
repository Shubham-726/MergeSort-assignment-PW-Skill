#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> ans;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (v[i] > v[j])
            ans.push_back(v[i++]);
        else
            ans.push_back(v[j++]);
    }
    while (i <= mid)
        ans.push_back(v[i++]);

    while (j <= high)
        ans.push_back(v[j++]);

    for (int i = low; i <= high; i++)
    {
        v[i] = ans[i - low];
    }
}
void mergeSort(vector<int> &v, int low, int high)
{
    if (low == high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
int main()
{
    int arr[] = {4, 1, 5, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + size);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    int low = 0;
    int high = size - 1;
    mergeSort(v, low, high);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}