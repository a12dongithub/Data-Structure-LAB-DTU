#include<stdio.h>
#define sz 150
int main()
{
    int a[sz],b[sz],c[sz],d[sz],f[2*sz]={};
    printf("Enter 1st polynomial's size and them the terms\n");
    int n,m;
    scanf("%d",&n);
    m=n;
    int i=0;
    while(i<n)
    {
        scanf("%d%d",&a[i],&b[i]);
        i++;
    }
    i=0;
    while(i<n)
    {
        f[b[i]]+=a[i];
        i++;
    }
    printf("Enter 2nd polynomial's size and them the terms\n");
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
        scanf("%d%d",&c[i],&d[i]);
        i++;
    }
    i=0;
    while(i<n)
    {
        f[d[i]]+=c[i];
        i++;
    }
    i=0;
    i=sz-1;
    printf("The final sum is: ");
    while(i>-1)
    {
        if(f[i])
            printf("%dx^%d ",f[i],i);
        i--;
    }
    int ans[2*sz]={};
    i=0;
    int j;
    while(i<m)
    {
        j=0;
        while(j<n)
        {
            ans[b[i]+d[j]]+=a[i]*c[j];
            j++;
        }
        i++;
    }
    printf("\nThe final Product is: ");
    i=2*sz-1;
    while(i>-1)
    {
        if(ans[i])
            printf("%dx^%d ",ans[i],i);
        i--;
    }
}