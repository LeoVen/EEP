/**
 * @file bitwise.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 12/05/2018
 * 
 * Demonstration of Bitwise operators
 */
#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{

    unsigned char a = 212, b = 1, c = 110, d = 59, e = 0;

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
    cout << endl;

    // NOT
    cout << "\tNOT Operator\n" << endl;
    unsigned char an = ~ a;
    unsigned char bn = ~ b;
    unsigned char cn = ~ c;
    unsigned char dn = ~ d;
    unsigned char en = ~ e;
    cout << " ~ [A: (" << bitset<8>(a) << ")] -> " << bitset<8>(~ a) << " = " << + an << endl;
    cout << " ~ [B: (" << bitset<8>(b) << ")] -> " << bitset<8>(~ b) << " = " << + bn << endl;
    cout << " ~ [C: (" << bitset<8>(c) << ")] -> " << bitset<8>(~ c) << " = " << + cn << endl;
    cout << " ~ [D: (" << bitset<8>(d) << ")] -> " << bitset<8>(~ d) << " = " << + dn << endl;
    cout << " ~ [E: (" << bitset<8>(e) << ")] -> " << bitset<8>(~ e) << " = " << + en << endl;
    cout << endl;

    /* Left Shift
     * 
     * first_operand << second_operand
     * 
     * first: Whose bits get left shifted
     * second: Number of places to be shifted
     * 
     * Trailing positions are filled with zero
     * Leading bits are truncated
     * 
     * var = x;
     * var << y;
     * 
     * Is the same as [x * 2^y]
     * - if the size can hold a number that big
     * 
     */
    cout << "\tLeft Shift Operator\n" << endl;
    unsigned char al = a << 1;
    unsigned char bl = b << 2;
    unsigned char cl = c << 3;
    unsigned char dl = d << 4;
    unsigned char el = e << 5;
    cout << " [A: (" << bitset<8>(a) << ")] << 1 -> " << bitset<8>(a << 1) << " = " << + al << endl;
    cout << " [B: (" << bitset<8>(b) << ")] << 2 -> " << bitset<8>(b << 2) << " = " << + bl << endl;
    cout << " [C: (" << bitset<8>(c) << ")] << 3 -> " << bitset<8>(c << 3) << " = " << + cl << endl;
    cout << " [D: (" << bitset<8>(d) << ")] << 4 -> " << bitset<8>(d << 4) << " = " << + dl << endl;
    cout << " [E: (" << bitset<8>(e) << ")] << 5 -> " << bitset<8>(e << 5) << " = " << + el << endl;
    cout << endl;

    /* Right Shift
     * 
     * first_operand >> second_operand
     * 
     * first: Whose bits get left shifted
     * second: Number of places to be shifted
     * 
     * Leading positions are filled with zero
     * Trailing bits are truncated
     * 
     * var = x;
     * var >> y;
     * 
     * Is the same as [x / 2^y]
     * - if the size can hold a number that big
     * - decimal positions are removed
     * 
     */
    cout << "\tRight Shift Operator\n" << endl;
    unsigned char ar = a >> 1;
    unsigned char br = b >> 2;
    unsigned char cr = c >> 3;
    unsigned char dr = d >> 4;
    unsigned char er = e >> 5;    
    cout << " [A: (" << bitset<8>(a) << ")] >> 1 -> " << bitset<8>(a >> 1) << " = " << + ar << endl;
    cout << " [B: (" << bitset<8>(b) << ")] >> 2 -> " << bitset<8>(b >> 2) << " = " << + br << endl;
    cout << " [C: (" << bitset<8>(c) << ")] >> 3 -> " << bitset<8>(c >> 3) << " = " << + cr << endl;
    cout << " [D: (" << bitset<8>(d) << ")] >> 4 -> " << bitset<8>(d >> 4) << " = " << + dr << endl;
    cout << " [E: (" << bitset<8>(e) << ")] >> 5 -> " << bitset<8>(e >> 5) << " = " << + er << endl;
    cout << endl;

    // XOR
    cout << "\tXOR Operator\n" << endl;
    cout << " [A: (" << bitset<8>(a) << ")] | [B: (" << bitset<8>(b) << ")] -> " << bitset<8>(a ^ b) << " = " << + (a ^ b) << endl;
    cout << " [B: (" << bitset<8>(b) << ")] | [C: (" << bitset<8>(c) << ")] -> " << bitset<8>(b ^ c) << " = " << + (b ^ c) << endl;
    cout << " [C: (" << bitset<8>(c) << ")] | [D: (" << bitset<8>(d) << ")] -> " << bitset<8>(c ^ d) << " = " << + (c ^ d) << endl;
    cout << " [D: (" << bitset<8>(d) << ")] | [E: (" << bitset<8>(e) << ")] -> " << bitset<8>(d ^ e) << " = " << + (d ^ e) << endl;

    return 0;
}