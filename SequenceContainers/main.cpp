//SequenceContainers
#include <iostream>
#include <array>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
void vector_info(const std::vector<T>& vec);


//#define STL_ARRAY
#define STL_VECTOR
#define tab "\t"
#define delimiter "\n---------------------------------------------\n"
void main()
{
    system("chcp 1251 > NUL");
    
#ifdef STL_ARRAY
    throw;
    const int n = 5;
    std::array<int,n> arr;
    for (int i = 0; i < arr.size(); ++i)
    {
        //arr[i] = rand() % 100;
        arr.at(i) = rand() % 100;
    }

    try 
    {
        for (int i = 0; i < arr.size() * 2; ++i)
        {
           //cout << arr[i] << tab;
           cout << arr.at(i) << tab;
        }

        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    /*catch (...)
    {
        std::cout << "Error: Something went wrong" << endl;
    }*/
   
    for (int i : arr)
    {
        cout << i << tab;
    }

    cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR


    std::vector<int> vec = {0,1,1,2,3,5,8,13,21,34,55};
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << tab;
    }
    cout << endl;
    vector_info(vec);
    vec.push_back(55);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << tab;
    }
    cout << endl;
    for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << tab;
    }
    cout << endl;
    vector_info(vec);

    //vec.shrink_to_fit();
    //.reserve(1600);
    //vec.push_back(1024);
    //vec.resize(18);
    for (int i : vec)
    {
        cout << i << tab; 
        
    }
    cout << endl;
    vector_info(vec);
    cout << vec.front() << endl;
    cout << vec.back() << endl;

    /////////////////////////////////////////////
    int index;
    int value;
    do
    {
        cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
        cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
    } while (index > vec.capacity());
    
    vec.insert(vec.begin()+index,value);
    for (int i : vec)cout << i << tab; cout << endl;

#endif // STL_VECTOR
  
}

template<typename T>
void vector_info(const std::vector<T>& vec)
{
    cout << "Size:\t" << vec.size() << endl;//фактический размер вектора,показывающий сколько элементов хранит вектор
    cout << "MaxSize:\t" << vec.max_size() << endl;//от типа данных и целевой арх
    cout << "Capacity:\t" << vec.capacity() << endl;//объем зарезервированной пам€ти

    cout << delimiter << endl;



}
