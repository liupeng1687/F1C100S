#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int MAX=1000;
struct Person{
    string m_name;
    int m_sex;
    int m_age;
    string m_Phone;
    string m_Addr;


};
struct Addressbooks{
    struct Person Array[MAX];
    int m_Size;

};
int isExist(Addressbooks * abs,string &name)
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->Array[i].m_name==name)
        {
            return i;
        }
    }
    return -1;
}
void deletePerson(Addressbooks *abs)
{
    cout<<"请输入您要删除的联系人:"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        for(int i=ret;i<abs->m_Size;i++)
        {
            abs->Array[i]=abs->Array[i+1];
        }
        abs->m_Size--;
        cout<<"删除成功"<<endl;

    }
    else{
        cout<<"查无此人"<<endl;

    }
    system("pause");
    system("cls");

    
}
void showMenu()
{
    cout<<"**********************"<<endl;
    cout<<"**** 1.添加联系人  ****"<<endl;
    cout<<"**** 2.显示联系人  ****"<<endl;
    cout<<"**** 3.删除联系人  ****"<<endl;
    cout<<"**** 4.查找联系人  ****"<<endl;
    cout<<"**** 5.修改联系人  ****"<<endl;
    cout<<"**** 6.情空联系人  ****"<<endl;
    cout<<"**** 0.退出通讯录  ****"<<endl;
    cout<<"**********************"<<endl;

    
}
void addPerson(Addressbooks &abs)
{
    if(abs.m_Size==MAX)
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;

    }
    string name;
    cout<<"请输入姓名:"<<endl;
    cin>>name;
    abs.Array[abs.m_Size].m_name=name;
  

    cout<<"请输入性别: "<<endl;
    cout<<"1 --- 男"<<endl;
    cout<<"2 --- 女"<<endl;
    int sex=0;
    while(true)
    {
       cin>>sex;
       if(sex==1||sex==2)
       {
            abs.Array[abs.m_Size].m_sex=sex;
            break;
       }
       else{
            cout<<"输入有误,请重新输入:"<<endl;
       }

    }
    cout<<"请输入年龄:"<<endl;

    int age=0;
    cin>>age;
    abs.Array[abs.m_Size].m_age=age;

    cout<<"请输入联系电话: "<<endl;
    string phone;
    cin>>phone;
    abs.Array[abs.m_Size].m_Phone=phone;
    cout<<"请输入家庭住址: "<<endl;
    string address;
    cin>>address;
    abs.Array[abs.m_Size].m_Addr=address;
    abs.m_Size++;
    cout<<"添加成功"<<endl;

    system("pause");
    system("cls");






    



}
void showPerson(Addressbooks* abs)
{
    if(abs->m_Size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else{
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"姓名: "<<abs->Array[i].m_name<<"\t";
            cout<<"性别: "<<(abs->Array[i].m_sex==1 ? "男":"女")<<"\t";
            cout<<"年龄: "<<abs->Array[i].m_age<<"\t";
            cout<<"电话："<<abs->Array[i].m_Phone<<"\t";
            cout<<"住址: "<<abs->Array[i].m_Addr<<"\t";
            cout<<endl;

        }
    }
    system("pause");
    system("cls");


}
void findPerson(Addressbooks *abs)
{
    cout<<"请输入您要查找的联系人:"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);

    if(ret!=-1)
    {
        cout<<"姓名: "<<abs->Array[ret].m_name<<"\t";
        cout<<"性别: "<<(abs->Array[ret].m_sex==1 ? "男":"女")<<"\t";
        cout<<"年龄: "<<abs->Array[ret].m_age<<"\t";
        cout<<"电话："<<abs->Array[ret].m_Phone<<"\t";
        cout<<"住址: "<<abs->Array[ret].m_Addr<<"\t";
        cout<<endl;

    }
    else{
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");




}
void modifyPerson(Addressbooks * abs)
{
    cout<<"请输入您要修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        string name;
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        abs->Array[ret].m_name=name;
        cout<<"请输入性别:"<<endl;
        cout<<"1 ---男"<<endl;
        cout<<"2 ---女"<<endl;
        int sex=0;
        while (true)
        {
            if(sex==1||sex==2)
        {
            abs->Array[ret].m_sex=sex;
            break;

        }
        else{
            cout<<"输入有误,请重新输入"<<endl;
        }
            
        }
        
        

        
    }
    else{
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;
    cout<<"通讯录已清空"<<endl;
    system("pause");
    system("cls");

}
int main()
{
    
    int select;
    Addressbooks abs;
    abs.m_Size=0;

    
    while (true)
    {
        showMenu();
        cout<<"请输入你的数字选项:"<<endl;
        cin>>select;
        switch(select)
        {
            case 1:
            addPerson(abs);
                break;
            case 2:
            showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
            case 5:
                modifyPerson(&abs);
            case 6:
                cleanPerson(&abs);

            case 0:
            cout<<"欢迎下次使用!"<<endl;
               
                return 0;
                break;
            default:
                break;

        }
        
    }
    

}