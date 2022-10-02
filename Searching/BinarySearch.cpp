#include<iostream>
using namespace std;

int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}

int main() {
   int arr[] = {1,2,3,4,5,6,7,8,9,10};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int num;

   cout << "Enter the number to search: \n";
   cin >> num;

   int index = binarySearch (arr, 0, n-1, num);
   if(index == -1){
      cout << "Found!";
   }else{
      cout << "Not Found!";
   }

   return 0;
}