# Studentų galutinio balo skaičiuoklė
## Programos versijos 
[v0.1](https://github.com/Step1st/2nd-Assignment/tree/v0.1)  
[v0.2](https://github.com/Step1st/2nd-Assignment/tree/v0.2)  
[v0.3](https://github.com/Step1st/2nd-Assignment/tree/v0.3)  
[v0.4](https://github.com/Step1st/2nd-Assignment/tree/v0.4)

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

#### Testavimo sistemos parametrai:
  CPU: Intel Core i7-10710U  
  Ram: 2 x SK Hynix DDR4-2666 8GB  
  SSD: Western Digital PC SN520 NVMe 512GB  

#### Testavimo rezultatai:

|Studentų skaičius | Generavimo laikas | Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- | ----------------- | ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- | 
| 1000             | 0.051983 s        | 0.0105604 s       | 0.0003101 s         | 0.0006044 s      | 0.0009792 s             | 0.0137528 s           |
| 10000            |  0.102473 s       |  0.0796106 s      |    0.0020251 s      |   0.0052371 s    |    0.0083455 s          |    0.0250293 s        |
| 100000           |  0.643024 s       |    0.780164 s     |     0.0179028 s     |      0.0642483 s |  0.0823578 s            |   0.100065 s          |
| 1000000          |  6.07747 s        |    7.89065 s      |     0.175481 s      |    0.764148 s    |   0.81658 s             |     0.94163 s         |
| 10000000         |  59.9028 s        |      78.8786 s    |     1.75618 s       |  8.64761 s       |   8.10971 s             |        9.09845 s      |

## Įdiegimas
Visus atsiustus failus įdėkite į viena atskyra aplankalą ir *v0.4.sln* failą atidarykite su Visual Studio.  
Atidarę šitam langelyje pasirinkite ```Release```   
  
![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/vsbuild1.png)

Toliau langelyje ```Build``` paspauskite ```Build Solution```   
  
![](https://raw.githubusercontent.com/Step1st/2nd-Assignment/assets/vsbuild2.png)  
  
Toliau jūsų aplankale turėtu atsirasti ```Release``` aplankalas kuriame ir bus pabaigtas programos failas

