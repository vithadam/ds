#include <iostream>
#define max 100
using namespace std;
int n, key;
int a[max];
int b;
class sequential
{

public:
    void input()
    {
        cout << "Enter how many elements you want to store: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter element  " << i << ": ";
            cin >> a[i];
        }
    }
    void search()
    {

        while (true)
        {

            cout << "enter the element you want to search ";
            cin >> key;
            int pos = -1;
            for (int i = 0; i <= n; i++)
            {
                if (key == a[i])
                {
                    pos = i;
                    break;
                }
            }
            if (pos == -1)
            {
                cout << "Element " << key << " is not found "<< endl;
            }
            else
            {
                cout << "Element " << key << "  is found at  " << pos << endl;
            }
            
            cout << " press 1 to quit  press 0 continue ";
            cin >> b;
            if (b==1)
            {
                cout<<"exititng...";
                break;
            }
            
        }
    };
};
    int main()
    {
        sequential s;
        s.input();
        s.search();
        return 0;
    }