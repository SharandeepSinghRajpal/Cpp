#include <iostream>

int SearchArray(int numbers[],int size,int x);

int main(){
    int numbers[]={0,1,2,3,4,5,6,7,8,9};
    int size =sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int x;
    using std::cout;
    using std::cin;

    cout<<"Enter a number between 0-9 to search: ";
    cin>>x;
    index = SearchArray(numbers,size,x);
    if (index!= -1){
        cout<<x<<" is at Index "<<index;
    }
    else {
        cout<<"Number is not in array";
    }

    return 0;
}

int SearchArray(int array[],int size,int element){

    for (int i=0;i<size;i++){
        if(array[i]==element)
        return i;
    }
    return -1;
}
