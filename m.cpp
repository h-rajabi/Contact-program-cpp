#include <iostream>

using namespace std;

int main(){


    int amir[2][2],rajab[2][2],av[2][2];

    for(int i=0;i<2;i++){

        for (size_t j = 0; j < 2;j++)
        {
            cout << "enter number :";
            cin>>amir[i][j];
        }
        
    }
    for(int i=0;i<2;i++){

        for (size_t j = 0; j < 2;j++)
        {
            cout<<amir[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}