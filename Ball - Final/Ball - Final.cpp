/****************************************
* Student Name: Neil Ball
* Date Due: 5/3/2022
* Date Submitted: 5/3/2022
* Program Name: Ball - Final
* Program Description: Book Reservation System
****************************************/
// Ball - Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

struct book* addBook(struct book* oldBooks, int& bookCount); //This function adds books to a book struct array.
struct customer* addCustomer(struct customer* oldCustomers, int& customerCount); //This function adds customers to a customer struct array.
struct book* rentBook(struct book* oldBooks, struct book bookRental, int& checkedOutCount, int day, int checkout); //This function adds books to the book struct array within the customer struct.
bool booksAvailable(book* books, int bookCount); //This function was required to avoid a fault.
void availableBooks(book* books, int bookCount); //This function lists the books that are available for rent.
void currentCustomers(customer* customers, int customerCount, int day); //This function displays a list of current customers.
void currentBooks(customer* customers, int customerCount, book* books, int bookCount); //This function displays a list of books that are checked out and available.
struct customer returnBook(customer& customer, book*& books, int bookCount, int day); //Only the late fees on returned books are factored in because books not returned continue to accrue fees.
struct customer* deleteCustomer(customer* customers, int customerSelection, int& customerCount); //This function replaces an old customer struct array with a new one that lacks the deleted customer.
int customerIndexRequest(customer* customers, int customerCount); //This function gives the indices of the current customers in the array.
int bookIndexRequest(book* books, int bookCount); //This function gives the indices of the current books in the array.
void payLateFee(customer* customers, int customerCount); //This function wipes out the late fees on returned books.

//http://www.cplusplus.com/forum/general/86425/
struct book
{
    string title;
    string author;
    string publisher;
    string releaseDate;
    string dueDate;
    bool available = true;
    int dueDay = 0;
    int lateFeePerDay = 3;
};

struct customer
{
    string name;
    string address;
    string phoneNumber;
    string registeredDate;
    int checkedOutCount = 0;
    book* booksBorrowed = {};
    int lateFee = 0;
};

int main()
{
    int customerCount = 0;
    int bookCount = 0;
    int selection = 0;
    int day = 0;
    int checkout = 7;
    int customerSelection = 0;
    int bookSelection = 0;

    book* books;
    customer* customers;

    //https://stackoverflow.com/questions/3613302/passing-array-of-structures-to-function-c
    books = { };
    customers = {};

    while (true)
    {
        system("CLS"); //https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
        cout << "Select an option: 1 = Add a book. 2 = Add a customer. 3 = Rent a book. 4 = Return a book. 5 = Pay late fee.\n 6 = Delete a customer. 7 = List of current books. 8 = List of current customers." << endl;
        cin >> selection;
        switch (selection)
        {
        case 1:
            books = addBook(books, bookCount);
            break;
        
        case 2:
            customers = addCustomer(customers, customerCount);
            break;

        case 3:
            if (customerCount > 0 && bookCount > 0)
            {
                if (booksAvailable(books, bookCount))
                    bookSelection = bookIndexRequest(books, bookCount);
                else
                {
                    cout << "There are no available books at this time." << endl;
                    cin.clear(); //https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
                    cin.ignore(INT_MAX, '\n');
                    getchar();
                    break;
                }

                customerSelection = customerIndexRequest(customers, customerCount);
                

                if (books[bookSelection].available && customers[customerSelection].checkedOutCount < 7)
                {
                    books[bookSelection].available = false;
                    customers[customerSelection].booksBorrowed = rentBook(customers[customerSelection].booksBorrowed, books[bookSelection], customers[customerSelection].checkedOutCount, day, checkout);
                }
                else
                {
                    cout << "This book is not available or this customer has 7 books checked out." << endl;
                    cin.ignore(INT_MAX, '\n');
                    getchar();
                }
                break;
            }
            cout << "The customer count or book count is less than 1." << endl;
            cin.ignore(INT_MAX, '\n');
            getchar();
            break;

        case 4:
            if (customerCount > 0 && bookCount > 0)
            {
                customerSelection = customerIndexRequest(customers, customerCount);

                customers[customerSelection] = returnBook(customers[customerSelection], books, bookCount, day);
            }
            break;
        case 5:

            payLateFee(customers, customerCount);
            break;

        case 6:
            if (customerCount > 0)
            {
                customerSelection = customerIndexRequest(customers, customerCount);;
                if (customers[customerSelection].checkedOutCount == 0 && customers[customerSelection].lateFee == 0)
                    customers = deleteCustomer(customers, customerSelection, customerCount);
                else
                {
                    cout << "This customer either has checked out books or unpaid late fees." << endl;
                    cin.ignore(INT_MAX, '\n');
                    getchar();
                }
                cin.ignore(INT_MAX, '\n');
                break;
            }
            break;
        case 7:
            currentBooks(customers, customerCount, books, bookCount);
            cin.ignore(INT_MAX, '\n');
            getchar();
            break;
        case 8:
            currentCustomers(customers, customerCount, day);
            cin.ignore(INT_MAX, '\n');
            getchar();
            break;
        default:
            day++; //THIS IS ONLY TO FAST FORWARD THE DAYS FOR TESTING PURPOSES.
        }
    }
}

//https://stackoverflow.com/questions/3613302/passing-array-of-structures-to-function-c
//https://www.quora.com/Why-do-variables-not-change-their-values-after-being-called-by-a-function-in-C
struct book* addBook(struct book* oldBooks, int& bookCount)
{
    int count = bookCount + 1;
    book* newBooks = new book[count];
    count -= 1;
    book newBook;
    cout << "Enter the title: ";
    //https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
    cin.clear(); //https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
    cin.ignore(INT_MAX, '\n');
    getline(cin, newBook.title);
    cout << "Enter the author: ";
    getline(cin, newBook.author);
    cout << "enter the publisher: ";
    getline(cin, newBook.publisher);
    cout << "Enter the release date: ";
    getline(cin, newBook.releaseDate);

    /* This creates a new array that is one element larger than the former (if one exists) and stores the new information within.*/
    if (bookCount > 0)
    {
        for (int a = 0; a < count; a++)
        {
            newBooks[a] = oldBooks[a];
        }

        
        newBooks[count].title = newBook.title;
        newBooks[count].author = newBook.author;
        newBooks[count].publisher = newBook.publisher;
        newBooks[count].releaseDate = newBook.releaseDate;
        newBooks[count].available = true;
        newBooks[count].dueDay = 0;
        newBooks[count].lateFeePerDay = 3;
    }
    else
    {
        newBooks[0].title = newBook.title;
        newBooks[0].author = newBook.author;
        newBooks[0].publisher = newBook.publisher;
        newBooks[0].releaseDate = newBook.releaseDate;
        newBooks[0].available = true;
        newBooks[0].dueDay = 0;
        newBooks[0].lateFeePerDay = 3;
    }
    bookCount++;
    return newBooks;
}

//https://stackoverflow.com/questions/3613302/passing-array-of-structures-to-function-c
//https://www.quora.com/Why-do-variables-not-change-their-values-after-being-called-by-a-function-in-C
struct book* rentBook(struct book* oldBooks, struct book bookRental, int& checkedOutCount, int day, int checkout)
{
    int count = checkedOutCount + 1;
    book* newBooks = new book[count];
    count -= 1;

    if (checkedOutCount > 0)
    {
        for (int a = 0; a < count; a++)
        {
            newBooks[a] = oldBooks[a];
        }

        newBooks[count].title = bookRental.title;
        newBooks[count].author = bookRental.author;
        newBooks[count].publisher = bookRental.publisher;
        newBooks[count].releaseDate = bookRental.releaseDate;

        cout << "When is this book due? ";
        cin >> newBooks[count].dueDate;

        newBooks[count].available = true;
        newBooks[count].dueDay = day + checkout;
        newBooks[count].lateFeePerDay = 3;
        checkedOutCount++;
    }
    else
    {
        newBooks[0].title = bookRental.title;
        newBooks[0].author = bookRental.author;
        newBooks[0].publisher = bookRental.publisher;
        newBooks[0].releaseDate = bookRental.releaseDate;

        cout << "When is this book due? ";
        cin >> newBooks[0].dueDate;

        newBooks[0].available = true;
        newBooks[0].dueDay = day + checkout;
        newBooks[0].lateFeePerDay = 3;
        checkedOutCount++;
    }

    return newBooks;
}

//https://stackoverflow.com/questions/3613302/passing-array-of-structures-to-function-c
//https://www.quora.com/Why-do-variables-not-change-their-values-after-being-called-by-a-function-in-C
struct customer* addCustomer(struct customer* oldCustomers, int& customerCount)
{
    int count = customerCount + 1;
    customer* newCustomers = new customer[count];
    count -= 1;
    customer newCustomer;
    cout << "Enter the name: ";
    //https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
    cin.clear(); //https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
    cin.ignore(INT_MAX, '\n');
    getline(cin, newCustomer.name);
    cout << "Enter the address: ";
    getline(cin, newCustomer.address);
    cout << "enter the phone number: ";
    getline(cin, newCustomer.phoneNumber);
    cout << "Enter today's date: ";
    getline(cin, newCustomer.registeredDate);

    /* This creates a new array that is one element larger than the former (if one exists) and stores the new information within.*/
    if (customerCount > 0)
    {
        for (int a = 0; a < count; a++)
        {
            newCustomers[a] = oldCustomers[a];
        }


        newCustomers[count].name = newCustomer.name;
        newCustomers[count].address = newCustomer.address;
        newCustomers[count].phoneNumber = newCustomer.phoneNumber;
        newCustomers[count].registeredDate = newCustomer.registeredDate;
        newCustomers[count].checkedOutCount = 0;
        newCustomers[count].booksBorrowed = {};
        newCustomers[count].lateFee = 0;
    }
    else
    {
        newCustomers[0].name = newCustomer.name;
        newCustomers[0].address = newCustomer.address;
        newCustomers[0].phoneNumber = newCustomer.phoneNumber;
        newCustomers[0].registeredDate = newCustomer.registeredDate;
        newCustomers[0].checkedOutCount = 0;
        newCustomers[0].booksBorrowed = {};
        newCustomers[0].lateFee = 0;
    }
    customerCount++;
    return newCustomers;
}

void availableBooks(book* books, int bookCount)
{
    bool available = false;
    for (int a = 0; a < bookCount; a++)
    {
        if (books[a].available)
        {
            cout << left << setw(20) << a << left << setw(20) << books[a].title << left << setw(20) << "-" << "Yes" << endl;
            available = true;
        }
    }
}

bool booksAvailable(book* books, int bookCount)
{
    bool available = false;
    for (int a = 0; a < bookCount; a++)
    {
        if (books[a].available)
        {
            available = true;
        }
    }

    return available;
}

void currentCustomers(customer* customers, int customerCount, int day)
{
    cout << left << setw(20) <<  "Customer" << left << setw(20) << "Books Borrowed" << "Due date" << endl;
    for (int a = 0; a < customerCount; a++)
    {
        for (int b = 0; b < customers[a].checkedOutCount; b++)
        {
            cout << left << setw(20) << customers[a].name << left << setw(20) << customers[a].booksBorrowed[b].title << customers[a].booksBorrowed[b].dueDate << endl;
        }
    }
}

void currentBooks(customer* customers, int customerCount, book* books, int bookCount)
{
    cout << left << setw(20) << "Index" << left << setw(20) << "Title" << left << setw(20) << "Borrowed by" << "Availability" << endl;
    for (int a = 0; a < customerCount; a++)
    {
        for (int b = 0; b < customers[a].checkedOutCount; b++)
        {
            cout << left << setw(20)<< b << left << setw(20) << customers[a].booksBorrowed[b].title << left << setw(20) << customers[a].name << "No" << endl;
        }
    }
    availableBooks(books, bookCount);
}

// https://www.quora.com/Why-do-variables-not-change-their-values-after-being-called-by-a-function-in-C
struct customer returnBook(customer& customer, book*& books, int bookCount, int day)
{
    int bookSelection = 0;
    int lateFee = 0;
    cout << left << setw(20) << "Customer Name: " << customer.name << "\n" << endl;
    cout << left << setw(20) << "Index" << left << setw(20) << "Book Title" << left << setw(30) << "Number of days Borrowed" << left << setw(20) << "No of Days Overdue" << "Late Fee" << endl;
    for (int a = 0; a < customer.checkedOutCount; a++)
    {
        
        int overdue = day - customer.booksBorrowed[a].dueDay;
        int fee = customer.booksBorrowed[a].lateFeePerDay * overdue;
        if (fee < 0)
            fee = 0;
        cout << left << setw(20) << a << left << setw(20) <<  customer.booksBorrowed[a].title << left << setw(30) <<  customer.booksBorrowed[a].dueDay << left << setw(20) <<  day - customer.booksBorrowed[a].dueDay << "$" << fee << ".00" << endl;

        lateFee += fee;
    }

    cout << "Total Late Fee: " << "$" << lateFee << ".00" << endl;
    cout << "Enter the index of the returned book: ";
    cin >> bookSelection;

    if ((day - customer.booksBorrowed[bookSelection].dueDay) * customer.booksBorrowed[bookSelection].lateFeePerDay > 0)
        customer.lateFee += (day - customer.booksBorrowed[bookSelection].dueDay) * customer.booksBorrowed[bookSelection].lateFeePerDay; //It only makes sense to save the late fees of the returned books.
    int checkoutSubtraction = customer.checkedOutCount;
    for (int a = 0; a < bookCount; a++)
    {
        if (books[a].title == customer.booksBorrowed[bookSelection].title && books[a].available == false)
        {
            books[a].available = true;
            checkoutSubtraction--;
        }
    }
    book* newBooks = new book[checkoutSubtraction];
    int newBookCounter = 0;
    for (int a = 0; a < customer.checkedOutCount; a++)
    {
        if (a != bookSelection && newBookCounter < checkoutSubtraction)
        {
            newBooks[newBookCounter] = customer.booksBorrowed[a];
            newBookCounter++;
        }
    }

    customer.checkedOutCount = checkoutSubtraction;
    customer.booksBorrowed = newBooks;

    return customer;
}

//https://www.quora.com/Why-do-variables-not-change-their-values-after-being-called-by-a-function-in-C
struct customer* deleteCustomer(customer* customers, int customerSelection, int& customerCount)
{
    int customerSubtraction = customerCount - 1;

    customer* newCustomers = new customer[customerSubtraction];
    int newCustomersCounter = 0;
    for (int a = 0; a < customerCount; a++)
    {
        if (a != customerSelection && newCustomersCounter < customerSubtraction)
        {
            newCustomers[newCustomersCounter] = customers[a];
            newCustomersCounter++;
        }
    }

    customerCount = customerSubtraction;

    return newCustomers;
}

int customerIndexRequest(customer* customers, int customerCount)
{
    int customerSelection = 0;
    cout << left << setw(20) << "Index" << "Customer Name" << endl;
    for (int a = 0; a < customerCount; a++)
        cout << left << setw(20) << a << left << setw(20) << customers[a].name << endl;

    cout << "Enter the index of the customer: ";
    cin >> customerSelection;

    return customerSelection;
}

int bookIndexRequest(book* books, int bookCount)
{
    int bookSelection = 0;
    cout << left << setw(20) << "Index" << left << setw(20) <<"Title" << left << setw(20) << "Borrowed by" << "Availability" << endl;

    availableBooks(books, bookCount);

    cout << "Enter the index of the book: ";
    cin >> bookSelection;

    return bookSelection;

}

void payLateFee(customer* customers, int customerCount)
{
    int customerIndex = customerIndexRequest(customers, customerCount);
    char y;
    cout << "Late fee: " << "$" << customers[customerIndex].lateFee << ".00." << endl;
    cout << "Enter the y key if paid. ";
    cin >> y;

    if (y == 'y')
        customers[customerIndex].lateFee = 0;
}
