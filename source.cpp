#################################################  Varianti 1 #################################################


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Student {
    float scoreToFind;


    void fillRandomly() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                studentScoreArr[i][j] = rand() % 100;
            }
        }
    }

    void sort() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        if (studentScoreArr[i][j] < studentScoreArr[k][l]) {
                            float temp = studentScoreArr[i][j];
                            studentScoreArr[i][j] = studentScoreArr[k][l];
                            studentScoreArr[k][l] = temp;
                        }
                    }
                }
            }
        }
    }

    void findScore() {
        for (int i = 0; i < 5; i++) {
            bool found = false;
            for (int j = 0; j < 5; j++) {
                if (studentScoreArr[i][j] == scoreToFind) {
                    std::cout << "Found at: " << i << " " << j << std::endl;
                    found = true;
                }
            }

            if (!found) {
                std::cout << "Not found" << std::endl;
            }
            found = false;
        }
    }


public:
    float studentScoreArr[5][5];
    Student(int scoreToFind) {
        this->scoreToFind = scoreToFind;
        fillRandomly();
        sort();
        findScore();
    }

    void print() {
        std::cout << "Python " << "C++ " << "Java " << "C " << "Js " << std::endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                std::cout << studentScoreArr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};


int main() {

    srand(time(NULL));
    Student student(4);
    student.print();

    for (int i = 0; i < 5; i++) {
        float maxForStudent = student.studentScoreArr[i][0];
        float sumForExceptMax = 0;
        for (int j = 0; j < 5; j++) {
            if (student.studentScoreArr[i][j] > maxForStudent) {
                maxForStudent = student.studentScoreArr[i][j];
            }
            else {
                sumForExceptMax += student.studentScoreArr[i][j];
            }

        }
        sumForExceptMax = cbrt(sumForExceptMax / 5);
        std::cout << "Max value for student: " << i << " is: " << maxForStudent << std::endl;
        std::cout << "Sum of other scores is: " << sumForExceptMax << std::endl;
    }

    return 0;
}


#################################################  Varianti 2 #################################################

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " " << std::endl;
    }
}

class Sorter {
    public:
        void bubbleSort(int *arr, int size){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size - 1; j++){
                    if(arr[j] < arr[i]) {
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
        }

};


int main() {

    srand(time(NULL));
    int arr[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    std::cout << "Filled array before sorting: " << std::endl;
    printArr(arr, 10);

    Sorter sorter;
    sorter.bubbleSort(arr, 10);
    std::cout << "After sorting: " << std::endl;
    printArr(arr, 10);

    switch(8 % 4) {
        case 1:
            std::cout << "1" << std::endl;
            break;
        case 2:
            std::cout << "2" << std::endl;
            break;

        case 3:
            std::cout << "3" << std::endl;
            break;
        case 0:
            std::cout << "4" << std::endl;
            break;
    }

    char str1[] = "Hello";
    char str2[] = "Hello";
    std::cout << strcmp(str1, str2) << std::endl;
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    strncpy(str1, str2, 5);
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    
    std::cout << (int)str1[0] << std::endl;

    char str3[strlen(str2)];
    for(int i = 0; i < strlen(str2); i++){
        str3[i] = (char)toupper((int)str2[i]);
    }
    std::cout << str3 << std::endl;
    return 0;
}





#################################################  Varianti 3 #################################################



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Student {
private:
    static const int ARRAY_SIZE = 5;
    char lookupSign;
    int marks[ARRAY_SIZE];

    void fillValues() {
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            marks[i] = rand() % 101; // Generate a random mark between 0 and 100
        }
    }

    void sortMarks() {
        std::sort(marks, marks + ARRAY_SIZE);
    }

    void findMatch() {
        bool matchFound = false;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (marks[i] == lookupSign) {
                std::cout << "Match found at index " << i << std::endl;
                matchFound = true;
                break;
            }
        }
        if (!matchFound) {
            std::cout << "No match found." << std::endl;
        }
    }

public:
    Student(char sign) : lookupSign(sign) {
        fillValues();
        sortMarks();
        findMatch();
    }

    void printMaxGrade() {
        int maxGrade = marks[ARRAY_SIZE - 1];
        std::cout << "Maximum grade: " << maxGrade << std::endl;
    }

    void sumRemainingGrades() {
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            sum += marks[i];
        }
        std::cout << "Sum of remaining grades: " << sum << std::endl;
    }

    void calculateThirdPowerRoot() {
        double sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            sum += marks[i];
        }
        double mean = sum / ARRAY_SIZE;
        double thirdRoot = cbrt(mean);
        std::cout << "Third power root of the arithmetic mean: " << thirdRoot << std::endl;
    }
};

int main() {
    Student student('A');
    student.printMaxGrade();
    student.sumRemainingGrades();
    student.calculateThirdPowerRoot();

    return 0;
}


#################################################  Varianti 4 #################################################



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

class ArrayManipulator {
private:
    static const int ARRAY_SIZE = 10;
    int array[ARRAY_SIZE];

public:
    ArrayManipulator() {
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = rand() % 100; // Generate a random number between 0 and 99
        }
    }

    void sortArrayDescending() {
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
                if (array[j] < array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    void printArray() {
        std::cout << "Array: ";
        for (int i = 0; i < ARRAY_SIZE; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayManipulator manipulator;
    manipulator.printArray();

    int balance = 4;
    switch (balance) {
        case 1:
            std::cout << "Balance is 1." << std::endl;
            break;
        case 2:
            std::cout << "Balance is 2." << std::endl;
            break;
        case 3:
            std::cout << "Balance is 3." << std::endl;
            break;
        default:
            std::cout << "Balance is 0." << std::endl;
            break;
    }

    char string1[] = "Hello";
    char string2[] = "World";

    int comparisonResult = strcmp(string1, string2);
    if (comparisonResult == 0) {
        std::cout << "The strings are equal." << std::endl;
    } else if (comparisonResult < 0) {
        std::cout << "String1 is less than String2." << std::endl;
    } else {
        std::cout << "String1 is greater than String2." << std::endl;
    }

    strcat(string2, string1 + 5);
    std::cout << "Concatenated string: " << string2 << std::endl;

    int firstCharacterValue = static_cast<int>(string1[0]);
    std::cout << "Numeric value of the first character: " << firstCharacterValue << std::endl;

    for (int i = 0; i < strlen(string2); i++) {
        string2[i] = toupper(string2[i]);
    }
    std::cout << "Uppercase string: " << string2 << std::endl;

    return 0;
}






