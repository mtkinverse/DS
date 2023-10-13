#include<iostream>
#include<string>
#include<vector>

// Here we are generating the possible number of pairs given by the user

using namespace std;
class Solution {
public:

   bool ValidPairs(string str,int ind,string cur){
		
		if(ind >= str.length()) return false;
		if(ind == str.length() - 1 && str[ind] == ')' && cur == "(") return true;
		
		if(str[ind] == '(') cur += str[ind];
		else if(cur.length()>0 && cur[cur.length()-1] == '(' ){
			cur.pop_back();
		}else return false;
		
		return ValidPairs(str,ind+1,cur);
	}

    void Generate(vector<string>& sol,string cur,int ind,int n){
        if(ind >= n){
            if(cur[cur.length()-1] != ')') return;
            if(ValidPairs(cur,0,""))
                sol.push_back(cur);
            return;
        }
        char var = '(';
        for(int i=0;i<2;i++){
            cur.push_back(var+i);
            Generate(sol,cur,ind+1,n);
            cur.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string cur = "";
        Generate(sol,cur,0,2*n);
        return sol;
    }
};

int main(){
   
    Solution obj;
   
    int n;
    cout << "How many pairs to be used : ";
    cin >> n;
   
    vector<string> sol = obj.generateParenthesis(n);
    for(auto i = sol.begin();i!=sol.end();i++) cout << *i << " ";
   

return 0;
}
