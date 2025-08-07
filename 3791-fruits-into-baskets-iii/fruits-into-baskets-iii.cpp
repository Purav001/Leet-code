class Solution {
public:
    // sqrt decomposition
    // instead of looking in whole baskets array , we divide the baskets array into sectors
    // where sector length is a - i.e. if m=9 we divide baskets into 3 sectors of 3 length each
    // we make a vector to store the max element of each vector
    // for every fruit we look into that sector max vector so that we get a sector in which we look instead of looking for whole baskets array
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0,m=baskets.size();
        // brute force

        // unordered_map<int,bool> mp;
        // for(int i=0; i<m; i++){
        //     mp[i]=false;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(!mp[j] && fruits[i]<=baskets[j]){
        //             mp[j]=true;
        //             ans++;
        //             break;
        //         }
        //     }
        // }

        // sqrt decomposition

        vector<int> smx;
        int a=sqrt(m); // size of one sector
        int cnt=0,mx=0;
        for(int i=0;i<m;i++){
            if(cnt==a){
                smx.push_back(mx); // mx element of sector
                cnt=1;
                mx=baskets[i];
            }
            else{
                cnt++;
                mx=max(mx,baskets[i]);
            }
        }
        // last sector
        smx.push_back(mx);
        int remain=0;
        // we start from left to right
        for(int i=0;i<n;i++){
            int k=0,set=1;
            for(int j=0;j<m;j+=a){
                if(smx[k]<fruits[i]){
                    // skip this sector
                    k++;
                    continue;
                }
                // find place to allocate
                for(int r=j;r<min(j+a,m);r++){
                    if(baskets[r]>=fruits[i]){
                        set=0;
                        baskets[r]=0;
                        break;
                    }
                }
                // if the fruit is allocated , than find the new max element of sector
                if(set==0){
                    smx[k]=0;
                    for(int r=j;r<min(j+a,m);r++) smx[k]=max(smx[k],baskets[r]);
                    break;
                }
            }
            remain+=set;
        }
        return remain;
    }
};