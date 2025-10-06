
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
		{"�123��77",{"���������� ������������ ����������� �������� ����� ��� �� 20 ��/�","������� � ������, ����������� ��������� ��������� �������� ","������������� �������� ���������� ��� �������������"}},
		{"�100BB33",{"��������� ������� ��������","������������ ������ ������������� ��� ��������������� �����������"}},
		{"�444��74",{"������ ���������������� �������� ��� �������� ��������� ��� ������� �������"}},
		{"�014��30",{"����� � ����� ����������� ������ ��� �������� ��������"}},
	};

	std::string CarNumber;
	std::string ViolationDescription;

	cout << "������� ��������������� ����� ����������: "; cin >> CarNumber;
	cout << "������� �������� ��������������: "; 
	std::cin.ignore();
	std::getline(cin, ViolationDescription);
	//���������� � ���� ������ ������ ��������������� ��� �� ���������� � �������������
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


	////������ ���� ����
	for (std::map<std::string, std::vector<std::string>>::iterator entry = DataBase.begin(); entry != DataBase.end(); ++entry)
	{
		cout << "���������� �: " << entry->first << endl;
		for (std::vector<std::string> ::iterator violation = entry->second.begin(); violation != entry->second.end(); ++violation)
		{
			cout << "���������: " << *violation << endl;
		}
		cout << endl;
	}
	
	//������ ������ �� ��������� ������ 
	cout << "������� ����� ������: "; cin >> CarNumber;

	std::map<std::string, std::vector<std::string>>::iterator it;
	it = DataBase.find(CarNumber);
	if (it != DataBase.end())
	{
		std::cout << "���������� �: " << it->first << endl;
		for (const std::string &violation : it->second)
		{
			cout << "���������: " << violation << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "���������� � ������� " << CarNumber << " �� ������ � ���� ������." << endl;
	}
	
	//������ ������ �� ��������� �������
	std::string Start;
	std::string End;
	std::map<std::string, std::vector<std::string>>::iterator LowerBoundIterator;
	std::map<std::string, std::vector<std::string>>::iterator UpperBoundIterator;

	cout << "������� ������ ���������: ";
	std::cin.ignore();
	std::getline(cin,Start);

	cout << "������� ����� ���������: ";
	std::getline(cin,End);

	LowerBoundIterator = DataBase.lower_bound(Start);
	UpperBoundIterator = DataBase.upper_bound(End);

	for (std::map<std::string, std::vector<std::string>>::iterator it = LowerBoundIterator; it != UpperBoundIterator; ++it)
	{
		cout << "���������� �: " << it->first << endl;
		for (const std::string& violation : it->second)
		{
			cout << "���������: " << violation << endl;
		}
		cout << endl;
	}

	//������ ���������� � ����
	std::string filename;
	cout << "������� ��� �����: ";
	
	std::getline(cin, filename);
	std::cin.ignore();
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr<<"������ �������� ����� ��� ������"<<endl;
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
	cout << "������ ������� ��������� � ����!" << filename << endl;

	return;
}