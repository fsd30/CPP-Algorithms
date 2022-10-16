class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
              if(fun(board,i,j,word,0))
                  return true;
        return false;
     }
    
bool fun(vector<vector<char>>&board,int r,int c,string &word,int count)
    {    
     
       if(word.size()==count)
           return true;
         
if(r>=board.size()||r<0||c<0||c>=board[0].size()||board[r][c]!=word[count])
    return false;
       
    
    // Visited
     board[r][c]='@';
                      // up                              // down                                   
      bool status= fun(board,r-1,c,word,count+1)|| fun(board,r+1,c,word,count+1) || 
               // left                          // right
          fun(board,r,c-1,word,count+1)||  fun(board,r,c+1,word,count+1);
    
    // Non Visited
    board[r][c]=word[count];
    
    return status;
}
     
};
