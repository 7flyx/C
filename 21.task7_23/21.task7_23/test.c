//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//int main()
//{
//    struct contact con = {0};  //����ͨѶ¼
//
//    Initcon(&con); //��ʼ��ͨѶ¼
//
//    int input = 0;
//    printf("����������Ҫ����������:\n");
//    do
//    {
//        remind(); //�˵���ʾ
//
//        scanf("%d", &input);
//
//        switch (input)
//        {
//        case Exit:
//            save_con(&con);     //��ͨѶ¼���浽�ļ���
//            free_con(&con); 	//һ��Ҫ�ǵ��ͷŶ�̬�ռ�.
//            printf("�Ѿ��ɹ��˳�ϵͳ!\n");
//            break;
//        case add:
//            add_con(&con);
//            printf("��Ϣ�洢���!\n�ȴ�������һ������:\n");
//            break;
//        case del:
//            del_con(&con);
//            printf("������Ϣɾ�����!\n�ȴ�������һ������:\n");
//            break;
//        case search:
//            printf("������Ϣ����:\n");
//            search_con(&con);
//            printf("���ҳɹ�,�ȴ�������һ������:\n");
//            break;
//        case modify:
//            modify_con(&con);
//            printf("�޸����\n�ȴ�������һ������:\n");
//            break;
//        case show:
//            printf("���洢�˵���ϸ��Ϣ����,��鿴:\n");
//            show_con(&con);
//            printf("չʾ���,�ȴ�������һ������:\n");
//            break;
//        case sort:
//            sort_con(&con);
//            printf("����ɹ�\n�ȴ�������һ������:\n");
//            break;
//        default:
//            printf("�������ڲ˵�����,������ѡ��:\n");
//            break;
//        }
//    } while (input);
//
//    return 0;
//}
