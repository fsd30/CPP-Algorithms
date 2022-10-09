class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int>res;
    unordered_map<string,int>wmap;
    int slen = s.size();           //lenght of string(18)
    int noOfWord = words.size();   //no of word in word vector(2)
    int wordLen = words[0].size(); //length of a single word(3)
    int TotalWSize = noOfWord*wordLen;  //total word size(6)
    
    if(TotalWSize > slen)      //if the total word size is more than slen (6>18)
        return res;
    
    //word map wth all entry wmap["foo":1, "bar":1]
    for(auto it:words)        
        wmap[it]++;
    
    for(int i=0;i<=slen-TotalWSize;i++){   //i<slen-TotalWSize this means i<18-6 / i<12
        //count of a freq in give length
        unordered_map<string,int>wfreq;
        for(int j=i;j<i+TotalWSize;j+=wordLen){ //taking the length of wordlen to jump
            string str = s.substr(j,wordLen);  //cal the sub string
            if(wmap.find(str)==wmap.end())   //if sub str is not present then break
                break;
            wfreq[str]++;
            if(wfreq[str]>wmap[str])       //if str cnt is more than break 
                    break;
        }
        if(wfreq == wmap)        //if we get all value same then add the start index
            res.push_back(i);
    }       
    return res;
}

};
