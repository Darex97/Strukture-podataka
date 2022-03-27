#include <iostream>

using namespace std;

#include "OpenScatterTable.h"
#include "Player.h"
#include "ScatterObject.h"
#include "DSException.h"

int main()
{
	OpenScatterTable<char*, Player>* hashTable = new OpenScatterTable<char*, Player>(1024);

	try
	{
		Player player1((char*)"111-123456-77", (char*)"FirstName1", (char*)"LastName1", 
			(char*)"NationalTeam1", 1);
		hashTable->insert(ScatterObject<char*, Player>(player1.getLabel(), player1));

		Player player2((char*)"111-123457-77", (char*)"FirstName2", (char*)"LastName2",
			(char*)"NationalTeam1", 2);
		hashTable->insert(ScatterObject<char*, Player>(player2.getLabel(), player2));

		Player player3((char*)"121-123456-77", (char*)"FirstName3", (char*)"LastName3",
			(char*)"NationalTeam2", 3);
		hashTable->insert(ScatterObject<char*, Player>(player3.getLabel(), player3));

		Player player4((char*)"321-987654-85", (char*)"FirstName4", (char*)"LastName4",
			(char*)"NationalTeam3", 4);
		hashTable->insert(ScatterObject<char*, Player>(player4.getLabel(), player4));

		Player player5((char*)"321-123456-73", (char*)"FirstName5", (char*)"LastName5",
			(char*)"NationalTeam3", 5);
		hashTable->insert(ScatterObject<char*, Player>(player5.getLabel(), player5));

		Player player6((char*)"100-135790-83", (char*)"FirstName6", (char*)"LastName6",
			(char*)"NationalTeam6", 6);
		hashTable->insert(ScatterObject<char*, Player>(player6.getLabel(), player6));

		Player player7((char*)"100-123456-67", (char*)"FirstName7", (char*)"LastName7",
			(char*)"NationalTeam6", 7);
		hashTable->insert(ScatterObject<char*, Player>(player7.getLabel(), player7));

		Player player8((char*)"523-555646-91", (char*)"FirstName8", (char*)"LastName8",
			(char*)"NationalTeam8", 8);
		hashTable->insert(ScatterObject<char*, Player>(player8.getLabel(), player8));

		Player player9((char*)"121-123456-78", (char*)"FirstName9", (char*)"LastName9",
			(char*)"NationalTeam2", 9);
		hashTable->insert(ScatterObject<char*, Player>(player9.getLabel(), player9));

		Player player10((char*)"654-321654-85", (char*)"FirstName10", (char*)"LastName10",
			(char*)"NationalTeam10", 10);
		hashTable->insert(ScatterObject<char*, Player>(player10.getLabel(), player10));

		cout << "Hash Table." << endl;
		hashTable->display();

		ScatterObject<char*, Player> tempScatterObject = 
			hashTable->find((char*)"321-123456-73");

		cout << "Scatter Object." << endl;
		tempScatterObject.print();
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception." << endl;
	}

	delete hashTable;

	return 0;
}