#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int x)
{
    // iterate over the array in order to find the key x
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int res = search(arr, x);
    if (res == -1)
    {
        cout << "Element is not present in the array";
    }
    else
    {
        cout << "Element is present at index " << res;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {100, 200, 300, 400, 500};
    int n = 5;
    int pos1 = 1;
    int pos2 = 5;
    int val1 = 150;
    int val2 = 450;

    for (int i = n; i > pos1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos1] = val1;
    n++;

    for (int i = n; i > pos2; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos2] = val2;
    n++;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    int n = 2;
    int pos = 2;

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int x = 80;
    int res = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            res = i;
        }
    }

    if (res == -1)
    {
        cout << "Element is not present in the array";
    }
    else
    {
        cout << "Element is present at index " << res;
    }
    return 0;
}