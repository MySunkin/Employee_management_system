//
// Created by x1998 on 2023/5/27.
//

#include "manager.h"

Manager::Manager(int id,std::string name,int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void Manager::showInfo() {
    std::cout<<"ְ����ţ� "<<this->m_Id<<"\tְ�������� "<<this->m_Name<<"\t��λ�� "<<this->getDepName()<<"\t��λְ�� ����ϰ��·������񣬲��·������Ա��"<<std::endl;
}

std::string Manager::getDepName() {
    return std::string ("����");
}

