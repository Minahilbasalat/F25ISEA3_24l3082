//#include <iostream>
//#include <string>
//#include <conio.h> 
//using namespace std;
//
//bool isPalindrome(const string& str) {
//    int left = 0;
//    int right = str.length() - 1;
//
//    while (left < right) {
//        if (str[left] != str[right]) {
//            return false; 
//        }
//        left++;
//        right--;
//    }
//    return true; 
//}
//
//int main() {
//    cout << "Palindrome Checker!!" << endl;
//    cout << "Press ESC at any time to quit.\n" << endl;
//
//    while (true) {
//        cout << "Enter a string: ";
//        string input;
//        getline(cin, input);
//
//        if (input.empty()) {
//            cout << "Empty input. Please try again." << endl;
//            continue;
//        }
//
//        if (isPalindrome(input)) {
//            cout << "Palindrome" << endl;
//        }
//        else {
//            cout << "Not Palindrome" << endl;
//        }
//
//        cout << "\nPress ESC to exit, or any other key to continue..." << endl;
//        char ch = _getch(); 
//        if (ch == 27) { 
//            cout << "Exiting program..." << endl;
//            break;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
