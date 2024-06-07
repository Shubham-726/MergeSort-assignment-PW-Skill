class Solution {
public:
    int ans;
    void merge(vector<int>&a,vector<int>&b,vector<int>&res){
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<a.size()&&j<b.size()){
        if((long long)a[i]>(long long)2*b[j]){
            ans+=a.size()-i;
            j++;
        }
        else 
            i++;
        }
        i =0;  j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                res[k] = a[i];
                i++;
                k++;
            }
            else{
                res[k] = b[j];
                k++;
                j++;
            }
        }
        if(i == a.size()){
            while(j<b.size()){
                res[k] = b[j];
                k++;
                j++;
            }
        }
        if(j == b.size()){
            while(i < a.size()){
                res[k] = a[i];
                k++;
                i++;
            }
        }
    }
    void mergeSort(vector<int>&v){
        int n = v.size();
        if(n==1)
            return;
        int n1 = n/2;
        int n2 = n-n/2;
        vector<int>a(n1), b(n2);
        for(int i = 0;i<n1; i++){
            a[i] = v[i];
        }
        for(int i = 0; i<n2; i++){
            b[i] = v[i+n1];
        }
        mergeSort(a);
        mergeSort(b);
        merge(a,b,v);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return ans;
    }
};