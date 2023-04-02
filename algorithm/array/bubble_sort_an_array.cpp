//Use case: Bubble sort an array

#include <bits/stdc++.h>

using namespace std;

void print_arr(const vector<int>& arr, int i_pass = -1, int j_pass = -1){
    if(i_pass == -1 && j_pass == -1){
        for(auto elem : arr){
            cout << elem << " ";
        }
        cout << endl;
    }
    else{
        cout << "After Pass: #" << i_pass << "." << j_pass << endl;
        for(auto elem : arr){
            cout << elem << " ";
        }
        cout << endl;
    }
}

void bubble_sort(vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            print_arr(arr, i, j);
        }
        
    }
}

int main(){
    vector<int> arr = {55, 9, 8, 5, 2};

    bubble_sort(arr);
    print_arr(arr);
}

