#include<iostream>
#include<stdlib.h>
using namespace std;
int studentcount=0;//stduent count mean who many student enter into array;
int teachercount=0;
//admin prototypes
void addstudentintoarray(string name,string fathername,string course,string section,double cnic,double marks,int rollnumber);
void studentrecord();
void admin();
void addstudent();
void addteacherintoarray(string name,string subject,double cnic,double phone,int salary,string post,int id);
void addteacher();
void removestudent();
void removeteacher();
void timetable();
void displayresult();
void attendancereport();
void teacherrecord();
//end of admin prototype.
//start of student array
const int maxrecord=20000;
string studentname[maxrecord];
int studentmarks[maxrecord];
int studentcnic[maxrecord];
int studentrollnumber[maxrecord];
string studentcourse[maxrecord];
string studentsection[maxrecord];
string studentfathername[maxrecord];
//end of student array.
//start of teacher array.
string teachername[maxrecord];
string teachersubject[maxrecord];
double teachercnic[maxrecord];
double teacherphone[maxrecord];
int teachersalary[maxrecord];
string teacherpost[maxrecord];
int teacherid[maxrecord];
//end of teacher array
//start of teacher user prototype
void teacheruser();
void passwordchanger();
void displayreport();
//end of teacher user prototype.
//start of student prototype

char studentmenu();
void studentuser();
void result(int number);
void notice();
void subject(int num);
void fee(int n);
void information(int num1);
//end of student prototype
char adminmenu() //admin can perform the following propertises
{
    cout << "admin option are:" << endl;
    cout << "1.add new students:" << endl;
    cout << "2.add new teacher:" << endl;
    cout << "3.remove student:" << endl;
    cout << "4.remove teacher:" << endl;
    cout << "5.view all record:" << endl;
    cout << "6.check timetable:" << endl;
    cout << "7.check student result:" << endl;
    cout << "8.check student attendanec status:" << endl;
    cout << "9.exit:"<<endl;
    cout << "your option:";
    char num;
    cin >> num;
    return num;
}
void header()
{
    cout << "*******************************************************" << endl;
    cout << "*         COLLEGE MANAGEMENT SYSTEM                   *" << endl;
    cout << "*******************************************************" << endl;
}
char teachermenu()
{
    header();
    cout << "you are in user option:" << endl;
    cout << "main menu > teacher:" << endl;
    cout << "1.view student record:" << endl;
    cout << "2.view atttendance status:" << endl;
    cout << "3.display result" << endl;
    cout << "4.Generate student report:" << endl;
    cout << "5.change password:" << endl;
    cout << "6.exit:"<<endl;
    cout << "yor option";
    char num;
    cin >> num;
    return num;
}
char user()
{
    cout<<"1.teacher:"<<endl;
    cout<<"2.student:"<<endl;
    cout<<"3.exit:"<<endl;
    char ch;
    cout<<"your option:"<<endl;
    cin>>ch;
    return ch;
}
char menu()
{
    header();
    cout << "MAIN MENU:" << endl;
    cout << "1.Admin:" << endl;
    cout << "2.User" << endl;
    cout << "3.exit"<<endl;
    cout << "your option:";
    char num1 = '0';
    cin >> num1;
    return num1;
}
main()
{
    while(true)
    {
        char num=menu();
        system("cls");
        if(num == '1')
        {
            admin();
            num=menu();
        }
        if(num == '2') 
        {
            system("cls");
            char ch=user();
            if(ch == '1')
            teacheruser();
            else if(ch == '2')
            studentuser();
            else if(ch == '3')
            break;
            else 
            {
                cout<<"enter correct option:"<<endl;
            }
        }
        if(num == '3')
        {   
            break;
        }
    }
}
void admin()
{
    string name1,name2;
    int password1,password2;
    cout<<"enter admin name:";
    cin>>name1;
    cout<<"enter admin password:";
    cin>>password1;
    cout<<"enter admin name again if you want to login:";
    cin>>name2;
    cout<<"enter password again:";
    cin>>password2;
    if(name1 == name2 && password1 == password2)
    {
        while (true)
        {
            char option=0;
            option=adminmenu();
            system("cls");
            if(option == '1')
            {
                addstudent();
                
            }
            else if(option == '2')
            {
                addteacher();
            }
            else if(option == '3')
            {
                removestudent();
            }
            else if(option == '4')
            {
                removeteacher();
            }
            else if(option == '5')
            {
                teacherrecord();
                studentrecord(); 
            }
            else if(option == '6')
            {
                timetable();
            }
            else if(option == '7')
            {
                displayresult();
            }
            else if(option == '8')
            {
                attendancereport();
            }
            else if(option == '9')
            {
                break;
            }
            else 
            {
                cout<<"wrong input please type correct input:"<<endl;
            }
            
        }
    }
}
void addstudent()
{
    string sname,scourse,ssection,sfathername;
    double smarks,sroll_number,scnic;
    cout << "enter student name:" << endl;
    cin >> sname;
    cout << "enter father  name:" << endl;
    cin >> sfathername;
    cout << "enter obtained marks in matric:" << endl;
    cin >> smarks;
    cout << "enter course name:";
    cin >> scourse;
    cout << "enter roll number:";
    cin >> sroll_number;
    cout << "enter CNIC:";
    cin >> scnic;
    cout << "enter SECTION:";
    cin >> ssection;
    addstudentintoarray(sname,sfathername,scourse,ssection,scnic,smarks,sroll_number);
}
void addstudentintoarray(string name,string fathername,string course,string section,double cnic,double marks,int rollnumber)
{
    studentname[studentcount]=name;
    studentfathername[studentcount]=fathername;
    studentcourse[studentcount]=course;
    studentsection[studentcount]=section;
    studentcnic[studentcount]=cnic;
    studentmarks[studentcount]=marks;
    studentrollnumber[studentcount]=rollnumber;
    studentcount=studentcount+1;
}
void teacherrecord()         //display all teacher recore in merit order
{
        cout<<"name:"<<"\t"<<"post:"<<"\t"<<"salary:"<<"\t"<<"subject:"<<"\t"<<"phone:"<<"\t"<<"id"<<"\t"<<"cnic:"<<endl;
    for(int x=0;x<teachercount;x++)
    {
        for(int i=0;i<teachercount-1;i++)
        {
            if(teachersalary[i] < teachersalary[i+1])
            {
                int temp=0;
                temp=teachersalary[i+1];
                teachersalary[i+1]=teachersalary[i];
                teachersalary[i]=temp;
                string temname,tempost,temsubject;      // changing variable
                int temphone,temcnic,temid;             //changing variable.
                temname=teachername[i+1];
                teachername[i+1]=teachername[i];
                teachername[i]=temname;
                tempost=teacherpost[i+1];
                teacherpost[i+1]=teacherpost[i];
                teacherpost[i]=tempost;
                temsubject=teachersubject[i+1];
                teachersubject[i+1]=teachersubject[i];
                teachersubject[i]=temsubject;
                temphone=teacherphone[i+1];
                teacherphone[i+1]=teacherphone[i];
                teacherphone[i]=temphone;
                temcnic=teachercnic[i+1];
                teachercnic[i+1]=teachercnic[i];
                teachercnic[i]=temcnic;
                temid=teacherid[i+1];
                teacherid[i+1]=teacherid[i];
                teacherid[i]=temid;
            }
        }
    }
    for(int y=0;y<teachercount;y++)
    {
        cout<<teachername[y]<<"\t"<<teacherpost[y]<<"\t"<<teachersalary[y]<<"\t"<<teachersubject[y]<<"\t"<<teacherphone[y]<<"\t"<<teacherid[y]<<"\t"<<teachercnic[y]<<endl;

    }
}
void studentrecord()               //display student record in merit order
{       cout<<"name:"<<"  "<<"father name:"<<"   "<<"section:"<<"  "<<"roll number:"<<"  "<<"course:"<<"  "<<"marks:"<<" "<<"cnic"<<endl;
    
    for(int x=0;x<studentcount;x++){
        for(int y=0;y<studentcount-1;y++){
            if(studentmarks[y]<studentmarks[y+1]){
                int temp;
                temp=studentmarks[y+1];
                studentmarks[y+1]=studentmarks[y];
                studentmarks[y]=temp; 
                string tname,tfname,tsection,tcourse;//temporaray store variable
                tname=studentname[y+1];
                studentname[y+1]=studentname[y];
                studentname[y]=tname;
                tfname=studentfathername[y+1];
                studentfathername[y+1]=studentfathername[y];
                studentfathername[y]=tfname;
                tsection=studentsection[y+1];
                studentsection[y+1]=studentsection[y];
                studentsection[y]=tsection;
                tcourse=studentcourse[y+1];
                studentcourse[y+1]=studentcourse[y];
                studentcourse[y]=tcourse;
                int tcnic,trollnumber; // temporaray store variable 
                tcnic=studentcnic[y+1];
                studentcnic[y+1]=studentcnic[y];
                studentcnic[y]=tcnic;
                trollnumber=studentrollnumber[y+1];
                studentrollnumber[y+1]=studentrollnumber[y];
                studentrollnumber[y]=trollnumber;
            }
        }
    }
    for(int i=0;i<studentcount;i++)
    {
        cout<<studentname[i]<<"\t"<<studentfathername[i]<<"\t"<<studentsection[i]<<"\t"<<studentrollnumber[i]<<"\t"<<studentcourse[i]<<"\t"<<studentmarks[i]<<"\t"<<studentcnic[i]<<endl;
    }       
}
void addteacher()
{
    string name,post,subject;
    double cnic,phone,salary;
    int id;
    cout<<"Enter teacher name:";
    cin>>name;
    cout<<"enter teacher post:";
    cin>>post;
    cout<<"enter teacher subject:";
    cin>>subject;
    cout<<"enter teacher cinc:";
    cin>>cnic;
    cout<<"enter phone number:";
    cin>>phone;
    cout<<"enter salary:";
    cin>>salary;
    cout<<"enter teacher id:";
    cin>>id;
    addteacherintoarray(name,subject,cnic,phone,salary,post,id);
}
void addteacherintoarray(string name,string subject,double cnic,double phone,int salary,string post,int id)
{
    teachername[teachercount]=name;
    teachersubject[teachercount]=subject;
    teachercnic[teachercount]=cnic;
    teacherphone[teachercount]=phone;
    teachersalary[teachercount]=salary;
    teacherpost[teachercount]=post;
    teacherid[teachercount]=id;
    teachercount=teachercount+1;   
}
void removestudent()
{
    int rollnumber;
    cout<<"enter student rollnumber if you want to remove:";
    cin>>rollnumber;
    for(int i=0;i<studentcount;i++)
    {
        if(rollnumber==studentrollnumber[i])
        {
            studentname[i]="nill";
            studentmarks[i]=0;
            studentcnic[i]=0;
            studentrollnumber[i]=0;
            studentcourse[i]="no_course";
            studentsection[i]="no_section";
            studentfathername[i]="remove";
        }
    }
}
void removeteacher()
{
    int id;
    cout<<"enter tecaher id which teacher you want to remove:";
    cin>>id;
    for(int i=0;i<teachercount;i++)
    {
        if(id=teacherid[i])
        {
            teachername[i]="remove";
            teachersubject[i]="nope";
            teacherpost[i]="no";
            teacherphone[i]=0;
            teachersalary[i]=0;
            teachercnic[i]=0;
        }
    }
}
void timetable()
{
    cout << "Main menu > check time table" << endl;
    cout << "   time    "<< "8:00 to 9:00"<< "9:00 to 10:00"<< "10:00 to 11:00" << endl;
    cout << "  monday   "<< "  math/bio  "<< "  english    "<< "   physics    " << endl;
    cout << "  tuesday  "<< "  urdu      "<< "  math/bio   "<< "   com/chem   " << endl;
    cout << " wenusday  "<< "  english   "<< "_____________"<< "   physics    " << endl;
    cout << " thurday   "<< "  math/bio  "<< "  math/bio   "<< "     urdu     " << endl;
    cout << "  friday   "<< "  english   "<< "  physics    "<< "     urdu     " << endl;
}
void displayresult()
{
    int eng[20];
    int phy[20];
    int urdu[20];
    int math[20];
    int total[20];
    for(int i=0;i<studentcount;i++)
    {
        cout<<"enter english marks:";
        cin>>eng[i];
        cout<<"enter math marks:";
        cin>>math[i];
        cout<<"enter physics marks:";
        cin>>phy[i];
        cout<<"enter urdu marks:";
        cin>>urdu[i];
        total[i]=urdu[i]+math[i]+eng[i]+phy[i];
    }
        cout<<"name:"<<"\t"<<"urdu"<<"\t"<<"physics"<<"\t"<<"english"<<"\t"<<"\t"<<"math"<<"total number:"<<endl;
    for(int x=0;x<studentcount;x++)
    {
        cout<<studentname[x]<<"\t"<<urdu[x]<<"\t"<<phy[x]<<"\t"<<eng[x]<<"\t"<<math[x]<<"\t"<<total[x]<<endl;
    }
}
void attendancereport()
{
    float days[20];
    float percentage[20];
    char month;
    cout<<"enter month number:";
    cin>>month;
    for(int i=0;i<studentcount;i++)
    {
        cout<<"enter days that student persent in days:";
        cin>>days[i];
    }
    for(int x=0;x<studentcount;x++)
    {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            percentage[x]=(100 * days[x])/31;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            percentage[x]=(100 * days[x])/31;
        }
        else 
        {
            percentage[x]=(100 * days[x])/28;
        }
    }
    float temp=0;
    string tempory;
    for(int y=0;y<studentcount;y++)
    {
        for(int z=0;z<studentcount-1;z++)
        {
            if(percentage[z]<percentage[z+1])
            {
                temp=percentage[z+1];
                percentage[z+1]=percentage[z];
                percentage[z]=temp;
                tempory=studentname[z+1];
                studentname[z+1]=studentname[z];
                studentname[z]=tempory;
            }
        }
    }
    cout<<"name :"<<"\t"<<"attendance report is:"<<endl;
    for(int i=0;i<studentcount;i++)
    {
        cout<<studentname[i]<<"\t"<<percentage[i]<<endl;
    }
}
void teacheruser()
{
    while(true)
    {
        char option=teachermenu();
        system("cls");
        if(option == '1')
        {
            if(studentcount > 0)
            {
                    cout<<"name"<<"\t"<<"father name:"<<"\t"<<"section"<<"\t"<<"course:"<<"\t"<<"roll number:"<<"\t"<<"marks:"<<"cnic:"<<endl;
                for(int i=0;i<studentcount;i++)
                {
                    cout<<studentname[i]<<"\t"<<studentfathername[i]<<"\t"<<studentsection[i]<<"\t"<<studentcourse[i]<<"\t"<<studentrollnumber[i]<<"\t"<<studentmarks<<studentcnic<<endl;
                }
            }
        }
        else if(option == '2')
        {
            attendancereport();
        }
        else if(option == '3')
        {
            displayresult();
        }
        else if(option == '4')
        {
            displayreport();
        }
        else if(option == '5')
        {
            passwordchanger();
        }
        else if(option == '6')
        {
            break;
        }
        else 
        {
            cout<<"type correct option,try again:"<<endl;
        }
    }    
}
void passwordchanger()
{
    string userpassword;
    cout<<"enter forget or update if you want to change the password:";
    cin>>userpassword;
    if(userpassword == "forget" || userpassword == "update")
    {
        string newpassword,phone_number;
        cout<<"enter phone number:";
        cin>>phone_number;
        cout<<"enter new password:";
        cin>>newpassword;
        cout<<"your password has been updated:"<<endl;
    }
    else 
    {
        cout << "sorry wrong input your password is not updates:try again:" << endl;
    }
}
void displayreport()
{
    int mark[20];
    for(int i=0;i<studentcount;i++)
    {
        cout<<"enter 11th class marks:"<<endl;
        cin>>mark[i];
    }
    for(int x=0;x<studentcount;x++)
    {
        if(mark[x]>=450)
        {
            cout<<"name:"<<studentname[x]<<" marks:"<<mark[x]<<"excellent performance:"<<endl;
        }
        else if(mark[x]>=400)
        {
            cout<<"name:"<<studentname[x]<<" marks:"<<mark[x]<<"good performance:"<<endl;
        }
        else if(mark[x]>=350)
        {
            cout<<"name:"<<studentname[x]<<" marks:"<<mark[x]<<"average performance:"<<endl;
        }
        else 
        {
            cout<<"name:"<<studentname[x]<<" marks:"<<mark[x]<<"average performance:"<<endl;
        }
        
    }

}
char studentmenu()   // student menu
{
    char num;
    cout << "main menu>user " << endl;
    cout << "1.change password" << endl;
    cout << "2.check  result" << endl;
    cout << "3.check notice" << endl;
    cout << "4.check subject:" << endl;
    cout << "5.fee challen" << endl;
    cout << "6.personal information" << endl;
    cout << "7.exit:"<<endl;
    cout << "your option" << endl;
    cin >> num;
    return num;
}
void studentuser()
{
    
    string name;
    cout<<"enter name:";
    cin>>name;
    int count=0;
    int i=0;
    for(;i<=studentcount;)
    {
        if(name == studentname[i])
        {
            count=count+1;
            break;
        }
        i++;
    }
    if(count == 1) 
    {
        string username,userpassword;
        string loginname,loginpassword;
        cout << "enter student user name:" << endl;
        cin>>username;
        cout << "enter  password:" << endl;
        cin>>userpassword;
        cout << "enter login name:" << endl;
        cin >> loginname;
        cout << "enter login password:" << endl;
        cin>>loginpassword;
        if( username == loginname && userpassword == loginpassword )
        {
            while (true)
            {
                char option=studentmenu();
                system("cls");
                if(option == '1')
                {
                    passwordchanger();
                }
                else if(option == '2')
                {
                    result(count);
                }
                else if(option == '3')
                {
                    notice();
                }
                else if(option == '4')
                {
                    subject(count);
                }
                else if(option == '5')
                {
                    fee(count);
                }
                else if(option == '6')
                {
                    information(count);
                }
                else if(option == '7')
                {
                    break;
                }
                else 
                {
                    cout << "wrong option is selected please select the correct option:"<<endl;
                }  
            }
        }
    }
    else 
    {
        cout<<"no user exit in data:"<<endl;
    }
    


}
void result(int number)
{

    studentmarks[number];
    float aggregate = (studentmarks[number] * 100) / 500;
    string remarks;
    if (aggregate >= 85)
    {
        remarks = "good";
    }
    else
    {
        remarks = "not_satisfied:";
    }
    cout << "name:"<< " " << studentname[number] << " "<< "roll number:" << studentrollnumber[number] << " "<< "aggregate:" << aggregate << " "<< "marks:" << studentmarks[number] << " "<< "remarks:" << remarks << endl;
}
void notice()
{
    cout << "welcome back student please submit your project on monday thanks:" << endl;
    cout << "your fee challan has been uploaded please submit your fee:"<<endl;

}
void subject(int num)
{;
    string subject1 = "math";
    string subject2 = "english";
    string subject3 = "computer";
    cout<<"your register subject are:"<<endl;
    cout << "name" << studentname[num] << "  "<< "subject name:"<< " " << subject1 << " " << subject2 << " "<< " " << subject3 << endl;
}
void fee(int n)
{
    cout << "main menu>fee challen" << endl;
    string bank1;
    cout << "enter bank account:";
    cin >> bank1;
    string bankid;
    cout << "enter bank id:" << endl;
    cin >> bankid;
    if (bank1 == bankid)
    {
        cout <<"name"<<studentname[n] <<"fee has been submitted:" << endl;
    }
    else
    {
        cout << "sorry! please submit your fee" << endl;
    }
}
void information(int num1)
{
    cout << "main menu > personal information:" << endl;
    cout <<"name"<<studentname[num1] << "fathername" << studentfathername[num1]<< " section:" << studentsection[num1] << " course " << studentcourse[num1] << " roll number:" << studentrollnumber[num1] << "CNIC" << studentcnic[num1] << endl;
}