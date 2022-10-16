#include <bits/stdc++.h>

using namespace std;
#define MAX_N 5000+1

int b[MAX_N];

int kmpPreprocess(char T[], int m){
    int j=-1, i=0, ans=0;
    while(i<m){
        while(j >= 0 && T[i] != T[j]) j = b[j];
        i++,j++;
        b[i] = j;
        ans = max(ans,j);
    }
    return ans;
}
int main(){
    cin.tie(NULL);ios_base::sync_with_stdio(false);
    b[0] = -1;
    char S[5000+1];
    int TC; cin >> TC;
    while(TC-->0){
        cin >> S;
        int len = strlen(S);
        int ans = 0;
        int i = 0;
        while(i<len){
            int jump = kmpPreprocess(S+i, len-i);
            ans = max(ans, jump);
            i+= b[jump]>0 ? b[jump] : 1;
        }
        cout << ans << endl;
    }

    return 0;
}
