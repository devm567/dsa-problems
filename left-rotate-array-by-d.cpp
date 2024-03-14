// Brute Force Approach

#include <bits/stdc++.h>    
using namespace std;

void leftRotate(int arr[], int n, int d)
{
    d = d % n;

    int temp[d];

    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cin >> d;
    leftRotate(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Time Complexity: O(d)+O(n-d)+O(d) = O(n+d), where n = size of the array, d = the number of rotations. Each term represents each loop used in the code.
// Space Complexity: O(d) extra space as we are using a temporary array of size d.


// Optimal Approach
#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cin >> d;
    leftRotate(arr, n, d);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// Time Complexity: O(d)+O(n-d)+O(n) = O(2*n), where n = size of the array, d = the number of rotations. Each term corresponds to each reversal step.
// Space Complexity: O(1) since no extra space is required.
