#include <stdio.h>
#include <malloc.h>
typedef struct{
	char TenDV[20];
	float TL, DG, GT;
	int PA;
}DoVat;

DoVat *Read(float *w, int *n){
	FILE *f;
	f = fopen("caibalo1.inp","r");
	fscanf(f,"%f",w);
	DoVat *dsdv;
	dsdv = (DoVat*) malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*) realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n = i;
	return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat t;
	t = *x;
	*x = *y;
	*y = t;
}

void bubbleSort(DoVat *dsdv, int n){
	for(int i = 0; i < n-2;i++){
		for(int j = n-1; j >= i;j--)
			if(dsdv[j].DG > dsdv[j-1].DG)
				swap(&dsdv[j],&dsdv[j-1]);
	}
}
void print(DoVat *dsdv, int n, float w){
	for(int i = 0; i < n; i++){
		printf("%20s-%3f-%3f-%3f-%3d\n",dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
	}
}

int main(){
	int n;
	float w;
	DoVat *dsdv;
	dsdv = Read(&w,&n);
	print(dsdv,n,w);
	bubbleSort(dsdv,n);
	printf("Mang sau khi sap xep:\n");
	print(dsdv,n,w);
	free(dsdv);
	return 0;
}
