//SequenceContainers
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
void vector_info(const std::vector<T>& vec);

template<typename T>
void PrintList(const std::list<T>& List);

template <typename T>
void InsertList(std::list<T>& List,int index,const T& value);

template <typename T>
void EraseList(std::list<T>& List, int index);

template<typename T>
void PrintForwardList(const std::forward_list<T>& List);

template<typename T>
void InsertForwardList(std::forward_list<T>& FList, int index,  const T& value);

template<typename T>
void EraseForwardList(std::forward_list<T>& FList,int index);

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_LIST
#define STL_FORWARD_LIST

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
    /*int index;
    int value;
    do
    {
        cout << "������� ������ ������������ ��������: "; cin >> index;
        cout << "������� �������� ������������ ��������: "; cin >> value;
    } while (index > vec.capacity());
    
    vec.insert(vec.begin()+index,value);
    for (int i : vec)cout << i << tab; cout << endl;*/

    cout << endl;

    //�������� �������� �� ���������� �������
    int index;
    cout << "������� ������ ���������� ��������: "; cin >> index;
    vec.erase(vec.begin() + index);
    cout << endl;
    for (int i : vec)
    {
        cout << i << tab;

    }
    cout << endl;
    vector_info(vec);

    //�������� ��������� � �������� ���������
    int index2;
    int index3;
    cout << "������� ������ � ����� ��������� ��� �������� ���������: ";
    cin >> index2 >> index3;
    vec.erase(vec.begin() + index2, vec.begin() + index3);
    cout << endl;
    for (int i : vec)
    {
        cout << i << tab;

    }
    cout << endl;
    vector_info(vec);

#endif // STL_VECTOR

#ifdef STL_LIST

    std::list<int> List = {5,15,23,42,95,17,1};
    PrintList(List);
    int Index;
    int Value;
    cout << endl;
    cout << "������� ������, ���� �������� ����� �������: ";
    cin >> Index;
    cout << "������� �������� ������ ��������: ";
    cin >> Value;
    InsertList(List,Index,Value);
    PrintList(List);
    cout << endl;
    ///////////////////////////////,
    cout << endl;
    std::list<int> List2 = {11,5,99,6,77,18,35,14 };
    PrintList(List2);
    int Index2;
    cout << "\n������� ������ �� �������� �� ������ ������� �������: "; cin >> Index2;
    EraseList(List2, Index2);
    PrintList(List2);

#endif // STL_LIST

#ifdef STL_FORWARD_LIST

    std::forward_list<int> flist = { 5,17,19,71,2,8,5,21 };
    PrintForwardList(flist);
    int Value;
    int Index;
    cout << "������� ������ �������� ���� �� ������ �������� �������: ";
    cin >> Index;
    cout << "������� �������� �������� ��� �������: "; cin >> Value;
    InsertForwardList(flist, Index, Value);
    PrintForwardList(flist);
    ////////////////////////
    cout << endl;
    std::forward_list<int> flist2 = {2,12,42,3,15,18};
    PrintForwardList(flist2);
    int Index2;
    cout << "������� ������ �� ������� �� ������ ������� �������: "; cin >> Index2;
    EraseForwardList(flist2,Index2);
    PrintForwardList(flist2);

#endif // STL_FORWARD_LIST

  
}

template<typename T>
void vector_info(const std::vector<T>& vec)
{
    cout << "Size:\t" << vec.size() << endl;//����������� ������ �������,������������ ������� ��������� ������ ������
    cout << "MaxSize:\t" << vec.max_size() << endl;//�� ���� ������ � ������� ���
    cout << "Capacity:\t" << vec.capacity() << endl;//����� ����������������� ������

}

template<typename T>
void PrintList(const std::list<T>& List)
{

    for (typename std::list<T> ::const_iterator iter = List.begin(); iter != List.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

}

template<typename T>
void InsertList(std::list<T>& List,int index,const T& value)
{
    if (index < 0 || index > List.size())
    {
        std::cerr << "������������ ������� �������." << endl;
        return;
    }
    typename std::list <T>::iterator iter = List.begin();
    std::advance(iter, index);
    List.insert(iter, value);

}

template<typename T>
void EraseList(std::list<T>& List, int index)
{
    if (index < 0 || index > List.size())
    {
        std::cerr<<"������! ������ ��� ����������� ���������"<<endl;
        return;
    }
    std::list <int>::iterator iter = List.begin();
    for (int i = 0; i < index; ++i)
    {
        ++iter;
    }
    List.erase(iter);
}

template<typename T>
void PrintForwardList(const std::forward_list<T>& Flist)
{
    for (const auto& i : Flist)
    {
        cout << i << " ";

    }
    cout << endl;
}

template<typename T>
void InsertForwardList(std::forward_list<T>& FList, int index,const T &value)
{
    int count = 0;
    for (typename std::forward_list <T>::iterator iter = FList.begin(); iter != FList.end(); ++iter)
    {
        ++count;
    }

    if (index < 0 || index > count)
    {
        std::cerr << "������ ��� ���������!" << endl;
        return;
    }
    typename std::forward_list<T>::iterator iter1 = FList.before_begin();
    typename std::forward_list<T>::iterator iter2 = FList.begin();
    for (int i = 0; i < index && iter2 != FList.end(); ++i)
    {
        ++iter2;
        ++iter1;
    }

    FList.insert_after(iter1, value);
}

template<typename T>
void EraseForwardList(std::forward_list<T>& FList, int index)
{
    int count = 0;
    for (typename std::forward_list <T>::iterator iter = FList.begin(); iter != FList.end(); ++iter)
    {
        ++count;
    }

    if (index < 0 || index >= count)
    {
        std::cerr << "������ ��� ���������!" << std::endl;
        return;
    }
    
    typename std::forward_list<T>::iterator before_delete = FList.before_begin();

    for (int i = 0; i < index; ++i)
    {
           
       before_delete++;   
    }

    FList.erase_after(before_delete);
      
}
