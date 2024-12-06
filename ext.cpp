#include "set.h"
#include <iostream>
#include <cmath>


template <typename T>
std::string toString(T val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

BigInt::BigInt(const BigInt &bigint) {                                  //конструктор копирвания
    nums = bigint.nums;
    check = bigint.check;
}

BigInt::~BigInt() {}

BigInt::BigInt(){                                                       //конуструктор для пустого ввода
    nums = "";
    check = 0;
}

BigInt::BigInt(const int& value) {                                      //конструктор для инта
    if (value > 0) check = 1;
    if (value < 0) check = -1;
    if (value == 0) check = 0;

    nums = toString(value);
}

BigInt::BigInt(const std::string& value){                               //конструктор для стринга
    if(value[0] == '-') check = -1;
    else if(value == "0") check = 0;
    else check = 1;

    if(value.size() >= 2){
        std::string st = value;

        if (check == -1){
            st.erase(1, st.find_first_not_of('0'));
            if (st.empty()) st = "0";
        } else if(check == 1){
            st.erase(0, st.find_first_not_of('0'));
            if (st.empty()) st = "0";
        }

        nums = st;
    }
    
    else nums = value;
}

BigInt::BigInt(const short& value) {                                    //конструктор для шорта
    if (value > 0) check = 1;   
    if (value < 0) check = -1;
    if (value == 0) check = 0;

    nums = toString(value); 
}

BigInt::BigInt(const char& value){                                      //конструктор для чара
    if (value > 0) check = 1;
    if (value < 0) check = -1;
    if (value == 0) check = 0;

    nums = toString(value);
}

BigInt::BigInt(const long& value) {                                     //конструктор для лонга
    if (value > 0) check = 1;
    if (value < 0) check = -1;
    if (value == 0) check = 0;

    nums = toString(value);
}

BigInt::operator int() const {                                                //приведение к инту
    return atoi(nums.c_str()); 
}

BigInt::operator std::string() const {                                        //приведение к стрингу
    return nums;
}

BigInt::operator short() const {                                              //приведение к шорту
    return atoi(nums.c_str());
}

BigInt::operator char() const {                                               //приведение к чару
    return atoi(nums.c_str());
}

BigInt::operator long() const {                                               //приведение к лонгу
    long res = 0;
    int i; 
    int leng = nums.size();
    if (check == 1) {
        for (i = 0; i < leng; i++) {
            res += (nums[(leng - 1) - i] - '0') * pow(10, i);
        }
    } else if (check == -1) {
        for (i = 0; i < leng - 1; i++) {
            res += (nums[(leng - 1) - i] - '0') * pow(10, i);
        }

        res = -res;
    }

    return res;
}

void BigInt::print() {                                                  //функция принт для бигинта
    std::cout << nums << std::endl;
}

std::string BigInt::getValue() const {return nums;}                     //получение значения



BigInt BigInt::GCD(BigInt left, BigInt right) {
    std::string num1 = left.nums;
    std::string num2 = right.nums;
    BigInt ok;

    if (right.check == -1) {right = -right;}
    if (left.check == -1) {left = -left;}

    BigInt n1 = BigInt(num1);
    BigInt n2 = BigInt(num2);

    while (left > BigInt(0) && right > BigInt(0)) {
        if (left >= right) {
            left = (left % right);
        } else {
            right = right % left;
        }
    }
    ok = (BigInt((left * BigInt(left > right))+ (right * BigInt(right > left))));
    std::cout << ok << std::endl;
    return ok;
}

BigInt BigInt::LCD(BigInt left, BigInt right) {
    BigInt res;

    if (right.check == -1) {right = -right;}
    if (left.check == -1) {left = -left;}

    res = (left * right) / GCD(left, right);

    return res;
}

bool BigInt::operator==(BigInt value) {
	return (this->nums == value.nums);
}
BigInt BigInt::operator=(std::string v) {                               //перегруженный оператор присваивания
    nums = v;
    return *this;
}

BigInt operator-(BigInt value) {                                        //унарный минус
    if (value.check == -1){                                             //меняет значение числа на противоположне по знаку
        value.check = 1;                                                
        std::string buf = "";
        int i;
        int sizee = value.nums.size();
        for(i = 1;i < sizee;++i){
            buf = buf + value.nums[i];
        }
        value.nums = buf;
    }
    else if(value.check == 1){
        value.check = -1;
        value.nums = "-" + value.nums;
    }
    return value;
}

BigInt BigInt::operator+(BigInt value)  {
    if (this->check == 1 && value.check == 1) {
        // Оба числа положительные
        std::string num1 = this->nums;
        std::string num2 = value.nums;
        std::string res;
        int carry = 0;
        int size1 = num1.size();
        // int size2 = num2.size();
        int i;

        // Выравниваем длины чисел
        while (num1.size() < num2.size()) {
            num1 = "0" + num1;
        }
        while (num2.size() < num1.size()) {
            num2 = "0" + num2;
        }
	
	size1 = num1.size();

        // Сложение чисел справа налево
        for (i = size1 - 1; i >= 0; --i) {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            res = toString(sum % 10) + res;
            carry = sum / 10;
        }

        // Добавляем оставшийся перенос
        if (carry > 0) {
            res = toString(carry) + res;
        }

        return BigInt(res);
    } else if (this->check == 1 && value.check == -1) {
        // Сложение положительного и отрицательного числа
        return *this - (-value);
    } else if (this->check == -1 && value.check == 1) {
        // Сложение отрицательного и положительного числа
        return value - (-*this);
    } else if (this->check == -1 && value.check == -1) {
        // Оба числа отрицательные
        return -((-*this) + (-value));
    } else if (this->check == 0) {
        // Если текущее число — 0
        return value;
    } else {
        // Если value — 0
        return *this;
    }
}



BigInt BigInt::operator-(BigInt value) {
    if (this->check == 1 && value.check == 1) {
        // Оба числа положительные
        if (value > *this) {
            // Если уменьшаемое меньше вычитаемого, меняем порядок
            return -(value - *this);
        }

        std::string num1 = this->nums;
        std::string num2 = value.nums;
        std::string res;
        int borrow = 0;
        int size1 = num1.size();
        // int size2 = num2.size();
        int i;

        // Выравниваем длины чисел
        while (num2.size() < num1.size()) {
            num2 = "0" + num2;
        }

        // Вычитание чисел справа налево
        for (i = size1 - 1; i >= 0; --i) {
            int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res = toString(diff) + res;
        }

        // Убираем ведущие нули
        while (res.size() > 1 && res[0] == '0') {
            res = res.substr(1);
        }

        return BigInt(res);
    } else if (this->check == 1 && value.check == -1) {
        // Положительное минус отрицательное
        return *this + (-value);
    } else if (this->check == -1 && value.check == 1) {
        // Отрицательное минус положительное
        return -(-*this + value);
    } else if (this->check == -1 && value.check == -1) {
        // Два отрицательных числа
        return -((-*this) - (-value));
    } else if (this->check == 0) {
        // Если текущее число — 0
        return -value;
    } else if (value.check == 0) {
        // Если вычитаемое — 0
        return *this;
    } else {
        // Сложение двух чисел с учётом знаков
        return (*this + (-value));
    }
}




BigInt BigInt::operator/(BigInt value) {
    std::string num1 = this -> nums;
    std::string num2 = value.nums;
    std::string q1, q2;
    BigInt totRes;

    int i, counter, sz1;

    if (num1[0] == '-') {num1.erase(0, 1); this -> check = -1;}
    if (num2[0] == '-') {num2.erase(0, 1); value.check = -1;}

    if (BigInt(num2) > BigInt(num1)) totRes = BigInt(0);
    if(num1 == num2) {
        totRes = BigInt(1);
        }
    else if(num2 == "0") {
        std::cout << "You cannot use 0 as second number" << std::endl;
        exit(1);
    }
    else {

        q1 = num1;
        q2 = num2;

        BigInt res("0");
        BigInt cur;
        sz1 = q1.size();

        for (i = 0; i < sz1; i++) {
            cur.nums += q1[i];
            cur.nums.erase(0, cur.nums.find_first_not_of('0'));
            if (cur.nums.empty()) cur.nums = "0";
            if (BigInt(q2) > cur) {
                if (!res.nums.empty()) res.nums += toString(0);
            } else if(cur >= q2) {
                counter = 0;
                BigInt n1 = cur.nums;
                BigInt n2 = q2;

                while(n1 >= n2) {
                    n1 = n1 - n2;
                    counter++;
                }

                cur.nums = n1.nums;
                q2 = n2.nums;
                res.nums += toString(counter);

            }
        }

        res.nums.erase(0, res.nums.find_first_not_of('0'));
        if (res.nums.empty()) res.nums = "0";
        totRes = res.nums;

    }

    if ((this->check == -1 && value.check == 1) || (this->check == 1 && value.check == -1)) {
    totRes = -BigInt(toString(totRes));
    }

    return totRes;
}

BigInt BigInt::operator%(BigInt value) {
    std::string num1 = this -> nums;
    std::string num2 = value.nums;

    if (num1[0] == '-') {num1.erase(0, 1);}
    if (num2[0] == '-') {num2.erase(0, 1);}

    BigInt res, step2, step3;
    std::string step1;
    step1 = toString(*this / value);
    step2 = (BigInt(value) * step1);
    step3 = (*this - step2);
    res = step3;
    
    return res;
}

BigInt BigInt::operator*(BigInt value) {
    std::string num1 = this->nums;
    std::string num2 = value.nums;
    int rs;

    // Убираем знаки чисел
    if (num1[0] == '-') {
        num1.erase(0, 1);
    }
    if (num2[0] == '-') {
        num2.erase(0, 1);
    }

    int size1 = num1.size();
    int size2 = num2.size();
    int i, j;

    // Инициализация строки для результата
    std::string res(size1 + size2, '0');

    // Умножение чисел
    for (i = size1 - 1; i >= 0; --i) {
        int carry = 0;
        for (j = size2 - 1; j >= 0; --j) {
            int temp = (res[i + j + 1] - '0') +
                       (num1[i] - '0') * (num2[j] - '0') + carry;
            res[i + j + 1] = (temp % 10) + '0';
            carry = temp / 10;
        }
        res[i + j + 1] = (res[i + j + 1] - '0' + carry) + '0';
    }

    // Удаление ведущих нулей
    i = 0;
    rs = res.size();
    while (i < rs && res[i] == '0') {
        ++i;
    }
    res = res.substr(i);

    // Если результат пустой, то это ноль
    if (res.empty()) {
        res = "0";
    }

    // Определяем знак результата
    BigInt summ(res);
    if ((this->check == 1 && value.check == -1) || (this->check == -1 && value.check == 1)) {
        summ = -summ;
    }

    return summ;
}



// BigInt BigInt::operator+(BigInt value) {
//     if (this -> check == 1 && value.check == 1) {
//         std::string num1 = this -> nums;
//         std::string num2 = value.nums;
//         std::string res;
//         int over = 0;
//         int i;
//         int summ;
//         int size1, size2;
//         while (num1.size() > num2.size()) {
//             num2 = "0" + num2;
//         }
//         while (num1.size() < num2.size()) {
//             num1 = "0" + num1;
//         }
//         size1 = num1.size();
//         size2 = num2.size();
//         for (i = 0; i < size1; ++i) {
//             summ = (num1[(size1 - 1) - i] - '0') +
//                (num2[(size2 - 1) - i] - '0') + over;
//             res = toString(summ%10) + res;
//             over = summ / 10;
// }
//         if (over == 1) {
//             res = toString(1) + res;
//         }
//         return BigInt(res);
//     } else if (this -> check == 1 && value.check == -1) {
//         value.check = 1; // Меняем знак value
//         return *this - value;    
//     } else if (this -> check == -1 && value.check == 1) {
//         this->check = 1; // Меняем знак текущего числа
//         return value - *this;       
//     } else if (this -> check == -1 && value.check == -1) {
//         this->check = 1; // Меняем знак обоих чисел
//         value.check = 1;
//         BigInt result = *this + value; // Складываем их модули
//         result.check = -1; // Устанавливаем отрицательный знак
//         return result;
//     } else if (this -> check == 0) {
//         return value;
//     } else if (value.check == 0) {
//         return *this;
//     } else {
//         return 0;
// } }

int BigInt::operator>(BigInt value) {
    std::string num1 = this -> nums;
    std::string num2 = value.nums;
    int nm1, nm2, sz1, sz2, i, mx = 0;

    while (num1.size() > num2.size()) {
        num2 = "0" + num2;
    }

    while (num2.size() > num1.size()) {
        num1 = "0" + num1;
    }


    if (num1 > num2) mx = 1;
    else if (num1 < num2) mx = 0;
    else {
        sz1 = this -> nums.size();
        sz2 = value.nums.size();

        for (i = 0; i < sz1; i++) {
            nm1 = this->nums[sz1 - 1 - i];
            nm2 = value.nums[sz2 - 1 - i];
            if (nm1 == nm2) continue;
            else if(nm1 > nm2) mx = 1;
            else if(nm1 < nm2) mx = 0;
        }
    }
    return mx;
}

int BigInt::operator>=(BigInt value) {
    std::string num1 = this -> nums;
    std::string num2 = value.nums;
    BigInt mx = 0;

    if ((int)(*this > value) || (num1 == num2)) mx = 1;

    return mx;
}

BigInt operator+(short value1, BigInt value2){
    return BigInt(value1) + value2;
}

BigInt operator+(BigInt value1, short value2){
    return value1 + BigInt(value2);
}

BigInt operator+(long value1, BigInt value2) {
    return BigInt(value1) + value2;
}

BigInt operator+(BigInt value1, long value2) {
    return value1 + BigInt(value2);
}

BigInt operator+(char value1, BigInt value2) {
    return BigInt(value1) + value2;
}

BigInt operator+(BigInt value1, char value2) {
    return value1 + BigInt(value2);
}

BigInt operator-(short value1, BigInt value2) {
    return BigInt(value1) - value2;
}
BigInt operator-(BigInt value1, short value2) {
    return value1 - BigInt(value2);
}
BigInt operator-(long value1, BigInt value2) {
    return BigInt(value1) - value2;
}
BigInt operator-(BigInt value1, long value2) {
    return value1 - BigInt(value2);
}
BigInt operator-(char value1, BigInt value2) {
    return BigInt(value1) - value2;
}
BigInt operator-(BigInt value1, char value2) {
    return value1 - BigInt(value2);
}

BigInt operator*(int value1, BigInt value2) {
    return BigInt(value1) * value2;
}
BigInt operator*(BigInt value1, int value2) {
    return value1 * BigInt(value2);
}
BigInt operator*(short value1, BigInt value2) {
    return BigInt(value1) * value2;
}
BigInt operator*(BigInt value1, short value2) {
    return value1 * BigInt(value2);
}
BigInt operator*(long value1, BigInt value2) {
    return BigInt(value1) * value2;
}
BigInt operator*(BigInt value1, long value2) {
    return value1 * BigInt(value2);
}
BigInt operator*(char value1, BigInt value2) {
    return BigInt(value1) * value2;
}
BigInt operator*(BigInt value1, char value2) {
    return value1 * BigInt(value2);
}

BigInt operator/(int value1, BigInt value2) {
    return BigInt(value1) / value2;
}
BigInt operator/(BigInt value1, int value2) {
    return value1 / BigInt(value2);
}
BigInt operator/(short value1, BigInt value2) {
    return BigInt(value1) / value2;
}
BigInt operator/(BigInt value1, short value2) {
    return value1 / BigInt(value2);
}
BigInt operator/(long value1, BigInt value2) {
    return BigInt(value1) / value2;
}
BigInt operator/(BigInt value1, long value2) {
    return value1 / BigInt(value2);
}
BigInt operator/(char value1, BigInt value2) {
    return BigInt(value1) / value2;
}
BigInt operator/(BigInt value1, char value2) {
    return value1 / BigInt(value2);
}

BigInt operator%(int value1, BigInt value2) {
    return BigInt(value1) % value2;
}
BigInt operator%(BigInt value1, int value2) {
    return value1 % BigInt(value2);
}
BigInt operator%(short value1, BigInt value2) {
    return BigInt(value1) % value2;
}
BigInt operator%(BigInt value1, short value2) {
    return value1 % BigInt(value2);
}
BigInt operator%(long value1, BigInt value2) {
    return BigInt(value1) % value2;
}
BigInt operator%(BigInt value1, long value2) {
    return value1 % BigInt(value2);
}
BigInt operator%(char value1, BigInt value2) {
    return BigInt(value1) % value2;
}
BigInt operator%(BigInt value1, char value2) {
    return value1 % BigInt(value2);
}

BigInt operator>=(int value1, BigInt value2) {
    return BigInt(value1) >= value2;
}
BigInt operator>=(BigInt value1, int value2) {
    return value1 >= BigInt(value2);
}
BigInt operator>=(short value1, BigInt value2) {
    return BigInt(value1) >= value2;
}
BigInt operator>=(BigInt value1, short value2) {
    return value1 >= BigInt(value2);
}
BigInt operator>=(long value1, BigInt value2) {
    return BigInt(value1) >= value2;
}
BigInt operator>=(BigInt value1, long value2) {
    return value1 >= BigInt(value2);
}
BigInt operator>=(char value1, BigInt value2) {
    return BigInt(value1) >= value2;
}
BigInt operator>=(BigInt value1, char value2) {
    return value1 >= BigInt(value2);
}

std::ostream& operator << (std::ostream &os, BigInt& bigint) {
    os << bigint.getValue();
    return os;
    
}

std::ostream& operator << (std::ostream &os, const BigInt& bigint) {
    os << bigint.getValue();
    return os;
    
}

std::istream& operator >> (std::istream &is, BigInt& bigint) {
    std::string value;
    int fg = 0;
    is >> value;

    fg = (value[0] == '-');
    
    if (fg) value = value.substr(1);

    if (value.empty() || value.find_first_not_of("0123456789") != std::string::npos) {
        std::cerr << "--------------Ошибка--------------" << std::endl;
        std::cerr << "|          Input failed          |" << std::endl;
        std::cerr << "| only this symbols are allowed  |" << std::endl;
        std::cerr << "|           -0123456789          |" << std::endl;
        std::cerr << "----------------------------------" << std::endl;
        exit(1);
    } else if (value[0] == '0' && value.size() >= 2) {
        std::cerr << "---------------Error--------------" << std::endl;
        std::cerr << "|          Number cannot         |" << std::endl;
        std::cerr << "|          start with '0'        |" << std::endl;
        std::cerr << "|                                |" << std::endl;
        std::cerr << "----------------------------------" << std::endl;
        exit(1);
    } else {
        if (fg) value = '-' + value;
        bigint = BigInt(value);
        return is;
    }
}
