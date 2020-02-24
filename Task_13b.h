#pragma once
#include<iostream>
#include <thread>
#include<ctime>
#include<fstream>
#include<list>
#include<string>
//#include <functional>
#define DEBUG	//îïðåäåëÿåò ðåæèì êîìïèëÿöèè êîäà (îòëàäî÷íûé\òèõèé)
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
//	if (this == &_copy)		// ïðîâåðêà íà ñàìîïðèñâàèâàíèå
//		return *this;
//	Name = _copy.Name; Duty = _copy.Duty; Price = _copy.Price;
//	cout << "\tÑðàáîòàë operator=." << endl;
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

bool input_text(string file_name, list<Node*>& _my_List);		//ñ÷èòûâàíèå èç ôàéëà
bool RandomCase(string file_name);								//ñîçäàíèå ôàéëà èñõîäíûõ(óñëîâíî-ñëó÷àéíûõ) çàïèñåé
bool list_size(const list<Node*>& _my_List);					//ïðîâåðêà ðàçìåðíîñòè ëèñòà ñ ïå÷àòüþ
void process_cmp(list<Node*>& _my_List);						//ñóììèðóþ ïîâòîðû
void list_c_print(list<Node*>& _my_List, string str = "\t");	//ïå÷àòü ëèñòà
bool list_f_print(const string file_name,const list<Node*>& _my_List, const int _take_duty);	//âûâîä â ôàéë

bool comp_sort(const Node* x, const Node* y);//ïðåäèêàò äëÿ std::list::sort()  ëåêñèêîãðàôè÷åñêàÿ ïðîâåðêà
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



