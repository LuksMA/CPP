// Dynamic Memory Allocation for Objects
using namespace std;

class A
{
	 public:
       	A() {
    	  cout << "Constructor" << endl;
      	}
       	~A() {
    	   cout << "Destructor" << endl;
        }
};

int main()
{
	A* a = new A[4];
	delete [] a; // Delete array
	return 0;
}
