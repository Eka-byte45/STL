
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

class PoliceDataBase
{
	class ReceiptViolations
	{

	};


	


};

void main()
{
	system("chcp 1251> NUL");

	std::map<std::string, std::vector<std::string>> DataBase = 
	{
		{"А123АА77",{"Превышение разрешённого ограничения скорости более чем на 20 км/ч","Стоянка в местах, запрещённых правилами дорожного движения ","Игнорирование сигналов светофоров или регулировщика"}},
		{"А100BB33",{"Нарушение порядка парковки","Неправильный проезд регулируемого или нерегулируемого перекрестка"}},
		{"А444АА74",{"Проезд железнодорожного переезда при закрытом шлагбауме или сигнале запрета"}},
		{"А014АА30",{"Обгон в зонах запрещающих знаков или дорожной разметки"}},
	};

	std::string CarNumber;
	std::string ViolationDescription;

	cout << "Введите регистрационный номер автомобиля: "; cin >> CarNumber;
	cout << "Введите описание правонарушения: "; 
	std::cin.ignore();
	std::getline(cin, ViolationDescription);
	//Добавление в базу данных нового правонарушителя или же добавление к существующему
	std::map<std::string, std::vector<std::string>>::iterator it;
	it = DataBase.find(CarNumber);

	if (it != DataBase.end())
	{
		it->second.push_back(ViolationDescription);
	}
	else
	{
		DataBase[CarNumber] = { ViolationDescription };
	}


	////Печать всей базы
	for (std::map<std::string, std::vector<std::string>>::iterator entry = DataBase.begin(); entry != DataBase.end(); ++entry)
	{
		cout << "Автомобиль №: " << entry->first << endl;
		for (std::vector<std::string> ::iterator violation = entry->second.begin(); violation != entry->second.end(); ++violation)
		{
			cout << "Нарушение: " << *violation << endl;
		}
		cout << endl;
	}
	
	//Печать данных по заданному номеру 
	cout << "Введите номер машины: "; cin >> CarNumber;

	std::map<std::string, std::vector<std::string>>::iterator it;
	it = DataBase.find(CarNumber);
	if (it != DataBase.end())
	{
		std::cout << "Автомобиль №: " << it->first << endl;
		for (const std::string &violation : it->second)
		{
			cout << "Нарушение: " << violation << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Автомобиль с номером " << CarNumber << " не найден в базе данных." << endl;
	}
	
	//Печать данных по диапазону номеров
	std::string Start;
	std::string End;
	std::map<std::string, std::vector<std::string>>::iterator LowerBoundIterator;
	std::map<std::string, std::vector<std::string>>::iterator UpperBoundIterator;

	cout << "Введите начало диапазона: ";
	std::cin.ignore();
	std::getline(cin,Start);

	cout << "Введите конец диапазона: ";
	std::getline(cin,End);

	LowerBoundIterator = DataBase.lower_bound(Start);
	UpperBoundIterator = DataBase.upper_bound(End);

	for (std::map<std::string, std::vector<std::string>>::iterator it = LowerBoundIterator; it != UpperBoundIterator; ++it)
	{
		cout << "Автомобиль №: " << it->first << endl;
		for (const std::string& violation : it->second)
		{
			cout << "Нарушение: " << violation << endl;
		}
		cout << endl;
	}

	//Запись информации в файл
	std::string filename;
	cout << "Введите имя файла: ";
	
	std::getline(cin, filename);
	std::cin.ignore();
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr<<"Ошибка открытия файла для записи"<<endl;
	}

	for (std::map<std::string, std::vector<std::string>>::iterator it = DataBase.begin(); it != DataBase.end(); ++it)
	{
		file << it->first << " ";
		for (std::vector<std::string>::iterator violation = it->second.begin(); violation != it->second.end(); ++violation)
		{
			file << *violation;
		}
		file << endl;

	}
	file.close();
	cout << "Данные успешно сохранены в файл!" << filename << endl;

	return;
}