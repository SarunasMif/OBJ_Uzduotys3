# Obj_Uzduotys2

# Realizacijos sparta be optimizavimo

100.000 studentu failo:
Class: 0.061102 sekundes
Struct: 0.0316057 sekundes

1.000.000 studentu failo:
Class: 0.795095 sekundes
Struct: 0.319547 sekundes

## Realizacijos sparta su optimizavimo lygiais 
### 100.000 studentų
| Optimization | Struct | Class | File size Struct | File size Class |
| :---: | :---: | :---: | :---: | :---: |
| O1 | 0.0127796 sekundes. | 0.027290 sekundes. | 260 KB | 254 KB |
| O2 | 0.0124957 sekundes. | 0.027528 sekundes. | 270 KB | 260 KB |
| O3 | 0.0118180 sekundes. | 0.028570 sekundes. | 255 KB | 256 KB |


### 1.000.000 studentų
| Optimization | Struct | Class | File size Struct | File size Class |
| :---: | :---: | :---: | :---: | :---: | 
| O1 | 0.129661 sekundes. | 0.447003 sekundes. |260 KB| 254 KB |
| O2 | 0.118778 sekundes. | 0.455142 sekundes. |270 KB| 260 KB | 
| O3 | 0.117472 sekundes. | 0.442860 sekundes. |255 KB| 256 KB |

# Class
## Class Structure

`Person` bazine abstrakcia klase sudaro sie nariai:
- `student_name`: string tipo kintamasis, kuri sudaro studento vardas.
- `student_surname`: string tipo kintamasis, kuri sudaro studento pavarde.

`Student_Data` derived klase sudaro sie nariai:

- `exam`: Duoble tipo kintamasis, kuri sudaro egzamino pazimys.
- `HW`: Duoble vektorius, kuri sudaro namu darbu pazymiai.

# Duomenu ivedimas

`SetName();`
`SetSurname();`
`SetExam():`
`SetHW(); `

Manual ivedimas:

    Student_Data Sdata;
    Sdata.SetName("Vardas");
    Sdata.SetSurname("Pavarde");
    Sdata.SetExam(8);
    Sdata.SetHW({4, 5, 6, 7});

Automatinis ivedimas:

    //main_vector.cpp
    Student_Data Sdata;
    string str_placeholder;

    cin >> Sdata; //Nuveda i Studentas.cpp

    vector<double> HomeWork;
    int Number_Of_Homework = 10;
    for (int i = 0; i < Number_Of_Homework; i++) {
        cout << "Iveskite namudarbo pazymi: ";
        cin >> str_placeholder;
        HomeWork.push_back(stoi(str_placeholder));
    }

    Sdata.SetHW();
    cout << "Iveskite egzamino pazymi: ";
    cin >> str_placeholder;
    Sdata.SetExam(stoi(str_placeholder));

    //Studentas.cpp
    string s_name, s_surname;

    cout << "Iveskite studento varda ir pavarde: ";
    set >> s_name;
    set >> s_surname;

    Sdata.SetName(s_name);
    Sdata.SetSurname(s_surname);

File ivedimas:

    //main_vector.cpp
    vector<Student_Data> Sdata;
    string filename = "kursiokai.txt"
    string str_placeholder;

    ifstream Read;

    Read.open(filename);

    getline(Read, str_placeholder);

    auto start = high_resolution_clock::now();

    while(getline(Read, str_placeholder)){
        Student_Data Adata;

        istringstream get(str_placeholder);
        Adata.readStudent(get); //nuveda i Studentas.cpp
        Sdata.push_back(Adata);

    }
    
    Read.close();

    //Studentas.cpp
    is >> student_name >> student_surname;

    HW.clear();

    double mark;
    while(is >> mark) {
      HW.push_back(mark);
    }

    exam = HW.back();
    HW.pop_back();

# Duomenu isvedimas

`vardas();`
`pavarde();`
`egzaminas();`
`ND();`

    Student_Data Sdata;
    cout << "Name: " << Sdata.vardas() << endl;
    cout << "Surname: " << Sdata.pavarde() << endl;
    cout << "Exam grade: " << Sdata.egzaminas() << endl;
    cout << "HW: ";
    for (double mark : Sdata.ND()) {
        cout << mark << " ";
    }


