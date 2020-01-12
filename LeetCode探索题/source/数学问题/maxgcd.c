// 最大公约数
#include <stdio.h>
int getMaxGcd(int big,int small){
    if(big % small == 0){
        return small;
    }
    // 记录除以2的次数
    int times = 0;
    while(big!=small){
        if(big % 2 == 0 && small % 2 == 0){
            big /= 1;
            small /= 2;
            times++;
        }else{
            int temp = big - small;
            if(temp >= small){
                big = temp;
            }else{
                big  = small;
                small = temp;
            }
        }
    }

    if(times == 0){
        return small;
    }else{
        return small * times * 2;
    }
}

int main(){
    int a,b;
    scanf("%d %d" ,&a,&b);
    // 始终使a是较大数，b是较小数
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    printf("%d",getMaxGcd(a,b));
}