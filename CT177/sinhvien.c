#include <stdio.h>
typedef struct {
    char mssv[10];
    char name[50];
    float lt;
    float th1;
    float th2;
} SinhVien;
typedef struct{
    SinhVien A[40];
    int n;

}List;
int main(){
    List L = {{{"B1806972","Hoang Minh", 5.5f, 4.5f, 5.0f}}, 1};
printf("Size L = %lu x %lu\n",
    sizeof(L.A)/sizeof(SinhVien), sizeof(SinhVien));
printf("n = %d",L.n);
    return 0;
}