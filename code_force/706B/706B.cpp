#include <iostream>
#include <cstdio>

using namespace std;

void merge(int arr[], int left, int right, int mid){
    //tạo biến chạy cho arr
    int arr_run_var = 0;
    //tạo biến chạy cho arr bên trái
    int left_run_var = 0;
    //tạo biến chạy cho arr bên phải
    int right_run_var = 0;
    //tạo 2 mảng mới chứa 2 mảng con
    int arr1[mid - left + 1];
    int arr2[right - mid - 1 + 1];
    
    for(int i = 0; i <= mid - left; i++){
        arr1[i] = arr[left + i] ;
    }
    for(int i = 0; i < right - mid; i++){
        arr2[i] = arr[mid + i + 1];
    }
    while(left_run_var <= mid - left && right_run_var <= right - mid - 1){
        if(arr1[left_run_var] < arr2[right_run_var]){
            arr[left + arr_run_var] = arr1[left_run_var];
            left_run_var++;
            arr_run_var++;
        }else{
            arr[left + arr_run_var] = arr2[right_run_var];
            right_run_var++;
            arr_run_var++;
        }
    }
    while(left_run_var <= mid - left){
        arr[left + arr_run_var] = arr1[left_run_var];
        left_run_var++;
        arr_run_var++;
    }
    while(right_run_var <= right - mid - 1){
        arr[left + arr_run_var] = arr2[right_run_var];
        right_run_var++;
        arr_run_var++;
    }
}
void sort(int *arr, int x, int y){
    int mid = x + (y - x) / 2;
    if( x < y){
        sort(arr, x, mid);
        sort(arr, mid + 1, y);
        merge(arr, x, y, mid);
    }
}

int binary_search(int x, int *arr, int left, int right){
    int ori_left = left;

    int ori_right = right;

    while(right  - left > 1){
        int mid = left + (right  - left) / 2;
        if(arr[mid] > x){
            right  = mid;
        }else if(arr[mid] <= x){
            left = mid;
        }
    }
    if(left > ori_left && right < ori_right){
        return left - ori_left + 1;
    }else if(left == right){
        if(arr[left] <= x){
            return 1;
        }else{
            return 0;
        }
    }else if(left == ori_left && right == ori_right){
        if(arr[right] <= x){
            return 2;
        }else if(arr[left] <= x){
            return 1;
        }else if(arr[left] > x){
            return 0;
        }
    }else if(left == ori_left){
        if(arr[left] > x){
            return 0;
        }else{
            return 1;
        }
    }else if(right == ori_right){
        if(arr[right] > x){
            return right - ori_left;
        }else{
            return right - ori_left + 1;
        }
    }
}

int main(){
    //nhận số cửa hàng
    int num_shop;
    scanf("%i", &num_shop);
    //nhận số tiền bán của mỗi cửa hàng
    int shop_cost[num_shop];
    for(int i = 0; i < num_shop; i++){
        scanf("%i", &shop_cost[i]);
    }
    //sort mảng shop_cost
    sort(shop_cost,0, num_shop - 1);
    //nhận số ngày mua rượu
    int num_day;
    scanf("%i", &num_day);
    //nhận số tiền có mỗi ngày
    int money[num_day];
    for(int i = 0; i < num_day; i++){
        scanf("%i", &money[i]);
        //search money[i] trong mảng
    }
    for(int i = 0; i < num_day; i++){
        //in ra 
        printf("%i \n",binary_search(money[i], shop_cost, 0, num_shop - 1));
    }

    return 0;
}