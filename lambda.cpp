#include <iostream>
using namespace std;

int main() {
    int m = 0, n = 0;
    auto func = [&, n] (int a) mutable  -> void {
        m = ++n + a;
    };
    func(6);
    cout << "C1: " << m << " " << n << endl;

    //C2
    [&, n] (int a) mutable {    //truyen tham tri doi voi n, truyen tham chieu voi bat ki bien nao khac
        m = ++n + a;
    } (6);
    cout << "C2: " << m << " " << n << endl;

    //C3
    [&] (int a) mutable {       //truyen tham chieu voi moi bien
        m = ++n + a;
    } (6);
    cout << "C3: " << m << " " << n << endl;

    //C4
    m = n = 0;
    [=] (int a) mutable {       //truyen tham tri voi moi bien
        m = ++n + a;
    } (6);
    cout << "C4: " << m << " " << n << endl;

    //C5
    [=] (int a) mutable {            //mutable cho phep thay doi gia tri bien duoc bat giu 
        ++n;                        //(neu bat giu tham tri thi chi thay doi trong pham vi ham lambda
        m = ++ n + a;
        cout << "Ben trong lambda: " << m << " " << n << endl;
    } (6);
    cout << "C5: " << m << " " << n << endl;
    return 0;
}