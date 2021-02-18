class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }else{
                digits[i]=0;
            }
        }
        vector<int> add;
        add.push_back(1);
        for(auto i:digits){
            add.push_back(i);
        }
        return add;
    }
};