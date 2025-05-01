#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

public:
    // Constructor
    FileEncryptor(string fname, int key) {
        filename = fname;
        encryptionKey = key;
    }

    // Encrypt the message and write it to a file
    void encryptAndWrite(string message) {
        ofstream outFile(filename.c_str());  
        if (!outFile.is_open()) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        for (int i = 0; i < message.length(); i++) {
            char encryptedChar = message[i] ^ encryptionKey;  // encryption
            outFile << encryptedChar;
        }

        outFile.close();
        cout << "Message successfully encrypted and saved in " << filename << endl;
    }

    // Read from file and decrypt the content
    string readAndDecrypt() {
        ifstream inFile(filename.c_str());
        if (!inFile.is_open()) {
            cout << "Error opening file for reading." << endl;
            return "";
        }

        string decrypted = "";
        char ch;
        while (inFile.get(ch)) {
            char decryptedChar = ch ^ encryptionKey;  // Decryption
            decrypted += decryptedChar;
        }

        inFile.close();
        return decrypted;
    }

    // Display decrypted message
    void displayFileContents() {
        cout << "\nDecrypting message from file...\n";
        string decryptedMessage = readAndDecrypt();
        cout << "Decrypted Message: " << decryptedMessage << endl;
    }
};

// Main function
int main() {
    string filename = "data.txt";
    int key = 1;
    string message;

    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    FileEncryptor encryptor(filename, key);
    encryptor.encryptAndWrite(message);
    encryptor.displayFileContents();

    return 0;
}

