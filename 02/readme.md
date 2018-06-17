Věc: Sledování činnosti ženského spolku FIT (Female Information Transfer).

V několika městech (s několika desítkami tisíc obyvatel) byla s úspěchem rozjeta činnost tajné ženské organizace, zabývající se šířením zpráv o dění ve městě. Komunikační síť v rámci jednoho města je propojena tak důmyslně, že ať zprávu odešle KTERÁKOLIV žena v daném městě, za chvíli ji postupným předáváním zpráv obdrží všechny ženy v tomto městě. Zároveň ale ženy nevědí, od koho zprávu dostávají, protože každá žena zná pouze kontakty, kam má zprávu rozeslat.

Spolek a systém komunikace v něm byl nastaven dobře, ale zjistili jsme v poslední době, že prosakují informace do sousedních měst, což chceme zamezit. Potřebujeme tedy odhalit dvojité agentky, které se infiltrovaly do spolku v jednom městě, ale odesílají zprávy i do jiných měst. Takové agentky je nutné včas odhalit.

Přikládáme seznam členek, které jsou spolu ve spojení. Členky jsou označeny kódovými čísly 0, 1, ..., N - 1. Seznam má následující formát:

Vstup:
N

Cislo1 mezera Cislo2

kde Cislo1 značí ženu, která má kontakt na ženu Cislo2 a té může odeslat zprávu. Nepodařilo se nám však bohužel včas roztřídit údaje od zpravodajů, a tak se nám smíchaly seznamy z jednotlivých měst. Nevíme tedy, která žena patří do kterého města.

Výstup:
Výstupem by měl být vzestupně setříděný seznam těch členek, které informují ženy z jiného než ze svého města. Očekáváme na každém řádku jedno číslo členky.

Příklad vstupu a výstupu
Vstup: 
 
11 
0 1 
1 2 
1 10 
2 0 
2 3 
2 4 
3 4 
4 5 
4 6 
4 8 
5 6 
5 7 
6 3 
7 8 
8 9 
9 7 
10 8 
10 9 
 
Výstup:

1 
2 
4 
5 
10 


Při implementaci máte k dispozici datové struktury z STL, viz ukázka. Struktury z STL použít můžete, ale nemusíte.

#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <list>
#include <stdint.h>

using namespace std;
#endif /* __PROGTEST__ */

void fit( const char * inFile, const char * outFile )
 {
   // mandatory, todo
 }


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   // tests
   return 0;
 }
#endif /* __PROGTEST__ */