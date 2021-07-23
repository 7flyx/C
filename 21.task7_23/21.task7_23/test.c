//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//int main()
//{
//    struct contact con = {0};  //创建通讯录
//
//    Initcon(&con); //初始化通讯录
//
//    int input = 0;
//    printf("请输入你想要操作的命令:\n");
//    do
//    {
//        remind(); //菜单提示
//
//        scanf("%d", &input);
//
//        switch (input)
//        {
//        case Exit:
//            save_con(&con);     //把通讯录保存到文件夹
//            free_con(&con); 	//一定要记得释放动态空间.
//            printf("已经成功退出系统!\n");
//            break;
//        case add:
//            add_con(&con);
//            printf("信息存储完毕!\n等待您的下一步命令:\n");
//            break;
//        case del:
//            del_con(&con);
//            printf("该人信息删除完毕!\n等待您的下一步命令:\n");
//            break;
//        case search:
//            printf("此人信息如下:\n");
//            search_con(&con);
//            printf("查找成功,等待您的下一步命令:\n");
//            break;
//        case modify:
//            modify_con(&con);
//            printf("修改完毕\n等待您的下一步命令:\n");
//            break;
//        case show:
//            printf("所存储人的详细信息如下,请查看:\n");
//            show_con(&con);
//            printf("展示完毕,等待您的下一步命令:\n");
//            break;
//        case sort:
//            sort_con(&con);
//            printf("排序成功\n等待您的下一步命令:\n");
//            break;
//        default:
//            printf("你的命令不在菜单栏中,请重新选择:\n");
//            break;
//        }
//    } while (input);
//
//    return 0;
//}
