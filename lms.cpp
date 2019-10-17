#include<iostream> 
#include<iomanip> 
#include<string>
#include<fstream> 
#include<cmath>
#include<sstream>
#include<stdlib.h>
#include<cstring>
#include<conio.h>
using namespace std;
//****************
//global variables
//****************
int n=0;
int index=0;//used in finding index function
int counter=0;
int flag=0;
int count;  // incremented when add course and decremented when delete course
int COUNT; //incremented when student is added and decremented when student is decremented
//*******************
// declaring functions
//*********************
bool IsValidCourseCodeL(string code);//for checking the letters validity of course_code
bool IsValidCourseCodeN(string code);//for checking the numbers validity o fcourse_code
bool IsValidCourseName(string name);//for checking the validation of course_name
bool IsValidCreditHours(int crdHrs);//for checking whether credit hours is between 1-3
bool IsValidSemester(int sem);//for checking whether semester is between 1-8
int CourseIndex(string course_code,string code1[]);//for finding the given course code from the course code list
void AddCourses(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,int i);//Adding courses
void UpdateCourse(string name1[],string char1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,char course_code[]);//Updating courses
void DeleteCourse(string name1[],string char1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,char course_code[]);//Deleting courses
void ViewAllCourses(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem);//Viewing all the courses 
void ViewSemesterCourses(string name1[],string code1[],int crdHrs1[], int sem1[],string name,string code,int crdHrs,int semester);//Viewing the courses semester vice
void saveCourses( string n[], string c[], int crd[],int s[]);//Saving Courses
int str_int(string str);//for changing string to integer
void loadCourses(string name1[],string code1[],int crdHrs1[],int sem1[]);//loading the courses 
bool loadUsers(string Userlist[],string Passwordlist[]);//loading the passwords and usenames
bool IsValidStdName(string stdname);//for checking the validation of student name
bool ValidRegNo( char RegNo[] );	//for checking the validation of registration number
void addStudent(string stdNameList[],string stdRegNoList[],string stdname,char Reg_No[]);//Adding students
void updateStudent(string stdNameList[],string stdRegNoList[],string stdName,char RegNo[]);//Updating students
void deleteStudent(string stdNameList[],string stdRegNoList[],string stdName,char RegNo[]);//Deleting Students
int RegIndex(string stdRegNoList[],char RegNo[]);//for finding the given registeration number from the registration number list
void UnRegisterCourses(string stdRegNoList[],string stdCourseList[][50], char course_code[],char RegNo[]);//for Unregistering courses of student
void  RegisterCourses(string stdRegNoList[],string stdCourseList[][50], char course_code[],char RegNo[],string code1[]);//for registering courses of student
void view_Std(string RegNoList[],string stdNameList[] ); //Viewing students
bool checkReg(string RegNoList[],char RegNo[]);  //checking existence of redistration number inn the regNo list
void saveStudents(string stdRegNoList [],string stdCourseList[][50],string stdNameList[]);//saving student's information 
void loadStudents(string stdRegNoList [],string stdCourseList[][50],string stdNameList[]); //loading student's information
                              //----------------------------------------------
							 //************************************************   
                                              //main function
                             //*************************************************
							 //------------------------------------------------                 
int main()

{ 
//*********************   
//Variables declaration
//*********************
	 string name1[50]; string code1[50],Userlist[50],Passwordlist[50]; 
     int crdHrs1[50], sem1[50];
     char course_code[5];
     string stdName;
     char RegNo[12];
	 string stdNameList[50],stdRegNoList[50];
     string stdCourseList[50][50]={{"\0"},{"\0"}};
     string name, code,Pass; int crdHrs, sem ;
     string stdRegNo;
     bool condition =true,flag=false;
	 int op,option;
	 //************************************************
	 //choosing whether you are administrator or student
	 //************************************************
	     	loadCourses(name1 , code1 , crdHrs1 ,  sem1); 
	     	//cout << code1[0] << endl << code1[1] << endl;
		    loadStudents(stdRegNoList,stdCourseList,stdNameList);
	 cout<<endl<<"  Choose the option for Login :"<<endl;
	 cout<< " --------------------------------------"<<endl;
	 cout<<endl<<" 1 for Admin "<<endl;
	 cout<<endl<<" 2 for student"<<endl<<endl;
	 cout<<" Enter Option :";
	 cin>>option;
	 //****************************************************
	 //For Admin
	 //****************************************************
	 if(option==1)
	 {
	 	
//***********************************	 
//printing the startup of the program
//***********************************
     cout<<"                                     --------------------------------------------------------\n";
     cout<<"                                     -------------------------------------------------------\n" ;  
	 cout<<"                                     **Welcome to university learning Management System**\n";
	 cout<<"                                     -------------------------------------------------------\n";
	 cout<<"                                      -------------------------------------------------------\n\n";
//*************************************************
//condition will terminate when user enter the op 13
//************************************************* 	 
		while(op!=13)             
      	    {  
	      if(loadUsers(Userlist,Passwordlist)==true)   
          {                                             
   	        	cout <<endl<< "you have successfully logged in.";
           	  
          }
          else                                                
         	{
		 	cout<<"Sorry, we are unable to run the program ,as user data doesnot exists "<<endl<<endl;
	     	cout<<" please re-enter username and password :"<<endl<<endl;
	     	main();                       
			}
do
{ 
    //*********************
	//Presenting the options
	//********************* 
	cout<<endl<<" Choose the following options\t: "<<endl<<endl<<"-------------------------------"<<endl<<endl<<" 1\tAdd Course"<<endl<<" 2\tUpdate Course"<<endl<<" 3\tDelete Course"<<endl<<" 4\tView All Courses"<<endl<< " 5\tView courses of a semester"<<endl<<" 6\tAdd New Student"<<endl<<" 7\tUpdate Student"<<endl<<" 8\tDelete Student"<<endl<<" 9\tView All Students "<<endl<<" 10\tRegister the Courses for student"<<endl<<" 11\tUnregister the course for student "<<endl<<" 12\t Logout of the system "<<endl<<" 13\tExit Program"<<endl<<endl<<"   \tChoose the option\t  :  "<<endl<<endl;   
	cin>>op;
//****************
//Switch structure
//***************
switch(op)
{
	case 1:  //*********Add Courses********
		{ 
			int c;
			cout<<"Enter the number of courses you want to enter  : ";
			cin>>c;
			for(int i=0;i<c;i++)
    		{
				cout<<endl<<"Enter the course details, code    credit hours    semester  name :";
    			cin>>code	>>crdHrs>>sem ;
   				getline(cin, name);
				AddCourses(name1,code1,crdHrs1,sem1,name,code,crdHrs,sem,i);
   			}
			break;
		}
	case 2:  //**********Update Courses*********
		{ 
			cout<<"Enter the course_code you want to edit ";
			cin>>course_code;
	 		UpdateCourse( name1, code1, crdHrs1, sem1, name, code, crdHrs, sem, course_code);
			break;
		}
	case 3://**********Delete Courses*********
		{
		
			DeleteCourse(name1, code1, crdHrs1, sem1, name, code, crdHrs, sem, course_code);	
			break;
		}
	case 4://********View All Courses*********
		{
			ViewAllCourses(name1,code1,crdHrs1,sem1,name,code,crdHrs,sem);	
			break;
		}
	case 5://***********View Semester vise courses*********
		{
			int semester;
			cout<<"Enter the semester whose details you want to see "<<endl;
			cin>>semester;
			ViewSemesterCourses(name1,code1,crdHrs1,sem1,name,code,crdHrs,semester);		
			break;
		}
	case 6://************Add STUDENTS*********
			{
				cout<<" Enter student name :"<<endl;
				cin>>stdName;
				cout<<" Enter Registration Number :"<<endl;
				cin>>RegNo;	
				addStudent(stdNameList,stdRegNoList,stdName,RegNo);
				for(int i=0;i<count ;i++)
				{
					cout<<stdNameList[i]<<endl;
					cout<<stdRegNoList[i]<<endl;	
				}
				break;
			}
	case 7://**********Update students*********
	{
		cout<<"Enter the registration number to edit :"<<endl;
		cin>>RegNo;
	 	updateStudent (stdNameList, stdRegNoList, stdName , RegNo);	
		break;
	}
	case 8://**************delete students*************
	{
		cout<<"Enter the registration number to delete :"<<endl;
		cin>>RegNo;
		deleteStudent( stdNameList, stdRegNoList, stdName,RegNo);
		break;
	}
	case 9://**************view students*********
	{ 
	    view_Std( stdRegNoList, stdNameList );
		break;
	}
	case 10://***********Register Courses********
	{
		cout<<endl<<" Enter the registration number of student for course registration "<<endl;
		cin>>RegNo;
		cout<<" ENter the course_code for registering course"<<endl;
		cin>>course_code;
		RegisterCourses( stdRegNoList, stdCourseList, course_code, RegNo , code1);
		break;
	}
	case 11://***********Unregister courses*******
	{   cout<<endl<<" Enter the registration number of student for course registration "<<endl;
		cin>>RegNo;
		cout<<" ENter the course_code for un_registering"<<endl;
		cin>>course_code;
	//	UnRegisterCourses( stdRegNoList, stdCourseList,  course_code, RegNo, code1);
		break;
	}
	case 12: //********logging out //saving courses and student's information*******
	{
			cout<<"You have successfully log out.\n\nPlease log in again to get access to the main menu."<<endl;
		saveCourses( name1,code1,crdHrs1,sem1);
	saveStudents(stdRegNoList,stdCourseList,stdNameList);
		break;
	}
	case 13: //**********Exiting the program******
	{
		system("CLS");
		main();
		break;
	}
	default:
	  cout<<"Please enter choice from 1-13";	
	}
		}	 
	while(op!=12 && op!=13);
}
}

//**********************************************
//For Student
//**********************************************
else if(option==2)
{


	 
       int n;
       cout<<endl<<" Enter Registration Number :";
       cin>>RegNo;
       int r=RegIndex(stdRegNoList,RegNo);
         cout << stdNameList[r];
       string Pa=stdNameList[r];
       int len=Pa.length();
       cout<<endl<<" Enter Password :";
       cin>>Pass;
       int p=0;
       int q=0;
       for(int i=len-3;i<len;i++)
       {
       	if(Pass[p]==Pa[i])
       	{
       		q++;
		}
		   p++;
	   }
	  /* if(q==3)
	   {
	   	   flag=true;
	   }
	   if(flag==true)*/
	   {     cout<<" You have succesfully logged in as student "<<endl;
	   	int n1;
do   {	   	
	   	cout<<endl<<" Enter 1 to view registered courses ";
	   	cout<<endl<<" Enter 2 to logout of the system ";
	   	cout<<endl<<" Enter 3 to exit "<<endl<<endl;
	   	cout<<" choose option :";
	   	cin>>n1;
	   	switch(n1)
	   	{
	   		case 1:
			   {  
			   cout<<endl;
			   cout<<" Enter the registration number to view the registration courses :";
			   cin>>RegNo;
			   int s=checkReg(stdRegNoList,RegNo);
			   cout<<endl<<" Courses :"<<endl<<endl;
			   for(int i=0;i<5;i++)
			   {
			   	if(stdCourseList[s][i]!="\0")
			   	{
			   		cout<<stdCourseList[s][i]<<" , ";
			   		
			   	}
			   	cout<<endl;
			   }
				break;
			   }
			   case 2:
			   {
			   	main();
				
			   }
			   case 3:
			   {
				return 0;
			   }
	   			
		   }
	   }
	   while(option!=-1);
       }
       }
	   /*else 
	   {
	   	cout<<endl<<" Invalid password "<<endl;
	   	main();
	   }*/



  return 0;
}
 //***************************
 //valid course code(letters)
 //***************************
bool IsValidCourseCodeL(string code) 
     {
      bool	flag=false;
	  for(int n=0;n<2;n++)
	  {
	 	if(code[n]>=';'&& code[n]<=':')
	 	{
			flag=true;
	 	}
     }
	return flag;
} 
    //***************************
	// valid course code(numbers)
	//***************************
bool IsValidCourseCodeN(string code)
{
	bool flag=false;
	for(int n=2;n<5;n++)
	{
		if(code[n]>='0' && code[n]<='9')
		flag=true;
	}
	return flag;
}
//*********************
 // valid Course name
 //********************
bool IsValidCourseName(string name)	
	{
		int counter=0, emptyness=0;
		bool flag=false;
	
		{
			for(int i=0; i<name.size() ; i++)
			{
				if(isalpha(name[i]) || isspace(name[i])!=0)
				{
					counter+=1;
					if(isspace(name[i])!=0)
					{
						 emptyness++;
					}
				
				}
			}
		
		}
		if(name.size()==counter && emptyness!=counter)
		{
			flag=true;
		}
			return flag;
	}
//******************	
// valid Credit hours
//*******************	
bool IsValidCreditHours(int crdHrs)		
{
	 bool flag=false;
   	if(crdHrs<=3)
		{
			flag=true;
		}
	return flag;
}
    //*************
	//valid semester
	//**************
bool IsValidSemester( int sem)																														// valid semester
{
	 bool flag=false;
	if(sem<=8)
		flag=true;
	return flag;
}

//***************
//Adding Courses
//***************
void AddCourses(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,int i)   									// add course
{
 	
	bool flag1=IsValidCourseCodeL(code);
	bool flagN=IsValidCourseCodeN(code);
	if(flag1==true&&flagN==true)
	{
    	bool flag2=IsValidCourseName(name);
	    if(flag2==true)
		{
	   		 bool flag3=IsValidCreditHours(crdHrs);
   			 if(flag3==true)		
			{
   				bool flag4=IsValidSemester(sem);
    				if(flag4==true)
						{
			
						 index = i;
						 code1[index]= code;
						 crdHrs1[index]=crdHrs;
						 sem1[index]=sem;
					     name1[index]=name;
						 cout << "\nCourse has been added successfully" << endl;
						 index++;
						 flag=0;
					     count++;
						}
				else 
				cout<<"Invalid semester \n";
				}
					else
					cout<<"Invalid credit hours\n";
				}
					else
					cout<<"Invalid coursename \n";
				}
					else 
					cout<<" Invalid coursecode \n";
} 

//****************************
//For Viewing all the courses
//****************************
void ViewAllCourses(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem )											// view all courses
{ 
	cout << left << setw(16) << "CourseCode" << setw(50) << "CourseName" << setw(15) << "CreditHours" << setw(15) << "Semester" << endl;
    for(int i=0  ; i<count ;i++)
    {
     	cout<< left << setw(16) << code1[i ]<< setw(50) << name1[i] << setw(15) << crdHrs1[i] << setw(15) << sem1[i] << endl;
	}	 
}
//*******************************
//Viewing Semestervise Courses
//*******************************
void ViewSemesterCourses(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code ,int crdHrs,int semester)											// view semester courses
{
	
	  cout<<setw(16)<<"CourseCode"<<setw(50)<<"CourseName"<<setw(15)<<"CreditHours"<<endl;
	  for(int i=0 ;i<count;i++)
	  {
	  		if(semester==sem1[i])
	     {
		  cout<<setw(16)<<code1[i]<<setw(50)<<name1[i]<<setw(15)<<crdHrs1[i]<<endl;
	      }
      }
}
//*****************************************
//Finding Index of the given Course_code
//**************************************
int CourseIndex(string course_code,string code1[])
{
	 int newcode;
	 for(int i=0;i<100;i++)
	  {
		if(code1[i]==course_code)
		newcode=i;
		break;
	  }
	  return newcode;
}
//************
// updation
//************
void UpdateCourse(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,char course_code[])
{
	
	cout<<"Enter the new  details  of  the course :";
	cin>>code>>crdHrs>>sem;
	getline(cin,name);
	if(IsValidSemester(sem) == 1 && IsValidCourseCodeL(code) == 1 && IsValidCreditHours(crdHrs)==1 && IsValidCourseName(name)==1 && IsValidCourseCodeN(code)==1)
    {
	
		code1[counter] = code; 
			name1[counter]=name;
			crdHrs1[counter]=crdHrs;
			sem1[counter]=sem;
	        cout<<"Course has been edited succesfully :\n";		
	
    }
    else
    cout<<" Course not found : \n";

	
}
//**********
// deletion
//**********
void DeleteCourse(string name1[],string code1[],int crdHrs1[],int sem1[],string name,string code,int crdHrs,int sem,char course_code[])
{
		int f=-1;
		
		int f_Index;
		bool isValid=false;
		cout<<"Enter course code: ";
		cin>>code;
		cin.clear();
				
			for(int i=0 ; i<n ; i++)
			{
				if(code1[i]==code) 
				{
					isValid=true;
					f_Index=i;
				}
			}
			for(int i=f_Index; i<n; i++) 
			{
				code1[i]=code1[i+1];
				name1[i]=name[i+1];
				crdHrs1[i]=crdHrs1[i+1];
				sem1[i]=sem1[i+1];		
			}
			 cout<<"Course has been deleted successfully!\n" << n;
			 count--;
		}
//**************
//load courses
//************
void loadCourses(string name1[],string code1[],int crdHrs1[],int sem1[])
{
	ifstream input;
	input.open("Courses.txt");
    string N,Crd,S,C,line;
    int c1,s1;
    int s=0;
    while(getline(input,line))
    {
	  stringstream ss(line);
	  getline(ss,C,',');
	  getline(ss,N,',');
	  getline(ss,Crd,',');
	  c1=str_int(Crd);
	  getline(ss,S,',');
	   s1=str_int(S);
		code1[s]=C;
		name1[s]=N;
		crdHrs1[s]=c1;
		sem1[s]=s1;
		s++;	
    }
      input.close();
}
//**************
//Save courses
//**************
void saveCourses(string nM[], string c[],int crd[],int s[])
{
	ofstream output;
	output.open("Courses.txt" ,ios :: app);
	for(int i=0;i<n;i++)
    {
		output<<c[i];
		output<<",";
		output<<nM[i];
		output<<",";
		output<<crd[i];
		output<<",";
		output<<s[i];
		output<<"\n";
		
	}
	output.close();
}
//******************************
//string to integer conversion
//******************************
int str_int(string str)
{
	int n=0;
	int size=str.size();
	for(int i=0; i<size;i++)
	{
		n+=(str[--size]-'0')*pow(10,i);
	}
	return n;
}
//********************************
//Loading Usernames and Passwords
//********************************
bool loadUsers( string Userlist[],string Passwordlist[])
{
	 int x=0;
	 string U_N,Pa,U,P,line;
	 ifstream get;
	 get.open("Users.txt");
	 while(getline(get,line))
   {
	stringstream ss(line);
	getline(ss,U,',');
	getline(ss,P,'\n');
	Userlist[x]=U;
	Passwordlist[x]=P;	
	x++;
   }
		cout<<"Dear User,current software is intended for authorized users only"<<endl<<" Login to the system to get access"<<endl;
	    cout<<" Username : ";
	    cin>>U_N;
	    cout<<endl<<" Password : ";
	    cin>>Pa;
	
       get.close();	
	   bool flag;
	  for(int i=0;i<x;i++)
	  {
	    if(Userlist[i] ==U_N&&Passwordlist[i] ==Pa)
	     {
		   flag=true;
		
	    }
	    else
	    flag=false;
	
      }
       return flag;
}
//***********************
//Valid Registration No
//**********************

bool ValidRegNo( char RegNo[] ) 
{
	bool flag=false;
	int size=12;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<4;j++)
		if(RegNo[j]>='0'&& RegNo[j]<='9')
		{
		
          for(int  k=6;k<8;k++)
		
			if(RegNo[k]>='A'&& RegNo[k]<='Z')
			
		    for(int z=9;z<11;z++)
              if(RegNo[z]>='0'&& RegNo[z]<='9')
		      flag=true;
		}
		
	}
	return flag;
}
//****************
//Adding students
//***************
void addStudent(string stdNameList[],string stdRegNoList[],string stdname,char RegNo[])
{
  
	 static int c=0;
		if( IsValidStdName( stdname))
		{
		  if(ValidRegNo( RegNo ))
		    {
		     stdNameList[c]=stdname;
		      stdRegNoList[c]=RegNo;
		      c++;
		      COUNT=c;
			  cout<<" Student has been added succesfully  "<<endl<<endl;	
		    }
		 else
			cout<<" Invalid Registeration number "<<endl;
				
		}
		else
		cout<<" Invalid student name "<<endl;
	}
	
//********************	
//valid student name
//*******************	
bool IsValidStdName(string stdname)																														// valid Course name
	{
		int counter=0, emptyness=0;
		bool flag=false;
	
		{
		
			for(int i=0; i<stdname.size() ; i++)
			{
				if(isalpha(stdname[i]) || isspace(stdname[i])!=0)
				{
					counter+=1;
					if(isspace(stdname[i])!=0)
					{
						 emptyness++;
					}
				
				}
			}
		
	}
		if(stdname.size()==counter && emptyness!=counter)
		{
			flag=true;
		}
			return flag;
	}
//*****************	
//Updating students
//*****************	
void updateStudent(string stdNameList[],string stdRegNoList[],string stdName,char RegNo[])
{
		int index=RegIndex(stdRegNoList , RegNo);
		 int c=index;
	cout<<"Enter the new  details  of  the students  Reg No and student name:"<<endl<<endl;
	cin>>RegNo;
	getline(cin,stdName);
	
		if( IsValidStdName( stdName))
		{
		   if(ValidRegNo( RegNo ))
		       {
			
	             stdNameList[c]=stdName;
		          stdRegNoList[c]=RegNo;
		           	
		}
		
	
	
	        cout<<"Student has been edited succesfully :\n\n";		
	
          }
        else
        cout<<" student  not found : \n\n";
}
//****************************
//finding Registration Number
//****************************
int RegIndex(string stdRegNoList[],char RegNo[])
{
	 int newRegNo;
	for(int i=0;i<100;i++)
	  {
		if(stdRegNoList[i]==RegNo)
		newRegNo=i;
		break;
	}
	  return newRegNo;

}
//*******************
//Deleting Students
//******************
void deleteStudent(string stdNameList[],string stdRegNoList[],string stdName, char RegNo[])
{


int i=0;
while(stdRegNoList[i]!=" ")
       {
		int index=RegIndex(stdRegNoList , RegNo);
	   count++;
	    for(;i<COUNT;i++)
	   {

	    stdRegNoList[index] = stdRegNoList[index+1]; 
		stdNameList[index]=stdNameList[index+1];
		cout<<" Student has been deleted succesfully "<<endl<<endl;
		
				
	   }
		stdRegNoList[COUNT] = " " ;
	   stdNameList [COUNT] = " " ;
	    COUNT--;
	
       }
}
//*******************************************
//Checking existence of registeration number
//*****************************************
bool checkReg(string RegNoList[],char RegNo[])
{
	bool flag=false;
	for(int i=0;i<50;i++ )
	{
		if(RegNoList[i]==RegNo)
		flag=true;
	}
	return flag;
}
//*********************
//Registering Courses
//********************
void RegisterCourses(string stdRegNoList[],string stdCourseList[][50], char course_code[],char RegNo[], string code1[])
{        
        int index=RegIndex(stdRegNoList , RegNo);
 		if(checkReg( stdRegNoList , RegNo))
        {
           if(ValidRegNo(  RegNo ))
		   {
		   	
		      if(IsValidCourseCodeL(course_code)&&IsValidCourseCodeN(course_code))
		       {
		         for(int i=0;i<50;i++)
		          {
			         if(stdCourseList[index][i]=="\0")
			         {  
			             
				         stdCourseList[index][i]= course_code;
				         cout << endl << "Course has been registered successfully...."<< endl ;
				        //cout << stdCourseList[index][i] << endl;
			         }
			         
		          }
		       }
                 else
                 {
       	        cout<<"Invalid Course code"<<endl;
	            }
	       }
	        else
           {
       	     cout<<"Invalid RegNo"<<endl;
	       }
	    }
	   else
	   {
	   	cout<<"course not found "<<endl;
	   }
              
			
}

//**************************
//Unregistering the courses
//*************************
void UnRegisterCourses(string stdRegNoList[],string stdCourseList[][50], char course_code[],char RegNo[],string code1[])
{    int Nreg=0;   
     if(checkReg( stdRegNoList , RegNo))
        {

           if(ValidRegNo(  RegNo ))
		   {
		      if(IsValidCourseCodeL(course_code)&&IsValidCourseCodeN(course_code))
		       {
					     
		          int index=RegIndex(stdRegNoList , RegNo);
		          int Nreg=0;
			       for(int i=0;i<50;i++)
		           {
			         if(stdCourseList[index][i]==course_code)
			         {
				         Nreg=i;

				         break;
                     }
                   }
               }
                 else
                 {
       	        cout<<"Invalid Course code"<<endl;
	            }
	       }
	        else
           {
       	     cout<<"Invalid RegNo"<<endl;
	       }
	    }
	   else
	   {
	   	cout<<"course not found "<<endl;
	   }
       while(stdCourseList[index][Nreg+1]!="\0")
     {
	  stdCourseList[index][Nreg]=stdCourseList[index][Nreg];
	   Nreg++;
     }

}
//****************
//viewing students
//****************
void view_Std(string RegNoList[],string stdNameList[] )
{
	cout << right << setw(25)<<  "Name" << right << setw(20) << "Reg. No. "<< endl;
	for(int i=0;i<COUNT; i++)
	{
		cout << right << setw(25) << stdNameList[i] << right << setw(25) << RegNoList[i] << endl;
	}
}
//*******************************
// Saving Student's information
//********************************
void saveStudents(string stdRegNoList [],string stdCourseList[][50],string stdNameList[])
{
	ofstream output("Student.txt",ios::app);
	for(int i=0;i<COUNT;i++)
	{
		output<<stdRegNoList[i];
		output<<",";
		output<< stdNameList[i];
		output<<endl;
		for(int j=0; j<COUNT; j++)
		{
			if(stdCourseList[i][j]!="\0")
			{
				output << stdCourseList[i][j]<<",";
		    }
		}
			output<<endl;
	}
		output.close();
	
}
//*******************************
//loading student's information
//*******************************
void loadStudents(string stdRegNoList [],string stdCourseList[][50],string stdNameList[])
{
	ifstream outFile("Student.txt");
	string line1 , line2 ;
	string N;
	string R;
	string C;
	int n=0 ; int i=0;
	    while(getline(outFile , line1))   
	    {
	    	stringstream ss (line1);
	    	getline( ss ,  R , ',');
	    	getline( ss , N ,',' );
	    			stdNameList[n]=N;
	    			stdRegNoList[n]= R;
	    	//cout << endl << stdNameList[n] << " ," << stdRegNoList[n] ;
	    	getline(outFile , line2);
	    	stringstream ss2(line2);
	    	for(int k=0; k<5 ; k++)
	    	{
	    		getline(ss2 , C ,',');
	    		stdCourseList[n][i]=C;
	    		//  cout << endl << stdCourseList[n][i] << " ";
	    		  i++;
			}
			  n++;
		}
		outFile.close();
	
}
