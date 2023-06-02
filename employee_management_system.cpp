#include <iostream>
#include "workerManger.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

//��ʾҳ��
void test00()
{
    WorkerManger workerManger;
    int choice = 0;
    while (true) {
        workerManger.showMenu();
        std::cout<<"���������ѡ��"<<std::endl;
        std::cin>>choice;
        switch (choice) {
            case 0://�˳�ϵͳ
                workerManger.exitSystem();
                break;
            case 1://���ְ��
                workerManger.addEmp();
                break;
            case 2://��ʾְ����Ϣ
                workerManger.show_Emp();
                break;
            case 3://ɾ��ְ����Ϣ
            {
                int ret = workerManger.isExist(3);//���� ���Է���
                if(ret!= -1)
                {
                    std::cout<<"ְ������"<<std::endl;
                    std::cout<<"ְ����λ��Ϊ�� "<<ret<<std::endl;
                } else
                {
                    std::cout<<"ְ��������"<<std::endl;
                                    }
            }//���Բ���    ����û������
                workerManger.del_Emp();
                break;
            case 4://�޸�ְ����Ϣ
                workerManger.mod_Emp();
                break;
            case 5://����ְ����Ϣ
                workerManger.find_Emp();
                break;
            case 6://����ְ����Ϣ
                workerManger.sort_emp();
                break;
            case 7://����ļ�
            workerManger.cleanFile();
                break;
            default:
                system("cls");
                break;

        }


    }
}

//���Զ�̬
void test01()
{
    Worker *worker = NULL;
    worker = new Employee(1,"����",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"����",2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3,"����",3);
    worker->showInfo();
    delete worker;
}
//���
//ְ����ţ� 1	ְ�������� ����	��λ�� Ա��	��ɾ�����������
//ְ����ţ� 2	ְ�������� ����	��λ�� ����	��λְ�� ����ϰ��·������񣬲��·������Ա��
//ְ����ţ� 3	ְ�������� ����	��λ�� �ܲ�	��λְ�� ����˾��������


int main() {
    test00();
    return 0;
}
