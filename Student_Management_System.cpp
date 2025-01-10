#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Student{

  private:

  string name;
  int id;
  float grad;
  int age;

  public:

  Student(string n,const int i,int ag,float gr){
    name=n;
    id=i;
    grad=gr;
    age=ag;
  }

  int getId(){
    return id;
  }

  string getName(){
    return name;
  }
  void setName(string n){
    name=n;
  }

  float getGrad(){
    return grad;
  }
  void setGrad(float g){
     grad=g;
  }
  int getAge(){
    return age;
  }
  void setAge(int ag){
     age=ag;
  }
};

class System{

    private:

    vector<Student>students;

    public:

    void addStudent(string name , const int& id ,int age ,float grad){
        Student newStudent(name,id,age,grad);
       for( auto &S:students){
         if(S.getId()==id){
          cout<<"The Id Already exist, try use defirent Id."<<endl;
          return;
         }
       }
        students.emplace_back(newStudent);
    }

    void deleteStudent(const int& id){
        bool found=false;
     for(int i=0;i<students.size();i++){
        if(students[i].getId()==id){
         students.erase(students.begin()+i);
         found=true;
        }
     }
     if (!found)
     {
       cout<<"THE ID NOT FOUND!"<<endl;
     }
     
    }
 
     void updateStudent(string name , const int id ,int age ,float grad){
       for(int i=0;i<students.size();i++){
        if(students[i].getId()==id){
         students[i].setName(name);
         students[i].setAge(age);
         students[i].setGrad(grad);
        }
      }
    }

    void displayStudents(){
        int studentNumber=1;
       for(int i=0;i<students.size();i++){
        cout<<"     The Studernt: "<<studentNumber++<<endl;
        cout<<"     Name: "<<students[i].getName()<<endl;
        cout<<"     Age: "<<students[i].getAge()<<endl;
        cout<<"     Grade: "<<students[i].getGrad()<<endl;
        cout<<"     Id: "<<students[i].getId()<<endl;
        cout<<endl;
      }       
    }
};

int main(){
    
    int op;
    System Manager;
    
    do{
     cout<<"_____Student Management System Guide_____"<<endl;
     cout<<"0. Exit"<<endl;
     cout<<"1. Add Student "<<endl;
     cout<<"2. Delete Student"<<endl;
     cout<<"3. Update Student"<<endl;
     cout<<"4. Display Students"<<endl;
     cout<<"5. Clear Scren"<<endl;
     cin>>op;
     
     switch(op){
        case 0:
        break;

        case 1:{
        string name;
        int age;
        float grad;
        int id;
        cout<<"<Enter The id>"<<endl;
        cin>>id;
        cin.ignore();
        cout<<"<Enter The Name>"<<endl;
        getline(cin,name);
        cout<<"<Enter The Age>"<<endl;
        cin>>age;
        cout<<"<Enter The Grad>"<<endl;
        cin>>grad;
        Manager.addStudent( name , id ,age , grad);
        cout<<endl;
        cout<<"----ADDED SUCCESSFULY----"<<endl;
        break;
      }

        case 2:{
        int id;
        cout<<"<Enter The id>"<<endl;
        cin>>id;
        Manager.deleteStudent(id);
        cout<<endl;
        cout<<"----DELETED SUCCESSFULY----"<<endl;
        break;
      }

      case 3:{
                string name;
        int age;
        float grad;
        int id;
        cout<<"<Enter The Student id>"<<endl;
        cin>>id;
        cin.ignore();
        cout<<"<Enter The Updated Name>"<<endl;
        getline(cin,name);
        cout<<"<Enter The Updated Age>"<<endl;
        cin>>age;
        cout<<"<Enter The Updated Grad>"<<endl;
        cin>>grad;
        Manager.updateStudent(name,id,age,grad);
        cout<<endl;
        cout<<"----UPDATED SUCCESSFULY----"<<endl;
        break;
      }

      case 4:
      Manager.displayStudents();
      break;
     
     case 5:{
      system("cls");
     }
     
     break;
        
        default:
        cout<<"....WRONG! TRY AGAIN....";
      }
    }while(op!=0);

    return 0;
}