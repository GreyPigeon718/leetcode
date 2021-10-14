class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        O(n)
 //       int i = 0;
 //       for( i = 0; i < arr.size(); ++i)
 //       {
  //          if(arr[i] > arr[i+1])
 //               return i;
 //       }
   //     return i ;
   //二分查找
        int left = 0, right = arr.size() - 2;
        int index;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] > arr[mid + 1])
            {
                index = mid;
                right--;
            }
            else
                left++;
        }
        return index;
    }
};