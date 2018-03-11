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
        case   0: println("[00000] ( OK ) Success.");                                           break;
        case   1: println("[00001] ( ERROR ) Structure is empty.");                             break;
        case   2: println("[00002] ( ERROR ) Attempt of reset. Structure already empty.");      break;
        case   3: println("[00003] ( ERROR ) Attempt of removal. Structure is empty.");         break;
        case   4: println("[00004] ( ERROR ) Attempt of listing. Structure is empty.");         break;
        case   5: println("[00005] ( ERROR ) Attempt of insertion. Invalid position.");         break;
        case   6: println("[00006] ( ERROR ) Attempt of removal. Invalid position.");           break;
        case   7: println("[00007] ( ERROR ) Attempt of update. Invalid position.");            break;
            // Singly Linked List
        case 100: println("[00100] (OK) SLL Success");                                          break;
        case 101: println("[00101] ( ERROR ) SLL Structure is empty.");                         break;
        case 102: println("[00102] ( ERROR ) SLL Attempt of reset. Structure already empty.");  break;
        case 103: println("[00103] ( ERROR ) SLL Attempt of removal. Structure is empty.");     break;
        case 104: println("[00104] ( ERROR ) SLL Attempt of listing. Structure is empty.");     break;
        case 105: println("[00105] ( ERROR ) SLL Attempt of insertion. Invalid position.");     break;
        case 106: println("[00106] ( ERROR ) SLL Attempt of removal. Invalid position.");       break;
        case 107: println("[00107] ( ERROR ) SLL Attempt of update. Invalid position.");        break;
        case 108: println("[00108] ( ERROR ) SLL Attempt of cloning. Structure is empty.");     break;
        case 111: println("[00111] ( INFO ) List Initialized.");                                break;
        case 112: println("[00112] ( INFO ) List Reset and Initialized.");                      break;
        case 113: println("[00113] ( INFO ) Insert value at starting position.");               break;
        case 114: println("[00114] ( INFO ) Insert value at chosen position.");                 break;
        case 115: println("[00115] ( INFO ) Insert value at the last position.");               break;
        case 116: println("[00116] ( INFO ) First position removed.");                          break;
        case 117: println("[00117] ( INFO ) Chosen position removed.");                         break;
        case 118: println("[00118] ( INFO ) Last position removed.");                           break;
        case 119: println("[00119] ( INFO ) Entire List printed.");                             break;
        case 123: println("[00123] ( INFO ) List reset and initialized with random numbers.");  break;
        case 124: println("[00124] ( INFO ) Random numbers added.");                            break;
        case 125: println("[00125] ( INFO ) SLL Cloned");                                       break;
        // Array
        case 200: println("[00200] ( OK ) Array Success");                                      break;
        case 201: println("[00201] ( ERROR ) Array completely filled");                         break;
        case 210: println("[00210] ( INFO ) Successful insertion into array");                  break;
        case 211: println("[00211] ( INFO ) Successful push into array");                       break;
        case 500: println("[ 500 ] ( ERROR ) List not Initialized.");                           break;
        case 501: println("[ 501 ] ( ERROR ) Unexpected error.");                               break;
        default:  println("[?????] ( ????? ) Unknown error.");                                  break;
    }
}