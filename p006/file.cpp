#include<iostream>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        ll t1 = 3*n*n-n-2;
        ll t2 = n*(n+1)*t1;
        cout<<t2/12<<endl;
    }
    return 0;
}

/* Explanation:
    Sum of numbers from 1 to n is n*(n+1)/2
    Sum of squares of numbers from 1 to n i.e 1^2+2^2+...+n^2 is n*(n+1)*(2n+1)/6
    n*(n+1)*(2n+1)/6-n*n*(n+1)*(n+1)/4
    solving you get n*(n+1)*(3*n*n-n-2)/12
*/