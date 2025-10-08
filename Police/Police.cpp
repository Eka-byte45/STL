#include<iostream>
#include<map>
#include<list>
#include<string>
//#include<vector>
#include<fstream>
#include<sstream>

using std::cout;
using std::cin;
using std::endl;
#define delimetr "\n------------------------------------\n"
//Общее правонарушение
const std::map<int, std::string> VIOLATIONS =
{
	{0,"N/A"},
	{1,"Парковка в неположеном месте"},
	{2,"Непристегнутый ремень безопасности"},
	{3,"Пересечение сплошной"},
	{4,"Превышение скорости"},
	{5,"Проезд на красный"},
	{6,"Выезд на встречную полосу"},
	{7,"Езда в нетрезвом состоянии"},
	{8,"Оскорбление офицера"},
};
//Конкретное правонарушение
class Crime
{
	int violation;
	std::string place;
public:
	int get_violation()const
	{
		return violation;
	}

	const std::string& get_place()const
	{
		return place;
	}

	void set_violation(int violation)
	{
		this->violation = violation;
	}

	void set_place(const std::string& place)
	{
		this->place = place;

	}

	Crime(int violation, const std::string& place)
	{
		set_violation(violation);
		set_place(place);
	}

};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(44);
	os << std::left;
	return os << VIOLATIONS.at(obj.get_violation()) << "\t" << obj.get_place();
}
std::ofstream& operator <<(std::ofstream& ofs, const Crime& obj)
{
	 ofs << obj.get_violation() << " " << obj.get_place();
	 return ofs;
}
std::stringstream& operator>>(std::stringstream& ifs, Crime& obj)
{
	int violation;
	ifs >> violation;
	std::string place;
	std::getline(ifs, place);
	obj.set_violation(violation);
	obj.set_place(place);
	return ifs;

}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << "\t" << *violation << endl;
		}
		cout << delimetr << endl;
	}

}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		fout << plate->first << ":";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << *violation <<",";
		}
		fout << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
		
}
std::map<std::string, std::list<Crime>>load(const std::string& filename)
{
	std::map<std::string, std::list<Crime>> base;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			std::getline(fin, licence_plate,':');
			cout << licence_plate << "\t";
			const int SIZE = 1024 * 500;
			char all_crimes[SIZE];
			fin.getline(all_crimes,SIZE);
			cout << all_crimes << endl;
			const char delimetrs[] = ",";
			for (char* pch = strtok(all_crimes, delimetrs); pch; pch = strtok(NULL, delimetrs))
			{
				Crime crime(0,"");
				std::stringstream stream(pch);
				stream >> crime;
				base[licence_plate].push_back(crime);
			}
		}
	
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
		
	fin.close();
	return base;
}

void read(const std::string& filename)
{
	std::ifstream fine(filename);
	if (!fine.is_open())
	{
		std::cerr<<"Ошибка открытия файла."<<std::endl;
		return;
	}
	std::string str;
	while(!fine.eof())
	{
		str = "";
		getline(fine, str);
		cout << str << endl;
	}
	fine.close();
	return;
}

//#define HOME_WORK
//#define INIT_BASE
void main()
{
	system("chcp 1251> NUL");

#ifdef HOME_WORK
	//std::map<std::string, std::vector<std::string>> DataBase = 
//{
//	{"А123АА77",{"Превышение разрешённого ограничения скорости более чем на 20 км/ч","Стоянка в местах, запрещённых правилами дорожного движения ","Игнорирование сигналов светофоров или регулировщика"}},
//	{"А100BB33",{"Нарушение порядка парковки","Неправильный проезд регулируемого или нерегулируемого перекрестка"}},
//	{"А444АА74",{"Проезд железнодорожного переезда при закрытом шлагбауме или сигнале запрета"}},
//	{"А014АА30",{"Обгон в зонах запрещающих знаков или дорожной разметки"}},
//};

//std::string CarNumber;
//std::string ViolationDescription;

//cout << "Введите регистрационный номер автомобиля: "; cin >> CarNumber;
//cout << "Введите описание правонарушения: "; 
//std::cin.ignore();
//std::getline(cin, ViolationDescription);
////Добавление в базу данных нового правонарушителя или же добавление к существующему
//std::map<std::string, std::vector<std::string>>::iterator it;
//it = DataBase.find(CarNumber);

//if (it != DataBase.end())
//{
//	it->second.push_back(ViolationDescription);
//}
//else
//{
//	DataBase[CarNumber] = { ViolationDescription };
//}


//////Печать всей базы
//for (std::map<std::string, std::vector<std::string>>::iterator entry = DataBase.begin(); entry != DataBase.end(); ++entry)
//{
//	cout << "Автомобиль №: " << entry->first << endl;
//	for (std::vector<std::string> ::iterator violation = entry->second.begin(); violation != entry->second.end(); ++violation)
//	{
//		cout << "Нарушение: " << *violation << endl;
//	}
//	cout << endl;
//}
//
////Печать данных по заданному номеру 
//cout << "Введите номер машины: "; cin >> CarNumber;

//std::map<std::string, std::vector<std::string>>::iterator it;
//it = DataBase.find(CarNumber);
//if (it != DataBase.end())
//{
//	std::cout << "Автомобиль №: " << it->first << endl;
//	for (const std::string &violation : it->second)
//	{
//		cout << "Нарушение: " << violation << endl;
//	}
//	cout << endl;
//}
//else
//{
//	cout << "Автомобиль с номером " << CarNumber << " не найден в базе данных." << endl;
//}
//
////Печать данных по диапазону номеров
//std::string Start;
//std::string End;
//std::map<std::string, std::vector<std::string>>::iterator LowerBoundIterator;
//std::map<std::string, std::vector<std::string>>::iterator UpperBoundIterator;

//cout << "Введите начало диапазона: ";
//std::cin.ignore();
//std::getline(cin,Start);

//cout << "Введите конец диапазона: ";
//std::getline(cin,End);

//LowerBoundIterator = DataBase.lower_bound(Start);
//UpperBoundIterator = DataBase.upper_bound(End);

//for (std::map<std::string, std::vector<std::string>>::iterator it = LowerBoundIterator; it != UpperBoundIterator; ++it)
//{
//	cout << "Автомобиль №: " << it->first << endl;
//	for (const std::string& violation : it->second)
//	{
//		cout << "Нарушение: " << violation << endl;
//	}
//	cout << endl;
//}

////Запись информации в файл
//std::string filename;
//cout << "Введите имя файла: ";
//
//std::getline(cin, filename);
//std::cin.ignore();
//std::ofstream file(filename);
//if (!file.is_open())
//{
//	std::cerr<<"Ошибка открытия файла для записи"<<endl;
//}

//for (std::map<std::string, std::vector<std::string>>::iterator it = DataBase.begin(); it != DataBase.end(); ++it)
//{
//	file << it->first << " ";
//	for (std::vector<std::string>::iterator violation = it->second.begin(); violation != it->second.end(); ++violation)
//	{
//		file << *violation;
//	}
//	file << endl;

//}
//file.close();
//cout << "Данные успешно сохранены в файл!" << filename << endl;  
#endif // HOME_WORK

#ifdef INIT_BASE 
std::map<std::string, std::list<Crime>> base =
{
	{"а777аа",{Crime(4,"ул. Ленина "),Crime(5,"ул. Ленина"),Crime(7,"ул. Энтузиастов"),Crime(8,"ул. Энтузиастов")}},
	{"а123bb",{Crime(2,"ул. Пролетарская "),Crime(3,"ул. Ватутина")}},
	{"а001eg",{Crime(5,"ул. Октябрьская "),Crime(5,"ул. Октябрьская"),Crime(7,"ул. космическая"),Crime(7,"ул. Энтузиастов")}},

};
print(base);
save(base, "base.txt");
//read("base.txt");

#endif // INIT_BASE 

std::map<std::string, std::list<Crime>> base = load("base.txt");
print(base);
	return;
}