#pragma once
#include<iostream>
#include <thread>
#include<ctime>
#include<fstream>
#include<list>
#include<string>
//#include <functional>
#define DEBUG	//���������� ����� ���������� ���� (����������\�����)

using namespace std;

class Node
{
private:
	static const string my_name[];
	
public:
	string Name;
	int Duty;
	int Price;

	Node() : Name("noname"), Duty(0), Price(0) {}
	Node(string _name, int duty, int price) : Name(_name), Duty(duty), Price(price) {}
	
	//Node& operator=(const Node& _copy)
//{
//	if (this == &_copy)		// �������� �� ����������������
//		return *this;
//	Name = _copy.Name; Duty = _copy.Duty; Price = _copy.Price;
//	cout << "\t�������� operator=." << endl;
//	return *this;
//}
	
	const string Get_name_rand(const unsigned int i);
	void Set_name(const string r_name) { Name = r_name; }
	
	friend ostream& operator<<(ostream& os, const Node* _node);
	friend istream& operator>>(istream& is, Node* _node);

	~Node()
	{
#ifdef DEBUG
		//cout << "\tDestructor worked. " << endl;
#endif // DEBUG
	}
};

using iT = std::list<Node*>::iterator;

bool input_text(string file_name, list<Node*>& _my_List);		//���������� �� �����
bool RandomCase(string file_name);								//�������� ����� ��������(�������-���������) �������
bool list_size(const list<Node*>& _my_List);					//�������� ����������� ����� � �������
void process_cmp(list<Node*>& _my_List);						//�������� �������
void list_c_print(list<Node*>& _my_List, string str = "\t");	//������ �����
bool list_f_print(const string file_name,const list<Node*>& _my_List, const int _take_duty);	//����� � ����

bool comp_sort(const Node* x, const Node* y);//�������� ��� std::list::sort()  ������������������ ��������
void del_list(list<Node*>& _my_List);

class SimpleTimer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start;
public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
		std::cout << "Duration: " << duration.count() << " s" << std::endl;
		cin.get();
	}
};



