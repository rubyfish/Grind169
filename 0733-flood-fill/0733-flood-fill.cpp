class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int src_color, int target_color){
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        if (image[sr][sc] != src_color)
            return;
        image[sr][sc] = target_color;

        dfs(image, sr + 1, sc, src_color, target_color);
        dfs(image, sr - 1, sc, src_color, target_color);
        dfs(image, sr, sc + 1, src_color, target_color);
        dfs(image, sr, sc - 1, src_color, target_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }
};