class Solution {
public:
    bool solve(string s, int &i){
        if(s[i]=='t'){
            i++;
            return true;
        }
        if(s[i]=='f'){
            i++;
            return false;
        }
        char op=s[i++];
        i++; // skips '('
        vector<bool> values;
        while(s[i]!=')'){
            if(s[i]==','){
                i++;
                continue;
            }
            values.push_back(solve(s,i));
        }
        i++; // skips ')'
        if(op=='!')  return !values[0];
        if(op=='&'){
            for (auto v:values) if(!v) return false;
            return true;
        }
        if(op=='|'){
            for(auto v:values) if(v) return true;
            return false;
        } 
        return false;
    }
    bool parseBoolExpr(string s) {
        int i=0;
        return solve(s,i);
    }
};