#include <stdio.h>
#include <string.h>

typedef struct{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;   
}SinhVien;
typedef struct{
    SinhVien A[40];
    int n;
}DanhSach;
void danhsachRong(DanhSach *L){
    L->n = 0;
}
void nhap(int n, DanhSach *L){
    for(int i = 0 ; i < n;i++){
        fgets(L->A[i].MSSV,10,stdin);
        if(L->A[i].MSSV[strlen(L->A[i].MSSV) - 1] == '\n')
            L->A[i].MSSV[strlen(L->A[i].MSSV) - 1] = '\0';
        fgets(L->A[i].HoTen,50,stdin);
        if(L->A[i].HoTen[strlen(L->A[i].HoTen) - 1] == '\n')
            L->A[i].HoTen[strlen(L->A[i].HoTen) - 1] = '\0';
        fscanf(stdin,"%f", &L->A[i].DiemLT);
        fscanf(stdin,"%f", &L->A[i].DiemTH1);
        fscanf(stdin,"%f ", &L->A[i].DiemTH2);
        L->n++;
    }

}
void hienthiSV(SinhVien sv){
    printf("%s - %s - %.2f - %.2f - %.2f ",sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2);
    printf("\n");
}
void hienthi(DanhSach L){
    for(int i = 0 ; i < L.n;i++){
        printf("%s - %s - %.2f - %.2f - %.2f ",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    
        printf("\n");
    }
}
void dat(DanhSach L){
    for(int i = 0 ; i  < L.n;i++){
        float x = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(x > 4)
            hienthiSV(L.A[i]);
    }
}

