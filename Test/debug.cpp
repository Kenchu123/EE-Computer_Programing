//PREPEND BEGIN

#include <iostream>
#include <iomanip>
#include <string>

// uncomment line below if you use dev-c++
//#include <stdint.h>

using namespace std;

// range of uint64_t is 0 ~ 18,446,744,073,709,551,615
// define 10^19-1 as the max value in single element
// which means we can have 19 '9's
// the U added at the end means this is an unsigned number
const uint64_t CARRY = 10000000000000000000U;
const uint64_t CARRY_LENGTH = 19U;

class HugeInteger {
public:
    HugeInteger();                     // default constructor
    HugeInteger(const string& s);      // constructor with value
    HugeInteger(const HugeInteger& n); // copy constructor
    ~HugeInteger();                    // destructor

    HugeInteger  operator +  (HugeInteger& n);
    HugeInteger  operator -  (HugeInteger& n);
    HugeInteger  operator *  (HugeInteger& n);
    HugeInteger  operator /  (HugeInteger& n);
    HugeInteger  operator %  (HugeInteger& n);

    HugeInteger& operator  = (const HugeInteger& n);
    HugeInteger& operator += (HugeInteger& n);
    HugeInteger& operator -= (HugeInteger& n);
    HugeInteger& operator *= (HugeInteger& n);
    HugeInteger& operator /= (HugeInteger& n);
    HugeInteger& operator %= (HugeInteger& n);

    HugeInteger& operator ++ ();    // prefix
    HugeInteger& operator -- ();    // prefix
    HugeInteger  operator ++ (int); // postfix
    HugeInteger  operator -- (int); // postfix

    bool operator < (HugeInteger& n){
        this->resize(); n.resize();
        if(_sign != n._sign){
            for(int i = 0 ; i < this->_length ; ++i)
                if(_data[i] || n._data[i]) return _sign;
        }
        else{
            for(int i = 0 ; i < this->_length ; ++i){
                if( _data[i] > n._data[i]) return  _sign;
                if( _data[i] < n._data[i]) return !_sign;
            }
        }
        return false;
    }
    bool operator > (HugeInteger& n){
        this->resize(); n.resize();
        if(_sign != n._sign){
            for(int i = 0 ; i < this->_length ; ++i)
                if(_data[i] || n._data[i]) return !_sign;
        }
        else{
            for(int i = 0 ; i < this->_length ; ++i){
                if( _data[i] > n._data[i]) return !_sign;
                if( _data[i] < n._data[i]) return  _sign;
            }
        }
        return false;
    }
    bool operator == (HugeInteger& n){
        this->resize(); n.resize();
        if(_sign != n._sign){
            for(int i = 0 ; i < this->_length ; ++i)
                if(_data[i] || n._data[i]) return false;
        }
        else{
            for(int i = 0 ; i < this->_length ; ++i)
                if( _data[i] != n._data[i]) return false;
        }
        return true;
    }
    bool operator != (HugeInteger& n){
        return !(this->operator==(n));
    }
    bool operator <= (HugeInteger& n){
        return !(this->operator>(n));
    }
    bool operator >= (HugeInteger& n){
        return !(this->operator<(n));
    }

    void abs(){ _sign = false; }

    friend istream& operator >> (istream& is, HugeInteger& n);
    friend ostream& operator << (ostream& os, const HugeInteger& n);

private:
    bool           _sign; // false for positive ; true for negative
    int64_t      _length; // length of data array
    uint64_t*      _data; // integer array holding the huge integer
    static int64_t _maxl; // max length of data array in exist HugeInteger(s)

    // d is Divisor, q is Quotient(pointer), r is Remainder(pointer)
    void divider(const HugeInteger& d, HugeInteger& q, HugeInteger& r);

    // increase the length of data array to max length
    void resize();
};

int64_t HugeInteger::_maxl = 1;

HugeInteger::HugeInteger(){
    _length = _maxl;
    _data = new uint64_t[_length];
    for(int i = 0 ; i < _length; ++i)
        _data[i] = 0;
    _sign = false;
    return;
}

HugeInteger::HugeInteger(const string& s){
    while( s.length() > _maxl*CARRY_LENGTH )
        _maxl <<= 1;
    _length = _maxl;
    _data = new uint64_t[_length];
    for(int i = 0 ; i < _length; ++i)
        _data[i] = 0;
    if(s.length() == 0) return;
    _sign = (s[0] == '-');
    for(int i = (_sign?1:0) ; i < s.length() ; ++i){
        _data[(CARRY_LENGTH*_length+i-s.length())/CARRY_LENGTH] *= 10;
        _data[(CARRY_LENGTH*_length+i-s.length())/CARRY_LENGTH] += (uint64_t)((char)s[i]-'0');
    }
    return;
}

HugeInteger::HugeInteger(const HugeInteger& n){
    _data = new uint64_t[n._length];
    _length = n._length;
    _sign = n._sign;
    for(int i = 0; i < n._length ; ++i)
        _data[i] = n._data[i];
    return;
}

HugeInteger::~HugeInteger(){
    delete [] _data;
    return;
}
//PREPEND END

//TEMPLATE BEGIN
HugeInteger HugeInteger::operator + (HugeInteger& n){
    // TODO 1
    this->resize(); n.resize();
    HugeInteger a(*this), b(n);
    if (a._sign == b._sign) {
        HugeInteger ans;
        uint64_t carry = 0;
        for (int i = a._length - 1; i >= 0; i--) {
            uint64_t a_d = a._data[i], b_d = b._data[i] + carry;
            carry = 0;
            ans._data[i] = a_d + b_d;
            if (ans._data[i] >= CARRY) {
                ans._data[i] -= CARRY;
                carry = 1;
            }
        }
        ans._sign = a._sign;
        return ans;
    }
    else {
        if (a._sign == 0) {
            b._sign = 0;
            return a - b;
        }
        else {
            a._sign = 0;
            return b - a;
        }
    }
}
HugeInteger HugeInteger::operator - (HugeInteger& n){
    // TODO 2
    HugeInteger a(*this), b(n);
    if (this->_sign == 0 && n._sign == 1) {
        b._sign = 0;
        return a + b;
    }
    else if (this->_sign == 1 && n._sign == 0) {
        b._sign = 1;
        return a + b;
    }
    else {
        bool isMinus = 0;
        bool sign = 0;
        if (a._sign == 1) isMinus = 1;
        a.abs(), b.abs(); 
        if (a < b) {
            sign = 1;
            HugeInteger tmp(a);
            a = b;
            b = tmp;
        }
         // a - b
        HugeInteger ans;
        int carry = 0;
        for (int i = a._length - 1; i >= 0; i--) {
            uint64_t a_d = a._data[i], b_d = b._data[i];
            b_d += carry;
            if (a_d >= b_d) {
                ans._data[i] = a_d - b_d;
                carry = 0;
                continue;
            }
            else { // a_d < b_d + carry
                ans._data[i] = CARRY - b_d + a_d;
                carry = 1;
            }
        }
        ans._sign = sign;
        if (isMinus) ans._sign = !ans._sign;
        return ans;
    }
}
HugeInteger HugeInteger::operator * (HugeInteger& n){
    this->resize(); n.resize();
    HugeInteger zero;
    HugeInteger ans;
    HugeInteger tmp(n);
    tmp.abs();
    while(tmp > zero){
        ans+=(*this);
        --(tmp);
    }
    ans._sign = this->_sign ^ n._sign;
    return ans;
}
HugeInteger HugeInteger::operator / (HugeInteger& n){
    this->resize(); n.resize();
    // TODO 3
    HugeInteger ans, q, r;
    (*this).divider(n, q, r);
    return q;
}
HugeInteger HugeInteger::operator % (HugeInteger& n){
    this->resize(); n.resize();
    // TODO 4
    HugeInteger q, r;
    (*this).divider(n, q, r);
    return r;
}

HugeInteger& HugeInteger::operator ++ (){
    // TODO 5
    HugeInteger one("1");
    (*this) = (*this) + one;
    return *this;
}
HugeInteger& HugeInteger::operator -- (){
    // TODO 6
     HugeInteger one("1");
    (*this) = (*this) - one;
    return *this;
}
HugeInteger  HugeInteger::operator ++ (int){
    // TODO 7
    HugeInteger tmp(*this), one("1");
    (*this) = (*this) + one;
    return tmp;
}
HugeInteger  HugeInteger::operator -- (int){
    // TODO 8
    HugeInteger tmp(*this), one("1");
    (*this) = (*this) - one;
    return tmp;
}
HugeInteger& HugeInteger::operator = (const HugeInteger& n){
    // TODO 9
    this->_length = n._length;
    this->_sign = n._sign;
    delete [] this->_data;
    this->_data = new uint64_t[this->_length];
    for (int i = 0;i < this->_length; i++) this->_data[i] = n._data[i];
}
//TEMPLATE END

//APPEND BEGIN
HugeInteger& HugeInteger::operator += (HugeInteger& n){
    this->operator=(this->operator+(n));
    return (*this);
}
HugeInteger& HugeInteger::operator -= (HugeInteger& n){
    this->operator=(this->operator-(n));
    return (*this);
}
HugeInteger& HugeInteger::operator *= (HugeInteger& n){
    this->operator=(this->operator*(n));
    return (*this);
}
HugeInteger& HugeInteger::operator /= (HugeInteger& n){
    this->operator=(this->operator/(n));
    return (*this);
}
HugeInteger& HugeInteger::operator %= (HugeInteger& n){
    this->operator=(this->operator%(n));
    return (*this);
}

istream& operator >> (istream& is, HugeInteger& n){
    string s;
    is >> s;
    while( s.length() > n._maxl*CARRY_LENGTH )
        n._maxl <<= 1;
    n._length = n._maxl;
    n._data = new uint64_t[n._length];
    for(int64_t i = 0 ; i < n._length; ++i)
        n._data[i] = 0;
    if(s.length() == 0) return is;
    n._sign = (s[0] == '-');
    for(int64_t i = (n._sign?1:0) ; i < s.length() ; ++i){
        n._data[(CARRY_LENGTH*n._length+i-s.length())/CARRY_LENGTH] *= 10;
        n._data[(CARRY_LENGTH*n._length+i-s.length())/CARRY_LENGTH] += (uint64_t)((char)s[i]-'0');
    }
    return is;
}
ostream& operator << (ostream& os, const HugeInteger& n){
    bool not_zero = false;
    for(int64_t i = 0 ; (i < n._length && (!not_zero)) ; ++i)
        not_zero |= n._data[i];
    if(!not_zero){
        os << '0';
        return os;
    }

    os << ( n._sign ? "-" : "" );
    int64_t iter;
    for( iter = 0 ; iter < n._length ; ++iter )
        if( n._data[iter] || iter == (n._length-1) ){
            os << n._data[iter];
            break;
        }
    for( ++iter ; iter < n._length ; ++iter )
        os << setw(CARRY_LENGTH) << setfill('0') << n._data[iter];
    return os;
}
void HugeInteger::divider(const HugeInteger& d, HugeInteger& q, HugeInteger& r){
    HugeInteger _d(d);
    bool q_sign = (this->_sign != _d._sign);
    bool r_sign = this->_sign;

    q = HugeInteger("0");
    r = HugeInteger(*this);
    HugeInteger one("1");

    r.resize(); _d.resize();
    r.abs();    _d.abs();
    if( _d != q )
        while(r >= _d){
            r-=_d;
            q+=one;
        }

    q._sign = q_sign;
    r._sign = r_sign;
    return;
}

void HugeInteger::resize(){
    if(_maxl == _length) return;
    uint64_t* temp = _data;
    _data = new uint64_t[_maxl];
    for(int i = 0 ; i < _maxl-_length; ++i)
        _data[i] = 0;
    for(int i = _maxl-_length ; i < _maxl; ++i)
        _data[i] = temp[i+_length-_maxl];
    delete [] temp;
    _length = _maxl;
    return;
}

int main(){
    // mode 0: no * or /
    // mode 1: only *
    // mode 2: only /
    // mode 3: * and /
    int mode;
    HugeInteger n1, n2;

    cin >> mode >> n1 >> n2;
    cout << "+: " << n1 + n2 << endl;
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;

    cout << "-------------------------------" << endl;

    cout << (n1> n2?"n1 > n2" :"") << endl;
    cout << (n1==n2?"n1 == n2":"") << endl;
    cout << (n1< n2?"n1 < n2" :"") << endl;

    cout << "-------------------------------" << endl;

    cout << "+: " << (n1 + n2) << endl;
    cout << "-: " << (n1 - n2) << endl;
    if(mode%2 == 1) cout << "*: " << (n1 * n2) << endl;
    if(mode > 1) cout << "/: " << (n1 / n2) << endl;
    if(mode > 1) cout << "%: " << (n1 % n2) << endl;

    cout << "-------------------------------" << endl;

    cout << (n1++) << ", ";
    cout <<  n1    << ", ";
    cout << (++n1) << ", ";
    cout <<  n1    << ", ";
    cout << (n1--) << ", ";
    cout <<  n1    << ", ";
    cout << (--n1) << ", ";
    cout <<  n1    << endl;
    return 0;
}
//APPEND END
