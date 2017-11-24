#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		int arr[16][16];
		int arr_1[16][16];
		int arr_2[16][16];
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&arr[i][j]);
				arr_1[i][j]=arr[i][j];
				arr_2[i][j]=arr[i][j];
			}
		}
		for(int l=2;l<=k;l++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					arr_2[i][j]=0;
					for(int m=0;m<n;m++){
						arr_2[i][j] += arr_1[i][m]*arr[m][j];
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					arr_1[i][j]=arr_2[i][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d",arr_2[i][0]);
			for(int j=1;j<n;j++){
				printf(" %d",arr_2[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
