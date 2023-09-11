#include <iostream>
#include <list>
#include <string>
using namespace std;

string str;
char command, input;
int M;
list <char> l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    cin >> M;
    
    for(int i=0; i<str.size(); i++){
		l.push_back(str.at(i));
	}
    list<char>::iterator cur = l.end();

    for (int i = 0; i < M; i++)
    {
        cin >> command;
        
        if (command == 'L')
        {if (cur != l.begin()) cur--;}
            
        else if (command == 'D')
            {if (cur != l.end()) cur++;}
        
        else if (command == 'B')
        {if (cur != l.begin())
                cur = l.erase(--cur);}
        
        else if (command == 'P')
        {
            cin >> input;
            l.insert(cur, input);
        }
    }
    
    for (list<char>::iterator itr=l.begin(); itr != l.end(); itr++)
        cout << *itr;
    
    return 0;
}