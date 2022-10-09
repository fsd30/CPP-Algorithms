#include<bits/stdc++.h>
using namespace std;

int findSubArrays(vector<int>& arr ,int n ,int sum){
    map<int, int> map;
    int current_sum = 0,res = 0;

    
    for (int i = 0; i < n;i++){

        current_sum += arr[i];


        // to check if there exists any subarray from index 0 till i that satisfies the sum
        if(current_sum == sum){
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl;
            res++;
        
        }

        // to check if there aready exists some subarray whish satisfies sum
        if(map.find(current_sum-sum) != map.end()){
            cout << "Sum found between indexes "
                 << map[current_sum - sum] + 1
                 << " to " << i << endl;
            res++;
        }
        map[current_sum] = i;

        // cout << res << endl;
    }

    return res;
}

int main()
{
    int n,sum;
    cin >> n ;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cin >> sum;
    cout << findSubArrays(arr, n, sum);
}
