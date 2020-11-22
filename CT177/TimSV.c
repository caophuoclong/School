#include "DanhSach.c"

int tim(char mssv[], DanhSach L){
    for(int i=0; i<L.n; i++){
        if(strcmp(mssv,L.A[i].MSSV) == 0){
            return i;
        }
    }
    return L.n + 1;
}

int main(){
    int n;
    scanf("%d  ",&n);
    DanhSach L;
    danhsachRong(&L);
    nhap(n,&L);
    hienthi(L);
    char mssv[10];
    fgets(mssv,10,stdin);
    if (mssv[strlen(mssv)-1] == '\n')
        mssv[strlen(mssv)-1] = '\0';
    if (tim(mssv,L) < L.n){
        printf("Tim thay sinh vien %s. Thong tin sinh vien:\n",mssv);
        hienthiSV(L.A[tim(mssv,L)]);   
    }
    else{
        printf("Khong tim thay sinh vien %s",mssv);
    }

    return 0;
}