#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    int sampNum;    // 采样点数
    int width;       // 位宽
    int widthPoints; // 位宽点数
    double y;
    double phi; // 初始相位
    int n;
    int out;    // 输出整数

    FILE *fp;
    fp = fopen("out.txt","w"); // 创建out.txt文件用于储存输出结果

    printf("请输入位宽: \n");
    scanf("%d",&width);
    printf("请输入采样点数: \n");
    scanf("%d",&sampNum);
    printf("请输入初始相位(N*4/π)：\n");
    scanf("%d",&n);

    phi = M_PI*n/4;// 初始相位为输入n的PI/4倍
    widthPoints = pow(2,width)-1; // 位宽点数为2的输入位宽次方减一
    for(i=0;i<sampNum;i++){
        y = sin(2*M_PI*i/sampNum + phi); // 计算一个周期内的每个抽样点的大小
        out = widthPoints*(y+1)/2;
        printf("LUT[ %d ] <= %d'd %d;\n",i,width,out);
        fprintf(fp,"LUT[ %d ] <= %d'd %d;\n",i,width,out); // 结果按照格式存入文件out.txt
    }
    fclose(fp);// 关闭文件
    printf("按下任意按键退出");
    system("pause");
    return 0;
}

