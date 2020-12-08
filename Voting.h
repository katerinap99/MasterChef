//Aikaterini Patsoura, 9496, aikpatste@ece.auth.gr
//Papavasileiou Ioanna Maria,9375,ipapavas@ece.auth.gr

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

#include <vector>
#include <map>
#include <iostream>
#include "Vote.h"
#include <string>
#include "Team.h"

using namespace std;

class Voting{
public:
    static vector<Vote> votes ;
    static map<string,int> results;

    static void votingProcess(Team &team);
};

#endif // VOTING_H_INCLUDED
