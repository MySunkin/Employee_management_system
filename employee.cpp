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
    std::cout<<"ְ����ţ� "<<this->m_Id<<"\tְ�������� "<<this->m_Name<<"\t��λ�� "<<this->getDepName()<<"\t��ɾ�����������"<<std::endl;
}

std::string Employee::getDepName() {
    return std::string("Ա��");
}