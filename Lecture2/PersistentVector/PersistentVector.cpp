#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class pvector {
    string filename;
    vector<T> v;
    void readvector() {
        ifstream ifs(filename);
        for (;;) {
            T x; ifs >> x; if (!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
        typename vector<T>::iterator fst = v.begin(), lst = v.end();
        while (fst != lst) ofs << *fst++ << endl;
    }
public:
    pvector(string fname)
        : filename(fname) {
        readvector();
    }
    ~pvector() {
        writevector();
    }
    void push_back(const T& el) {
        v.push_back(el);
    }
    void pop_back() {
        v.pop_back();
    }
    T get(int index) {
        return v[index];
    }
};

void doSmthWithIntVector(pvector<int> &vector) {
    vector.push_back(5);
    vector.push_back(6);
    vector.push_back(7);
}

void doSmthWithStrVector(pvector<string>& vector) {
    vector.push_back("first");
    vector.push_back("second");
    vector.push_back("third");
}

int main()
{
    pvector<int> pintVector("int.txt");
    doSmthWithIntVector(pintVector);

    pvector<string> pstrVector("string.txt");
    doSmthWithStrVector(pstrVector);
}
