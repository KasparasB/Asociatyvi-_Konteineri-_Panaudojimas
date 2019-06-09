# Asociatyvių konteinerių kūrimas

### Užduoties formuluotė

1. Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: www.delfi.lt naujiena ar Hario Poterio knygos puslapis/fragmentas. Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
2. Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
3. URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!
4. Repozicija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.
5. Papildoma užduotis iš asociatyvių konteinerių ir/ar std::string tematikos bus paskirta egzamino metu "individualiai"!

Užduočiai atlikti pasinaudojau std::map rikiavimo konteinerį, kuris tam tikras poras suriša su unikaliu raktu. Šiai užduočiai tai labai naudinga, nes galima surišti žodį su vektoriumi, kuriame talpinu visų eilučių numerius, kuriuose tas žodis buvo pavartotas. 

Programos veikimas susideda iš kelių dalių:

```shell
        readUrl();
	read(reference);
	print(reference);
```
**1. Programa nuskaito visą vartotojo pateiktą tekstą, sudeda jį į std::vector tipo konteinerį ir ieško jame url adresų. Jeigu pavyksta rasti url adresą, programa perrašo duomenų failą taip, jog jame neliktų url adresų.**

url paieška vykdoma pagal kelis kriterijus. 
* Tikrinama ar adresas prasideda "https::/", "http::/", "www"
* Tikrinama ar adresas turi 2 taškus

Todėl adresas https://github.com/ neveiktų, nes turi tik vieną tašką, o www.delfi.lt veiktų, nes turi 2 taškus.

Labai patogu tai, jog tekstą galima dėti nesulygiuotą ir programa jį sutvarko.

**2. Nuskaitomas tekstas ir ištrinami tokie simboliai kaip: **',','-','.','!','?','(', ')','„','–','“' **
**3. Viso teksto žodžių raidės nustatomos mažosiomis **
**4. Į konteinerį sudedami žodžiai išsaugant jų eilutės numerį **
**5. Rezultatas išvedamas į failą **

### Teksto pavyzdys

```shell

Tikrai nesirengiau dar kartą sugrįžti prie balandžio mėnesį mano aprašytosios Čekijos cirko gastrolių Lietuvoje temos, sukėlusios aštrią neabejingos Lietuvos visuomenės dalies diskusiją. Tačiau dienos bėga, o situacija visiškai nesikeičia. Negana to, svečiai iš Čekijos, peržengdami visas padorumo ribas, tiesiog įžūliai tyčiojasi iš mūsų. Gegužės mėnesio pradžioje Seimo narys Linqas Balsys, dar 2017 metais Seime įregistravęs Gyvūnų gerovės ir apsaugos įstatymo pataisas, kreipėsi į Aplinkos ministeriją, Aplinkos apsaugos agentūrą, Valstybinę maisto ir veterinarinę tarnybą bei Kelių direkciją prie Susisiekimo ministerijos dėl balandžio 30 dieną Šiauliuose gatvėmis vedžioto dramblio.

Skaitykite daugiau: https://www.15min.lt/naujiena/aktualu/lietuva/alvidas-jancevicius-dar-karta-apie-dramblius-lietuvoje-56-1155322?copied

```

### Rezultato pavyzdys

```shell
Rasti url adresai:
https://www.15min.lt/naujiena/aktualu/lietuva/alvidas-jancevicius-dar-karta-apie-dramblius-lietuvoje-56-1155322?copied

Zodziai     |Pasikartojimu skaicius |Eilutes|
-----------------------------------------
aplinkos    |2                      |7 7  |
apsaugos    |2                      |6 7  |
balandžio   |2                      |1 9  |
cekijos     |2                      |2 4  |
dar         |2                      |1 6  |
ir          |2                      |6 8  |
iš          |2                      |4 5  |
prie        |2                      |1 8  |
```

### Išrikiuotas tekstas

```shell
Tikrai nesirengiau dar karta sugrižti prie balandžio menesi mano aprašytosios
Cekijos cirko gastroliu Lietuvoje temos, sukelusios aštria neabejingos Lietuvos visuomenes
dalies diskusija. Taciau dienos bega, o situacija visiškai nesikeicia. Negana
to, sveciai iš Cekijos, peržengdami visas padorumo ribas, tiesiog ižuliai
tyciojasi iš musu. Gegužes menesio pradžioje Seimo narys Linqas Balsys,
dar 2017 metais Seime iregistraves Gyvunu geroves ir apsaugos istatymo
pataisas, kreipesi i Aplinkos ministerija, Aplinkos apsaugos agentura, Valstybine maisto
ir veterinarine tarnyba bei Keliu direkcija prie Susisiekimo ministerijos del
balandžio 30 diena Šiauliuose gatvemis vedžioto dramblio. Skaitykite daugiau:
```
Reikia nepamiršti, jog programa spausdina tik tuos žodžius, kurie pasikartoja daugiau nei 1 kartą:

Lentelei sudaryti naudojamos funkcijos: 
* **int repeatingLength(map<string, vector<int>> &reference)** 
* **int wordLength(map<string, vector<int>>& wordsNumbers)**
