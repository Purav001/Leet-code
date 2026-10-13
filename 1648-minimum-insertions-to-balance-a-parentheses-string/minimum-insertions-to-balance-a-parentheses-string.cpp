class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,result=0,n=s.size();
        int flag=0,i=0;
        while(i<n){
            if(i==n-1){
                flag=1;
                break;
            }
            if(s[i]=='(') cnt++;
            else{
                if(cnt>0){
                    if(s[i+1]==')') {
                        cnt--;
                        i++;
                    }
                    else {
                        result++;i++;
                    }
                }
                else{
                    if(s[i+1]==')'){
                        i++;
                        result++;
                    }
                    else {
                        result+=2;
                        cnt++;
                        i++;
                    }
                }
            }
            i++;
        }
        if(flag==1){
            if(s[i]==')'){
                if(cnt>0){
                    result++;
                    cnt--;
                }
                else result+=2;
            }
            else cnt++;
        }
        return (cnt*2)+result;
    }
};