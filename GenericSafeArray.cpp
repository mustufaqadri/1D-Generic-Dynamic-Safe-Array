#include "GenericSafeArray.h"

#include<iostream>
#include<string.h>
using namespace std;

template<class T>
GenericSafeArray<T>::GenericSafeArray()
{
    Size=0;
    Elements=0;
}

template<class T>
GenericSafeArray<T>::GenericSafeArray(T Arr[],T Capacity)
{
    if(Capacity<0)
    {
        cout<<"\n\n*** Invalid Size Give ***";
        exit(0);
    }
    Size=Capacity;
    Elements=new T[Size];
    memcpy(Elements,Arr,sizeof(T) * Size);
}

template<class T>
GenericSafeArray<T>::GenericSafeArray(int Capacity)
{
    if(Capacity<0)
    {
        cout<<"\n\n*** Invalid Size Give ***";
        exit(0);
    }
    Size=Capacity;
    Elements=new T[Size];
    SetData();
}

template<class T>
GenericSafeArray<T>::GenericSafeArray(const GenericSafeArray<T> &RHS)
{
    Elements=new T[RHS.Size];
    Size=RHS.Size;
    memcpy(Elements,RHS.Elements,sizeof(T) * Size);
}

template<class T>
GenericSafeArray<T> GenericSafeArray<T>:: operator = (const GenericSafeArray<T> &RHS)
{
    if(this!=&RHS)
    {
        if(Elements!=0)
        {
            delete[] Elements;
        }
        Elements=0;
        Size=RHS.Size;
        Elements=new T[Size];
        memcpy(Elements,RHS.Elements,sizeof(T) * Size);
    }
    else
    {
        return (*this);
    }
}

template<class T>
T& GenericSafeArray<T>:: operator [](T Index)
{
    if(Index<0||Index>Size-1)
    {
    cout<<"\n\n*** Invalid Size Given ***\n";
    exit(1);
    }
    return (*(Elements+Index));
}

template<class T>
void GenericSafeArray<T>::Display()
{
    for(int i=0;i<Size;i++)
    {
    cout<<Elements[i]<<endl;
    }
}

template<class T>
void GenericSafeArray<T>::SetData()
{
    cout<<"\n\nEnter Data : \n";
    for(int i=0;i<Size;i++)
    {
        cin>>Elements[i];
    }
}

template<class T>
void GenericSafeArray<T>::UpdateSize(int Capacity)
{
    T *NewArray=new T[Capacity];
    memset(NewArray,0,sizeof(T)*Capacity);
    for(int i=0;i<Size;i++)
    {
        NewArray[i]=Elements[i];
    }
    delete []Elements;
    Size=Capacity;
    Elements=new T[Size];
    memcpy(Elements,NewArray,sizeof(T)*Size);
    delete []NewArray;
    NewArray=0;
}

template<class T>
GenericSafeArray<T>::~GenericSafeArray()
{
    if(Elements!=0)
    {
        delete [] Elements;
    }
    Elements=0;
    Size=0;
}
