#include <string>
using namespace std;
//////////////////

char ch; // .h
string s; // .h
extern int error_number; // .cc
static double sq(double); // .cc
int count = 1; // .cc
const double pi = 3.2; // .h
struct fraction { int c; int d; }; // .h 
//char* prog[] = { "echo","hello","world!",NULL }; // .cc
extern "C" void c_swap(int* a, int* b); // .cc
double sqrt(double); // .h
void swap(int& a, int& b) { int c = a; a = b; b = c; } // .h
template<typename T> T add(T a, T b) { return a + b; } // .cc
namespace { int a; } // .cc
struct user; // .h