#include "GenericSafeArray.cpp"
#include<iostream>
using namespace std;
int main()
{
    int Arr[]={2,3};
    GenericSafeArray<int> S(Arr,2);
    S.Display();
    S.UpdateSize(5);
    S.SetData();
    S.Display();
}
