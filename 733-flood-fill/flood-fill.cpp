class Solution {
public:
    void f(int sr,int sc,int &orlc,int color,vector<vector<int>>& image){
        if(sr<0 || sc<0 || sr==image.size() || sc==image[0].size())return ;
        if(orlc!=-1 && image[sr][sc]!=orlc)return;
        else orlc=image[sr][sc];
        image[sr][sc]=color;
        f(sr+1,sc,orlc,color,image);//down
        f(sr-1,sc,orlc,color,image);//up
        f(sr,sc+1,orlc,color,image);//left
        f(sr,sc-1,orlc,color,image);//right


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])return image;
        int orlc=image[sr][sc];
        f(sr,sc,orlc,color,image);
        return image;
    }
};