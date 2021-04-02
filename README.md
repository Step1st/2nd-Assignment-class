# Studentų galutinio balo skaičiuoklė
## Programos versijos 
[v0.1](https://github.com/Step1st/2nd-Assignment/tree/v0.1)  
[v0.2](https://github.com/Step1st/2nd-Assignment/tree/v0.2)  
[v0.3](https://github.com/Step1st/2nd-Assignment/tree/v0.3)  
[v0.4](https://github.com/Step1st/2nd-Assignment/tree/v0.4)  
[v0.5](https://github.com/Step1st/2nd-Assignment/tree/v0.5)

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
Paleisti testavimo režimą galima per komandine eilutė į vedus flag’ą ```test``` ir konteinerį norimą patikrinti.
```
C:\Users\stolo\source\repos\v0.5\x64\Release>v0.5 test vector
```
Paleidus testavimo režimą programoje bus sugeneruoti `1000, 10000, 1000000, 10000000` studentų failai ir išmatuotas jų apdorojimo laikas pasirinktam konteineriui. Jeigu studentų failai jau egzistuoja nauji nebus generuojami.

```
C:\Users\stolo\source\repos\v0.5\x64\Release>v0.5 test vector
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

#### Vector:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- | 
| 1000             |  0.0353497 s       | 0.000225 s          | 0.0010648 s      | 0.0009733 s             | 0.022296 s            |
| 10000            |    0.0721342 s     |    0.0010962 s      |   0.0052371 s    |    0.0083455 s          |    0.0250293 s        |
| 100000           |     0.686503 s     |     0.0034008 s     |      0.0954395 s |  0.081143 s             |   0.106562 s          |
| 1000000          |   6.90946 s        |    0.0220216 s      |    1.12152 s     |   0.799415 s            |    1.00997 s          |
| 10000000         |       70.8632 s    |     0.272733 s      | 12.8804 s        |   7.99633 s             |       10.5594 s       |

#### List:

|Studentų skaičius | Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- | ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             | 0.0068402 s       | 0.0001927 s         | 0.0004039 s      | 0.0008633 s             | 0.0134239 s           |
| 10000            |  0.0658105 s      |    0.0006487 s      |   0.0050253 s    |    0.0086414 s          |    0.0282394 s        |
| 100000           |    0.651334 s     |     0.005143 s      |      0.0934613 s |  0.0933846 s            |   0.129447 s          |
| 1000000          |    6.50563 s      |     0.0593183 s     |    1.48599 s     |   0.8731 s              |     1.21993 s         |
| 10000000         |      65.8759 s    |     0.619371 s      |  20.5131 s       |   8.71794 s             |        12.2231        |

#### Deque:

|Studentų skaičius | Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- | ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- | 
| 1000             | 0.0081628 s       | 0.0005872 s         | 0.0010862 s      | 0.0009901 s             | 0.0136431 s           |
| 10000            |  0.0713746 s      |    0.0017012 s      |   0.0083788 s    |    0.0083946 s          |    0.0267434 s        |
| 100000           |    0.706195 s     |     0.00405 s       |      0.124205 s  |  0.0856192 s            |   0.116703 s          |
| 1000000          |    7.20883 s      |     0.0515288 s     |   1.49856 s      |   0.855429 s            |     1.09735 s         |
| 10000000         |     74.4758 s     |     0.534967 s      | 18.6328 s        |   8.46752 s             |     12.5377 s         |

## Įdiegimas
Visus atsiustus failus įdėkite į viena atskyra aplankalą ir *v0.4.sln* failą atidarykite su Visual Studio.  
Atidarę šitam langelyje pasirinkite ```Release```   
  
![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/vsbuild1.png)

Toliau langelyje ```Build``` paspauskite ```Build Solution```   
  
![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/vsbuild2.png)  
  
Toliau jūsų aplankale turėtu atsirasti ```Release``` aplankalas kuriame ir bus pabaigtas programos failas
