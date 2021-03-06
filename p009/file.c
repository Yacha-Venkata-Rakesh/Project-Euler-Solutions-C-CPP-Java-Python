#include<stdio.h>
int sq_root(int n){
    int f=1,l=n, ans;    
    while(f<=l){         
        long long int mid = f+(l-f)/2;
        long long int t = mid*mid;
        if(t == n) 
            return mid;
        if(t<n){ 
            f = mid+1; 
            ans = mid; 
        }  
        else
            l = mid-1;         
    } 
    return ans; 
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int flag = 0;
        for(int c = 0.414*n;c<n/2;c++){
            int t1 = c*c-n*n+2*n*c;
            int t2 = sq_root(t1);
            if(t2*t2 == t1){
                int b = (n+t2-c)/2;
                int a = n-b-c;
                printf("%lld\n",a*b*c);
                flag = 1;
                break;
            }
        }
        if(flag==0)
            printf("-1\n");
    }
    return 0;
}
/*  Explanation:
        a+b+c = n
        a+b = n-c
        (a+b)² = (n-c)²
        a²+b²+2ab = n²+c²-2nc
        c²+2ab = n²+c²-2nc  ( a²+b² = c²)
        n² = 2ab+2nc
        n² = 2(ab+nc)
        n² is a 2 multiple  =>  n is a 2 multiple.

        Hence n is always an even number


        from above n² = 2ab+2nc
                    n²-2nc = 2ab
                    2nc-n² = -2ab
                    2nc+c²-n² = c²-2ab
                    2nc+c²-n² = a²+b²-2ab
                    2nc+c²-n² = (a-b)²
                    
        Thus 2*n*c+c²-n² must be a perfect square.

        From above 2nc+c²-n² = (a-b)²
                   2nc+c²-n²>0
                   c²+2nc-n²>0
                   c²+2nc>n²
                   c²+2nc+n²>2*n²
                   (c+n)²>2*n²
                   c+n>√2*n
                   c>(√2-1)*n
        
        Hence c > (√2-1)*n

        (a-b)² = c²-n²+2nc
        (a-b)² = t1
        a-b = t2
        a+b = n-c

        Solving both    b = (n-c-t2)/2
        a = n-c-b
*/