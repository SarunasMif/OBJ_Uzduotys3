#include "includes.h"
#include "Studentas.h"
#include "headers_vector.h"
#include "Vector_Lib.h"

void splitstudents(Vector_Lib<Student_Data>& S_Data, string mode){
    string split_type;
    
    do {
        cout << "Pagal, kuria strategija dalinti studentus [1] du naujus vektorius, [2] vienas naujas vektorius, [3] optimizuota naudojant funkcijas: ";
        cin >> split_type;

        if(!isDigit(split_type, 4)){
            cout << "Error. Skaicius turi but tarp 1 ir 3" << endl;
        }
    } while (!isDigit(split_type, 4));

    if (split_type == "1"){
        auto start = high_resolution_clock::now();

        Vector_Lib<Student_Data> kietiakiai;
        Vector_Lib<Student_Data> nuskriaustukai;

        for (const auto& adata : S_Data){
            if (avg_grade(adata) < 5){
                nuskriaustukai.push_back(adata);
            }else{
                kietiakiai.push_back(adata);
            }
        }

        auto stop = high_resolution_clock::now();
        chrono::duration<double> diff = stop - start;
        cout << "Rusiavimas baigtas! Rusiavimas uztruko " << diff.count() << " sekundes." << endl;

        printData(kietiakiai, mode, "kietiakiai.txt");
        printData(nuskriaustukai, mode, "nuskriaustukai.txt");
    }
    else if (split_type == "2"){
        auto start = high_resolution_clock::now();

        Vector_Lib<Student_Data> vargsiukai;

        size_t i = 0;

        while (i < S_Data.size()){
            if (avg_grade(S_Data[i]) < 5){

                vargsiukai.push_back(move(S_Data[i]));

                S_Data[i] = move(S_Data.back());
                S_Data.pop_back();
            }else {
                i++;
            }
        }

        auto stop = high_resolution_clock::now();
        chrono::duration<double> diff = stop - start;
        cout << "Rusiavimas baigtas! Rusiavimas uztruko " << diff.count() << " sekundes." << endl;

        printData(S_Data, mode, "kietiakiai.txt");
        printData(vargsiukai, mode, "nuskriaustukai.txt");
    }else {
        auto start = high_resolution_clock::now();

        Vector_Lib<Student_Data> vargsiukai;

        auto split = partition(S_Data.begin(), S_Data.end(), [](const Student_Data& S_Data){
            return avg_grade(S_Data) < 5;
        });

        auto extract = remove_if(S_Data.begin(), split, [](const Student_Data& S_Data){
            return avg_grade(S_Data) < 5;
        });

        move(extract, split, back_inserter(vargsiukai));

        S_Data.erase(extract, split);

        auto stop = high_resolution_clock::now();
        chrono::duration<double> diff = stop - start;
        cout << "Rusiavimas baigtas! Rusiavimas uztruko " << diff.count() << " sekundes." << endl;

        printData(S_Data, mode, "kietiakiai.txt");
        printData(vargsiukai, mode, "nuskriaustukai.txt");
    }
    

}// Sukuria du vektorius rusiuoti studentams pagal  vidurkius.

bool isDigit(const string& str_placeholder, int check){
    for (char c : str_placeholder){
        if (!isdigit(c)){
            return false;
        }
    }

    if (check == 1){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 10){
            return false;
        }
    }

    if (check == 2){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 4){
            return false;
        }
    }

    if (check == 3){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 2){
            return false;
        }
    }

    return true;
}// Tikrina ar string yra sudarytas tiks is skaiciu

bool isString(const string& str_placeholder){
    for (char c : str_placeholder){
        if (!isalpha(c)){
            return false;
        }
    }

    return true;
}// Tikrina ar string yra sudarytas tiks is raidziu

void printData(const Vector_Lib<Student_Data>& Sdata, string mode, string filename){
    Vector_Lib<Student_Data> sorted = Sdata;
    string setting;
    
    do {
        cout << "Jei norite isvesti i terminala iveskite 1. Jei norite isvesti i faila iveskite 2: ";
        cin >> setting;

        if (!isDigit(setting, 3)){
            cout << "Error! Turi buti sveikasis skaicius nuo 1 iki 2.";
        }

    }while(!isDigit(setting, 3));//Pasirinkimas del isvedimo tipu

    auto start = high_resolution_clock::now();

    if (setting == "1"){       
        cout << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;

        if (mode == "1"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.vardas().substr(6)) < stoi(b.vardas().substr(6));
            });
        }//Rusiuoja pagal varda
        else if (mode == "2"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.pavarde().substr(7)) < stoi(b.pavarde().substr(7));
            });
        }//Rusiuoja pagal pavarde
        else if (mode == "3"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return avg_grade(a) < avg_grade(b);
            });
        }//Rusiuoja pagal vidurki
        else if (mode == "4"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return median_grade(a) < median_grade(b);
            });
        }//Rusiouja pagal pazimiu mediana

        for (const auto& Sdata : sorted){
            cout << left << setw(17) << Sdata.vardas() << setw(15) << Sdata.pavarde() << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
        }
        
    }else{

        if (mode == "1"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.vardas().substr(6)) < stoi(b.vardas().substr(6));
            });
        }//Rusiuoja pagal varda
        else if (mode == "2"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.pavarde().substr(7)) < stoi(b.pavarde().substr(7));
            });
        }//Rusiuoja pagal pavarde
        else if (mode == "3"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return avg_grade(a) < avg_grade(b);
            });
        }//Rusiuoja pagal vidurki
        else if (mode == "4"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return median_grade(a) < median_grade(b);
            });
        }//Rusiouja pagal pazimiu mediana

        ofstream write(filename);

        write << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
        write << "---------------------------------------------------------------" << endl;

        for (const auto& Sdata : sorted){
            stringstream Adata;
            Adata << left << setw(17) << Sdata.vardas() << setw(15) << Sdata.pavarde() << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata);
            write << Adata.str() << endl;
        }
    }

    //system("pause");
    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Isvedimas baigtas! Isvedimas uztruko " << diff.count() << " sekundes." << endl;
}

int manualInput(){
    Vector_Lib<Student_Data> Sdata;

    string str_placeholder;

    do {
        cout << "Ar zinote kiek studentu yra jusu klaseje? (y/n): ";
        cin >> str_placeholder;
    }while (str_placeholder != "y" && str_placeholder != "n");

    do {
        cout << "Ar norite, kad pazymiai butu sugeneruoti? (y/n): ";
        cin >> gen_s;
    }while (gen_s != "y" && gen_s != "n");

    if (str_placeholder == "y"){
        cout << "Kiek studentu yra jusu klaseje: ";
        cin >> str_placeholder;

        Number_Of_Students = stoi(str_placeholder);
        Vector_Lib<Student_Data> Sdata(Number_Of_Students);

        for (int i = 0; i < Number_Of_Students; i++){
            Input(Sdata[i], gen_s);
        }    

        do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

        splitstudents(Sdata, str_placeholder);

        return 0;
    }else{
        do {
            Student_Data Stud_data;
            Input(Stud_data, gen_s);
            Sdata.push_back(Stud_data);

            cout << "Ar norite ivesti dar viena studenta(y/n): ";
            cin >> str_placeholder;
        }while (str_placeholder == "y");

        do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

        splitstudents(Sdata, str_placeholder);

        return 0;
    }
}// Rankinis studentu duomenu isvedimas

void Input(Student_Data& Sdata, string gen_s){
    string str_placeholder;
    int int_placeholder;

    cin >> Sdata; //Input daline realizacija

    if (gen_s == "y"){                                   
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 10);

        Number_Of_Homework = dis(gen);
        Vector_Lib<double> HomeWork;

        for (int i = 0; i < Number_Of_Homework; i++){
            HomeWork.push_back(dis(gen));
        }
        Sdata.SetHW(HomeWork);

        Sdata.SetExam(dis(gen));
        // Sugeneruojami atsitiktinei pazymiai
    }else{
        do {
            cout << "Kiek namu darbu turejo studentai: ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 0)){
                cout << "Error! Turi buti skaicius. " << endl;
            }
        }while (!isDigit(str_placeholder, 0));

        Number_Of_Homework = stoi(str_placeholder);
        Vector_Lib<double> HomeWork;

        for (int j = 0; j < Number_Of_Homework; j++){
           
            do {
                cout << "[" << j + 1 << "] Iveskite pazymi: ";
                cin >> str_placeholder;

                if (!isDigit(str_placeholder, 1)){
                    cout << "Error! Pazimys turi buti naturalusis skaicius nuo 1 iki 10." << endl;
                }
            }while (!isDigit(str_placeholder, 1));

            HomeWork.push_back(stoi(str_placeholder));
        }

        Sdata.SetHW(HomeWork);

        do {
            cout << "Iveskite egzamino pazymi: ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 1)){
                cout << "Error! Pazimys turi buti naturalusis skaicius nuo 1 iki 10." << endl;
            }
        }while (!isDigit(str_placeholder, 1));

        Sdata.SetExam(stoi(str_placeholder));
    }// Jei vartotojas zino kiek turejo namu darbu
}


int fileInput(string filename){
    Vector_Lib<Student_Data> Sdata;
    string str_placeholder;

    ifstream Read;

    try {
        Read.open(filename);

        if (!Read){
            throw "Failas nerastas!";
            return 1;
        }
    }
    catch (const char* error){
        cerr << "Error: " << error << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    

    getline(Read, str_placeholder);

    auto start = high_resolution_clock::now();

    while(getline(Read, str_placeholder)){
        Student_Data Adata;

        istringstream get(str_placeholder);
        Adata.readStudent(get);
        Sdata.push_back(Adata);

    }
    
    Read.close();

    do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;

    cout << "Failo nuskaitymas uztruko " << fixed << setprecision(6) << seconds << " sekundes." << endl;

    splitstudents(Sdata, str_placeholder);

    return 0;
}

int generateFile(){
    int s_num = 0;
    int hw_hum = 0;
    string filename;

    cout << "Kiek studentu generuoti norit: ";
    cin >> s_num;

    cout << "Kiek namu darbu buvo: ";
    cin >> hw_hum;
    //Number_Of_Homework = hw_hum;

    auto start = high_resolution_clock::now();
    filename =  "Studentai" + to_string(s_num) + ".txt";
    ofstream write(filename);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);

    write << left << setw(15) << "Vardas" << setw(15) << "Pavarde";

    for (int i = 0; i < hw_hum; i++){
        write << "ND" + to_string(i + 1) << "\t";
    }
    write << "Egz." << endl;

    for (int i = 0; i < s_num; i++){
        stringstream s_data;
        s_data << left << setw(15) << "Vardas" + to_string(i + 1) << setw(15) << "Pavarde" + to_string(i + 1);

        for (int j = 0; j <= hw_hum; j++){
            s_data << setw(6) << dis(gen) << "\t";
        }

        write << s_data.str() << endl;
    }//Sugeneruoja pazymius atsitiktinai

    write.close();

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Failas sukurtas! Failo kurimas uztruko " << diff.count() << " sekundes." << endl;

    fileInput(filename);

    return 0;

}

int main() {
    cout << "VECTOR" << endl;
    cout << "Ar norite ivesti studentu duomenis rankiniu budu ar nuskaityti is failo?" << endl;
    string input_mode;
    
    do {
        cout << "Iveskite 1, jei norite uzpildyti rankiniu budu, iveskite 2, jei norite nuskaityti nuo failo, jei noite generuoti faila iveskite 3: ";
        cin >> input_mode;

        
    }while (input_mode != "1" && input_mode != "2" && input_mode != "3");

    if (input_mode == "1"){
        manualInput();
    }
    else if (input_mode == "3"){
        generateFile();
    }else if (input_mode == "2"){
        string filename;
        string filename2;
        string input;
        filename = "Studentai10000.txt";
        filename2 = "Studentai100000.txt";
        cout << "Kuri faila norite nuskaityti?" << endl;
        cout << "[1] Studentai10000.txt (iveskite 1)" << endl;
        cout << "[2] Studentai100000.txt (iveskite 2)" << endl;
        
        do {
            cout << "Input: ";
            cin >> input;
        } while (input != "1" && input != "2");

        if (input == "1") {
            fileInput(filename); 
        } else {
            fileInput(filename2); 
        }  
    }

    system("pause");
}