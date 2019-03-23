#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int ch,n,i;
    char s1[50], s2[50], key;
    
    cout << "Type your message" << endl;
    cin.getline(s1 , 50);
    do
    {
        cout << "\n----Data Encryption----\n1]Encrypt\n2]Decrypt\n3]Exit\nEnter your choice:  \n";
        cin >> ch;
        switch(ch)
        {
            case 1: cout << "Enter the key character to encrypt data:\n";
            cin >> key;
            for(i=0; s1[i] != '\0'; i++)
            {
                s2[i] = s1[i]^key;
            }
            s2[i] = '\0';
            cout << "Your data encrypted successfully \n Your secure character key is\n" << key;
            cout << "\n---YOUR ENCRYPTED DATA IS---\n" << s2;
            break;
            case 2: 
            cout << "\nEnter the Key character to decrypt data:\n";
            char t;
            cin >> t;
            if( key == t)
            {
                for(i = 0; s2[i] != '\0'; i++)
                {
                    s2[i] = s2[i]^key;  
                }
                cout << "---YOUR DECRYPTED DATA IS---\n" << s2;
            }
            else
            cout << "Invalid character key\n";
            break;
            
            case 3: break;
            default: cout << "Invalid choice, try again\n";
        }
        
    }
    while( ch != 3);



}
