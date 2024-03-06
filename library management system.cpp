#include <iostream>
#include <iomanip>
#include <string>  // Include the <string> header for getline function

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 100;
const int MAX_ISSUES = 100;
int bookIds[MAX_BOOKS];

string bookTitles[MAX_BOOKS];
string bookAuthors[MAX_BOOKS];

int memberIds[MAX_MEMBERS];

string memberNames[MAX_MEMBERS];

int issuedBooks[MAX_ISSUES][2];
int totalBooks = 0;
int totalMembers = 0;
int totalIssues = 0;

//FUNCTIONS' Declaration

void displayMenu();
void addBook();
void deleteBook();
void searchBook();
void viewBooks();
void addMember();
void viewMembers();
void issueBook();
void returnBook();
void generateReports();

//Main Function

int main()
{
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            viewBooks();
            break;
        case 5:
            addMember();
            break;
        case 6:
            viewMembers();
            break;
        case 7:
            issueBook();
            break;
        case 8:
            returnBook();
            break;
        case 9:
            generateReports();
            break;
        case 10:
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}

//Functions' Definitions

void displayMenu()
{
    cout << "\n\t\t\t\t******* LIBRARY MANAGEMENT SYSTEM *******\n\n";
    cout << "---> MAIN MENU:\n\n";
    cout << "1. Add Book\n";
    cout << "2. Delete Book\n";
    cout << "3. Search Book\n";
    cout << "4. View Books\n";
    cout << "5. Add Member\n";
    cout << "6. View Members\n";
    cout << "7. Issue Book\n";
    cout << "8. Return Book\n";
    cout << "9. Generate Reports\n";
    cout << "10. Exit\n";
}
void addBook() {
    system("cls");

    cout << "\n---> Add Book:\n\n";
    if (totalBooks >= MAX_BOOKS) {
        cout << "Maximum number of books reached. Cannot add more books.\n";
        system("PAUSE");
        system("CLS");
        return;
    }
    cout << "Enter Book ID: ";
    cin >> bookIds[totalBooks];
    cin.ignore();  // Clear the newline character from the input buffer
    cout << "\nEnter Book Title: ";
    getline(cin, bookTitles[totalBooks]);
    cout << "\nEnter Author: ";
    getline(cin, bookAuthors[totalBooks]);
    totalBooks++;
    cout << "\nBook added successfully!\n";
    system("PAUSE");
    system("CLS");
}
void deleteBook() {
    system("cls");

    cout << "\n---> Delete Book:\n\n";
    int bookId;
    cout << "Enter the Book ID to delete: ";
    cin >> bookId;
    int foundIndex = -1;
    for (int i = 0; i < totalBooks; i++) {
        if (bookIds[i] == bookId) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        for (int i = foundIndex; i < totalBooks - 1; i++) {
            bookIds[i] = bookIds[i + 1];
            bookTitles[i] = bookTitles[i + 1];
            bookAuthors[i] = bookAuthors[i + 1];
        }
        totalBooks--;
        cout << "ID: " << bookIds[foundIndex] << ", Title: " << bookTitles[foundIndex] << ", Author: " << bookAuthors[foundIndex] << "\n" << endl;
        cout << "\nBook deleted successfully!\n";
    }
    else {
        cout << "\nBook not found!\n";
    }
    system("PAUSE");
    system("CLS");
}
void searchBook() {
    system("cls");

    cout << "\n---> Search Book:\n\n";
    int bookId;
    cout << "Enter the Book ID to search: ";
    cin >> bookId;
    int foundIndex = -1;
    for (int i = 0; i < totalBooks; i++) {
        if (bookIds[i] == bookId) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        cout << "\nBook Found!\n";
        cout << "ID: " << bookIds[foundIndex] << ", Title: " << bookTitles[foundIndex] << ", Author: " << bookAuthors[foundIndex] << "\n" << endl;
    }
    else {
        cout << "\nBook not found!\n";
    }
    system("PAUSE");
    system("CLS");
}
void viewBooks() {
    system("cls");

    cout << "\n---> View Books:\n\n";
    cout << "List of Books:\n";
    cout << setw(5) << "ID" << setw(25) << "Title" << setw(20) << "Author\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << setw(5) << bookIds[i] << setw(25) << bookTitles[i] << setw(20) << bookAuthors[i] << endl;
    }
    system("PAUSE");
    system("CLS");
}
void addMember() {
    system("cls");

    cout << "\n---> Add Member:\n\n";
    cout << "Enter Member ID: ";
    cin >> memberIds[totalMembers];
    cin.ignore();  // Clear the newline character from the input buffer
    cout << "\nEnter Member Name: ";
    getline(cin, memberNames[totalMembers]);
    totalMembers++;
    cout << "\nMember added successfully!\n";
    system("PAUSE");
    system("CLS");
}
void viewMembers() {
    system("cls");

    cout << "\n--->  View Members:\n\n";
    cout << "List of Members:\n";
    cout << setw(5) << "ID" << setw(20) << "Name\n";
    for (int i = 0; i < totalMembers; i++) {
        cout << setw(5) << memberIds[i] << setw(20) << memberNames[i] << endl;
    }
    system("PAUSE");
    system("CLS");
}
void issueBook() {
    system("cls");

    cout << "\n---> Issue Book:\n\n";
    int bookId, memberId;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;
    cout << "\nEnter Member ID: ";
    cin >> memberId;
    bool bookFound = false;
    bool memberFound = false;
    for (int i = 0; i < totalBooks; i++) {
        if (bookIds[i] == bookId) {
            bookFound = true;
            break;
        }
    }
    for (int i = 0; i < totalMembers; i++) {
        if (memberIds[i] == memberId) {
            memberFound = true;
            break;
        }
    }
    if (!bookFound) {
        cout << "\nBook not found!\n";
        return;
    }
    if (!memberFound) {
        cout << "\nMember not found!\n";
        return;
    }
    issuedBooks[totalIssues][0] = bookId;
    issuedBooks[totalIssues][1] = memberId;
    totalIssues++;
    cout << "\nBook issued successfully!\n";
    system("PAUSE");
    system("CLS");
}
void returnBook() {
    system("cls");

    cout << "\n---> Return Book:\n\n";
    int bookId, memberId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;
    cout << "\nEnter Member ID: ";
    cin >> memberId;
    int foundIndex = -1;
    for (int i = 0; i < totalIssues; i++) {
        if (issuedBooks[i][0] == bookId && issuedBooks[i][1] == memberId) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        for (int i = foundIndex; i < totalIssues - 1; i++) {
            issuedBooks[i][0] = issuedBooks[i + 1][0];
            issuedBooks[i][1] = issuedBooks[i + 1][1];
        }
        totalIssues--;
        cout << "Book returned successfully!\n";
    }
    else {
        cout << "Issue record not found!\n";
    }
    system("PAUSE");
    system("CLS");
}
void generateReports() {
    system("cls");

    cout << "\n---> Generate Reports:\n\n";
    cout << "Library Reports:\n";
    cout << "\nTotal Books: " << totalBooks << endl;
    cout << "\nTotal Issued Books: " << totalIssues << endl;
    cout << "\nTotal Available Books: " << (totalBooks - totalIssues) << endl;
    system("PAUSE");
    system("CLS");
}
