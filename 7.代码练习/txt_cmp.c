/*************************************************************************
	> File Name: txt_cmp.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月24日 星期日 08时29分24秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAXLEN 257
#define MAXLEN 257
void CompareFile(FILE *fa,FILE *fb,FILE *flog) {
char sa[MAXLEN],sb[MAXLEN],temp[MAXLEN],flag;
fgets(sa,MAXLEN,fa);
while(!feof(fa)&&!feof(fb)) {
fgets(sa,MAXLEN,fa);
 fgets(sb,MAXLEN,fb);
 
 if(strcmp(sa,sb) != 0) { 
 if(0==strcmp(sa,temp)) ; //消除重复数据 最后一行回车
else  {fputs(sa,flog);  fputs(sb,flog);}  strcpy(temp,sa);}
}
}
int  main( )
{
	FILE *fa,*fb,*flog;
fa = fopen("output1.txt","rt"); //真实数据 存在第一行没用的数据
fb = fopen("output3.txt","rt");
flog = fopen("log.txt","wt"); //at+
if(fa == NULL ) {
printf("actual seg 文件未找到。\n");
return 1;
}
if( fb == NULL ) {
printf("expect  seg文件未找到。\n");
return 1;
} 
CompareFile(fa,fb,flog);
fclose(fa);
fclose(fb);
fclose(flog);
return 0;	
}

