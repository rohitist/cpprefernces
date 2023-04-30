//Right Rotatae the given array by k {1,2,3,4,5,6,7} if k == 3, result shoud be {5,6,7,1,2,3,4} if k == 1, result should be {7,1,2,3,4,5,6}

#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& nums){
    for(auto i : nums){
        cout << i << " ";
    }

    cout << endl;
}

void rotate(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> temp(n);

    for(int i = 0; i < n; i++){
        temp[(i + k) % n] = nums[i];
        cout << "(" << i << "+" << k << ") %" << n << " = " << ((i + k) % n) << endl;
    }

    nums = temp;
}



int main(){
    vector<int> nums = {1,2,3,4,5,6,7};

    rotate(nums, 3);
    print(nums);


    return 0;

}