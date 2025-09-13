#include <iostream>

void SortArray(int numbers[],int size);

int main(){
    int numbers[]={1,3,7,2,4,5,0,9,8,6};
    int size =sizeof(numbers)/sizeof(numbers[0]);
 
    using std::cout;
    using std::cin;

    cout<<"Original Array: ";
    for(int i=0;i<size;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<std::endl;

    SortArray(numbers,size);

    cout<<"Sorted Array: ";
    for(int i=0;i<size;i++){
        cout<<numbers[i]<<" ";
    };

    return 0;
}

void SortArray(int array[],int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            for (int k = 0; k < size; k++) std::cout << array[k] << " ";
            std::cout <<"\n";
        }

    }

}
