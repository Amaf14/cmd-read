#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
        char free[30], total[30];
        int i, a=0, b=0;
        FILE *ff, *ft;
        ff=popen("egrep 'MemFree' /proc/meminfo", "r");
        ft=popen("egrep 'MemTotal' /proc/meminfo", "r");
        fgets(free, 30, ff);
        fgets(total, 30, ft);
        for(i=0;i<=strlen(free);i++) {
                if(free[i]>=48 && free[i]<=57)
                        a=a*10+(int)(free[i]-'0');
        }
        for(i=0;i<=strlen(total);i++) {
                if(total[i]>=48 && total[i]<=57)
                        b=b*10+(int)(total[i]-'0');
        }
        printf("%d \n", a/1024);
        printf("%d \n", b/1024);
        exit(1);
}
