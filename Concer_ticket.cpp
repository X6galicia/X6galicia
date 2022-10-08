#include <iostream>
#include <string>
#include "label.hpp"

using namespace std;

class Node
{
  public:
	string name;
	string ticket;
	Node *next;
};

Node *head = new Node();
void Sort_Names(Node *head)
{
	Node *ptr_head = head;
	while (ptr_head->next != NULL)
	{
		{
			if (ptr_head->name > ptr_head->next->name)
			{
				ptr_head->name.swap(ptr_head->next->name);
				ptr_head->ticket.swap(ptr_head->next->ticket);
			}
		}
		ptr_head = ptr_head->next;
	}
}
void View_Attendees(Node *head, int *ctr)
{
	int ctr_ptr = 1;
	if (head == NULL)
	{
		Notif4();
		return;
	}
	while (head != NULL)
	{
		Sort_Names(head);
		{
			cout << "    " << ctr_ptr << "\t\t" << head->name << "\t\t\t" << head->ticket << endl;
		}
		ctr_ptr++;
		head = head->next;
	}
	*ctr = ctr_ptr;
}

void Reserve_Ticket(string n, string t, int ctr)
{
	if (ctr > 10)
	{
		Notif6();
		Function1();
		return;
	}
	if (n == "0")
	{
		return;
	}
	else
	{
		{
			Node *new_node = new Node();
			new_node->name = n;
			new_node->ticket = t;

			new_node->next = head;
			head = new_node;
			cout << " Ticket :" << t << endl;
			Notif1();
			Function1();
			return;
		}
	}
}

void Cancel_Reservation(Node **head, int pos, int ctr)
{
	Node *temp_head = *head;
	if (pos > ctr || pos < 0)
	{
		Notif5();
		Function1();
		return;
	}
	else if (pos == 0)
	{
		return;
	}
	if (*head != NULL)
	{
		if (pos == 1)
		{
			Notif2();
			*head = temp_head->next;
			temp_head->~Node();
			Function1();
			return;
		}
		{
			for (int i = 0; i < pos - 2; i++)
				temp_head = temp_head->next;

			Notif2();
			Node *temp_head2 = temp_head->next;
			temp_head->next = temp_head2->next;
			temp_head2->~Node();
			Function1();
		}
		return;
	}
}

void Check_Ticket(Node *head, string t)
{
	if (head == NULL)
	{
		Notif4();
		return;
	}
	if (t == "0")
	{
		return;
	}
	while (head != NULL)
	{
		{
			if (head->ticket == t)
			{
				cout << head->name << "\t\t" << head->ticket << endl;
				Function1();
				return;
			}
			else if (head->next == NULL && head->ticket != t)
			{
				Notif3();
				Function1();
				return;
			}
		}
		head = head->next;
	}
}

int main()
{
	head = NULL;
	int opt, pos;
	string a_name, a_ticket;
	string f_tkt = "TKT-00";
	string b_tkt = "-MOIRA";
	int m_tkt = 69, ctr = 1, tkt_ctr = 11;
	string s_tkt;

	do
	{
		system("cls");
		header();
		cout << "[1] Reserve Ticket " << endl;
		cout << "[2] Cancel Reservation " << endl;
		cout << "[3] Check Ticket " << endl;
		cout << "[4] View Attendees " << endl;
		cin >> opt;
		system("cls");
		switch (opt)
		{
		case 1:
			header();
			tkt_ctr -= 1;
			Function3();
			cout << tkt_ctr << endl;
			cin.ignore();
			Function2();
			cout << " Name :";
			getline(cin, a_name);
			s_tkt = to_string(m_tkt);
			a_ticket = f_tkt + s_tkt + b_tkt;
			m_tkt += 3;
			Reserve_Ticket(a_name, a_ticket, ctr);
			break;

		case 2:
			label();
			View_Attendees(head, &ctr);
			cin.ignore();
			Function2();
			cout << " Position :";
			cin >> pos;
			Cancel_Reservation(&head, pos, ctr);
			break;

		case 3:
			header();
			cin.ignore();
			Function2();
			cout << " Ticket :";
			getline(cin, a_ticket);
			Check_Ticket(head, a_ticket);
			break;

		case 4:
			label();
			View_Attendees(head, &ctr);
			Function1();
			break;
		}
	} while (opt != 5);
}
