#include <iostream>
using namespace std;
int temp()
{

    int sizee;
    cout << "enter size";
    cin >> sizee;
    int fakeSize = sizee + 1;
    int fakearr[fakeSize];
    int arr[sizee];
    cout << "enter values";
    for (int i = 0; i < sizee; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < sizee; i++)
    {
        cout << arr[i] << " ";
    }

    int key;
    cout << "enter key";
    cin >> key;
    int pos = -1;
    for (int i = 0; i < sizee; i++)
    {
        if (arr[i] == key)
        {
            pos = i;
            cout << "element found at " << pos;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "cant find";
    }
    return 0;
}

int main()
{
    temp();
}