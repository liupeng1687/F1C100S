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
    cout<<"��������Ҫɾ������ϵ��:"<<endl;
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
        cout<<"ɾ���ɹ�"<<endl;

    }
    else{
        cout<<"���޴���"<<endl;

    }
    system("pause");
    system("cls");

    
}
void showMenu()
{
    cout<<"**********************"<<endl;
    cout<<"**** 1.�����ϵ��  ****"<<endl;
    cout<<"**** 2.��ʾ��ϵ��  ****"<<endl;
    cout<<"**** 3.ɾ����ϵ��  ****"<<endl;
    cout<<"**** 4.������ϵ��  ****"<<endl;
    cout<<"**** 5.�޸���ϵ��  ****"<<endl;
    cout<<"**** 6.�����ϵ��  ****"<<endl;
    cout<<"**** 0.�˳�ͨѶ¼  ****"<<endl;
    cout<<"**********************"<<endl;

    
}
void addPerson(Addressbooks &abs)
{
    if(abs.m_Size==MAX)
    {
        cout<<"ͨѶ¼�������޷����"<<endl;
        return;

    }
    string name;
    cout<<"����������:"<<endl;
    cin>>name;
    abs.Array[abs.m_Size].m_name=name;
  

    cout<<"�������Ա�: "<<endl;
    cout<<"1 --- ��"<<endl;
    cout<<"2 --- Ů"<<endl;
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
            cout<<"��������,����������:"<<endl;
       }

    }
    cout<<"����������:"<<endl;

    int age=0;
    cin>>age;
    abs.Array[abs.m_Size].m_age=age;

    cout<<"��������ϵ�绰: "<<endl;
    string phone;
    cin>>phone;
    abs.Array[abs.m_Size].m_Phone=phone;
    cout<<"�������ͥסַ: "<<endl;
    string address;
    cin>>address;
    abs.Array[abs.m_Size].m_Addr=address;
    abs.m_Size++;
    cout<<"��ӳɹ�"<<endl;

    system("pause");
    system("cls");






    



}
void showPerson(Addressbooks* abs)
{
    if(abs->m_Size==0)
    {
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }
    else{
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"����: "<<abs->Array[i].m_name<<"\t";
            cout<<"�Ա�: "<<(abs->Array[i].m_sex==1 ? "��":"Ů")<<"\t";
            cout<<"����: "<<abs->Array[i].m_age<<"\t";
            cout<<"�绰��"<<abs->Array[i].m_Phone<<"\t";
            cout<<"סַ: "<<abs->Array[i].m_Addr<<"\t";
            cout<<endl;

        }
    }
    system("pause");
    system("cls");


}
void findPerson(Addressbooks *abs)
{
    cout<<"��������Ҫ���ҵ���ϵ��:"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);

    if(ret!=-1)
    {
        cout<<"����: "<<abs->Array[ret].m_name<<"\t";
        cout<<"�Ա�: "<<(abs->Array[ret].m_sex==1 ? "��":"Ů")<<"\t";
        cout<<"����: "<<abs->Array[ret].m_age<<"\t";
        cout<<"�绰��"<<abs->Array[ret].m_Phone<<"\t";
        cout<<"סַ: "<<abs->Array[ret].m_Addr<<"\t";
        cout<<endl;

    }
    else{
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");




}
void modifyPerson(Addressbooks * abs)
{
    cout<<"��������Ҫ�޸ĵ���ϵ��"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        string name;
        cout<<"����������:"<<endl;
        cin>>name;
        abs->Array[ret].m_name=name;
        cout<<"�������Ա�:"<<endl;
        cout<<"1 ---��"<<endl;
        cout<<"2 ---Ů"<<endl;
        int sex=0;
        while (true)
        {
            if(sex==1||sex==2)
        {
            abs->Array[ret].m_sex=sex;
            break;

        }
        else{
            cout<<"��������,����������"<<endl;
        }
            
        }
        
        

        
    }
    else{
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;
    cout<<"ͨѶ¼�����"<<endl;
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
        cout<<"�������������ѡ��:"<<endl;
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
            cout<<"��ӭ�´�ʹ��!"<<endl;
               
                return 0;
                break;
            default:
                break;

        }
        
    }
    

}