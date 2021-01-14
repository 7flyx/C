// snake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "snake.h"

struct Snake_tlg snake;
struct Food_tlg food;
int speedup = 0;

void GameInit()
{
    //蛇的初始化--  蛇一开始是从左上角出发的
    snake.num = 10; //蛇身原始的长度
    snake.score = 0; //分数
    snake.dir = RIGHT;  //方向
    snake.size = 10;  //蛇身的长度和宽度，就是一个格子长宽

    //下面的初始化，就是使蛇身的格子，对于整个图形来说的坐标
    snake.coor[2].x = 0;
    snake.coor[2].y = 0;
    snake.coor[1].x = snake.size;
    snake.coor[1].y = 0;
    snake.coor[0].x = 2 * snake.size;
    snake.coor[0].y = 0;


    //食物的初始化
    food.color = RGB(rand() % 256, rand() % 256, rand() % 256);  //颜色的范围在0-255之间
    food.flag = 1;
    food.xy.x = rand() % (MAX_WIDTH / 10) * 10;  //先除以10 ，得到64，即就是随机值在0-63之间，再乘10即可
    food.xy.y = rand() % (MAX_HEIGHT / 10) * 10;  //不然直接模出来的数，不一定是10的整数倍
}


void GameDraw()
{
    //1. 设置背景颜色
    setbkcolor(RGB(105, 160, 141));
    cleardevice();//用背景色清空整个屏幕(整个画布)
 

    //2. 画蛇
  
    int i = 0;
    for (i = 0; i < snake.num; i++)
    {  
        setlinecolor(BLACK);
        setfillcolor(YELLOW);  //蛇身的颜色
        fillrectangle(snake.coor[i].x, snake.coor[i].y,
            snake.coor[i].x + snake.size, snake.coor[i].y + snake.size);
        //这个函数是图形库里面的，前面两个参数是左上角的横纵坐标，后面是右下角的坐标
        printf("%d %d\n", snake.coor[i].x, snake.coor[i].y );
    }

    //3. 画食物
    setfillcolor(food.color);
    solidellipse(food.xy.x, food.xy.y, food.xy.x + 10, food.xy.y + 10);

}


void Snakemove()
{
    int i = 0;
    for (i = snake.num - 1; i > 0; i--) //蛇自己移动
    {
        snake.coor[i].x = snake.coor[i - 1].x;
        snake.coor[i].y = snake.coor[i - 1].y;
        if (speedup == 0)  //控制速度
            Sleep(50);
        else
            Sleep(10);
    }
    switch (snake.dir)
    {
    case UP:
        //每次循环进来，先进行判断蛇头的坐标，是否已经超出了窗口的范围，然后再进行坐标的运算
        if (snake.coor[0].y == 0)
            snake.coor[0].y = MAX_HEIGHT;
        snake.coor[0].y -= 10;  //图形函数规定了的，纵坐标向上为减，与数学里面的相反的
            break;
    case DOWN:
        //每次循环进来，先进行判断蛇头的坐标，是否已经超出了窗口的范围，然后再进行坐标的运算
        if (snake.coor[0].y == MAX_HEIGHT)
            snake.coor[0].y = 0;
        snake.coor[0].y += 10;
        break;
    case LEFT:
        //每次循环进来，先进行判断蛇头的坐标，是否已经超出了窗口的范围，然后再进行坐标的运算
        if (snake.coor[0].x == 0)
            snake.coor[0].x = MAX_WIDTH;
        snake.coor[0].x -= 10;
        break;
    case RIGHT:
        //每次循环进来，先进行判断蛇头的坐标，是否已经超出了窗口的范围，然后再进行坐标的运算
        if (snake.coor[0].x == MAX_WIDTH)
            snake.coor[0].x = 0;
        snake.coor[0].x += 10;
        break;
    default :
        break;
    }
}


void KeyControl()
{
    //使用win32API获取键盘信息
    //这里的逻辑与，作用于，例如正在向下走，不能直接调头向上走
    if (GetAsyncKeyState(VK_UP) && snake.dir != DOWN)  //也可以用（'w'）或('s')等等
    {
        snake.dir = UP;
    }
    if (GetAsyncKeyState(VK_DOWN) && snake.dir != UP)
    {
        snake.dir = DOWN;
    }if (GetAsyncKeyState(VK_LEFT) && snake.dir != RIGHT)
    {
        snake.dir = LEFT;
    }if (GetAsyncKeyState(VK_RIGHT) && snake.dir != LEFT)
    {
        snake.dir = RIGHT;
    }
    if (GetAsyncKeyState(' '))  //加速
        speedup = 1;
    else
        speedup = 0;
}


void EatFood()
{
    if (snake.coor[0].x == food.xy.x && snake.coor[0].y == food.xy.y)
    {
        //坐标相等后，吃掉食物,蛇身加长
        snake.num++;
       // food.flag = 0; //为下一次食物生成做准备
          //再次产生食物
        food.color = RGB(rand() % 256, rand() % 256, rand() % 256);  //颜色的范围在0-255之间
        food.flag = 1;
        food.xy.x = rand() % (MAX_WIDTH / 10) * 10;  //先除以10 ，得到64，即就是随机值在0-63之间，再乘10即可
        food.xy.y = rand() % (MAX_HEIGHT / 10) * 10;  //不然直接模出来的数，不一定是10的整数倍
    }
  
}



int Is_win() //判断生死
{
    //如果咬到自身，游戏结束
    int i = 0;
    for (i = 1; i < snake.num; i++)
    {
        if (snake.coor[i].x == snake.coor[0].x && snake.coor[i].y == snake.coor[0].y)
        {
            //输出文本

            initgraph(MAX_WIDTH, MAX_HEIGHT, SHOWCONSOLE);
            settextcolor(RGB(255, 255, 0));   //设置字体颜色   
            settextstyle(30, 0, "微软雅黑");  //设置字体样式: 字体高度为100像素, 宽度不指定, 字体名称为"微软雅黑"
            outtextxy(200, 190, "你真笨，咬到自己啦\n"); //在指定位置输出文本
            Sleep(2000);
            return 0;  //游戏结束
        }
    }
    return 1;  //游戏继续
}