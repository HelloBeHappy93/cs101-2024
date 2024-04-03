#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateNumbers(int numbers[5][7]) 
{
    int i, j;
    for (i = 0; i < 7; ++i) {
        int num;
        do {
            num = rand() % 69 + 1;
            // 檢查是否已經存在於陣列中
            int found = 0;
            for (j = 0; j < i; ++j) 
            {
                if (numbers[i][j] == num) 
                {
                    found = 1;
                    break;
                }
            }
            if (!found) 
            {
                numbers[i][j] = num;
                break;
            }
            else if(numbers[i][j]==0)
            {
                found = 1;
                break;
            }
        } while (1);
    }
}

int main()
{
    FILE *fp;
    int set;
    printf("歡迎光臨長庚樂透彩機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &set);
    getchar();
    time_t curtime;
    time(&curtime);
    char times[6]="00001";
    if(set==0)
    {
        int n[4];
        printf("請輸入中獎號碼(最多三個):");
        printf("輸入中獎號碼為:");
        scanf("%d %d %d", &n[0],&n[1],&n[2]);
        for (int i = 0; i < 4;i++)
        {
            if(n[i]<10)
            {
                printf("%d%d", 0, n[i]);
            }
            else
            {
                printf("%d", n[i]);
            }
            if(i>0)
            {
                printf(" ");
            }
        }
        printf("以下為中獎的彩卷:\n");
    }

    fp = fopen("lotto[00001].txt", "w+");
    fprintf(fp,"======== lotto649 ========\n" );
    fprintf(fp, "=======+ No.%s +=======\n",times);
    fprintf(fp, " %s", ctime(&curtime));
    int random_n[5][7]={0};
    srand((unsigned)time(NULL));
    for (int i = 0; i <= set - 1; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int n = rand() % 69 + 1;
            random_n[i][j] = n;
        }
    }
    /// 上面是製造array
    for (int i = 0; i <= 4; i++)
    {
        fprintf(fp, "[%d]:", i + 1);
        for (int j = 0; j < 7; j++)
        {
            if (random_n[i][j] < 10 && random_n[i][j]>0)
            {

                fprintf(fp, " %d%d", 0, random_n[i][j]);
                ///若為個位數則補零
            }
            else if(random_n[i][j]==0)
            {
                fprintf(fp, " __");
                ///沒有數字則畫底線
            }
            else
            {
                fprintf(fp, " %d", random_n[i][j]);
                ///非個位數
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
    return 0;
}
