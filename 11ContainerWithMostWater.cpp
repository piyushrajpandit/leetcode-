class Solution {
public:
    int maxArea(vector<int>& height) {
        int min_height = height[0];
        int max_height = height[height.size() -1];
        int min_index =0;
        int max_index = height.size()-1;

        if(min_height > max_height){
            min_height = max_height;
            min_index = max_index;
            max_height = height[0];
            max_index = 0;
        }
            int w = height.size() -1;
            int max_area = min_height* w;

            while(w > 0){
                int idx = min_index;
                while(height[idx] <= min_height){
                    if(min_index < max_index){
                        idx++;
                    }
                    else{
                        idx--;
                    }
                    w--;
                    if(w< 1){
                        break;
                    }

                }
                if(height[idx]> max_height){
                    min_height = max_height;
                    min_index = max_index;
                    max_height = height[idx];
                    max_index = idx;
                }
                else{
                    min_index = idx;
                    min_height = height[idx];
                }
                max_area = max(max_area, min_height*w);
            }
        
        
        return max_area;
    }
};
