#include <iostream>
using namespace std;


int main(){
    //basic arrays



    //fixed array
    cout<<"----Fixed Size Arrays----\n";
    int myArray[5]={1,2,3,4,5};
    cout<<  "your array element is:"<< myArray[2]<<endl;

    //custom sizes array
    cout<<"----custom size array----\n";

    int number;
    cout<< "enter size of array:";
    cin>> number;
    int mycustomArray[number];
    

    for (int counter = 0; counter < number; counter++)
    {
        cout<<"Enter "<<counter+1<<" element:";
        cin>> mycustomArray[counter];
    }
    for (int i = 0; i < number; i++)
    {
        cout<<"your "<<i+1<< " element of array is:";
        cout<<mycustomArray[i]<<"\n";
    }
    
}
