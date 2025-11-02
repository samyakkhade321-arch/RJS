#include<iostream>
using namespace std;
void isEven(){
    int n;
    cout << "ENTER THE VALUE OF ON : "<<endl;
    cin>>n;
    if(n % 2 == 0 ){
        cout << n << " IS A EVEN NUMBER "<<endl;
    }else{
        cout << n << " THIS IS NOT A EVEN NUMBER "<<endl;
        cout << n << " THIS IS A ODD NUMBER "<<endl;
    
}
int main(){
    
    cout << "============================================="<<endl;
    cout << "====WELLCOME_EVEN_NUMBER_CHECKER_PROGRAM===="<<endl;
    cout << "============================================="<<endl;
    string input;
    do{
        isEven();
        cout << "DO YOH WANT TO CHECK ANOTHER NUMBER (YES / NO ) : "<<endl;
        cin>>input;
    }while(input == "yes" || input == "Yes" || "YES");
    cout << "****************************************"<<endl;
    cout << "*****YOUR_PROGRAM_IS_DONE_SUSSFULLY*****"<<endl;
    cout << "****************************************"<<endl;
    return 0;
}
