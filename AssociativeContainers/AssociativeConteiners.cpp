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
		std::pair<int,std::string>(0,"Воскресенье"),
		std::pair<int,std::string>(1,"Понедельник"),
		std::pair<int,std::string>(2,"Вторник"),
		std::pair<int,std::string>(3,"Среда"),
		{4,"Четверг"},
		{5,"Пятница"},
		{5,"Пятница"},
		{5,"Пятница"},
		{5,"Пятница"},
		{5,"Пятница"},
		{6, "Суббота"},
		{7,"Воскресенье"},
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
		{"occasionaly",{"иногда","время от времени","случайно","изредко"}},
		{"causes",{"причина","приводить к..."}},
		{"space",{"космос","пространство","пробел"}},
		{"void",{"пустота","вакуум"}},
		{"sequence",{"последовательность","ряд","эпизод","череда"}},
		{"consequence",{"следствие","последствие","вывод"}},
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