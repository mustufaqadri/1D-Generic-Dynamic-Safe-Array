#pragma once

template<class T>
class GenericSafeArray
{
    private:
        T *Elements;
        T Size;
    public:

        //Basic Function
        GenericSafeArray();
        GenericSafeArray(T Arr[],T Capacity);
        GenericSafeArray(int Capacity);
        GenericSafeArray(const GenericSafeArray<T> &RHS);
        GenericSafeArray operator = (const GenericSafeArray<T> &RHS);
        void Display();
        void SetData();
        ~GenericSafeArray();

        //Special Functions
        T& operator [](T Index);
        void UpdateSize(int Capacity);
};
