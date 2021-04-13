#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    int sampNum;    // ��������
    int width;       // λ��
    int widthPoints; // λ�����
    double y;
    double phi; // ��ʼ��λ
    int n;
    int out;    // �������

    FILE *fp;
    fp = fopen("out.txt","w"); // ����out.txt�ļ����ڴ���������

    printf("������λ��: \n");
    scanf("%d",&width);
    printf("�������������: \n");
    scanf("%d",&sampNum);
    printf("�������ʼ��λ(N*4/��)��\n");
    scanf("%d",&n);

    phi = M_PI*n/4;// ��ʼ��λΪ����n��PI/4��
    widthPoints = pow(2,width)-1; // λ�����Ϊ2������λ��η���һ
    for(i=0;i<sampNum;i++){
        y = sin(2*M_PI*i/sampNum + phi); // ����һ�������ڵ�ÿ��������Ĵ�С
        out = widthPoints*(y+1)/2;
        printf("LUT[ %d ] <= %d'd %d;\n",i,width,out);
        fprintf(fp,"LUT[ %d ] <= %d'd %d;\n",i,width,out); // ������ո�ʽ�����ļ�out.txt
    }
    fclose(fp);// �ر��ļ�
    printf("�������ⰴ���˳�");
    system("pause");
    return 0;
}

