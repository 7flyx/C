# define _CRT_SECURE_NO_WARNINGS 

#include "snake.h"



int main()
{
    initgraph(MAX_WIDTH, MAX_HEIGHT, SHOWCONSOLE);
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        IMAGE image;//定义一个IMAGE叫做image
        initgraph(MAX_WIDTH, MAX_HEIGHT, SHOWCONSOLE);
            loadimage(&image, "C:\\Users\\听风\\Downloads\\贪吃蛇.jpeg", MAX_WIDTH, MAX_HEIGHT);
            putimage(0, 0, &image);
             GameInit();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            while (1)
            {
                GameDraw();  //画蛇

                Snakemove(); //蛇自己移动

                KeyControl();  //键盘控制

                EatFood();

                int ret = Is_win();
                if (ret == 0)
                    break;

            }
        case 0:
            break;
        default:
            break;
        }
        
        getchar();
        closegraph();
    } while (input);

    printf("退出成功\n");
  
    return 0;
}



