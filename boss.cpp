//
// Created by x1998 on 2023/5/27.
//

#include "boss.h"

Boss::Boss(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo() {
    std::cout<<"ְ����ţ� "<<this->m_Id<<"\tְ�������� "<<this->m_Name<<"\t��λ�� "<<this->getDepName()<<"\t��λְ�� ����˾��������"<<std::endl;
}

std::string Boss::getDepName() {
    return std::string ("�ܲ�");
}