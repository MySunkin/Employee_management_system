//
// Created by x1998 on 2023/5/27.
//

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_BOSS_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_BOSS_H
#include "iostream"
#include "worker.h"


class Boss: public Worker{
public:
    Boss(int id,std::string name,int dId);

    //��ʾ������Ϣ
    void showInfo();
    //��ȡְ����λ����
    std::string getDepName();
};


#endif //EMPLOYEE_MANAGEMENT_SYSTEM_BOSS_H
