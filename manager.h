//
// Created by x1998 on 2023/5/27.
//

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_MANAGER_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_MANAGER_H
#include "iostream"
#include "worker.h"

class Manager: public Worker{
public:
    Manager(int id,std::string name,int dId);
    //��ʾ������Ϣ
    void showInfo();
    //��ȡְ����λ��Ϣ
    std::string getDepName();

};


#endif //EMPLOYEE_MANAGEMENT_SYSTEM_MANAGER_H
