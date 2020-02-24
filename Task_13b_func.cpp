#include"Task_13b_string_New.h"

const string Node::my_name[]{	//определение статического поля

		"Name_A", "Name_B", "Name_C", "Name_D", "Name_E", "Name_F",
		"Name_G", "Name_H", "Name_I", "Name_J", "Name_K", "Name_L"
};

const string Node::Get_name_rand(const unsigned int i)
{
	if (i < size(my_name) && i >= 0)
		return my_name[i];
	else return my_name[0];
}


bool input_text(string file_name, list<Node*>& _my_List)	//связываем поток с файлом и читаем
{
	ifstream fin;
	fin.open(file_name, ios_base::in);			//режим открытия файла-по умолчанию
	if (!fin.is_open())
	{
#ifdef DEBUG
		cerr << "Can not open file: " << file_name << endl;
#endif // DEBUG
		fin.close();
		return false;
	}
	else
	{
		while (1)
		{
			Node* pnt = new Node();
			fin >> pnt;
			if (fin.fail() || fin.eof()) break;
			_my_List.emplace_front(pnt);
		}
	}
	fin.close();
	return list_size(_my_List);
}

bool list_size(const list<Node*>& _my_List)
{
	if (!_my_List.empty())
	{
		cout << "Прочитано: " << _my_List.size() << " записей." << endl;
		return true;
	}
	else
	{
		cerr << "Empty List" << endl;
		return false;
	}
}


bool RandomCase(string file_name)
{				
	int numb;
#ifdef DEBUG
	cout << "Для заполнения файл исходными данными введите число элементов: " << endl;
	cin >> numb;
	cin.get();
#else
	numb = 5000;
#endif // !DEBUG

	ofstream fout;
	fout.open(file_name, ios_base::out | ios_base::trunc);

	const unsigned int min_price = 100;	const unsigned int max_price = 1000;
	const unsigned int min_duty = 10;	const unsigned int max_duty = 80;

	if (!fout.is_open())
	{
		cerr << "\tFile not created: " << file_name << endl;
		fout.close();
		return false;
	}
	else {
		srand(static_cast <unsigned int> (time(NULL)));		// Инициализация генератора случайных чисел
		
		Node* my_buf = new Node();
		for (int i = 0; i < numb; i++)
		{
			my_buf->Set_name(my_buf->Get_name_rand(rand() % 12));
			my_buf->Price = min_price + rand() % (max_price - min_price);
			my_buf->Duty = min_duty + rand() % (max_duty - min_duty);
	
			fout << my_buf;
		}
		delete my_buf;
	}
	fout.close();
	return true;
}

void process_cmp(list<Node*>& _my_List)	//суммирую повторы
{
	iT End = _my_List.end();

	for (iT Start = _my_List.begin(); Start != End; Start++)
	{
		iT Start2 = ++iT(Start);
		while (Start2 != End)
		{
			if ((*Start)->Name == (*Start2)->Name)
			{
				(*Start)->Price += (*Start2)->Price;
				(*Start)->Duty += (*Start2)->Duty;
				delete (*Start2);
				Start2 = _my_List.erase(Start2);
			}
			else ++Start2;
			//if (Start2 == End) break;
		}
	}
}

void list_c_print(list<Node*>& _my_List, string str)
{
	cout << " " << str << endl;
	if (list_size(_my_List))
		for (auto x : _my_List) cout << x;
}

bool list_f_print(const string file_name, const list<Node*>& _my_List, const int _take_duty)
{
	ofstream fout;
	fout.open(file_name, ios_base::out | ios_base::trunc);
	if (!fout.is_open())
	{
		cerr << "File2 opening failed!" << endl;
		return false;
	}
	else
	{
		fout << "Befor std::list::sort():\n" << endl;
		fout << "Name:\t\tPrice_with_duty: " << endl;
		for (auto x : _my_List)
			if (x->Duty > _take_duty)
			{
				fout << x->Name << "\t\t" << x->Price*x->Duty << endl;
			}
		/*for (iT Start = my_List.begin(); Start != my_List.end(); Start++)
		{
			fout << *Start << endl;
		}*/
	} 	 
	fout.close();
	return true;
}


bool comp_sort(const Node* x, const Node* y)	//предикат для std::list::sort()
{
	return (x->Name < y->Name);	// лексикографическая проверка
}

void del_list(list<Node*>& _my_List)
{
	for (auto x : _my_List)
		delete x;
	_my_List.clear();
}


ostream& operator<<(ostream& os, const Node* _node)
{
	os << _node->Name << "\t" << _node->Duty << "\t" << _node->Price << endl;
	return os;
}
istream& operator>>(istream& is, Node* _node)
{
	is >> _node->Name >> _node->Duty >> _node->Price;
	return is;
}
