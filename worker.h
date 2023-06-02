//
// Created by x1998 on 2023/5/27.
//

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_WORKER_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_WORKER_H

#include "iostream"
#include "string"

class Worker
{
public:
    //显示员工个人信息
    virtual void showInfo()  = 0;
    //获取岗位名称
    virtual std::string getDepName() = 0;

    std::string m_Name;
    int m_Id;
    int m_DeptId;
};
#endif //EMPLOYEE_MANAGEMENT_SYSTEM_WORKER_H
