#include <iostream>

int getDigit(const int number);
int sumODDDigits(const std::string cardNumber);
int sumEVENDigits(const std::string cardNumber);

int main(){
    using namespace std;
    string cardNumber;
    int result =0;

    cout<<"Enter a credit card number: "; 
    cin>>cardNumber;

    result =sumODDDigits(cardNumber)+sumEVENDigits(cardNumber);

    if(result % 10 ==0){
        cout<<cardNumber<<" is valid "<<endl;
    }else{
        cout<<cardNumber<<" is invaid! "<<endl;
    }
    return 0;

}

int getDigit(const int number){

    return number % 10 + (number/10 %10) ;

}
int sumODDDigits(const std::string cardNumber){
    int sum=0;
    for (int i=cardNumber.size()-1;i>=0;i-=2){
        sum +=getDigit(cardNumber[i]-'0');
    }

    return sum;
   
}
int sumEVENDigits(const std::string cardNumber){
    int sum=0;
    for (int i=cardNumber.size()-2;i>=0;i-=2){
        sum +=getDigit((cardNumber[i]-'0')*2);
    }

    return sum;
   
}