# Studentų galutinio balo skaičiuoklė
## Programos versijos 
[v0.1](https://github.com/Step1st/2nd-Assignment/tree/v0.1)  
[v0.2](https://github.com/Step1st/2nd-Assignment/tree/v0.2)  
[v0.3](https://github.com/Step1st/2nd-Assignment/tree/v0.3)  
[v0.4](https://github.com/Step1st/2nd-Assignment/tree/v0.4)  
[v0.5](https://github.com/Step1st/2nd-Assignment/tree/v0.5)  
[v1.0](https://github.com/Step1st/2nd-Assignment/tree/v1.0)  
[v1.1](https://github.com/Step1st/2nd-Assignment-class/tree/v1.1)  
[v1.2](https://github.com/Step1st/2nd-Assignment-class/tree/v1.2)  
[v1.5](https://github.com/Step1st/2nd-Assignment-class/tree/v1.5.1)  
[v2.0](https://github.com/Step1st/2nd-Assignment-class/tree/v2.0)  

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
C:\Users\stolo\source\repos\v0.5\x64\Release>v1.1 test1 vector
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

#### 2 strategija:

#### Vector(10000000):

#### Struct:

|Optimizavimo lygis|  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| /O1              |   42.269222 s      |    0.161010 s       |   10.963281 s    |   8.177022 s            |    9.126611 s         |
| /O2              |     42.336427 s    |    0.141348 s      | 10.291992 s       |   8.239003 s            |     9.200767 s        |

#### Class:

|Optimizavimo lygis|  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| /O1              |   50.669040 s      |    0.236547 s       |   29.778892 s    |  8.493949 s             |    9.477555 s         |
| /O2              |     49.334820 s    |     0.168400 s      | 27.023528 s      |   8.279520 s            |      9.206352 s       |

## Įdiegimas

### Naujodant installer'į

Paleiskite ```setup.exe``` installer'į, atlikite nurodytas instrukcijas installer'yje ir programa bus sėkmingai įdiegta. 

### Naudojant CMake
Visus atsiustus failus įdėkite į viena atskyra aplankalą ir CMake.   
CMake aplinkoje į ``` Where is the source code``` įrašykite kelią iki atsiustų failų, o į ``` Where to build the binaries``` įrašykite kelią kur norite gauti veikiančia programa.  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-1.png)  

Toliau paspauskite ``` Configure``` ir pasirinkite kokiai aplinkai generuosite projekta.   

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-2.png)  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-3.png)  
  
Toliau spauskite ``` Generate``` ir jūsų nurodytam kelyje bus paruostas projektas arba makefile’as  jūsų nurodytai aplinkai.  

![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/cmake-4.png)  
  

