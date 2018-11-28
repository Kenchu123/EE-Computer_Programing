//PREPEND BEGIN
#include <iostream>

using namespace std;

enum color_code{Black, Brown, Red, Orange, Yellow,
                Green, Blue, Purple, Gray, White,
                Gold, Silver, None};
//PREPEND END

//TEMPLATE BEGIN
class Resistor{
    private:
        bool valid;
        color_code code[4];
        int four_circle[8] = {Brown, Red, Green, Blue, Purple, Gray, Gold, Silver};
                            // 1 2 5 6 7 8 10 11 
        char ntoc[12][10] = {"Black", "Brown", "Red", "Orange", "Yellow",
            "Green", "Blue", "Purple", "Gray", "White","Gold", "Silver"
        };
        char ctoper[12][10] = {
           "", " +/-1%", " +/-2%","","", " +/-0.5%", " +/-0.25%", " +/-0.1%", " +/-0.05%","", " +/-5%", " +/-10%"
        };
        char ctoOm[12][10] = { "", "0", "00", "000", "0000", "00000", "000000", "0000000", "00000000",
         "000000000", ".", "0."};
    public:
        bool setValue(color_code a,color_code b,color_code c,color_code d){
            // TODO
            valid = true;
            code[0] = a, code[1] = b, code[2] = c, code[3] = d;
            if (a < Brown || a > White) valid = false;
            if (b > White || b < Black) valid = false;
            if (c > Silver || c < Black) valid = false;
            bool check = false;
            for (int i = 0;i < 8; i++) if (d == four_circle[i]) check = true;
            valid = valid & check;
            return valid;
        }
        void display_color(){
            // TODO
            cout << ntoc[code[0]] << " | " << ntoc[code[1]] << " | " << ntoc[code[2]] << " | " << ntoc[code[3]] << endl;
        }
        void display_value(){
            // TODO
            if (code[2] < 10) cout << code[0] << code[1] << ctoOm[code[2]] << ctoper[code[3]] << endl;
            else if (code[2] == 10) {
                cout << code[0] << ctoOm[code[2]] << code[1] << ctoper[code[3]] << endl;
            } 
            else {
                cout << ctoOm[code[2]] << code[0] << code[1] << ctoper[code[3]] << endl;
            }
        }
};
//TEMPLATE END

//APPEND BEGIN
int main(){
    Resistor R;
    int a, b, c, d;
    do{
        cin >> a >> b >> c >> d;
    }while(!(R.setValue(static_cast<color_code>(a),\
                        static_cast<color_code>(b),\
                        static_cast<color_code>(c),\
                        static_cast<color_code>(d))));

    R.display_color();
    R.display_value();

    return 0;
}
//APPEND END