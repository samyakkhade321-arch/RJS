
#include<iostream>
using namespace std;
void add(){
    float a ; 
    float b ;
    cout << "ENTER THE VALUE OF A : "<<endl;
    cin>>a;
    cout << "ENTER THE VALUE OF B A:"<<endl;
    cin>>b;
    float addition = a + b ; 
    cout << "THE SUM OF A AND B IS : "<<addition<<endl;
}

void sub(){
    float a;
    float b; 
    cout << "ENTER TYE VALUE OF A : "<<endl;
    cin>>a;
    cout << "ENTER THE THE VALUE OF B : "<<endl;
    cin>>b;
    float substraction = a - b ;
    cout << "SUBSTRACTION OF A AND B IS : "<< substraction<<endl;
}

void mul(){
    float a;
    float b;
    cout << "ENTER THE VALUE OF A : "<<endl;
    cin>>a;
    cout << "ENTER THE VALUE OF N : "<<endl;
    cin>>b;
    float multiplication = a * b ; 
    cout << " THE MULTIPLICATION OF A AND B IS : "<<multiplication<<endl;
}
void _div(){
    float a;
    float b;
    cout << "ENTER THE VALUE OF A : "<<endl;
    cin>>a;
    cout << "ENTER THE VALUE OF N : "<<endl;
    cin>>b;
    if(b == 0 ){
        cout << "Error:THE VALIE OF B IS CANNOT B ZERO!!! "<<endl;
    }else{
        float division = a / b ; 
        cout << "THE DIVISION OF A AND B IS : "<<division<<endl;
    }
}
int main(){
    cout << "=================================================="<<endl;
    cout << "====WELLCOME_TO_THE_SIMPLE_CALCULATOR_PROGRAM_===="<<endl;
    cout << "=================================================="<<endl;
    string choice;
    string input;
    do{
        cout << "CHOSE WHAT DO YOU WANT TO DO(add,sub,div,mul) : "<<endl;
        cin>>choice;
        if(choice == "add"){
            add();
        }else if(choice == "sub"){
            sub();
        }else if(choice == "mul"){
            mul();
        }else if(choice == "div"){
            _div();
        }else{
            cout << "PLEASE CHOSE FORM ADD , SUB , MUL , DIV "<<endl;
        }
        cout << "***************************************************"<<endl;
        cout << "DO YOU WANT YO RWAPET THIS AGAIN (YES;NO) : "<<endl;
        cout << "***************************************************"<<endl;
        cin>>input;
    }while(input == "Yes" || input == "yes" || input == "Y" || input == "y" || input == "YES");
    cout << "*****************************************"<<endl;
    cout << "****YOUR_PROGRAM_IS_DONE_SUSSFULLY!!!****"<<endl;
    cout << "*****************************************"<<endl;
    return 0;
}