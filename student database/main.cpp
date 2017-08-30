#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;

class Student
{
  private:
    string id;
    string name;
    string year;
    string gender;

  public:
    Student();
    Student(string i, string n, string y, string g);
    string getName();
    string getId();
    string getYear();
    string getGender();
    void setName(string n);
    void setGender(string g);
    void setYear(string y);
};

Student::Student(){

}

Student::Student(string i, string n, string y, string g)           /*constructor*/
{
    id=i;
    name=n;
    year=y;
    gender=g;
}

string Student::getId(){
    return id;
}

string Student::getName(){
    return name;
}

void Student::setName(string n){
    name = n;
}

string Student::getGender(){
    return gender;
}

void Student::setGender(string g){
    gender = g;
}

string Student::getYear(){
    return year;
}

void Student::setYear(string y){
    year = y;
}

const int MAX_STUDENTS = 20;
Student *studentDb[MAX_STUDENTS];                        /* array of student objects*/

void addStudent(string id,string name,string year,string gender);
void printStudents();
void printStudentDetails(string id);
void modifyStudent(string id);
void removeStudent(string id);
void printStudentYear(string yr);
void writeStudentFile();
void readStudentFile();
int idValidate(string id);
int yearValidate(string year);
int genderValidate(string gender);

int main()
{
    int choice, ret = 0;
    string name="", id, gender, year;
    do
     {
        cout << "\n\n\n";
        cout<<"\t****Welcome to UMASS Student database****\n"<<endl;
        cout <<"\n\t\t*********MENU********\n"<<endl;
        cout << "\t1. Add new student record (press key 1)\t" << endl;
        cout << "\t2. Remove student record (press key 2)\t" << endl;
        cout << "\t3. Modify student record (press key 3)\t" << endl;
        cout << "\t4. Print details of a student (press key 4)\t" << endl;
        cout << "\t5. Print details of students based on year(press key 5)\t" << endl;
        cout << "\t6. Write to file (press key 6)\t"<<endl;
        cout << "\t7. Read from file (press key 7)\t"<<endl;
        cout << "\t8. Print details of all students (press key 8)\t" << endl;
        cout << "\t9. Exit ( press key 9)\t" << endl;
        cin >> choice;
        switch(choice)
           {
            case 1 :
                cout<< "\nEnter student name(first and last name with space separation):\n";
                cin.ignore();
                getline(cin,name);
                do
                {                                                                            /* looping if incorrect input*/
                    cout<<"\nEnter student id(9 digits): "<<endl;
                    cin>> id;
                    ret = idValidate(id);
                }
                while(ret!=1);
                do
                {                                                                            /* looping if incorrect input*/
                    cout<<"\nEnter year of study(freshman,sophomore,junior or senior):\n"<<endl;
                    cin>>year;
                    ret=yearValidate(year);
                }
                while(ret!=1);
                do
                {                                                                            /* looping if incorrect input*/
                    cout<<"\nEnter student gender(male, female):"<<endl;
                    cin>>gender;
                    ret=genderValidate(gender);
                }
                while(ret!=1);
                addStudent(id, name, year, gender);
                break;
            case 2:
                cout<<"\nEnter student id to be removed:\n";
                cin>>id;
                removeStudent(id);
                break;
            case 3:
                cout << "\nEnter student id: ";
                cin>>id;
                modifyStudent(id);
                break;
            case 4:
                cout<<"\nEnter student id:\t"<<endl;
                cin>>id;
                printStudentDetails(id);
                break;
            case 5:
                cout<<"\nEnter the year(freshman\tsophomore\tjunior\tsenior)\n"<<endl;
                cin>>year;
                printStudentYear(year);
                break;
            case 6:
                writeStudentFile();
                break;
            case 7:
                readStudentFile();
                break;
            case 8:
                printStudents();
                break;
            case 9:
                exit(0);
            default:
                cout<< "\ninvalid input!!"<<endl;
                break;
          }
    }
    while(choice!=9);
    return 0;
}

int idValidate( string id)
{
    for(int i=0;i< MAX_STUDENTS; i++)
    {
        if (studentDb[i])
        {
            if(studentDb[i]->getId() == id)                                 /* validate if adding an existing student*/
            {
                cout<<"\n Student already exists!!\n";
                return 0;
            }
        }
    }
    if ((id.length()!=9))                                                   /* length of id should be equal to 9*/
    {
        cout<<"\nInvlaid input. Id should have 9 digits !!"<<endl;
        return 0;

    }
    for(int i = 0; i < id.length(); i++)
    {
        if(! (((id[i] >= '0' ) && (id[i] <= '9')) || (id[i] == ' ')) )      /* id should not contain any character*/
        {
            cout<<"\n Invalid input. Enter digits between 0 and 9 !!\n"<<endl;
            return 0;
        }

    }
    return 1;
}

int yearValidate(string year)                                                          /* validate year input*/
{
    if((year == "freshman")|| (year == "sophomore")|| (year == "junior")|| (year == "senior"))
    {
        return 1;

    }
    else
    {
        cout<<"\n Invalid year!!\n"<<endl;
        return 0;
    }
}

int genderValidate(string gender)                                                       /* validate gender input*/
{
    if( gender == "female"|| gender =="male")
        return 1;
    else
    {
        cout<<"\n Invalid gender!!"<<endl;
        return 0;
    }

}


void addStudent(string id, string name,string year, string gender)
{
    for(int i=0;i< MAX_STUDENTS; i++)
    {
        if(!studentDb[i])
        {
            studentDb[i] = new Student(id, name, year, gender);
            break;
        }
    }
}
void printStudentDetails(string id)
{
    cout<<"\n\tID\t\tNAME\t\tYEAR\t\tGENDER\n"<<endl;
    for(int i=0; i< MAX_STUDENTS; i++)
    {
        if(studentDb[i]->getId()== id)
        {
            cout<<"\n"<<studentDb[i]->getId();
            cout<<"\t"<<studentDb[i]->getName();
            cout<<"\t"<<studentDb[i]->getYear();
            cout<<"\t"<<studentDb[i]->getGender();
            break;
        }

    }

}
void printStudentYear(string yr)
{
    cout<<"\n\t\tSTUDENTS LIST\n"<<endl;
    for(int i=0; i< MAX_STUDENTS; i++)
    {
        if(studentDb[i])
        {
            if(studentDb[i]->getYear()== yr )
            {
                cout<<"\n"<<studentDb[i]->getId();
                cout<<"\t"<<studentDb[i]->getName();

            }
        }
        else
        {
            break;
        }
    }

}
void printStudents()
{
    cout<<"\n\t\tSTUDENT DATABASE\n"<<endl;
    cout<<"\nID\tNAME\t\tYEAR\t\tGENDER\n"<<endl;
    for(int i=0; i< MAX_STUDENTS; i++)
    {
        if(studentDb[i])                                       /* if array is not empty*/
        {
            cout<<"\n"<<studentDb[i]->getId();
            cout<<"\t"<<studentDb[i]->getName();
            cout<<"\t"<<studentDb[i]->getYear();
            cout<<"\t"<<studentDb[i]->getGender();
        }
        else
        {
            break;
        }
    }
}

void modifyStudent(string id)
{
    int modifyField = 0,  foundIndex = -1;
    bool found = false;
    string newName,newGender,newYear;
    for (int i = 0; i< MAX_STUDENTS;i++)
    {
        if(studentDb[i])
        {
            if(id == studentDb[i]->getId())
            {
                found = true;
                foundIndex = i;
            }
        }
    }
    if(!found){
        cout << "\nStudent not found"<<endl;
    }
    while(found && modifyField < 4)
    {
        cout<<"\nEnter the field to be modified:\n";
        cout<<"\n1. name(press 1) \n2. year (press 2) \n3. gender(press 3) \n4. quit to main menu (press 4)\n";
        cin>>modifyField;
        if(modifyField==1)
        {
            cout<<"\nenter new name:";
	    cin.ignore();
	    getline(cin,newName);
            studentDb[foundIndex]->setName(newName);
        }
        else if(modifyField==2)
        {
            cout<<"\nenter new year:";
            cin>>newYear;
            int temp=yearValidate(newYear);
            if(temp==0) continue;
            studentDb[foundIndex]->setYear(newYear);
        }
        else if(modifyField==3)
        {
            cout<<"\nenter new gender:";
            cin>>newGender;
            int temp= genderValidate(newGender);
            if(temp==0) continue;
            studentDb[foundIndex]->setGender(newGender);
        }
    }

}


void removeStudent(string id)
{
    int j= 0 ,flag=0;
    for(int i=0; i < MAX_STUDENTS; i++ )
    {
        if(studentDb[i])
        {
            if(studentDb[i]->getId()==id)
            {
                j=i;
                while(studentDb[j+1])
                {
                   studentDb[j]=studentDb[j+1];
                   j++;
                }
                studentDb[j] = '\0';
                flag=1;
                break;
            }

        }
    }
    if(flag)
        cout<<"\nStudent successfully removed from database!\n ";
    else
        cout<<"\nStudent not found!!";

}

void writeStudentFile(){
    string writeFileName;
    int i = 0;
    ofstream studWfile;                                          /*object of ofstream */
    cout << "Enter Filename: ";
    cin >> writeFileName;
    studWfile.open(writeFileName.c_str());                       /* open file */
    if (studWfile.is_open())
    {
        while(studentDb[i])
        {
        studWfile << studentDb[i]->getId() <<",";                /* writing into file separated by comma*/
	    studWfile << studentDb[i]->getName() <<",";
	    studWfile << studentDb[i]->getYear() <<",";
	    studWfile << studentDb[i]->getGender() <<endl;
	    i++;
        }
        cout<<"\nSuccessfully wrote to file "<<writeFileName<<endl;
    }
    else cout << "Unable to open file "<<writeFileName<<endl;
    studWfile.close();
}

void readStudentFile(){
    string tempName, tempId, tempGender,tempYear;
    int i = 0, cellIndex = 0;
    string line, cell, readFileName;
    cout << "\nEnter filename: ";
    cin >> readFileName;
    ifstream studRfile(readFileName.c_str());                /* object of ifstream*/
    while(getline(studRfile, line))                          /*  extracting each line */
    {
        stringstream lineStream(line.c_str());
        cellIndex = 0;

        while(getline(lineStream, cell, ','))                /* extracting each cell from line*/
        {

            switch(cellIndex)
            {
            	case 0:
                    tempId = cell;
                    break;
            	case 1:
                    tempName = cell;
                    break;
            	case 2:
                    tempYear = cell;
                    break;
            	case 3:
                    tempGender = cell;
                    break;
            }
            cellIndex++;	
        }
        studentDb[i] = new Student(tempId, tempName, tempYear, tempGender); /* load file contents to database*/
        i++;
    }
    cout<<"\n Successfully read from file to database!!\n";
    studentDb[i] = '\0';
}
