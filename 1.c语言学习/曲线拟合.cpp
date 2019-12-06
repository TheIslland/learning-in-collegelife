#include<cstdio>
#include<cmath>
//#include<cconio>
float cf(int i,float f) {
	float g = 1.0;
	while(i--){g *= f;
	return g;}
}
void ColPivot(float a[99][99], int n, float b[99][1], float z[99]){
	float max, m, temp;
	int k, q = 0, i, j, l;
	for(k = 0; k < n && q == 0; k++){
		max = a[k][k];
		for(i = k + 1; i < n; i++)
			if(fabs(max) < fabs(a[i][k])){
				max = a[i][k];l = i;}
			if(max == 0){
				q = 1;
			}else {
				if (l != k){
					temp = b[l][0];  b[l][0] = b[k][0];
					b[k][0] = temp;
		for(i = n - 1; i >= 0; i--){
			for(j = n - 1; j >= i + 1; j--) {
				b[i][0] = b[i][0] - a[i][j] * z[j];
				z[i] = b[i][0] / a[i][i];
            }
    }
}
int main(){
	float x[99], y[99], z[99],s[99][99],t[99][1];
	int n, m , i, j, k;  printf("n = ");  scanf("%d", &n);
	printf("m = ");scanf("%d", &m);
	printf("x[%f] = ",n);
	for(i = 0; i < n; i++) 
		scanf("%f", &x[i]);
	printf("y[%f] = ", n);
	for(i = 0; i < n; i++) 
		scanf("%f", &y[i]);
	for(i = 0; i <= m; i++) {
		for(j = 0; j <= m; j++){
			s[i][j] = 0.0;
			for(k = 0; k <= n - 1; k++)   s[i][j] += cf(i + j, x[k]);}
		t[i][0] = 0.0;
		for(j = 0; j <= n - 1; j++)
			t[i][0] += y[i] * cf(i, x[j]);}
	for(i = 0; i <= m; i++) {
		for(j = 0; j <= m + 1; j++)   printf("%f\t", s[i][j]);printf("\n");}
	ColPivot(s, m + 1, t, x);
	printf("\n\n");
	for(i = 0; i <= m; i++)
		printf("\na[%d] = %f", i, x[i]);
        printf("\n\n");
}