#include<iostream>
#include<vector>
#include<string>
using namespace std;

// This code provides the combinations of all the letters against the numbers on keys of old fashioned keyboard (keypad mobiles). The digits are provided in the string

void Combinations(string digits,vector<string>& sol,string comb[],int ind,string cur){
        if(ind == digits.length()){
            sol.push_back(cur);
            return;
        }
        string curStr = comb[digits[ind] - '2'];

        for(int i=0;i<curStr.length();i++){
            cur += curStr[i];
            Combinations(digits,sol,comb,ind+1,cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string comb[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> sol;
        if(digits.length() == 0)return sol;
        
        string cur = "";
        
        Combinations(digits,sol,comb,0,cur);
        
        return sol;
    }

int main(){
    string dig = "23";
    vector<string> sol = letterCombinations(dig);

    for(auto it = sol.begin();it != sol.end() ; it++) cout << *it <<" ";
    cout << endl;
}
