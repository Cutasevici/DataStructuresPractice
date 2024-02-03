#include "ll.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "BST.cpp"
#include <cmath>
#include "DoubleLinkeList.cpp"
using namespace std;





int main() {
	BST* myBst = new BST();
	myBst->insert(2);
	myBst->insert(4);
	myBst->insert(18);
	myBst->insert(167);

	int maxValue = myBst->getMax();

	if (maxValue != INT_MIN) {
		cout << "Maximum value in the BST: " << maxValue << endl;
	}

	
    
	return 0;
}