# define _CRT_SECURE_NO_WARNINGS 

#include "snake.h"



int main()
{
    initgraph(MAX_WIDTH, MAX_HEIGHT, SHOWCONSOLE);
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        IMAGE image;//����һ��IMAGE����image
        initgraph(MAX_WIDTH, MAX_HEIGHT, SHOWCONSOLE);
            loadimage(&image, "C:\\Users\\����\\Downloads\\̰����.jpeg", MAX_WIDTH, MAX_HEIGHT);
            putimage(0, 0, &image);
             GameInit();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            while (1)
            {
                GameDraw();  //����

                Snakemove(); //���Լ��ƶ�

                KeyControl();  //���̿���

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

    printf("�˳��ɹ�\n");
  
    return 0;
}



