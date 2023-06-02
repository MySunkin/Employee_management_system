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
    std::cout<<"职工编号： "<<this->m_Id<<"\t职工姓名： "<<this->m_Name<<"\t岗位： "<<this->getDepName()<<"\t岗位职责： 完成老板下发的任务，并下发任务给员工"<<std::endl;
}

std::string Manager::getDepName() {
    return std::string ("经理");
}

