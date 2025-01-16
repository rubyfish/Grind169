class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int target, int color){
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        if (image[sr][sc] != target)
            return;
        
        image[sr][sc] = color;
        dfs(image, sr+1, sc, target, color);
        dfs(image, sr-1, sc, target, color);
        dfs(image, sr, sc+1, target, color);
        dfs(image, sr, sc-1, target, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] != color)
            dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }
};