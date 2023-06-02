//
// Created by x1998 on 2023/5/27.
//

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_EMPLOYEE_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_EMPLOYEE_H
#include "iostream"
#include "worker.h"//虚基类
#include "string"

class Employee :public Worker{
public:
    //构造函数
    Employee(int id,std::string name,int dId);
    //显示个人信息
    void showInfo();
    //获取职工岗位名称
    std::string getDepName();
};

#endif //EMPLOYEE_MANAGEMENT_SYSTEM_EMPLOYEE_H
