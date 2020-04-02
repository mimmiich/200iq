//stek S, promqna na N-ti element sled wyrha w nowa stoinost A, kato ostanalite elementi zapazwat stoinostite si
//da se izwede sydyrjanieto na ekrana, stoinosti za A i N da se wywejdat ot potrebitelq, kakto i pyrwonachalnoto sydyrjanie na S
#include <iostream>
using namespace std;
struct ime {
	int key;
	ime* next;
}
*start, * pst, * qst;

ime* push(ime* st, int n);
ime* pop(ime* st, int& n);
void init(ime** st);
int empty(ime* st);

void init(ime** st) {
	*st = NULL;
}

int empty(ime* st) {
	if (st == NULL)
		return 1;
	else
		return 0;
}

ime* push(ime* st, int n) {
	ime* p;
	p = new ime;
	p->key = n;
	p->next = st;
	st = p;
	return p;
}

ime* pop(ime* st, int& n) {
	ime* p;
	n = st->key;
	p = st;
	st = st->next;
	delete p;
	return st;
}
 
int menu() {
	int ch;
	cout << "\n\n \t Menu" << endl;
	cout << "1. Create a stack" << endl;
	cout << "2. Replace element in stack" << endl;
	cout << "3. Print elements" << endl;
	do {
		cout << "Your choise is: ";
		cin >> ch;
	} while (ch < 1 || ch>3);
	return(ch);
}


void replace_element(int num) {
	int N, A;
		cout << "\n Input the element number from top you want to change: ";
		cin >> N;
		cout << "\n And the new value: ";
		cin >> A;
		while (N > 0) {
			start = pop(start, num);
			pst = push(pst, num);
			N--;
		}
		start = pop(start, num);
		start = push(start, A);
		while (!empty(pst)) {
			pst = pop(pst, num);
			start = push(start, num);
		}
}

void print(int br, int num) {
	init(&qst);
	cout << "\n Stack: ";
	while (!empty(start)) {
		start = pop(start, num);
		cout << num << " ";
		qst = push(qst, num);
	}
	while (!empty(qst)) {
		qst = pop(qst, num);
		start = push(start, num);
	}

}

int main() {
	int num, N, A, br, br2;
	int choice;
	do {
		choice = menu();
		switch (choice) {
		case 1:  init(&start);
			cout << "\nElements in the stack: " << endl;
			cin >> br;
			br2 = br;
			cout << "\nInput number in stack: " << endl;
			while (br2 > 0) {
				cin >> num;
				start = push(start, num);
				br2--;
			} break;
		case 2: init(&pst);
			if (empty(start)) {
				cout << "\nPlease create stack first!" << endl;
				break;
			}
			else {
				replace_element(num); break;
			}
		case 3: 
			if (empty(start)) {
			cout << "\nPlease create stack first!" << endl;
			break;
		}
			  else {
			print(br, num); break;
		}

	   }
	} while (choice != 4);

	system("pause");
}