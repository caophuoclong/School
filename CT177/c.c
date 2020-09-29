#include <stdio.h>
#include <string.h>
#define MAX = 20;
typedef struct{
    char mssv[20][10];
    char hoten[20][25];
    int last;
} Sv;
void dsRong(Sv *sv) {

    sv->last = 0;
}
Sv nhap(){
    Sv siv;
    //Khởi tạo danh sách rỗng
    dsRong(&siv);
    int number;
    char x[10];
    printf("%d",siv.last);
    //Nhập số lượng sinh sinh viên
    printf("Nhap so nguyen: ");
    scanf("%d",&number);
    printf("%d",number);
    fgets(x,10,stdin);
    //Nhập vào danh sách sinh viên
    for (int i = 0;i<number;i++){
        
        printf("Nhap sinh vien thu %d\n" ,i );
        printf("MSSV: ");
        fgets(siv.mssv[i],10,stdin);
        printf ("HOTen: ");
        fgets(siv.hoten[i],25,stdin);
        siv.last++;
        
    }
    //Kiểm tra có trùng sinh viên không. Nếu trùng thì xoá đi
    for (int i=0; i<siv.last; i++) {
        for (int j=i+1; j<siv.last; j++) {
            if (strcmp(siv.mssv[i],siv.mssv[j]) == 0) {
                strcpy(siv.mssv[j] ,siv.mssv[j+1]);
                strcpy(siv.hoten[j],siv.hoten[j+1]);
                j-=1;
                siv.last --;
            }
        }
    }
    return siv;
}


int main(){
    Sv sv = nhap();
    printf("SV\n");
    for (int i = 0;i < sv.last;i++){
        printf("MSSV: %s\n",sv.mssv[i]);
        printf("HOTEN: %s\n",sv.hoten[i]);
    }

    
    return 0;
    
}


