/*
    book Allocation
    K = 2

    10, 20, 30, 40


    Iteration 1:
    Search Space => 0 ---- 100

    mid = 50

    i => 10 + 20
    ii => 30
    iii => 40
    =>>>-------------> s = mid + 1;

    Iteration 2:
    Search Space => 51 --- 100

    mid 75

    i => 10 + 20 + 30
    ii => 40

    =>>>>----------------> ASN = mid; e = mid - 1;

    Iteration 3:
    Search Space => 51 --- 74;

    mid 62

    i => 10 + 20 + 30;
    ii => 40

    =>>>---------------> ANS = mid; e = mid -1;

    Iteration 4:
    Search Space => 51 ---- 61
    mid = 56

    i => 10 + 20;
    ii => 30
    iii => 40

    =>>>------------------> s = mid  + 1;

    Iteration 5:
    Search Space => 57 --- 61

    mid  59

    i => 10 + 20
    ii => 30
    iii => 40

    =>>>>--------------- s = mid + 1;

    Iteration 6:
    Search Space 60 ---- 61
    mid = 60

    i => 10 + 20 + 30
    ii => 40

    =>>>----------------> ANS = mid; e = mid -1;

    Beak => s > e

   ANS => 60

*************************************************************
    1) divided the given array ... K number partition with max value lastly min value all of them
    2) Search space => minimize [ .. ]
    3) sum of all element Search Space on it 0 - sum
    4)  Binary Search on 0 - sum => mid
    5) try to make with given contigious arr + + K number group with => mid
    6) if it gives K > then => s = mid +1
    7)


 */


 #include<bits/stdc++.h>
 using namespace std;

 bool isPossible(int arr[], int n, int k, int mid)
 {
     int studentCount = 1;
     int pageSum = 0;

     for(int i = 0; i < n; i++)
     {
         // page sum 10 + 20 <= 50 Like
         if(pageSum + arr[i] <= mid)
         {
             pageSum += arr[i];
         }
         else{

            // next partition => 30 + 40
            // next student partition
            studentCount++;
            if(studentCount > k || arr[i] > mid)
            {
                // if the student k or next arr[i] element > mid cha boro
                return false;
            }
            pageSum = arr[i];

         }
     }

     return true;
 }


 int allocationBooks(int arr[], int n, int k)
 {

     int s = 0;
     int sum = 0;

     for(int i = 0; i < n; i++)
     {
         sum += arr[i];
     }

     int e = sum;

     int mid = s + (e - s)/2;

     int ans = -1;
     while(s <= e)
     {
         // call for find make k partition
         if(isPossible(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
         }
         else{
            s = mid + 1;
         }
         mid = s + (e - s)/2;
     }


     return ans;
 }


 int main()
 {
     int arr[4] = {10, 20, 30, 40};

     cout << allocationBooks(arr, 4, 2) << endl;

     return 0;
 }
