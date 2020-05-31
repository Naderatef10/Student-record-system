#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
#define subjects  2
#define totalmark 400
#include <iomanip>
const int FILESIZE=100;
int counterer=10;
using namespace std;
struct carrier{
string namer;
string laster;
int id1;
float marks[subjects];
string cityy;
string district;
int zipcode;
};
class CUFE{
private: string name; string last;
char grade;
int id;
float mark[subjects];
struct address{
string city,residential_area; int zip_code;
}address1;
public:
int compare_string(string targeter){
if(targeter==name){
return 1;}
return 0;
}
int compare_integar(int targeter){
if(id==targeter){
return 1;}
return 0;}
void insert_student();
void modify_student(int choicer);
void read_student(carrier w[]);
void display_student();
void Inserter(carrier &a);
char gradecaluclator();
};
void CUFE::insert_student(){
cout<<"Please enter the name of the student" << endl;
cin >> name;
cout<<"please enter the id of the new student" << endl;
cin >>id;
cout<<"please enter the marks of the student" << endl;
int i;
for(i=0;i<subjects;i++){
cout << "please enter the mark of the subject number:" << i+1 << endl;
cin >> mark[i];
}cout << "please enter the city of the student" << endl;
cin >>address1.city;
cout << "please enter the residental area of the student" << endl;
cin>>address1.residential_area;
cout << "please enter the zipcode of the student" << endl;
cin >> address1.zip_code;
}
int search_number_id(CUFE x[],int target){
int i;
for(i=0;i<counterer;i++){
if(x[i].compare_integar(target))
return i;
}
return -1;
}int search_name_id(CUFE x[],string target){
int i;
for(i=0;i<counterer;i++){
if(x[i].compare_string(target)){
return i;
}
}
return -1;
}void CUFE::modify_student(int choicer){
int i;
if(choicer==1){
for(i=0;i<subjects;i++){
cout << "please enter the new mark of the subject number:"<< i << endl;
cin>>mark[i];
}}
else if(choicer==2){
cout << "please enter the first new name of the student" << endl;
cin >> name;
cout << "please enter the last name of the student" << endl;
}
else if(choicer==3){
cout << "please enter the new id of the student" << endl;
cin >>id;
}
else if(choicer==4){
cout << "please enter the new city of the student" << endl;
cin >>address1.city;
}else if(choicer==5){
cout << "please enter the new residental area of the student" << endl;
cin>>address1.residential_area;
}else if(choicer==6){
cout << "Please enter the new zipcode  of the student" << endl;
cin >>address1.zip_code;
}else if(choicer==7){
for(i=0;i<subjects;i++){
cout << "please enter the new mark of the subject number:"<< i+1 << endl;
cin>>mark[i]; }
cout << "please enter the new first name of the student" << endl;
cin >> name;
cout << "please enter the last name of the student" << endl;
cin >> last;
name=name+" "+last;
cout << "please enter the new id of the student" << endl;
cin >>id;
cout << "please enter the new residental area of the student" << endl;
cin>>address1.residential_area;
cout << "Please enter the zipcode of the area of the student" << endl;
cin >>address1.zip_code;
cout << "please enter the new city of the student" << endl;
cin >>address1.city;
}
}
void CUFE::display_student(){
cout  << "Name is:"<< name << endl;
cout << "Id is"<< id << endl;
cout << "Number of subjects taken in this semster is:"<< subjects << endl;
cout << "The city of the student is:" << address1.city << endl;
cout << "The district of the student is:" << address1.residential_area << endl;
cout << "The zipcode of the district is:" << address1.zip_code << endl;
int k;
for(k=0;k<subjects;k++){
cout << "Your mark in the" << k+1 << "subject is:" << mark[k] << endl;
}
}char CUFE::gradecaluclator(){
float percentage; int i;
float total_student=0;
for(i=0;i<subjects;i++){total_student+=mark[i];}
percentage=(total_student/totalmark)*100;
if(percentage<50){
return 'F';
}
else if(percentage>=50&&percentage<65){
return 'D';
}else if(percentage>=65&&percentage<75){
return 'C';
}else if(percentage>=75&&percentage<85){
return 'B';}
else{
return 'A';
}}
void CUFE::Inserter(carrier &a){
name=a.namer;
last=a.laster;
name=name+" "+last;
id=a.id1;
address1.city=a.cityy;
address1.zip_code=a.zipcode;
address1.residential_area=a.district;
int v;
for(v=0;v<subjects;v++){
mark[v]=a.marks[v];
}
}
void CUFE::read_student(carrier w[])
{ifstream fin; int i;
i=0; int k;
fin.open("monster.txt");
while(fin>>w[i].namer>>w[i].laster&&i<FILESIZE){

fin>>w[i].id1;
for(k=0;k<subjects;k++){
fin>>w[i].marks[k];
}fin>>w[i].cityy>>w[i].district>>w[i].zipcode;
i++;
}
fin.close();
}int main()
{int variable; char w;
string name1;
int searchholder;
int choice;
int j; carrier k[FILESIZE]; CUFE d;
CUFE students[FILESIZE];
d.read_student(k);
for(j=0;j<FILESIZE;j++){
students[j].Inserter(k[j]);
}
cout << "Welcome to Cairo university student recording system" << endl;
cout << "Enter your choice from the following list" << endl;
start:
int menu;
cout << "1-Insert a student into the system" << endl;
cout << "2-Search for a student record" << endl;
cout << "3-Modify student record" << endl;
cout << "4-calculate the total score and get grade of the student" << endl;
cout << "5-Print student information" << endl;
cin >> menu;
switch(menu){
case 1:{
students[counterer].insert_student();
counterer++;}
goto start;
break;
case 2: cout << "1-search by name" << endl;
cout << "2-search by id" << endl;
cin >> choice;
if(choice==1){
cout << "please enter the name of the student" << endl;
cin >> name1;
searchholder=search_name_id(students,name1);
if(searchholder<0){cout <<"the student record is not found"<< endl;
goto start;
}
students[searchholder].display_student();
goto start;
}
else{
cout << "please enter the id of the student" << endl;
cin >> variable;
searchholder=search_number_id(students,variable);
if(searchholder<0){cout <<"the student record is not found"<< endl;
goto start;
}
students[searchholder].display_student();
goto start;
}
break;
case 3:
cout<< "please enter the id of the student" << endl;
cin>>variable;
searchholder=search_number_id(students,variable);
if(searchholder<0){cout <<"the student record is not found"<< endl;
goto start;}
else{
cout <<"Choose from the list below what do you want to edit" << endl;
cout <<"1-edit the marks of the student" << endl;
cout <<"2-edit the name of the student" << endl;
cout <<"3-edit the id of the student" << endl;
cout <<"4-edit the city of the student" << endl;
cout <<"5-edit the residental area of the student" << endl;
cout <<"6-edit the zipcode of the student"<< endl;
cout <<"7-edit all info" << endl;
cin >>choice;
students[searchholder].modify_student(choice);
goto start;
}break;
case 4: cout << "please enter the id of the student " << endl;
cin >> variable;
searchholder=search_number_id(students,variable);
if(searchholder<0){cout <<"the student record is not found"<< endl;
goto start;
}
w=students[searchholder].gradecaluclator();
cout << "congrats your grade is:"<< w << endl;
goto start;
break;
case 5:cout << "please enter the id of the student" << endl;
cin >> variable;
searchholder=search_number_id(students,variable);
if(searchholder<0){cout <<"the student record is not found"<< endl;
goto start;
}
students[searchholder].display_student();
goto start;
break;
}
return 0;
}

