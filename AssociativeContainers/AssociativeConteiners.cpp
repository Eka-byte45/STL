#include<iostream>
#include<map>
#include<list>
using  std::cin;
using  std::cout;
using  std::endl;
#define STL_MAP
#define tab "\t"
#define delimetr "\n-------------------------------------\n"
void main()
{
	system("chcp 1251 > NUL");

#ifdef  STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int,std::string>(0,"�����������"),
		std::pair<int,std::string>(1,"�����������"),
		std::pair<int,std::string>(2,"�������"),
		std::pair<int,std::string>(3,"�����"),
		{4,"�������"},
		{5,"�������"},
		{5,"�������"},
		{5,"�������"},
		{5,"�������"},
		{5,"�������"},
		{6, "�������"},
		{7,"�����������"},
	};
	for (std::map <int, std::string > :: iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << delimetr << endl;
	for (std::pair<int, std::string>i : week)
	{
		cout << i.first << tab << i.second << endl;
	}
	cout << delimetr << endl;

	std::map<std::string, std::list<std::string>>dictionary =
	{
		{"occasionaly",{"������","����� �� �������","��������","�������"}},
		{"causes",{"�������","��������� �..."}},
		{"space",{"������","������������","������"}},
		{"void",{"�������","������"}},
		{"sequence",{"������������������","���","������","������"}},
		{"consequence",{"���������","�����������","�����"}},
	};
	for (std::map<std::string,std::list<std::string>>::iterator it= dictionary.begin();it!=dictionary.end();++it)
	{
		cout << (*it).first << ": ";
		/*for (const std::string& item : (*it).second)
		{

			cout << item << ", ";

		}*/
		for (std::list<std::string>::iterator violation = it->second.begin(); violation != it->second.end(); ++violation)
		{
			cout << *violation<<" ";
		}

		cout << endl;
	} 




#endif //  STL_MAP

}