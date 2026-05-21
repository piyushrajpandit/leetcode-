// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// there are two ways binary search ke tarah se bhi kar sakte hai  aur recurssion se ye hai hi 
class Solution {
public:
    int firstBadVersion(int n) {
        return fBV(1,n);
        
    }
    int fBV(int s, int e){
        if(s==e){
            return s; 

        }
        int mid = s+ (e-s)/2; //(s+e)/2
        if(isBadVersion(mid))
            return fBV(s, mid);
        return fBV(mid+1, e);
        

    }
};
