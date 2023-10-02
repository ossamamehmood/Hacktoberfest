/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0, l = mountainArr.length() - 1, mid;
		
		// binary Search Peak element
        while(s < l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) s = mid + 1;
            else l = mid;
        }
        
        int peak = s;
        
		// binary Search in First Half
        s = 0; l = peak;
        bool flagL = false, flagR = false;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagL = true;
                break;
            }
            else if(mountainArr.get(mid) < target) s = mid + 1;
            else l = mid - 1;
        }
        
        if(flagL) return mid;
        
		// binary Search in second Half
        s = peak + 1; l = mountainArr.length() - 1;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagR = true;
                break;
            }
            else if(mountainArr.get(mid) > target) s = mid + 1;
            else l = mid - 1;
        }

        if(flagR) return mid;
        
        return -1;
    }
};
