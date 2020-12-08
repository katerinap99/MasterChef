//Aikaterini Patsoura, 9496, aikpatste@ece.auth.gr
//Papavasileiou Ioanna Maria,9375,ipapavas@ece.auth.gr

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED


#include <iostream>
#include <string>
using namespace std;

class Vote {
    string voted;
    string reason;
public:
    Vote(){voted=""; reason = "";}
    Vote(string a,string b){voted=a; reason = b;}
    ~Vote(){cout << "Destroyed Object With Label: " << getvoted()<< endl;}
    string getvoted(){return voted;}
    string getreason(){return reason;}
    void setvoted(string a){voted = a;}
    void setreason(string b){reason = b;}
    void status(){cout << "Voted: "<<getvoted() << endl << "Reason: " << getreason() << endl;}
};

#endif // VOTE_H_INCLUDED
