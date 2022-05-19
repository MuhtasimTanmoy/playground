class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(int i = 0 ; i < size(image); i++) {
            int start = 0;
            int end = size(image[i]) - 1;
            while(start < end) {
                if (image[i][start] != image[i][end]) 
                    swap(image[i][start], image[i][end]);
                start++;
                end--;
            }
        }
        
        for(int i = 0 ; i < size(image); i++ ) 
            for(int j = 0 ; j < size(image[i]); j++ ) 
                image[i][j] = 1 - image[i][j];
        
        return image;

    }
};