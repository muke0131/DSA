#include <stdio.h>
int main()
{
    int t,n,i,j,k1,k2,sum,temp;
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            scanf("%d %d",&k1,&k2);
            sum=0;
            for(i=k1-1;i<k2;i++){
                sum+=a[i];
            }
            printf("%d",sum);
        }
    }
	return 0;
}