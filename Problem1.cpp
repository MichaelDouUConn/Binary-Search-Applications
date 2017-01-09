class Solution {
    /**
     * Input:
     *    A : an rotated, sorted array of integets
     *    target :  an integer to be searched
     * Output:
     * If not found, return -1;
     * If found, return the index of the target in the array A
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int low = 0;
        int high = A.size()-1;
        int mid;
        
        while( low <= high ){ // Shrink the search range of the given array until 0
            mid = (low+high)/2;
            if (A.at(mid) == target){ // Target Found !
                return mid;
            } else if (A.at(mid) > target ) {
                 if ( target < A.at(low) && A.at(low) <= A.at(mid) ){// Go to RIGHT half 
                     low = mid + 1;
                 } else {// Go to LEFT half
                     high = mid - 1;
                 }
            } else { // A.at(mid) < target
                if ( target > A.at(high) && A.at(high) >= A.at(mid) ){// Go to LEFT half
                    high = mid - 1;
                } else {// Go to RIGHT half
                    low = mid + 1;
                }
            }            
        }
        
        return -1; // not found !       
    }
};
