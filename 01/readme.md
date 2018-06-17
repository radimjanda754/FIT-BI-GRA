Finanční situace Čistých drah (dále jen ČD) donutila přemýšlet společnost o optimalizaci poskytování dopravy. Potřebují seriózní studii o tom, které tratě by se daly zrušit, protože nejsou výdělečné a jejich údržba se nevyplácí. Zároveň si ale nesmí dovolit zrušit dopravní obslužnost mezi městy, která doposud spojená byla, protože by se starostové příliš hlučně ozývali.

Úkolem pro Vás je zjistit, které tratě mezi městy se dají zrušit tak, aby zůstala zachována dopravní obslužnost mezi všemi městy, v kterých Čisté dráhy poskytují dopravu. Zároveň chtějí ale tuto dosažitelnost udržovat s co nejnižšími náklady. Vyčíslení nákladů za rok v mil. korun na danou trať máte od ČD samozřejmě k dispozici. Navrhněte řešení a vyčíslete náklady na roční údržbu celé optimalizované sítě.

Když bylo představenstvem ČD vše projednáno a schváleno, všiml si jeden mladší člen dozorčí rady poznámky v projektech financovaných fondem rozvoje EU, že na nově rekonstruovaných tratích, na které byla dotace čerpána, garantují ČD provoz pro dalších 20 let. Tyto tratě tedy nesmíte v žádném případě zrušit!

Údaje poskytnuté ČD vypadají následovně: Máte N měst číslovaných od nuly a M dvojic měst, mezi kterými vede obousměrná trať. Města v této síti jsou navzájem propojená tak, že se dostanete z libovolného města do jiného. Tuto vlastnost rozhodně chtějí ČD zachovat. Předpokládejte dále, že N i M jsou řádově 10^4.

Vstup:
N M

seznam dotovaných tratí jako seznam dvojic měst I J mezi kterými vede trať, města jsou oddělena mezerou, jednotlivé dvojice čárkou. Vše na jednom řádku.

seznam tratí jako seznam trojic I J C, na každém řádku jedna trojice kde I a J jsou města, a C je celočíselný náklad na provoz. Pro jednoznačnost předpokládejme, že všechna C jsou navzájem různá.

Výstup:
S (součet nákladů na všechny tratě v optimalizované síti)

Výsledná síť reprezentovaná jako seznam následníků. Na každém řádku číslo města a vzestupně setříděný seznam sousedních měst. Řádky musí být setříděny vzestupně podle čísla města.

Příklad vstupu a výstupu
Vstup: 

11 18 
9 7,7 8,10 9,8 9 
9 7 129 
7 8 120 
4 8 150 
4 5 88 
1 2 77 
0 1 69 
10 9 142 
8 9 128 
10 8 136 
2 3 111 
1 10 132 
5 7 153 
4 6 104 
2 0 81 
2 4 110 
6 3 99 
3 4 83 
5 6 96 
 
Výstup:

1174 
0 1 
1 0 2 10 
2 1 4 
3 4 
4 2 3 5 
5 4 6 
6 5 
7 8 9 
8 7 9 
9 7 8 10 
10 1 9 

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

void cd( const char * inFile, const char * outFile )
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