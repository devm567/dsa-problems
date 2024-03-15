// Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> temp;

    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }

    for(int i=0; i<temp.size();i++){
        arr[i]=temp[i];
    }

    for(int i=temp.size(); i<n; i++){
        arr[i]=0;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
// X = no. of non-zero elements, and N-X = total no. of zeros.
// Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).

// Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
// Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.


// Optimal Approach
#include<bits/stdc++.h>
using namespace std;

int moveZeroes(vector<int> &arr, int n){
    int j=-1;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return 0;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    moveZeroes(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Time Complexity: O(N), N = size of the array.
// Reason: We have used 2 loops and using those loops, we are basically traversing the array once.
// Space Complexity: O(1) as we are not using any extra space to solve this problem.
