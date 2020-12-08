//Aikaterini Patsoura, 9496, aikpatste@ece.auth.gr
//Papavasileiou Ioanna Maria,9375,ipapavas@ece.auth.gr

#include "Voting.h"

using namespace std;

//synarthsh diadikasias pshfoforias
void Voting::votingProcess(Team &team){
    int num = team.getNumberOfPlayers();
    Player *p;
    p= team.getPlayers();     //pinakas gia prosbash stous paiktes kathws einai private metablhth sthn klash Team
    for(int i=0; i<num; i++){
            for(int v=p[i].getVotes();v>0;v--){             //kathe paikths pshfizei oses fores dikaoutai analoga me to an exei asylia h oxi
           		 if(p[i+1].getImmunity()== false && p[i-1].getImmunity()== false ){     //an o prohgoumenos kai o epomenos ston pinaka den exoyn
                    if((i+1)<num)                                                       // asylia mporoun na pshfistoun.Osos den bgainoume ektos oriwn pinaka
                        {Voting::votes[i].setvoted(p[i+1].getName());                   //o paikths pshfizei auton pou einai sthn epomenh thesh tou pinaka
                        Voting::votes[i].setreason("Den kserei na mageireuei");}
                    else
                        {Voting::votes[i].setvoted(p[i-1].getName());                   //alliws pshfizei auton sthn prohgoumenh thesh
                        Voting::votes[i].setreason("Den exei plaka");}}
        		else {                                                                  //an oi paiktes sthn prohgoumenh kai epomenh thesh tou pinaka
               		 if((i+2)<num){                                                     // exoun asylia tote pshfizetai autos pou einai dyo theseis meta
                    Voting::votes[i].setvoted(p[i+2].getName());
                    Voting::votes[i].setreason("Vromaei");}
           		 else                                                                   //an bgoume ektos oriwn phsfizei auton pou einai dyo theseis prin
                {Voting::votes[i].setvoted(p[i-2].getName());
                Voting::votes[i].setreason("Me evrise");}
        }
            }
    }
    int t= Voting :: votes.size();                              //megethos vector
    for(int i=0; i<t; i++){
        Voting::votes[i].status();
    }
    int a[t];
    for(int i=0; i<t; i++){                             //pinakas gia na metraei tis pshfous tou kathe paikth
        a[i]=0;
    }

    string names[t];                                    //pinakas gia na krataei ta onomata oswn pshfisthkan
    for(int i=0;i<t;i++)
        names[t]="";

    for(int i=0;i<t;i++){
        for(int k=0;k<t;k++){
            if(votes[i].getvoted()!= names[k])                              //an einai h prwth fora pou katagrafontai h pshfoi
                a[i]=1;                                                     //tote exei mia pshfo
                names[i]=votes[i].getvoted();                               //kai krataw to onoma autou pou pshfisthke sth thesh i tou pinaka names
        }
        for(int j=1;j<t-1;j++){
            if((i+j)<t){
                if(votes[i].getvoted()==votes[i+j].getvoted())        //otan brethoun dyo pshfoi ston idio paikth i
                    a[i]++;                                             //auksanei ton arithmo twn pshfwn sthn thesh i tou pinaka a
            }
        }

    }

    for(int i=0; i<t ; i++){
        Voting :: results.insert(pair<string,int> (names[i],a[i]));          //xarths me ta onomata twn pshfismenwn kai ton arithmo pshfwn tou kathena
    }
    map<string,int>::const_iterator mp = Voting :: results.begin();
    while(mp!= Voting::results.end()){
        cout << mp->first << " " << mp->second << endl;                        //ektupwsh xarth
        mp++;

    }
    int max=a[0];
    int index1=0;
    string candidate1 ="";
    string candidate2="";
    for(int i=0; i<t; i++){
        if(a[i]!=0&&names[i]!=""){
            if(a[i]>max){
                index1=i;                                   //o index1 krataei th thesh
                max=a[i];
                candidate1=names[i];                        //to candidate1 krataei to onoma autou me tis perissoteres pshfous ws prwto ypopshfio
          }                                                 //max o arithmos twn perissoterwn pshfwn se atomo
        }
    }
    a[index1]=-1;
    max = 0;
    for(int i=0; i<t; i++){
            if(a[i]!=0&&names[i]!=""){
                if(i!=index1 && a[i]>max ){                            //o index2 krataei th thesh tou deuteroy upopshfiou
                    max=a[i];                                          //pou einai aytos me tis deuteres perssoteres pshfous
                    candidate2=names[i];                               //to candidate2 krataei to onoma tou
            }
        }
    }
    int indexCandidate1=0,indexCandidate2=0;
    for(int i=0;i<num;i++){
        if(p[i].getName()==candidate1){
            i=indexCandidate1;
        }
        else if(p[i].getName()==candidate2){
            i=indexCandidate2;
        }
    }
    p[indexCandidate1].setCandidate(true);
    p[indexCandidate2].setCandidate(true);

    if(p[indexCandidate1].getTechnique()< p[indexCandidate2].getTechnique()){
        team.removePlayer(indexCandidate1);
    }else{
    team.removePlayer(indexCandidate2);}
    }


