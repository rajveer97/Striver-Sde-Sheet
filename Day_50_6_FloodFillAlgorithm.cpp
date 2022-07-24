// Method 1: Using DFS Traversal
void dfs(vector<vector<int>>& image, int x, int y, int newColor, int source)
{
    if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size())
        return ;
    else if(source != image[x][y])
        return ;

    image[x][y] = newColor;

    dfs(image, x-1, y, newColor, source); // UP
    dfs(image, x+1, y, newColor, source); // DOWN
    dfs(image, x, y-1, newColor, source); // LEFT
    dfs(image, x, y+1, newColor, source); // RIGHT      
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if(image[x][y] == newColor)
        return image;

    int source = image[x][y];
    dfs(image, x, y, newColor, source);

    return image;    
}