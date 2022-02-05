#include<iostream>
#include <fstream>
#include<cstring>
#include"graphics.h"
#include"winbgi.h"
#include"dibutil.h"
#include"winbgim.h"
#include"winbgitypes.h"
#include"winbgi.h"
#include"dibapi.h"
using namespace std;
class Person
{
protected:
	char* name;
	char* age;
	char* gender;
public:
	Person()
	{
		name = nullptr;
		age = nullptr;
		gender = '\0';
	}
	Person(char* a, char* b, char* c)
	{
		set(a, b, c);
	}
	virtual void input()
	{
		char* a = new char[50];
		char* b = new char[3];
		char* c = new char;
		cout << "Enter name of person\n";
		cin.ignore();
		cin.getline(a, 50);
		cout << "Enter age of person\n";
		cin >> b;
		cout << "Enter gender of person\n";
		cin >> c;
		set(a, b, c);
		delete[]a;
	}
	void set(char* a, char* b, char* c)
	{
		int size = strlen(a);
		name = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
			name[i] = a[i];
		name[i] = '\0';
		age = b;
		gender = c;
	}
	virtual void print() = 0;
	virtual void fileinput(ifstream& fin)
	{
		char* a = new char[50];
		char* b=new char[3];
		char* c = new char;
		fin >> a;
		fin >> b;
		fin >> c;
		set(a, b, c);
	}

};
class Adult : public Person
{
private:
	char* Occupation;
	char* Qualification;
	char* NIC;
public:
	Adult()
	{
		Occupation = nullptr;
		Qualification = nullptr;
		NIC = nullptr;
	}
	Adult(char* a, char* b, char* c, char* d, char* e, char* f) :Person(a, b, c)
	{
		set(d, e, f);
	}
	void input() override
	{
		Person::input();
		char* a = new char[50];
		char* b = new char[50];
		char* c = new char[50];
		cout << "Enter Occupation of Adult\n";
		cin >> a;
		cout << "Enter Qualification of Adult\n";
		cin >> b;
		cout << "Enter NIC of Adult\n";
		cin >> c;
		set(a, b, c);
		delete[]a;
		delete[]b;
		delete[]c;
	}
	void set(char* a, char* b, char* c)
	{
		int i, j, k;
		int size1 = strlen(a);
		int size2 = strlen(b);
		int size3 = strlen(c);
		Occupation = new char[size1 + 1];
		Qualification = new char[size2 + 1];
		NIC = new char[size3 + 1];
		for (i = 0; i < size1; i++)
			Occupation[i] = a[i];
		Occupation[i] = '\0';
		for (j = 0; j < size2; j++)
			Qualification[j] = b[j];
		Qualification[j] = '\0';
		for (k = 0; k < size3; k++)
			NIC[k] = c[k];
		NIC[k] = '\0';
	}
	void print() override
	{
		readimagefile("bogiee.jpg", 100, 100, 600, 600);
		outtextxy(110, 190, "Name of Adult: ");
		outtextxy(220, 190, name);
		outtextxy(110, 250, "Age of Adult: ");
		outtextxy(210, 250, age);
		outtextxy(110, 320, "Gender of Adult: ");
		outtextxy(220, 320, gender);
		outtextxy(110, 390, "Occupation of Adult: ");
		outtextxy(250, 390, Occupation);
		outtextxy(110, 460, "Qualification of Adult: ");
		outtextxy(260, 460, Qualification);
		outtextxy(110, 530, "NIC of Adult: ");
		outtextxy(210, 530, NIC);
	}
	void fileinput(ifstream& fin)
	{
		Person::fileinput(fin);
		char* a = new char[50];
		char* b = new char[50];
		char* c = new char[50];
		fin >> a;
		fin >> b;
		fin >> c;
		set(a, b, c);
	}
};
class kid :public Person
{
private:
	char* B_form_number;
public:
	kid()
	{
		B_form_number = nullptr;
	}
	kid(char* a, char* b, char* c, char* d) :Person(a, b, c)
	{
		set(d);
	}
	void input() override
	{
		Person::input();
		cout << "Enter B form number of kid\n";
		char* a = new char[50];
		cin >> a;
		set(a);
		delete[]a;
	}
	void set(char* a)
	{
		int size = strlen(a);
		B_form_number = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
			B_form_number[i] = a[i];
		B_form_number[i] = '\0';
	}
	void print() override
	{
		readimagefile("bogiee.jpg", 100, 100, 600, 600);
		outtextxy(110, 190, "Name of kid: ");
		outtextxy(220, 190, name);
		outtextxy(110, 250, "Age of kid: ");
		outtextxy(210, 250, age);
		outtextxy(110, 320, "Gender of kid: ");
		outtextxy(220, 320, gender);
		outtextxy(110, 390, "B Form of kid: ");
		outtextxy(210, 390, B_form_number);
	}
	void fileinput(ifstream& fin)
	{
		Person::fileinput(fin);
		char* a = new char[50];
		fin >> a;
		set(a);
	}
};
class Bogie
{
private:
	int Bogie_ID;
	Bogie* next;
	Person** people;
	char* familyName;
	int adults;
	int kids;
	bool full;
public:
	Bogie()
	{
		Bogie_ID = 0;
		next = nullptr;
		people = nullptr;
		familyName = nullptr;
		full = false;
		adults = 0;
		kids = 0;
	}
	Bogie(int ID)
	{
		Bogie_ID = ID;
		next = nullptr;
		people = nullptr;
		familyName = nullptr;
		full = false;
		adults = 0;
		kids = 0;
	}
	void AddPassengers()
	{
		int i;
		familyName = new char[50];
		cout << "Enter a Family Name\n";
		cin >> familyName;
		cout << "How many adults you want to add\n";
		cin >> adults;
		while (adults > 4)
		{
			cout << "You cannot add more than 4 adults\n";
			cin >> adults;
		}
		cout << "How many kids you want to add\n";
		cin >> kids;
		while (kids > 6)
		{
			cout << "You cannot add more than 6 kids\n";
			cin >> kids;
		}
		int total = adults + kids;
		people = new Person * [total];
		if (adults > 0)
			cout << "\nEnter data for adults\n\n";
		for (i = 0; i < adults; i++)
		{
			people[i] = new Adult;
			people[i]->input();
		}
		if (kids > 0)
			cout << "\nEnter data for kids\n\n";
		for (; i < total; i++)
		{
			people[i] = new kid;
			people[i]->input();
		}
	}
	void Print()
	{
		if (familyName != nullptr)
		{
			outtextxy(100, 50, "Family Name: ");
			outtextxy(200, 50, familyName);
		}
		else
			outtextxy(100, 50, "No family present: ");
		int total = adults + kids;
		for (int j = 0; j < total + 1; )
		{
			if (j == total)
				break;
			if (ismouseclick(WM_LBUTTONDOWN))
				people[j]->print();
			delay(2000);
			if (GetAsyncKeyState(VK_RIGHT))
			{
				j++;
				delay(100);
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				j--;
				delay(100);
			}
		}
	}
	friend class train;
	void Addfromfile(ifstream &fin)
	{
		int i;
		familyName = new char[50];
		fin >> familyName;
		fin >> adults;
		fin >> kids;
		int total = adults + kids;
		people = new Person * [total];
		for (i = 0; i < adults; i++)
		{
			people[i] = new Adult;
			people[i]->fileinput(fin);
		}
		for (; i < total; i++)
		{
			people[i] = new kid;
			people[i]->fileinput(fin);
		}
	}
	~Bogie()
	{
		Bogie_ID = 0;
		next = nullptr;
		int total = adults + kids;
		for (int i = 0; i < total; i++)
			delete people[i];
		delete[]people;
		people = nullptr;
		delete[]familyName;
		familyName = nullptr;
	}
};
class train
{
private:
	Bogie* engine;
	Bogie* current;
public:
	train()
	{
		engine = nullptr;
		current = nullptr;
	}
	void addBogie(int id)
	{
		Bogie* temp = new Bogie(id);
		if (engine == nullptr)
		{
			engine = temp;
			current = temp;
			current->next = nullptr;
		}
		else
		{
			current->next = temp;
			current = current->next;
			current->next = nullptr;
		}
	}
	void addPassengers(int id)
	{
		Bogie* temp = engine;
		int count = 0;
		while (temp != nullptr)
		{
			if (temp->Bogie_ID == id && temp->full == false)
			{
				temp->AddPassengers();
				temp->full = true;
				count++;
			}
			temp = temp->next;
		}
		if (count == 0)
			cout << "Bogie already full\n";
	}
	void printTrain()
	{
		readimagefile("train2.jpg", 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		char* ans;
		int x1 = 20, y1 = 100, x2 = 300, y2 = 350;
		Bogie* temp = engine;
		int max = total();
		outtextxy(20, 50, "Total bogies added: ");
		outtextxy(160, 50, tochar(max));
		while (temp != nullptr)
		{
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				ans = tochar(temp->Bogie_ID);
				readimagefile("bogiee.jpg", x1, y1, x2, y2);
				settextstyle(COMPLEX_FONT, HORIZ_DIR, 0);
				outtextxy(x1 + 30, y1 + 70, ans);
				x1 = x1 + 300; x2 = x2 + 300;
				if (x1 > GetSystemMetrics(SM_CXSCREEN) || x2 > GetSystemMetrics(SM_CXSCREEN))
				{
					y1 = y1 + 280; y2 = y2 + 280;
					x1 = 20;
					x2 = 300;
				}
				temp = temp->next;
			}
		}
	}
	void printdata(int id)
	{
		Bogie* temp = engine;
		while (temp != nullptr)
		{
			if (temp->Bogie_ID == id)
			{
				readimagefile("train1.jpg", 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
				temp->Print();
			}
			temp = temp->next;
		}
	}
	char* tochar(int x)
	{
		int temp = x;
		int count = 0;
		while (temp != 0)
		{
			count++;
			temp = temp / 10;
		}
		int* result = new int[count + 1];
		for (int i = count - 1; i >= 0; i--)
		{
			result[i] = x % 10;
			x = x / 10;
		}
		char* id = new char[count + 1];
		int j;
		for (j = 0; j < count; j++)
			id[j] = result[j] + 48;
		id[j] = '\0';
		return id;
	}
	bool SearchBogie(int id)
	{
		Bogie* temp = engine;
		while (temp != nullptr)
		{
			if (temp->Bogie_ID == id)
				return true;
			temp = temp->next;
		}
		return false;
	}
	int bogieposition(int id)
	{
		Bogie* temp = engine;
		for (int i = 1; temp != nullptr; i++)
		{
			if (temp->Bogie_ID == id)
				return i;
			temp = temp->next;
		}
		return -1;
	}
	int total()
	{
		int count = 0;
		Bogie* temp = engine;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void removeBogie(int id)
	{
		int n = bogieposition(id);
		int max = total();
		if (n != -1)
		{
			Bogie* temp1 = engine;
			if (n == 1)
			{
				engine = temp1->next;
				delete temp1;
				temp1 = nullptr;
			}
			else if (n == max)
			{
				Bogie* temp = engine;
				while (temp->next->next != nullptr)
				{
					temp = temp->next;
				}
				delete temp->next;
				temp->next = nullptr;
			}
			else
			{
				int i = 1;
				while (i < n - 1)
				{
					temp1 = temp1->next;
					i++;
				}
				Bogie* temp2 = temp1->next;
				temp1->next = temp2->next;
				delete temp2;
				temp2 = nullptr;
			}
		}
		else
			cout << "Bogie not found\n";
	}
	void addfromfile(int id,ifstream &fin)
	{
		Bogie* temp = engine;
		int count = 0;
		while (temp != nullptr)
		{
			if (temp->Bogie_ID == id && temp->full == false)
			{
				temp->Addfromfile(fin);
				temp->full = true;
				count++;
				cout << "Done\n";
			}
			temp = temp->next;
		}
		if (count == 0)
			cout << "Bogie already full\n";
	}
	~train()
	{
		Bogie* temp1 = engine->next;
		while (temp1 != nullptr)
		{
			engine->next = temp1->next;
			temp1->next = nullptr;
			delete temp1;
			temp1 = engine->next;
		}
		delete engine;
		engine = nullptr;
		current = nullptr;
	}
};
int main()
{
	train* station = new train;
	cout << endl << "\t\t\t\t\t\tWelcome to Train Station\n";
	int n = 0;
	bool flag = true;
	int ID;
	int x = 0;
	ifstream fin;
	fin.open("data.txt");
	while (flag == true)
	{
		if (x == 0)
		{
			initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Train Station");
			readimagefile("train.jpg", 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
			n = 0;
		}
		x = 1;
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			flag = false;
			delay(100);
			n = 0;
		}
		else if (GetAsyncKeyState(VK_INSERT))
		{
			n = 1;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_DELETE))
		{
			n = 2;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			n = 3;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			n = 4;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			n = 5;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			n = 6;
			delay(100);
		}
		else if (GetAsyncKeyState(VK_RBUTTON))
		{
			n = 7;
			delay(100);
		}
		if (n == 1)
		{
			closegraph();
			cout << "Enter a bogie ID to add\n";
			cin >> ID;
			if (!station->SearchBogie(ID))
			{
				station->addBogie(ID);
				cout << "Bogie successfully added\n";
			}
			else
				cout << "This bogie ID already exists\n";
			x = 0;
		}
		else if (n == 2)
		{
			closegraph();
			cout << "Enter a bogie ID to remove\n";
			cin >> ID;
			if (station->SearchBogie(ID))
			{
				station->removeBogie(ID);
				cout << "Bogie successfully removed\n";
			}
			else
				cout << "This bogie ID does not exist\n";
			x = 0;
		}
		else if (n == 3)
		{
			closegraph();
			cout << "Enter a bogie ID to search\n";
			cin >> ID;
			initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Train Station");
			readimagefile("train3.jpg", 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 0);
			if (station->SearchBogie(ID))
			{
				outtextxy(100, 100, "This bogie exists");
			}
			else
				outtextxy(100, 100, "This bogie does not exist");
			delay(5000);
			closegraph();
			x = 0;
		}
		else if (n == 4)
		{
			closegraph();
			cout << "Enter a bogie ID to view its data\n";
			cin >> ID;
			if (station->SearchBogie(ID))
			{
				initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Train Station");
				station->printdata(ID);
			}
			else
				cout << "This bogie ID does not exist\n";
			closegraph();
			x = 0;
		}
		else if (n == 5)
		{
			closegraph();
			initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Train Station");
			station->printTrain();
			delay(5000);
			closegraph();
			x = 0;
		}
		else if (n == 6)
		{
			closegraph();
			cout << "Enter a bogie ID to add passengers\n";
			cin >> ID;
			if (station->SearchBogie(ID))
			{
				station->addPassengers(ID);
			}
			else
				cout << "This bogie ID does not exist\n";
			x = 0;
		}
		else if (n == 7)
		{
			closegraph();
			if (fin)
			{
				cout << "Enter a bogie ID to add passengers\n";
				cin >> ID;
				if (station->SearchBogie(ID))
				{
					station->addfromfile(ID, fin);
				}
				else
					cout << "This bogie ID does not exist\n";
			}
			else
				cout << "Input file not found\n";
			x = 0;
		}
	}
	closegraph();
	fin.close();
	cout << "\nThank you for travelling in train\n\n";
	system("pause");
	return 0;
}