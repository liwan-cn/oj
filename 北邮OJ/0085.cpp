#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool flag = false;
        double state[128][2],xl;
        if(n<3) puts("No");
        else{
            for(int j=0;j<n;j++)
                scanf("%lf%lf",&state[j][0],&state[j][1]);
            for(int k=0;k<n-2;k++){
                for(int m=k+1;m<n-1;m++){
                   xl = (state[m][1]-state[k][1])/(state[m][0]-state[k][0]);
                    for(int l = m+1;l<n;l++){
                        if (xl==(state[l][1]-state[k][1])/(state[l][0]-state[k][0])){
                        	flag = true;
                        	break;
						}
                    }
                    if(flag) break;
                }
				if(flag) break;
            }
            puts(flag?"Yes":"No");
        }
    }
    return 0;
}
