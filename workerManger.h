//
// Created by x1998 on 2023/5/27.
//
//�����ฺ����������£�
//
//���û��Ĺ�ͨ�˵�����
//��ְ����ɾ�Ĳ�Ĳ���
//���ļ��Ķ�д����

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H

#include "iostream"
#include "worker.h"
#include "fstream"
#define FILENAME "empFile.txt"



class WorkerManger {
public:
    WorkerManger();//���캯��

    ~WorkerManger();//��������

    void exitSystem();//�˳�����

    void showMenu();//��ʾ�˵�

    //��¼�ļ��е���������
    int m_EmpNum;


    //ְ������ָ��
    Worker **m_EmpArray;

    //���ְ��
    void addEmp();

    //��ְ����Ϣ���浽�ļ�
    void save();

    //��־�ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty = false;

    //ͳ������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void show_Emp();

    //�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
    int isExist(int id);

    //ɾ��ְ��
    void del_Emp();

    //�޸�ְ��
    void mod_Emp();

    //����Ա��
    void find_Emp();

    //����Ա��
    void sort_emp();

    //����ļ�
    void cleanFile();
};



#endif //EMPLOYEE_MANAGEMENT_SYSTEM_WORKERMANGER_H
