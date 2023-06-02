//
// Created by x1998 on 2023/5/27.
//
#include "workerManger.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"




WorkerManger::WorkerManger() {

    //1. 文件不存在
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);//读文件

    if (!ifs.is_open())
    {
        std::cout<<"文件不存在"<<std::endl;
        //初始化属性

        //初始化记录人数
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;

        //初始化文件是否为空
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //2.文件存在 没有记录
    char ch;
    ifs>>ch;//语句从文件中读取一个字符并将其存储在变量 ch 中
    if(ifs.eof())
    {
        std::cout<<"文件为空"<<std::endl;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件存在 并且记录数据
    int num = this->get_EmpNum();
    std::cout<<"职工个数为： "<<num<<std::endl;
    this->m_EmpNum = num;//更新成员属性


    //开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
//    将文件中的数据，存到数组中
    init_Emp();

    //测试代码 用于刚打开程序时打印已经存储的文件信息----------------------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < this->m_EmpNum; i++) {
        std::cout<<"职工编号"<<this->m_EmpArray[i]->m_Id
        <<" 姓名： "<<this->m_EmpArray[i]->m_Name
        <<" 部门编号： "<<this->m_EmpArray[i]->m_DeptId<<std::endl;
    }
    //测试代码 用于刚打开程序时打印已经存储的文件信息----------------------------------------------------------------------------------------------------------------------------------






//    //初始化人数
//    this->m_EmpNum = 0;
//
////    初始化数组指针
//    this->m_EmpArray =NULL;
}

void WorkerManger::addEmp() {
    std::cout<<"请输入添加职工数量： "<<std::endl;
    int addNum = 0;//保存用户的输入数量

    std::cin>>addNum;
    if (addNum>0)
    {
        //添加
        int newSize = this->m_EmpNum+addNum;//新空间 = 原来记录的人数+新增人数

        //开辟新空间
         Worker ** newSpace = new Worker *[newSize];

        //将原空间下的内容放到新空间下
        if(this->m_EmpArray !=NULL)
        {
            for (int i = 0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //输入新数据
        for(int i = 0;i<addNum;i++)
        {
            int id;
            std::string name;
            int dSelect;

            std::cout<<"请输入第 "<<i+1<<"个新职工编号"<<std::endl;
            std::cin>>id;

            std::cout<<"请输入第 "<<i+1<<"个新职工姓名"<<std::endl;
            std::cin>>name;

            std::cout<<"请选择该员工的岗位"<<std::endl;
            std::cout<<"1.普通员工"<<std::endl;
            std::cout<<"2.经理"<<std::endl;
            std::cout<<"3.老板"<<std::endl;
            std::cin>>dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1://普通员工
                    worker = new Employee(id,name,1);
                    break;
                case 2://经理
                    worker = new Manager(id,name,2);
                    break;
                case 3://老板
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
                newSpace[this->m_EmpNum+i] = worker;
        }

        //释放原有空间
        delete[] this->m_EmpArray;


        //更改新空间的指向

        this->m_EmpArray = newSpace;

        //更新新的个数
        this->m_EmpNum = newSize;

        //更新职工不为空标志
        this->m_FileIsEmpty = false;

        //提示信息
        std::cout<<"成功添加"<<addNum<<"名新员工"<<std::endl;

        //保存到文件
        this->save();
    }

    else
    {
        std::cout<<"输入有误"<<std::endl;
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
        //记录人数
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
        //根据不同的部分Id
        if(dId ==1)
        {
            worker = new Employee(id,name,dId);
        }
        else if(dId ==2)
        {
            worker = new Manager(id,name,dId);
        }
        else//总裁
        {
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index++;

    }
}

void WorkerManger::showMenu() {
    std::cout << "********************************************" << std::endl;
    std::cout << "*********  欢迎使用职工管理系统！ **********" << std::endl;
    std::cout << "*************  0.退出管理程序  *************" << std::endl;
    std::cout << "*************  1.增加职工信息  *************" << std::endl;
    std::cout << "*************  2.显示职工信息  *************" << std::endl;
    std::cout << "*************  3.删除离职职工  *************" << std::endl;
    std::cout << "*************  4.修改职工信息  *************" << std::endl;
    std::cout << "*************  5.查找职工信息  *************" << std::endl;
    std::cout << "*************  6.按照编号排序  *************" << std::endl;
    std::cout << "*************  7.清空所有文档  *************" << std::endl;
}

void WorkerManger::exitSystem(){
    std::cout<<"欢迎下次使用"<<std::endl;
    system("pause");
    exit(0);
}

//显示职工
void WorkerManger::show_Emp(){
    //判断文件是否为空
    if(this->m_FileIsEmpty)
    {
        std::cout<<"文件不存在或记录为空"<<std::endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++) {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//判断职工是否存在
int WorkerManger::isExist(int id) {
    int index = -1;//-1就是不存在
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
        std::cout<<"文件不存在或记录为空"<<std::endl;
    }
    else
    {
        //按职工编号删除
        std::cout<<"请输入想要删除的职工号"<<std::endl;
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
            std::cout<<"删除成功"<<std::endl;
        }

        else
        {
            std::cout<<"删除失败，未找到该职工"<<std::endl;
        }
        system("pause");
        system("cls");

    }
}

void WorkerManger::mod_Emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"文件不存在或记录为空！"<<std::endl;
    }
    else
    {
        std::cout<<"请输入修改职工的编号： "<<std::endl;
        int id;
        std::cin>>id;

        int ret = this->isExist(id);
        if(ret!=-1)
        {
            //查到该编号的职工存在
            delete this->m_EmpArray[ret];

            int newId = 0;
            std::string newName = " ";
            int dSlect = 0;

            std::cout<<"查到： "<<id<<"号员工，请输入新职工号： "<<std::endl;
            std::cin>>newId;
            std::cout<<"请输入新姓名： "<<std::endl;
            std::cin>>newName;

            std::cout<<"请输入岗位： "<<std::endl;
            std::cout<<"1. 普通职工"<<std::endl;
            std::cout<<"2. 经理"<<std::endl;
            std::cout<<"3. 老板"<<std::endl;

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
            //更新数据 到组中
            this->m_EmpArray[ret] = worker;
            std::cout<<"修改成功"<<std::endl;
            //保存到文件
            this->save();
        }
        else
        {
            std::cout<<"查无此人"<<std::endl;
        }
    }
    //按任意键清屏
    system("pause");
    system("cls");
}

void WorkerManger::find_Emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"文件不存在或记录为空"<<std::endl;
    }
    else
    {
        std::cout<<"请输入查找的方式： "<<std::endl;
        std::cout<<"1. 按职工编号进行查找"<<std::endl;
        std::cout<<"2. 按姓名进行查找"<<std::endl;

        int select = 0;
        std::cin>>select;
        if(select ==1)//按职工编号进行查找
        {
            int id;
            std::cout<<"请输入查找的职工编号： "<<std::endl;
            std::cin>>id;

            int ret = isExist(id);
            if(ret!=-1)
            {
                std::cout<<"查找成功，该职工信息如下： "<<std::endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                std::cout<<"查找失败，查无此人"<< std::endl;
            }
        }
        else if (select==2)
        {
            std::string name;
            std::cout<<"请输入查找到姓名： "<<std::endl;
            std::cin>>name;

            bool flag = false;//查找的标志
            for (int i = 0; i < m_EmpNum; i++)
            {
                if(m_EmpArray[i]->m_Name==name)
                {
                    std::cout<<"查找成功，职工编号为： "<<m_EmpArray[i]->m_Id<<" 号的信息如下： "<<std::endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }if(flag== false)
            {
                //查无此人
                std::cout<<"查无此人"<<std::endl;
            }
        }else
        {
            std::cout<<"输入有误"<<std::endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManger::sort_emp() {
    if(this->m_FileIsEmpty)
    {
        std::cout<<"文件不存在或文件记录为空"<<std::endl;
        system("pause");
        system("cls");
    }

    else
    {
        std::cout<<"请选择排序方式： "<<std::endl;
        std::cout<<"1. 按照职工编号进行升序"<<std::endl;
        std::cout<<"2. 按照职工编号进行降序"<<std::endl;

        int select = 0;
        std::cin>>select;


        for (int i = 0; i < m_EmpNum; i++) {
            int minOrMax = i;
            for (int j = i+1; j <m_EmpNum; j++) {
                if(select==1)//升序
                {
                    if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else //降序
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
        std::cout<<"排序成功，排序后结果为： "<<std::endl;
        this->save();
        this->show_Emp();
    }
}

void WorkerManger::cleanFile()
{
    std::cout<<"确认清空"<<std::endl;
    std::cout<<"1. 确认"<<std::endl;
    std::cout<<"2. 返回"<<std::endl;

    int select = 0;
    std::cin>>select;

    if(select ==1)
    {
        //打开模式ios::trunc 如果存在删除文件并重新创建
        std::ofstream ofs(FILENAME,std::ios::trunc);
        ofs.close();

//        if (this->m_EmpArray !=NULL)
//        {
//            //删除堆区的每个职工对象
//            for (int i = 0; i < this->m_EmpNum; i++)
//            {
//                if (this->m_EmpArray[i] !=NULL)
//                {
//                    delete this->m_EmpArray[i];
//                }
//                //删除堆区数组指针
//            }
//            this->m_EmpNum = 0;
//            delete[]this->m_EmpArray;
//            this->m_EmpArray = NULL;
//            this->m_FileIsEmpty = true;
//        }
        std::cout<<"清空成功！"<<std::endl;
    }
    system("pause");
    system("cls");
}