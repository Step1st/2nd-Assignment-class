# Studentų galutinio balo skaičiuoklė
## Programos versijos 
[v0.1](https://github.com/Step1st/2nd-Assignment/tree/v0.1)  
[v0.2](https://github.com/Step1st/2nd-Assignment/tree/v0.2)  
[v0.3](https://github.com/Step1st/2nd-Assignment/tree/v0.3)  
[v0.4](https://github.com/Step1st/2nd-Assignment/tree/v0.4)  
[v0.5](https://github.com/Step1st/2nd-Assignment/tree/v0.5)  
[v1.0](https://github.com/Step1st/2nd-Assignment/tree/v1.0)

##  Programos naudojimas ir veikimo principas
### Veikimo princimas
Šioje programoje bus apskaičiuotas studentų galutinis balas ir išvestas  tokiu pavidalų: 
```
First name          Last name           Final grade(average)
-----------------------------------------------------------
Steponas            Tolomanovas          9.30
```
Programoje įvedus arba atitiktinai sugeneravus pažymius už namų darbus ir egzaminą galutinis balas suskaičiuojamas pagal tokią 
formulę: ```Galutinis = 0.4 * vidurkis + 0.6 * egzaminas``` Visi pažymiai bei jų kiekiai gali būti įvedami ranka arba atitiktinai sugeneruojami.
Taip pat yra galimybė vietoj vidurkio galutinio balo skaičiavimui galima naudoti medianą:
```
First name          Last name           Final grade(median)
----------------------------------------------------------
Steponas            Tolomanovas          9.40
```
### Programos naudojimas
Paleidus programą bus paklausta ar norima duomenys apie studentus skaityti iš failo ar įvesti ranka.
```
Get students from file or enter manually?(f/m): m
Enter the number of students:
```
#### Pasirinkus skaityti iš failo
Pasirinkus skaityti iš failo programoje bus paklausta ***naudoti egzistuojanti faila ar generuoti nauja***.
```
Get students from file or enter manually?(f/m): f
Use exiting file or generate?(e/g):
```
Pasirinkus e(egzistuojanti) programoje bus nuskaitytas kursiokai.txt failas, duomenys apdorojami ir rezultatas bus išvedamas į output.txt failą. (kursiokai.txt failas turi būti tam pačiam aplankale kaip ir programa)
```
Get students from file or enter manually?(f/m): f
Use exiting file or generate?(e/g): e
Use median for final grade?(y/n): y
Reading...
Reading took 7.83969 s
Calculating...
Calculating took 0.175532 s
Writing...
writing to buffer took 0.798725 s
Writing took 0.925016 s
Press any key to continue . . .
```
Pasirinkus g(generuoti) programoje bus paprašyta įvesti studentų skaičių. Įvedus bus Sugeneruotas failas kursiokai.txt. Toliau programoje bus nuskaitytas kursiokai.txt failas, duomenys apdorojami ir rezultatas bus išvedamas į du failus, kietiakiai.txt ir vargšiukai.txt.
```
Get students from file or enter manually?(f/m): f
Use exiting file or generate?(e/g): g
Enter the number of students: 10000000

Generating...
Generating took 59.9028 s
Reading...
Reading took 78.8786 s
Calculating...
Calculating took 1.75618 s
Sorting...
Sorting took 8.64761 s
Writing...
writing to buffer took 8.10971 s
Writing took 9.09845 s
Press any key to continue . . .
```

#### Pasirinkus ranka
Pasirinkus įvesti ranka bus paprašyta įvesti studentų kiekį. Įvesti galima tik skaitmenis, įvedus kitus simbolius bus pranešta apie klaidą ir paprašyta įvesti studentų kiekį dar karta, kol nebus įrašytas tinkamas skaičius.
```
Enter the number of students: two

Error! Please enter only digits
Try to enter your number again: 2
```
Įvedus studentų skaičių bus paprašyta įvesti kiekvienam studentui vardą, pavardę ar žinomas pažymių kiekis (***jei taip tai įvesti jį***), sugeneruoti pažymius atitiktinai ar įvesti pačiam. Vardui ir pavardei galima naudoti tik raides, į klausimus ***žinomas pažymių kiekis*** ir ***ar sugeneruoti pažymius atitiktinai*** atsakymai gali būti tik y(taip) n(ne), o pažymiai gali būti nuo 0 iki 10 imtinai. Taip pat privalo būti nors vienas namų darbų pažymys.
```
Enter the number of students: two

Error! Please enter only digits
Try to enter your number again: 2

Enter students first name: Steponas

Enter students last name: Tolomanovas

Is the number of grades known?(y/n): y
Enter the number of grades: 5

Generate grades randomly?(y/n): n
1. Enter grade: 8
2. Enter grade: 9
3. Enter grade: 10
4. Enter grade: 9
5. Enter grade: 10

Enter students exam grade: 9
```
Pasirinkus nežinomą pažymių kiekį bei įvedinėjimą juos ranka, pabaigti įvedimą galima įvedus ```end```
```
Enter students first name: Vardenis 

Enter students last name: Pavardenis
Is the number of grades known?(y/n): n

Generate grades randomly?(y/n): n

To finish entering grades type in 'end'
1. Enter grade: 7
2. Enter grade: 10
3. Enter grade: 8
4. Enter grade: 9
5. Enter grade: end

Enter students exam grade: 10
```
Įvedus visus studentus programoje bus paklausta ***ar naudoti mediana galutiniam pažymiui***. Pasirinkus n(ne) bus naudojimas vidurkis.
```
Use median for final grade?(y/n): y
```
Pasirinkus vidurki ar mediana bus išvestų studentų galutiniai pažymiai.
```
Use median for final grade?(y/n): y

First name          Last name           Final grade(median)
----------------------------------------------------------
Steponas            Tolomanovas          9.00
Vardenis            Pavardenis           9.40
```
## Testavimas
#### Testavimo režimas
Paleisti testavimo režimą galima per komandine eilutė į vedus flag’ą ```test1``` arba ```test2``` ***(priklausomai kurią strategiją norite patikrinti)*** ir konteinerį norimą patikrinti. 
```
C:\Users\stolo\source\repos\v0.5\x64\Release>v0.5 test1 vector
```
Paleidus testavimo režimą programoje bus sugeneruoti `1000, 10000, 1000000, 10000000` studentų failai ir išmatuotas jų apdorojimo laikas pasirinktam konteineriui. Jeigu studentų failai jau egzistuoja nauji nebus generuojami.

```
C:\Users\stolo\source\repos\v0.5\x64\Release>v0.5 test1 vector
Generating...
Generating 1000 took 0.023594 s
Generating...
Generating 10000 took 0.0613205 s
Generating...
Generating 100000 took 0.52451 s
Generating...
Generating 1000000 took 5.195 s
Generating...
Generating 10000000 took 51.0129 s

Vector
Reading...
Reading took 0.009010 s
Calculating...
Calculating took 0.000577 s
Sorting...
Sorting took 0.000914 s
Writing...
writing to buffer took 0.001047 s
Writing took 0.013780 s
...
```

#### Testavimo sistemos parametrai:
  CPU: Intel Core i7-10710U  
  RAM: 2 x SK Hynix DDR4-2666 8GB  
  SSD: Western Digital PC SN520 NVMe 512GB  

#### Testavimo rezultatai:

#### 1 strategija:

#### Vector:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.018525 s        | 0.000531 s          | 0.000665 s       |  0.000829 s             | 0.001698 s            |
| 10000            |    0.048041 s      |    0.000685 s       |   0.007394 s     |    0.007873 s           |    0.011220 s         |
| 100000           |     0.615828 s     |     0.002930 s      |      0.078734 s  |  0.082460 s             |   0.097304 s          |
| 1000000          |   4.115486 s       |    0.018452 s       |   0.994884 s     |   0.802577 s            |    0.924011 s         |
| 10000000         |     26.890814 s    |     0.086319 s      | 5.485796 s       |   4.382828 s            |      4.958608 s       |

#### List:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.019897 s        |0.000136 s           | 0.000342 s       | 0.000859 s              |0.001933 s             |
| 10000            |   0.049986 s       |    0.000558 s       |   0.004659 s     |   0.007986 s            |   0.010934 s          |
| 100000           |     0.609269 s     |    0.006022 s       |     0.067790 s   |  0.094484 s             |   0.107240 s          |
| 1000000          |   4.303545 s       |    0.032977 s       |    0.974123 s    |   0.835239 s            |    0.968338 s         |
| 10000000         |       26.807541 s  |     0.202444 s      | 6.424478 s       |   4.688235 s            |       5.230455 s      |

#### Deque:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.019134 s        | 0.000207 s          | 0.000647 s       |  0.000862 s             | 0.002151 s            |
| 10000            |    0.044909 s      |    0.000397 s       |  0.008070 s      |    0.008108 s           |   0.011065 s          |
| 100000           |     0.609020 s     |     0.004744 s      |      0.100477 s  |  0.083608 s             |   0.096319 s          |
| 1000000          |   4.110294 s       |    0.030471 s       |    1.359355 s    |   0.865812 s            |    0.992446 s         |
| 10000000         |       27.120232 s  |    0.201896 s       | 7.768315 s       |   4.511575 s            |      5.011196 s       |


#### 2 strategija:

#### Vector:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007720 s        | 0.000188 s          | 0.000597 s       | 0.000834 s              | 0.001869 s            |
| 10000            |    0.039074 s      |    0.000365 s       |   0.005998 s     |    0.007923 s           |    0.010746 s         |
| 100000           |     0.548156 s     |     0.003233 s      |     0.065653 s   |  0.078402 s             |    0.091283 s         |
| 1000000          |   3.792698 s       |    0.016268 s       |    0.875766 s    |  0.754080 s             |    0.852496 s         |
| 10000000         |      24.485012 s   |     0.079543        | 4.940063 s       |   4.115565 s            |       4.653740 s      |

#### List:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007212 s        | 0.000217 s          | 0.000285 s       |  0.000996 s             |  0.004266 s           |
| 10000            |    0.039058 s      |    0.000630 s       |   0.003773 s     |    0.008353 s           |    0.011525 s         |
| 100000           |     0.567019 s     |     0.005614 s      |      0.065533 s  |  0.088193 s             |   0.101014 s          |
| 1000000          |   3.745888 s       | 0.035473 s          |    1.029524 s    |   0.832052 s            |     0.934534 s        |
| 10000000         |       24.862976 s  |     0.220341 s      | 7.123599 s       |   4.502971 s            |      5.000355 s       |

#### Deque:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007146 s        | 0.000179 s          | 0.000624 s       | 0.000860 s              |0.002058 s             |
| 10000            |     0.038378 s     |     0.000398 s      |  0.006895 s      |    0.008412 s           |    0.011029 s         |
| 100000           |    0.577493 s      |      0.005186 s     |      0.094161 s  |  0.081560 s             |   0.095201 s          |
| 1000000          |   3.726173 s       |    0.030681 s       |   1.230832 s     |   0.792141 s            |    0.885720 s         |
| 10000000         |      24.494511 s   |     0.214100 s      | 7.127771 s       |   4.356007 s            |      4.822920 s       | 

## Įdiegimas
Visus atsiustus failus įdėkite į viena atskyra aplankalą ir CMake.   
CMake aplinkoje į ``` Where is the source code``` įrašykite kelią iki atsiustų failų, o į ``` Where to build the binaries``` įrašykite kelią kur norite gauti veikiančia programa.  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-1.png)  

Toliau paspauskite ``` Configure``` ir pasirinkite kokiai aplinkai generuosite projekta.   

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-2.png)  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-3.png)  
  
Toliau spauskite ``` Generate``` ir jūsų nurodytam kelyje bus paruostas projektas arba makefile’as  jūsų nurodytai aplinkai.  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-4.png)  
  

