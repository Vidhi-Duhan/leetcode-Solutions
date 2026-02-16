# 31. Next Permutation
## Intuition
The idea is to generate the next lexicographically greater permutation with the smallest possible change.

To find the next permutation treat the array as like a digit and find what could be its next greater.

 for eg-array->1,2,3 . 
array->1,2,3 .

step 1) Treat it like a digit-> 123.

step2)  Now, find what could be the next greatest element after 123 including 1,2 and 3.

 ans->132.

Hence, the next permutation of the given array is 1,3,2.
---

## Approach

step1) Take a pivot element. idx=-1;

step2) Now compare this pivot element with whole array and find the first smallest pivot.

step3) If does not find pivot that means the array is in descending order then convert it into ascending order by reversing or sorting the whole array . To do it, we can apply the reverse or sorting function.

step4) Now, find the first element which is just greater than pivot element.

step5)Now, swap the pivot element with the element which is just greater than pivot.

step6) Now, we get the next permutation of the array.
---

## Complexity
** Time complexity: **

For Best Case->O(n)

For Average Case->O(n)

For Worst Case->O(n)

Space complexity:O(1)
---

# Code
## 💻 C++ Code
```cpp
#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;  //idx=pivot element;
        //find first pivot element ;
          for(int i=n-2; i>=0; i--){ 
             if(nums[i]<nums[i+1]){
                idx=i;
                break;
              }
          }
          //if does not find(i.e. array is in descending order then make it into ascending by rev or sorting) reverse the whole array ;
          if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //after finding first pivot element reverse the array part which is after the pivot;
              reverse(nums.begin()+idx+1,nums.end());
              // then find the just first greater element then pivot element;
              int j=-1;
              for(int i=idx+1; i<n; i++){
                if(nums[i]>nums[idx]){
                   j=i;
                    break;
                }
              }
              //now swap pivot with first greater element;
              int temp=nums[idx];
              nums[idx]=nums[j];
              nums[j]=temp;   
    
    return;
    }
};
```
