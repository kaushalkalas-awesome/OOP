/*
  Name: Kaushal Kishor Kalas
  Student ID (PRN): 24UAM305
*/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool isHardcover;
    float* chapterPages;
    int numChapters;

public:
    //Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';

        author = new char[1];
        author[0] = '\0';

        pageCount = 0;
        isHardcover = false;
        chapterPages = NULL;
        numChapters = 0;
    }

    //Parameterized Constructor
    Book(const char* _title, const char* _author, int _pages, bool _format, int _chapters) {
        //Copying strings
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);

        author = new char[strlen(_author) + 1];
        strcpy(author, _author);

        pageCount = _pages;
        isHardcover = _format;
        numChapters = _chapters;

        //Uniform distribution of pages across chapters
        chapterPages = new float[numChapters];
        float avgPages = static_cast<float>(pageCount) / numChapters;

        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = avgPages;
        }
    }

    //Copy Constructor (Deep Copy)
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        pageCount = other.pageCount;
        isHardcover = other.isHardcover;
        numChapters = other.numChapters;

        if (numChapters > 0 && other.chapterPages != NULL) {
            chapterPages = new float[numChapters];
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = other.chapterPages[i];
            }
        } else {
            chapterPages = NULL;
        }
    }

    //Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    //Modify Chapter Page Count
    void modifyChapterPages(int chapterIndex, float newPageCount) {
        if (chapterIndex >= 0 && chapterIndex < numChapters) {
            chapterPages[chapterIndex] = newPageCount;
        } else {
            cout << "Invalid chapter index.\n";
        }
    }

    //Display Book Info
    void displayBookInfo() const {
        cout << "\n=== Book Information ===" << endl;
        cout << "Title        : " << title << endl;
        cout << "Author       : " << author << endl;
        cout << "Total Pages  : " << pageCount << endl;
        cout << "Format       : " << (isHardcover ? "Hardcover" : "Paperback") << endl;
        cout << "Chapters     : " << numChapters << endl;

        cout << "Chapter Page Distribution:\n";
        for (int i = 0; i < numChapters; i++) {
            cout << "  Chapter " << (i + 1) << ": " << chapterPages[i] << " pages\n";
        }
        cout << "==========================\n";
    }
};

//Main Function
int main() {
    //Using Default Constructor
    Book b1;
    b1.displayBookInfo();

    //Using Parameterized Constructor
    Book b2("How to Win and Influence People", "Dale Carnegie", 400, true, 4);
    b2.displayBookInfo();

    //Modify chapter 2 page count
    cout << "\nModifying chapter 2 in original book...\n";
    b2.modifyChapterPages(1, 120.5);
    b2.displayBookInfo();

    //Using Copy Constructor
    Book b3 = b2;
    cout << "\nCopy of Book (Deep Copy):\n";
    b3.displayBookInfo();

    //Demonstrating memory independence
    cout << "\nModifying chapter 1 in original book...\n";
    b2.modifyChapterPages(0, 50.0);
    b2.displayBookInfo();
    cout << "\nCopied book remains unchanged:\n";
    b3.displayBookInfo();

    return 0;
}
