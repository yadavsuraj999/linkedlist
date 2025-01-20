#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &, int, int, int);
void mergeSort(vector<int> &, int, int);
void selectionSort(vector<int>, int);
int main()
{

    int choice;
    do
    {
        cout << "\n------------------------------" << endl;
        cout << "\n1 for marge Sort " << endl;
        cout << "\n2 for Selection Sort " << endl;
        cout << "\n3 for Binary Search " << endl;
        cout << "\n4 for exit " << endl;
        cout << "------------------------------" << endl;
        cout << "Enter choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter size Array :- ";
            cin >> n;
            vector<int> arr(n);

            for (int i = 0; i < n; i++)
            {
                cout << "Enter Value : ";
                cin >> arr[i];
            }

            mergeSort(arr, 0, n - 1);

            for (int val : arr)
            {
                cout << val << " ";
            }
            break;
        }

        case 2:
        {
            int n;
            cout << "size of array :- ";
            cin>>n;
            vector<int> arr(n);

            for (int i = 0; i < n; i++)
            {
                cout << "Enter Value :- ";
                cin >> arr[i];
            }

            selectionSort(arr, n);
        }
        case 3:
        {
            int n;
            cout << "Enter size array";
            break;
        }
        case 4:
        {
            cout << "thank you visit again";
        }

        default:
            break;
        }
    } while (choice != 0);

    return 0;
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}






void selectionSort(vector<int> arr, int size){
    int temp;
    for (int i = 0; i < size; i++)
    {
        int min = i;

        for (int j = (i + 1); j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (arr[min] != 0)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    for(int val : arr){
        cout<<val<<" ";
    }
}
