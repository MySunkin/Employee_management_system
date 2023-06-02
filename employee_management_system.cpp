#include <iostream>
#include "workerManger.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

//显示页面
void test00()
{
    WorkerManger workerManger;
    int choice = 0;
    while (true) {
        workerManger.showMenu();
        std::cout<<"请输入你的选择"<<std::endl;
        std::cin>>choice;
        switch (choice) {
            case 0://退出系统
                workerManger.exitSystem();
                break;
            case 1://添加职工
                workerManger.addEmp();
                break;
            case 2://显示职工信息
                workerManger.show_Emp();
                break;
            case 3://删除职工信息
            {
                int ret = workerManger.isExist(3);//正常 可以返回
                if(ret!= -1)
                {
                    std::cout<<"职工存在"<<std::endl;
                    std::cout<<"职工的位置为： "<<ret<<std::endl;
                } else
                {
                    std::cout<<"职工不存在"<<std::endl;
                                    }
            }//测试查找    查找没有问题
                workerManger.del_Emp();
                break;
            case 4://修改职工信息
                workerManger.mod_Emp();
                break;
            case 5://查找职工信息
                workerManger.find_Emp();
                break;
            case 6://排序职工信息
                workerManger.sort_emp();
                break;
            case 7://清空文件
            workerManger.cleanFile();
                break;
            default:
                system("cls");
                break;

        }


    }
}

//测试多态
void test01()
{
    Worker *worker = NULL;
    worker = new Employee(1,"张三",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"李四",2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3,"王五",3);
    worker->showInfo();
    delete worker;
}
//输出
//职工编号： 1	职工姓名： 张三	岗位： 员工	完成经理交给的任务
//职工编号： 2	职工姓名： 李四	岗位： 经理	岗位职责： 完成老板下发的任务，并下发任务给员工
//职工编号： 3	职工姓名： 王五	岗位： 总裁	岗位职责： 管理公司所有事务


int main() {
    test00();
    return 0;
}
