#include<iostream>
#include<cstdio>
using namespace std;

class Student
{
private:
	static int generateRollNo;
	int rollNo;
	string name, dept;
	Student* link;
public:
	Student()
	{
		rollNo = 0;
		link = NULL;
	}
friend class ManageStudent;
};

int Student :: generateRollNo = 1000;

class ManageStudent
{
public:
	int generateRollNo();
	Student* storeStudentDetails(int rno, Student* std);
	void displayStudentDetails(int rno, Student* std);
};

int ManageStudent :: generateRollNo()
{
	Student std;
	std.generateRollNo += 1;
	return std.generateRollNo;
}

Student* ManageStudent :: storeStudentDetails(int rno, Student* std)
{
	Student* newStd = new Student;
	newStd->rollNo = rno;
	cout << "Enter name: " << endl;
	getchar();
	getline(cin, newStd->name);
	cout << "Enter department: " << endl;
	cin >> newStd->dept;
	if(std == NULL)
		std = newStd;
	else
	{
		Student* temp = std;
		while(1)
		{
			if(temp->link == NULL)
			{
				temp->link = newStd;
				break;
			}
			temp = temp->link;
		}
	}
	return std;
}

void ManageStudent :: displayStudentDetails(int rno, Student* std)
{
	if(std != NULL)
	{
		Student* temp = std;
		while(temp != NULL)
		{
			if(rno == temp->rollNo)
			{
				cout << "Roll Number: " << temp->rollNo << endl;
				cout << "Name: " << temp->name << endl;
				cout << "Department: " << temp->dept << endl;
				return;
			}
			temp = temp->link;
		}
	}
	cout << "Student details not found." << endl;
}

//Hash function
int getIndexNumber(int rno)
{
	return (rno%10)-1;
}

int main()
{
	int choice, rno, index;
	Student* std[10] = {NULL};
	ManageStudent mStd;
	do
	{
		cout << "1 -> Store new student details" << endl;
		cout << "2 -> Display student details" << endl;
		cout << "3 -> Update student details" << endl;
		cout << "4 -> Delete student details" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			rno = mStd.generateRollNo();
			index = getIndexNumber(rno);
			std[index] = mStd.storeStudentDetails(rno, std[index]);
			cout << "Student details stored successfully with RollNo: " << rno << endl;
			break;
		case 2:
			cout << "Enter roll number: " << endl;
			cin >> rno;
			index = getIndexNumber(rno);
			mStd.displayStudentDetails(rno, std[index]);
			break;
		case 3:
			cout << "Under construction" << endl;
			break;
		case 4:
			cout << "Under condtruction" << endl;
			break;
		default:
			cout << "Error: Wrong entry. Enter again." << endl;
			break;
		}
		cout << "Press 1 to continue, 0 to exit application." << endl;
		cin >> choice;
	} while(choice != 0);
	getchar();
	return 0;
}
