//Необходимо разработать программу, которая является промежуточным звеном в реализации телефонной книги. На вход подаётся N ≤ 1000 команд вида
//ADD User Number
//DELETE User
//EDITPHONE User Number
//PRINT User
//Согласно этим командам нужно соответственно добавить пользователя в телефонную книгу, удалить пользователя, изменить его номер и вывести на экран его данные.
//В случае невозможности выполнить действие, необходимо вывести ERROR.Добавлять пользователя, уже существующего в телефонной книге нельзя.
//Необходимо вывести протокол работы телефонной книге
//Input format                                      Output format
//В случае невозможности выполнения действия        ERROR
//В случае команды PRINT User                       User Number

#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

struct node {
	node *next;
	string name;
	string phone;
	node() {
		next = NULL;
		name = "";
	}
};

void add(node* &head, node* &n) {
	node *curr = head;
	bool presence = false;
	while (curr->next != NULL) {
		if (n->name == curr->name) {
			presence = true;
			break;
		}
		curr = curr->next;
	}
	if(n->name == curr->name) presence = true;
	if (presence == false) {
		curr->next = n;
	}else{
		free(n);
		printf("ERROR\n");
	}
}

void del(node* &head, string name) {
	node *curr = head;
	bool presence = false;
	while (curr->next != NULL) {
		if (name == curr->next->name) {
			presence = true;
			break;
		}
		curr = curr->next;
	}
	if (presence == false) printf("ERROR\n");
	else {
		node *tmp = curr->next;
		curr->next = curr->next->next;
		free(tmp);
	}
}

void editphone(node* head, string name, string phone) {
	node *curr = head;
	bool presence = false;
	while (curr->next != NULL) {
		if (name == curr->name) {
			presence = true;
			break;
		}
		curr = curr->next;
	}
	if (name == curr->name) presence = true;
	if (presence == false) printf("ERROR\n");
	else curr->phone = phone;
}

void print(node* head, string name) {
	node *curr = head;
	bool presence = false;
	while (curr->next != NULL) {
		if (name == curr->name) {
			presence = true;
			break;
		}
		curr = curr->next;
	}
	if (name == curr->name) presence = true;
	if (presence == false) printf("ERROR\n");
	else printf("%s %s\n", curr->name.c_str(), curr->phone.c_str());
}

void delete_node(node* &head) {
	while (head->next != NULL) {
		node *tmp = head->next;
		head->next = head->next->next;
		free(tmp);
	}
	free(head);
}

int main() {
	unsigned N;
	scanf("%d", &N);
	node* head = new node();
	string command;
	for (unsigned i = 0; i < N; ++i) {
		cin >> command;
		if (command == "ADD") {
			node *n = new node();
			cin >> n->name;
			cin >> n->phone;
			add(head, n);
			continue;
		}
		if (command == "DELETE") {
			string name;
			cin >> name;
			del(head, name);
			continue;
		}
		if (command == "EDITPHONE") {
			string name, phone;
			cin >> name;
			cin >> phone;
			editphone(head, name, phone);
			continue;
		}
		if (command == "PRINT") {
			string name;
			cin >> name;
			print(head, name);
		}
	}
	delete_node(head);
	return 0;
}