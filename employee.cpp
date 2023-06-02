//
// Created by x1998 on 2023/5/27.
//
#include "employee.h"

Employee::Employee(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo() {
    std::cout<<"职工编号： "<<this->m_Id<<"\t职工姓名： "<<this->m_Name<<"\t岗位： "<<this->getDepName()<<"\t完成经理交给的任务"<<std::endl;
}

std::string Employee::getDepName() {
    return std::string("员工");
}