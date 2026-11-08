class Solution {
public:
    vector<int> findnse(vector<int> & arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = arr.size() -1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }
            nse[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpsse(vector<int> & arr){
        int n = arr.size();
        vector<int> psse(n);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i] ){
                st.pop();
            }
            psse[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        return psse;
    }



    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> psse = findpsse(arr);


        int n = arr.size();

        long long total = 0;
        long long mod =  1e9 + 7;
        for(int i =0 ; i< n; i++){
            long left = i -psse[i];
            long right = nse[i] - i;
            total = (total + (right *left *1LL *arr[i])% mod) %mod;
        }
        return total;
    }
};
