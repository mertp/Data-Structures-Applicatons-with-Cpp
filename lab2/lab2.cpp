#include <iostream>
using namespace std;
class employee{
    private:
    string name;
    string id;
    string position;
    public:
    void setName(string name){
        this->name=name;

    }
    string getName(){
        return name;
    }
    void setPos(string position){
        this->position=position;
    }
    string getPOS(){
        return position;
    }
    void setIdnumber(string id){
        this->id=id;
    }
    string getID(){
        return id;
    }

};
int main()
{
int N;
string name;
string id;
string pos;
cout<<"Number of employees:";cin>>N;
employee *emp=new employee[N];
//Enter employee information:
cout<<"Enter employee information"<<endl;
for (int i = 0; i < N; i++)
{ cout<<i+1<<"th employee:"<<endl;
cout<<"\tname=";cin>>name;
cout<<"\tid =";cin>>id;
cout<<"\tpos =";cin>>pos;
emp[i].setName(name);
emp[i].setIdnumber(id);
emp[i].setPos(pos);
}
//Cleaning the screen 
system("cls");
//display employees:
cout<<"Display employees:"<<endl;
for (int i = 0; i < N; i++)
{ cout<<i+1<<"th employee:"<<endl;
cout<<"\tname="<<""+emp[i].getName()<<endl;
cout<<"\tid ="<<""+emp[i].getID()<<endl;
cout<<"\tpos ="<<""+emp[i].getPOS()<<endl;
}
return 0;
}