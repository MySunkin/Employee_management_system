//
// Created by x1998 on 2023/5/27.
//
//管理类负责的内容如下：
//
//与用户的沟通菜单界面
//对职工增删改查的操作
//与文件的读写交互

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H

#include "iostream"
#include "worker.h"
#include "fstream"
#define FILENAME "empFile.txt"



class WorkerManger {
public:
    WorkerManger();//构造函数

    ~WorkerManger();//析构函数

    void exitSystem();//退出函数

    void showMenu();//显示菜单

    //记录文件中的人数个数
    int m_EmpNum;


    //职工数组指针
    Worker **m_EmpArray;

    //添加职工
    void addEmp();

    //将职工信息保存到文件
    void save();

    //标志文件是否为空
    bool m_FileIsEmpty = false;

    //统计人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void show_Emp();

    //判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
    int isExist(int id);

    //删除职工
    void del_Emp();

    //修改职工
    void mod_Emp();

    //查找员工
    void find_Emp();

    //排序员工
    void sort_emp();

    //清空文件
    void cleanFile();
};



#endif //EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H
