// cityList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct node {
	char data[50];
	node* next;
};
struct ville {
	char name[50];
};

void displayList(node* head) {		//---2
	node* cur = head;
	while (cur != NULL) {
		cout << cur->data << " - ";
		cur = cur->next;
	}
}

void displayBetween(node* head, char ville1[], char ville2[]) {		//---3
	node* cur = head;

	while (cur != NULL) {
		if (cur->data == ville1) {
			while (cur->data != ville2) {
				cout << cur->data << " - ";
				cur = cur->next;
			};
			cout << ville2;
		}
		else {
			cur = cur->next;
		}
	}

}

void displayLetter(node* head, char c, ofstream& w) {		//---4
	node* cur = head;

	w.open("villeL.txt");
	if (!w) {
		cout << "Error opening file";
		exit(1);
	}

	while (cur != NULL) {
		if (cur->data[0] == c) {
			w << cur->data;
			cout << cur->data << " ";
		}
		cur = cur->next;
	}

	w.close();

}

void main() {

	node* tmp, * head, * cur;
	ville v;

	//1
	ifstream e;
	e.open("villes.txt");
	if (!e) {
		cout << "Error opening file";
		exit(1);
	};

	tmp = new node;
	e >> v.name;
	strncpy(tmp->data, v.name, 50);
	tmp->next = NULL;
	head = tmp;
	cur = tmp;
	e >> v.name;
	while (!e.fail()) {
		tmp = new node;
		tmp->next == NULL;
		strncpy(tmp->data, v.name, 50);
		cur->next = tmp;
		cur = tmp;
		e >> v.name;
	}

	//2
	displayList(head);

	//3
	char ville1[50], ville2[50];
	cout << "Enter ville 1: ";
	cin >> ville1;
	cout << "Enter ville 2: ";
	cin >> ville2;
	displayBetween(head, ville1, ville2);

	//4
	char c;
	cout << "Enter letter: ";
	cin >> c;
	ofstream w;
	displayLetter(head, c, w);

}
