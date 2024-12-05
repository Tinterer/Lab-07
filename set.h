#include <iostream>
#include<sstream>

class BigInt {
private:
    std::string nums;
    int check;
public:

    BigInt(const BigInt &bigint);
    ~BigInt();

    BigInt();                                       //
    BigInt(const int& a);                           //
    BigInt(const std::string& a);                   //      Приведение к длинному целому
    BigInt(const short& a);                         //      от базовых типов
    BigInt(const char& a);                          //
    BigInt(const long& a);                          //

    operator int() const;                                 //      
    operator std::string() const ;                         //      
    operator short() const;                               //      Приведение длинного целого к базовым типам данных
    operator char() const;                                //      
    operator long() const;                               //      

    BigInt GCD(BigInt left, BigInt right);
    BigInt LCD(BigInt left, BigInt right);
    void print();
    std::string getValue() const;
    
    bool operator==(BigInt value);
    BigInt operator=(std::string value);            //
    BigInt operator+(BigInt value2);                //      Операторы + и - и *
    BigInt operator-(BigInt value);                 //
    BigInt operator*(BigInt value);                 //
    BigInt operator/(BigInt value);
    BigInt operator%(const BigInt value);
    int operator>(BigInt value);
    BigInt operator<(BigInt value);
    int operator>=(BigInt value);
    BigInt operator<=(BigInt value);
    
    friend BigInt operator-(BigInt value);                                         
    friend std::ostream& operator << (std::ostream &os, BigInt& bigint);
    friend std::ostream& operator << (std::ostream &os, const BigInt& bigint);                        
    friend std::istream& operator >> (std::istream &is, BigInt& bigint);            
                                                                                    
    friend BigInt operator+(short value1, BigInt value2);                           
    friend BigInt operator+(BigInt value1, short value2);                           
    friend BigInt operator+(long value1, BigInt value2);                            
    friend BigInt operator+(BigInt value1, long value2);                            
    friend BigInt operator+(char value1, BigInt value2);                            
    friend BigInt operator+(BigInt value1, char value2);                            
                                                                                    
                                                                                    
    friend BigInt operator-(short value1, BigInt value2);                           
    friend BigInt operator-(BigInt value1, short value2);                           
    friend BigInt operator-(long value1, BigInt value2);                            
    friend BigInt operator-(BigInt value1, long value2);                            
    friend BigInt operator-(char value1, BigInt value2);                            
    friend BigInt operator-(BigInt value1, char value2);                            

    friend BigInt operator*(short value1, BigInt value2);
    friend BigInt operator*(BigInt value1, short value2);
    friend BigInt operator*(long value1, BigInt value2);
    friend BigInt operator*(BigInt value1, long value2);
    friend BigInt operator*(int value1, BigInt value2);
    friend BigInt operator*(BigInt value1, int value2);
    friend BigInt operator*(char value1, BigInt value2);
    friend BigInt operator*(BigInt value1, char value2);

    friend BigInt operator/(short value1, BigInt value2);
    friend BigInt operator/(BigInt value1, short value2);
    friend BigInt operator/(long value1, BigInt value2);
    friend BigInt operator/(BigInt value1, long value2);
    friend BigInt operator/(int value1, BigInt value2);
    friend BigInt operator/(BigInt value1, int value2);
    friend BigInt operator/(char value1, BigInt value2);
    friend BigInt operator/(BigInt value1, char value2);

    friend BigInt operator>=(short value1, BigInt value2);
    friend BigInt operator>=(BigInt value1, short value2);
    friend BigInt operator>=(long value1, BigInt value2);
    friend BigInt operator>=(BigInt value1, long value2);
    friend BigInt operator>=(int value1, BigInt value2);
    friend BigInt operator>=(BigInt value1, int value2);
    friend BigInt operator>=(char value1, BigInt value2);
    friend BigInt operator>=(BigInt value1, char value2);

    friend BigInt operator>(short value1, BigInt value2);
    friend BigInt operator>(BigInt value1, short value2);
    friend BigInt operator>(long value1, BigInt value2);
    friend BigInt operator>(BigInt value1, long value2);
    friend BigInt operator>(int value1, BigInt value2);
    friend BigInt operator>(BigInt value1, int value2);
    friend BigInt operator>(char value1, BigInt value2);
    friend BigInt operator>(BigInt value1, char value2);
};
