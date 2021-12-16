#include <stdio.h>
#include <string.h>
#define M 100
int main(void)
{
    FILE *fp=NULL;
    double nums[M],num2[M];
    double n1,n2;
    int len,i;
    char name[M],str[10];
    fp=fopen("chinagps.txt","r");
    while(fscanf(fp,"%d%s%d",&n1,str,&n2)!=-1)
    {
    	nums[i]=n1;
    	//strcpy(name[i],str);
    	num2[i]=n2;
    	i++;len++;
	}
	for(i=0;i<len;i++)
		printf("%d %d\n",nums[i],num2[i]);
	fclose(fp);
	return 0;
}
