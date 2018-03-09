/*
	Leonardo Vencovsky
	09/03/2018

    Error messagesz

*/

#include <utility.h>

void raise(int error)
{
    switch(error)
    {
        case   0: println("OK      [  0  ] Success.");                                         break;
        case   1: println("WARNING [  1  ] List is empty.");                                   break;
        case   2: println("WARNING [  2  ] Attempt of reset. List already empty.");            break;
        case   3: println("WARNING [  3  ] Attempt of removal. List is empty.");               break;
        case   4: println("WARNING [  4  ] Attempt of listing. List is empty.");               break;
        case   5: println("WARNING [  5  ] Attempt of insertion. Invalid position.");          break;
        case   6: println("WARNING [  6  ] Attempt of removal. Invalid position.");            break;
        case 101: println("INFO    [ 101 ] List Initialized.");                                break;
        case 102: println("INFO    [ 102 ] List Reset and Initialized.");                      break;
        case 103: println("INFO    [ 103 ] Insert value at starting position.");               break;
        case 104: println("INFO    [ 104 ] Insert value at chosen position.");                 break;
        case 105: println("INFO    [ 105 ] Insert value at the last position.");               break;
        case 106: println("INFO    [ 106 ] First position removed.");                          break;
        case 107: println("INFO    [ 107 ] Chosen position removed.");                         break;
        case 108: println("INFO    [ 108 ] Last position removed.");                           break;
        case 109: println("INFO    [ 109 ] Entire List printed.");                             break;
        case 113: println("INFO    [ 113 ] List reset and initialized with random numbers.");  break;
        case 114: println("INFO    [ 114 ] Random numbers added.");                            break;
        case 500: println("ERROR   [ 500 ] List not Initialized.");                            break;
        case 501: println("ERROR   [ 501 ] Unexpected error.");                                break;
        default:  println("ERROR   [00000] Unexpected error.");                                break;
    }
}