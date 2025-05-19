#include<iostream>
#include<climits>

using namespace std;

class Complex{
    int real,img;
public:
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }

    void showNum(){
        cout << real << " + " << img << "i \n" ;
    }

    Complex operator -(Complex c2){
        int resReal = this->real - c2.real ;
        int resImg = this->img - c2.img ;
        Complex res(resReal,resImg);
        return res;
    }
};

int main(){
    Complex c1(3,4);
    Complex c2(1,2);
    c1.showNum();
    c2.showNum();

    Complex c3 = c1 - c2;
    c3.showNum();
    return 0;
}