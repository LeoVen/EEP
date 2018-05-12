#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{

    unsigned char a = 1, b = 23, c = 55, d = 110, e = 212;

    /* Operators
     *
     * [ & ] - AND
     * [ | ] - OR
     * [ ~ ] - NOT
     * [ << ] - Left Shift
     * [ >> ] - Right Shift
     * [ ^ ] - XOR
     */

    cout << " A = " << bitset<8>(a) << " = " << + a << endl;
    cout << " B = " << bitset<8>(b) << " = " << + b << endl;
    cout << " C = " << bitset<8>(c) << " = " << + c << endl;
    cout << " D = " << bitset<8>(d) << " = " << + d << endl;
    cout << " E = " << bitset<8>(e) << " = " << + e << endl;

    cout << endl;

    // AND
    cout << "\tAND Operator\n" << endl;
    cout << " [A: (" << bitset<8>(a) << ")] & [B: (" << bitset<8>(b) << ")] -> " << bitset<8>(a & b) << " = " << + (a & b) << endl;
    cout << " [B: (" << bitset<8>(b) << ")] & [C: (" << bitset<8>(c) << ")] -> " << bitset<8>(b & c) << " = " << + (b & c) << endl;
    cout << " [C: (" << bitset<8>(c) << ")] & [D: (" << bitset<8>(d) << ")] -> " << bitset<8>(c & d) << " = " << + (c & d) << endl;
    cout << " [D: (" << bitset<8>(d) << ")] & [E: (" << bitset<8>(e) << ")] -> " << bitset<8>(d & e) << " = " << + (d & e) << endl;

    cout << endl;
    // OR
    cout << "\tOR Operator\n" << endl;
    cout << " [A: (" << bitset<8>(a) << ")] | [B: (" << bitset<8>(b) << ")] -> " << bitset<8>(a | b) << " = " << + (a | b) << endl;
    cout << " [B: (" << bitset<8>(b) << ")] | [C: (" << bitset<8>(c) << ")] -> " << bitset<8>(b | c) << " = " << + (b | c) << endl;
    cout << " [C: (" << bitset<8>(c) << ")] | [D: (" << bitset<8>(d) << ")] -> " << bitset<8>(c | d) << " = " << + (c | d) << endl;
    cout << " [D: (" << bitset<8>(d) << ")] | [E: (" << bitset<8>(e) << ")] -> " << bitset<8>(d | e) << " = " << + (d | e) << endl;

    // NOT
    cout << "\tNOT Operator\n" << endl;    

    // Left Shift
    cout << "\tLeft Shift Operator\n" << endl;

    // Right Shift
    cout << "\tRight Shift Operator\n" << endl;

    // XOR
    cout << "\tXOR Operator\n" << endl;
    cout << " [A: (" << bitset<8>(a) << ")] | [B: (" << bitset<8>(b) << ")] -> " << bitset<8>(a ^ b) << " = " << + (a ^ b) << endl;
    cout << " [B: (" << bitset<8>(b) << ")] | [C: (" << bitset<8>(c) << ")] -> " << bitset<8>(b ^ c) << " = " << + (b ^ c) << endl;
    cout << " [C: (" << bitset<8>(c) << ")] | [D: (" << bitset<8>(d) << ")] -> " << bitset<8>(c ^ d) << " = " << + (c ^ d) << endl;
    cout << " [D: (" << bitset<8>(d) << ")] | [E: (" << bitset<8>(e) << ")] -> " << bitset<8>(d ^ e) << " = " << + (d ^ e) << endl;

    return 0;
}