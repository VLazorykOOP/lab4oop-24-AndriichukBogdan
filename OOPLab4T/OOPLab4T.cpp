#include <iostream>
#include <map>
#include <string>
#include <locale>
using namespace std;

class Vector {
protected:
    int m_size;
    int m_numb;
    int codeError;
    int* vector;

public:
    Vector() {
        vector = new int[1];
        vector[0] = 0;
        m_size = 1;
        m_numb = 0;
        codeError = 0;
    }

    Vector(int size) {
        vector = new int[size];
        m_size = size;
        m_numb = 0;
        codeError = 0;
        for (int i = 0; i < size; i++) {
            vector[i] = 0;
        }
    }

    Vector(int size, int init_value) {
        vector = new int[size];
        m_size = size;
        m_numb = init_value;
        codeError = 0;
        for (int i = 0; i < size; i++) {
            vector[i] = init_value;
        }
    }

    Vector(const Vector& other) {
        m_size = other.m_size;
        m_numb = other.m_numb;
        codeError = other.codeError;
        vector = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            vector[i] = other.vector[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] vector;
            m_size = other.m_size;
            vector = new int[m_size];
            for (int i = 0; i < m_size; i++) {
                vector[i] = other.vector[i];
            }
        }
        return *this;
    }

    ~Vector() {
        cout << "Deleting vector" << endl;
        if (vector != nullptr)delete[] vector;
    }
    void get_vector() {
        for (int i = 0; i < m_size; i++) {
            cout << vector[i] << endl;
        }
    }
    int get_size() {
        return m_size;
    }

    Vector& operator--() {
        for (int i = 0; i < m_size; ++i)
            --vector[i];
        return *this;
    }
    Vector operator++() {
        for (int i = 0; i < m_size; ++i)
            ++vector[i];
        return *this;
    }
    bool operator!() {
        if (vector[0] != 0) return true;
        else {
            return false;
        }
    }
    Vector& operator-() {
        for (int i = 0; i < m_size; i++) {
            vector[i] *= -1;
        }
        return *this;
    }

    Vector operator+=(Vector& obj) {
        for (int i = 0; i < m_size; i++) {
            vector[i] = vector[i] + obj.vector[i];
        }
        return *this;
    }

    Vector operator-=(Vector& obj) {
        for (int i = 0; i < m_size; i++) {
            vector[i] = vector[i] - obj.vector[i];
        }
        return *this;
    }

    Vector operator*=(int numb) {
        for (int i = 0; i < m_size; i++) {
            vector[i] = vector[i] * numb;
        }
        return *this;
    }

    Vector operator/=(int numb) {
        for (int i = 0; i < m_size; i++) {
            vector[i] = vector[i] / numb;
        }
        return *this;
    }

    Vector operator%=(int numb) {
        for (int i = 0; i < m_size; i++) {
            vector[i] = vector[i] % numb;
        }
        return *this;
    }

    Vector operator-(Vector& other) {
        Vector temp(m_size);
        for (int i = 0; i < m_size; i++) {
            temp.vector[i] = vector[i] - other.vector[i];
        }
        return temp;
    }

    Vector operator+(Vector& obj) {
        Vector temp(m_size);
        for (int i = 0; i < m_size; i++) {
            temp.vector[i] = vector[i] + obj.vector[i];
        }
        return temp;
    }

    Vector operator*(int numb) {
        Vector temp(m_size);
        for (int i = 0; i < m_size; i++) {
            temp.vector[i] = vector[i] * numb;
        }
        return temp;
    }

    Vector operator/(int numb) {
        Vector temp(m_size);
        for (int i = 0; i < m_size; i++) {
            temp.vector[i] = vector[i] / numb;
        }
        return temp;
    }

    Vector operator%(int numb) {
        Vector temp(m_size);
        for (int i = 0; i < m_size; i++) {
            temp.vector[i] = vector[i] % numb;
        }
        return temp;
    }

    bool operator==(Vector& a) {
        return (m_size == a.m_size) && (m_numb == a.m_numb);
    }

    bool operator!=(Vector& a) {
        return (m_size != a.m_size) && (m_numb != a.m_numb);
    }

    int& operator[](int index) {
        if (m_size > index) {
            return vector[10];
        }
        else
        {
            codeError = 1;
            cout << "Invalid index(there is last index)" << vector[m_size - 1] << endl;
        }
    }

    Vector operator()() {
        for (int i = 0; i < m_size; i++) {
            vector[i] = 0;
        }
        return *this;
    }

    Vector operator>(Vector& a) {
        Vector result(m_size);
        for (int i = 0; i < m_size; i++) {
            result[i] = (vector[i] > a.vector[i]);
        }
        return Vector(result);
    }

    Vector operator>=(Vector& a) {
        Vector result(m_size);
        for (int i = 0; i < m_size; i++) {
            result[i] = (vector[i] >= a.vector[i]);
        }
        return Vector(result);
    }
    Vector operator<(Vector& a) {
        Vector result(m_size);
        for (int i = 0; i < m_size; i++) {
            result[i] = (vector[i] < a.vector[i]);
        }
        return Vector(result);
    }

    Vector operator<=(Vector& a) {
        Vector result(m_size);
        for (int i = 0; i < m_size; i++) {
            result[i] = (vector[i] <= a.vector[i]);
        }
        return Vector(result);
    }


    friend istream& operator>>(istream& is, Vector& a);
    friend ostream& operator<<(ostream& os, Vector& a);
};

istream& operator >> (istream& is, Vector& a)
{
    int i;
    for (i = 0; i < a.get_size(); i++) is >> a.vector[i];
    return is;
}
ostream& operator<<(ostream& os, Vector& a)
{
    int i;
    for (i = 0; i < a.get_size(); i++) os << " " << a.vector[i] << " ";
    return os;
}

void task1() {
    Vector v1(5, 2), v2(5, 3);

    cout << "Initial V1: " << v1 << endl;
    cout << "Initial V2: " << v2 << endl;

    v1 += v2;
    cout << "V1 after V1 += V2: " << v1 << endl;

    v1 -= v2;
    cout << "V1 after V1 -= V2: " << v1 << endl;

    v1 = v1 * 5;
    cout << "V1 after V1 * 5: " << v1 << endl;

    v1 = v1 / 2;
    cout << "V1 after V1 / 2: " << v1 << endl;

    v1 = v1 % 3;
    cout << "V1 after V1 % 3: " << v1 << endl;

    --v1;
    cout << "V1 after --V1: " << v1 << endl;

    ++v1;
    cout << "V1 after ++V1: " << v1 << endl;

    Vector v3 = v1 - v2;
    cout << "V1 - V2: " << v3 << endl;

    Vector v4 = v1 + v2;
    cout << "V1 + V2: " << v4 << endl;

    Vector v5 = -v1;
    cout << "Negation of V1: " << v5 << endl;

    bool isEqual = (v1 == v2);
    cout << "V1 == V2: " << isEqual << endl;

    bool isNotEqual = (v1 != v2);
    cout << "V1 != V2: " << isNotEqual << endl;

    cout << "V1[2]: " << v1[2] << endl;

    v1();
    cout << "V1 after reset: " << v1 << endl;

    Vector v6 = v1 > v2;
    cout << "V1 > V2: " << v6 << endl;

    Vector v7 = v1 >= v2;
    cout << "V1 >= V2: " << v7 << endl;

    Vector v8 = v1 < v2;
    cout << "V1 < V2: " << v8 << endl;

    Vector v9 = v1 <= v2;
    cout << "V1 <= V2: " << v9 << endl;
}


class AssocEntities {
private:
    map<int, string> associations;
    int CodeError;

public:
    AssocEntities() {
        CodeError = 0;
    }

    string intToWord(int num) {
        setlocale(LC_CTYPE, "ukr");
        switch (num) {
        case 1: return "Один";
        case 2: return "Два";
        case 3: return "Три";
        case 4: return "Чотири";
        case 5: return"Пять";
        case 6: return"Шiсть";
        case 7: return"Сiм";
        case 8: return"Вiсiм";
        case 9: return"Девять";
        case 10: return"Десять";
        default: return "невідоме число";
        }
    }

    void createAssociations() {
        for (int i = 1; i <= 10; ++i) {
            associations[i] = intToWord(i);
        }
    }

    string& operator[](int num) {
        if (associations.find(num) == associations.end()) {
            CodeError = -1;
            return associations[0];
        }
        else {
            CodeError = 0;
            return associations[num];
        }
    }

    int getErrorCode() {
        return CodeError;
    }

    friend ostream& operator<<(ostream& os, AssocEntities& ae);
    friend istream& operator>>(istream& is, AssocEntities& ae);
};

istream& operator>>(istream& is, AssocEntities& ae) {
    int num;
    string word;
    for (int i = 1; i <= 10; ++i) {
        is >> num >> word;
        ae.associations[num] = word;
    }
    return is;
}
ostream& operator<<(ostream& os, AssocEntities& ae) {
    for (auto& pair : ae.associations) {
        os << pair.first << " - " << pair.second << endl;
    }
    return os;
}

void task2() {
    AssocEntities assoc;

    assoc.createAssociations();


    cout << "Associations:" << endl;
    cout << assoc;


    int num = 10;
    cout << "Number " << num << " in words: " << assoc[num] << endl;


    if (assoc.getErrorCode() != 0) {
        cout << "Error: Number not found" << endl;
    }
}


int main()
{
    int choice;
    cout << "Choose task" << endl;
    cout << "1.Task 1 (with class Vector)" << endl;
    cout << "2.Task 2 (with Associative)" << endl;
    cout << "3.Exit" << endl;

    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: return 0;
    default: cout << "Error" << endl;
    }
}