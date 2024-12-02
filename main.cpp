#include <iostream>
#include "set.h"

int main() {
    //gtest
    BigInt value1, value2;
    BigInt resSum, resDif, resMul, resDiv, resOst, resGCD, resLCD;

    // std::cout << "Div test:" << std::endl;
    // value1 = 10; value2 = 3;
    // std::cout << "10 / 3 = " << (value1 / value2) << std::endl;
    // value1 = 10; value2 = -3;
    // std::cout << "10 / -3 = " << (value1 / value2) << std::endl;
    // value1 = -10; value2 = -3;
    // std::cout << "-10 / -3 = " << (value1 / value2) << std::endl;
    // value1 = -10; value2 = 3;
    // std::cout << "-10 / 3 = " << (value1 / value2) << std::endl;
    // value1 = 3; value2 = 10;
    // std::cout << "3 / 10 = " << (value1 / value2) << std::endl;
    // value1 = -3; value2 = 10;
    // std::cout << "-3 / 10 = " << (value1 / value2) << std::endl;
    // value1 = 10; value2 = 10;
    // std::cout << "10 / 10 = " << (value1 / value2) << std::endl;
    // value1 = -10; value2 = -10;
    // std::cout << "-10 / -10 = " << (value1 / value2) << std::endl;
    // value1 = -10; value2 = 10;
    // std::cout << "-10 / 10 = " << (value1 / value2) << std::endl;
    // value1 = 10; value2 = -10;
    // std::cout << "10 / -10 = " << (value1 / value2) << std::endl;


    // std::cout << "Ost test:" << std::endl;
    // value1 = 5; value2 = 2;
    // std::cout << "5 % 2 = " << (value1 % value2) << std::endl;
    // value1 = 5; value2 = -2;
    // std::cout << "5 % -2 = " << (value1 % value2) << std::endl;
    // value1 = -5; value2 = -2;
    // std::cout << "-5 % -2 = " << (value1 % value2) << std::endl;
    // value1 = -5; value2 = 2;
    // std::cout << "-5 % 2 = " << (value1 % value2) << std::endl;
    // value1 = 2; value2 = 5;
    // std::cout << "2 % 5 = " << (value1 % value2) << std::endl;
    // value1 = -2; value2 = 5;
    // std::cout << "-2 % 5 = " << (value1 % value2) << std::endl;
    // value1 = 5; value2 = 5;
    // std::cout << "5 % 5 = " << (value1 % value2) << std::endl;
    // value1 = -5; value2 = -5;
    // std::cout << "-5 % -5 = " << (value1 % value2) << std::endl;

    std::cout << "\n\n------------Big integer-----------" << std::endl;
    std::cout << "|Enter two numbers, which begin  |" << std::endl;
    std::cout << "|with either '-' or other number |" << std::endl;
    std::cout << "|number and this program  will   |" << std::endl;
    std::cout << "|show results of sum and dif     |" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::cout << "\n\n| First number:  ";
    std::cin >> value1;
    std::cout << "| Second number: ";
    std::cin >> value2;
    std::cout << "-------" << std::endl;

    // resSum.operator=(value1 + value2);
    // resDif.operator=(value1 - value2);
    // resMul.operator=(value1 * value2);
    // resDiv.operator=(value1 / value2);
    // resOst.operator=(value1 % value2);
    resGCD = resGCD.GCD(value1, value2);
    resLCD = resLCD.LCD(value1, value2);

    // std::cout << "| Sum res: " << resSum << std::endl;
    // std::cout << "| Dif res: " << resDif << std::endl;
    // std::cout << "| Mul res: " << resMul << std::endl;
    // std::cout << "| Div res: " << resDiv << std::endl;
    // std::cout << "| Ost res: " << resOst << std::endl;
    std::cout << "| GCD res: " << resGCD << std::endl;
    std::cout << "| LCD res: " << resLCD << std::endl;

    return 0;
}
