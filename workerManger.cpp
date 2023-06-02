//
// Created by x1998 on 2023/5/27.
//
#include "workerManger.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"




WorkerManger::WorkerManger() {

    //1. �ļ�������
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);//���ļ�

    if (!ifs.is_open())
    {
        std::cout<<"�ļ�������"<<std::endl;
        //��ʼ������

        //��ʼ����¼����
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;

        //��ʼ���ļ��Ƿ�Ϊ��
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //2.�ļ����� û�м�¼
    char ch;
    ifs>>ch;//�����ļ��ж�ȡһ���ַ�������洢�ڱ��� ch ��
    if(ifs.eof())
    {
        std::cout<<"�ļ�Ϊ��"<<std::endl;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //�ļ����� ���Ҽ�¼����
    int num = this->get_EmpNum();
    std::cout<<"ְ������Ϊ�� "<<num<<std::endl;
    this->m_EmpNum = num;//���³�Ա����


    //���ٿռ�
    this->m_EmpArray = new Worker *[this->m_EmpNum];
//    ���ļ��е����ݣ��浽������
    init_Emp();

    //���Դ��� ���ڸմ򿪳���ʱ��ӡ�Ѿ��洢���ļ���Ϣ----------------------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < this->m_EmpNum; i++) {
        std::cout<<"ְ�����"<<this->m_EmpArray[i]->m_Id
        <<" ������ "<<this->m_EmpArray[i]->m_Name
        <<" ���ű�ţ� "<<this->m_EmpArray[i]->m_DeptId<<std::endl;
    }
    //���Դ��� ���ڸմ򿪳���ʱ��ӡ�Ѿ��洢���ļ���Ϣ----------------------------------------------------------------------------------------------------------------------------------






//    //��ʼ������
//    this->m_EmpNum = 0;
//
////    ��ʼ������ָ��
//    this->m_EmpArray =NULL;
}

void WorkerManger::addEmp() {
    std::cout<<"���������ְ�������� "<<std::endl;
    int addNum = 0;//�����û�����������

    std::cin>>addNum;
    if (addNum>0)
    {
        //���
        int newSize = this->m_EmpNum+addNum;//�¿ռ� = ԭ����¼������+��������

        //�����¿ռ�
         Worker ** newSpace = new Worker *[newSize];

        //��ԭ�ռ��µ����ݷŵ��¿ռ���
        if(this->m_EmpArray !=NULL)
        {
            for (int i = 0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //����������
        for(int i = 0;i<addNum;i++)
        {
            int id;
            std::string name;
            int dSelect;

            std::cout<<"������� "<<i+1<<"����ְ�����"<<std::endl;
            std::cin>>id;

            std::cout<<"������� "<<i+1<<"����ְ������"<<std::endl;
            std::cin>>name;

            std::cout<<"��ѡ���Ա���ĸ�λ"<<std::endl;
            std::cout<<"1.��ͨԱ��"<<std::endl;
            std::cout<<"2.����"<<std::endl;
            std::cout<<"3.�ϰ�"<<std::endl;
            std::cin>>dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1://��ͨԱ��
                    worker = new Employee(id,name,1);
                    break;
                case 2://����
                    worker = new Manager(id,name,2);
                    break;
                case 3://�ϰ�
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
                newSpace[this->m_EmpNum+i] = worker;
        }

        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;


        //�����¿ռ��ָ��

        this->m_EmpArray = newSpace;

        //�����µĸ���
        this->m_EmpNum = newSize;

        //����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;

        //��ʾ��Ϣ
        std::cout<<"�ɹ����"<<addNum<<"����Ա��"<<std::endl;

        //���浽�ļ�
        this->save();
    }

    else
    {
        std::cout<<"��������"<<std::endl;
    }
    system("pause");
    system("cls");

}
WorkerManger::~WorkerManger() {
    if (this->m_EmpArray !=NULL)
    {
        delete[] this->m_EmpArray;
    }
}

void WorkerManger::save() {
    std::ofstream ofs;
    ofs.open(FILENAME,std::ios::out);

    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs<<this->m_EmpArray[i]->m_Id<<" "<<this->m_EmpArray[i]->m_Name<<" "<<this->m_EmpArray[i]->m_DeptId<<std::endl;
    }
    ofs.close();
}

int WorkerManger::get_EmpNum()
{
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);
    int id;
    std::string name;
    int dId;

    int num = 0;
    while(ifs>>id&&ifs>>name&&ifs>>dId)
    {
        //��¼����
        num++;
    }
    ifs.close();
    return num;
}

void WorkerManger::init_Emp() {
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);

    int id;
    std::string name;
    int dId;

    int index = 0;
    while (ifs>>id &&ifs>>name&&ifs>>dId)
    {
        Worker *worker = NULL;
        //���ݲ�ͬ�Ĳ���Id
        if(dId ==1)
        {
            worker = new Employee(id,name,dId);
        }
        else if(dId ==2)
        {
            worker = new Manager(id,name,dId);
        }
        else//�ܲ�
        {
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index++;

    }
}

void WorkerManger::showMenu() {
    std::cout << "********************************************" << std::endl;
    std::cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << std::endl;
    std::cout << "*************  0.�˳��������  *************" << std::endl;
    std::cout << "*************  1.����ְ����Ϣ  *************" << std::endl;
    std::cout << "*************  2.��ʾְ����Ϣ  *************" << std::endl;
    std::cout << "*************  3.ɾ����ְְ��  *************" << std::endl;
    std::cout << "*************  4.�޸�ְ����Ϣ  *************" << std::endl;
    std::cout << "*************  5.����ְ����Ϣ  *************" << std::endl;
    std::cout << "*************  6.���ձ������  *************" << std::endl;
    std::cout << "*************  7.��������ĵ�  *************" << std::endl;
}

void WorkerManger::exitSystem(){
    std::cout<<"��ӭ�´�ʹ��"<<std::endl;
    system("pause");
    exit(0);
}

//��ʾְ��
void WorkerManger::show_Emp(){
    //�ж��ļ��Ƿ�Ϊ��
    if(this->m_FileIsEmpty)
    {
        std::cout<<"�ļ������ڻ��¼Ϊ��"<<std::endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++) {
            //���ö�̬���ýӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManger::isExist(int id) {
    int index = -1;//-1���ǲ�����
    for (int i = 0; i < this->m_EmpNum; i++) {
        if(this->m_EmpArray[i]->m_Id ==id)
        {

            index = i;
            break;
        }
    }
    return index;
}


void WorkerManger::del_Emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"�ļ������ڻ��¼Ϊ��"<<std::endl;
    }
    else
    {
        //��ְ�����ɾ��
        std::cout<<"��������Ҫɾ����ְ����"<<std::endl;
        int id = 0;
        std::cin>>id;
        int index = this->isExist(id);
        if(index!=-1)
        {
            for (int i = index; i < this->m_EmpNum-1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
             }
            this->m_EmpNum--;
            this->save();
            std::cout<<"ɾ���ɹ�"<<std::endl;
        }

        else
        {
            std::cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<std::endl;
        }
        system("pause");
        system("cls");

    }
}

void WorkerManger::mod_Emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"�ļ������ڻ��¼Ϊ�գ�"<<std::endl;
    }
    else
    {
        std::cout<<"�������޸�ְ���ı�ţ� "<<std::endl;
        int id;
        std::cin>>id;

        int ret = this->isExist(id);
        if(ret!=-1)
        {
            //�鵽�ñ�ŵ�ְ������
            delete this->m_EmpArray[ret];

            int newId = 0;
            std::string newName = " ";
            int dSlect = 0;

            std::cout<<"�鵽�� "<<id<<"��Ա������������ְ���ţ� "<<std::endl;
            std::cin>>newId;
            std::cout<<"�������������� "<<std::endl;
            std::cin>>newName;

            std::cout<<"�������λ�� "<<std::endl;
            std::cout<<"1. ��ְͨ��"<<std::endl;
            std::cout<<"2. ����"<<std::endl;
            std::cout<<"3. �ϰ�"<<std::endl;

            std::cin>>dSlect;

            Worker *worker = NULL;
            switch (dSlect) {
                case 1:
                    worker = new Employee(newId,newName,dSlect);
                case 2:
                    worker = new Manager(newId,newName,dSlect);
                case 3:
                    worker = new Boss(newId,newName,dSlect);
                default:
                    break;
            }
            //�������� ������
            this->m_EmpArray[ret] = worker;
            std::cout<<"�޸ĳɹ�"<<std::endl;
            //���浽�ļ�
            this->save();
        }
        else
        {
            std::cout<<"���޴���"<<std::endl;
        }
    }
    //�����������
    system("pause");
    system("cls");
}

void WorkerManger::find_Emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"�ļ������ڻ��¼Ϊ��"<<std::endl;
    }
    else
    {
        std::cout<<"��������ҵķ�ʽ�� "<<std::endl;
        std::cout<<"1. ��ְ����Ž��в���"<<std::endl;
        std::cout<<"2. ���������в���"<<std::endl;

        int select = 0;
        std::cin>>select;
        if(select ==1)//��ְ����Ž��в���
        {
            int id;
            std::cout<<"��������ҵ�ְ����ţ� "<<std::endl;
            std::cin>>id;

            int ret = isExist(id);
            if(ret!=-1)
            {
                std::cout<<"���ҳɹ�����ְ����Ϣ���£� "<<std::endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                std::cout<<"����ʧ�ܣ����޴���"<< std::endl;
            }
        }
        else if (select==2)
        {
            std::string name;
            std::cout<<"��������ҵ������� "<<std::endl;
            std::cin>>name;

            bool flag = false;//���ҵı�־
            for (int i = 0; i < m_EmpNum; i++)
            {
                if(m_EmpArray[i]->m_Name==name)
                {
                    std::cout<<"���ҳɹ���ְ�����Ϊ�� "<<m_EmpArray[i]->m_Id<<" �ŵ���Ϣ���£� "<<std::endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }if(flag== false)
            {
                //���޴���
                std::cout<<"���޴���"<<std::endl;
            }
        }else
        {
            std::cout<<"��������"<<std::endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManger::sort_emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"�ļ������ڻ��ļ���¼Ϊ��"<<std::endl;
        system("pause");
        system("cls");
    }

    else
    {
        std::cout<<"��ѡ������ʽ�� "<<std::endl;
        std::cout<<"1. ����ְ����Ž�������"<<std::endl;
        std::cout<<"2. ����ְ����Ž��н���"<<std::endl;

        int select = 0;
        std::cin>>select;


        for (int i = 0; i < m_EmpNum; i++) {
            int minOrMax = i;
            for (int j = i+1; j <m_EmpNum; j++) {
                if(select==1)//����
                {
                    if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else //����
                {
                    if(m_EmpArray[minOrMax]->m_Id<m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if(i!=minOrMax)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i]  =m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        std::cout<<"����ɹ����������Ϊ�� "<<std::endl;
        this->save();
        this->show_Emp();
    }
}

void WorkerManger::cleanFile()
{
    std::cout<<"ȷ�����"<<std::endl;
    std::cout<<"1. ȷ��"<<std::endl;
    std::cout<<"2. ����"<<std::endl;

    int select = 0;
    std::cin>>select;

    if(select ==1)
    {
        //��ģʽios::trunc �������ɾ���ļ������´���
        std::ofstream ofs(FILENAME,std::ios::trunc);
        ofs.close();

//        if (this->m_EmpArray !=NULL)
//        {
//            //ɾ��������ÿ��ְ������
//            for (int i = 0; i < this->m_EmpNum; i++)
//            {
//                if (this->m_EmpArray[i] !=NULL)
//                {
//                    delete this->m_EmpArray[i];
//                }
//                //ɾ����������ָ��
//            }
//            this->m_EmpNum = 0;
//            delete[]this->m_EmpArray;
//            this->m_EmpArray = NULL;
//            this->m_FileIsEmpty = true;
//        }
        std::cout<<"��ճɹ���"<<std::endl;
    }
    system("pause");
    system("cls");
}