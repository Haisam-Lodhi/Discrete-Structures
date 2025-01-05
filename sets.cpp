//#include <iostream>
//#include<string>
//using namespace std;
//
//// Function to create a set by taking input from the user
//void createSet(int set[], int& size, const string& setName) {
//	cout << "Enter the number of elements in " << setName << ": ";
//	cin >> size;
//	cout << "Enter elements of " << setName << ":\n";
//	for (int i = 0; i < size; i++) {
//		cin >> set[i];
//	}
//}
//
//// Function to check if an element is present in a given array
//bool isPresent(int element, int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		if (arr[i] == element) {
//			return true;
//		}
//	}
//	return false;
//}
//
//// Function to compute the union of two sets
//void unionSets(int setA[], int sizeA, int setB[], int sizeB, int result[], int& sizeResult) {
//	sizeResult = 0;
//
//	// Add all elements from set A
//	for (int i = 0; i < sizeA; i++) {
//		result[sizeResult++] = setA[i];
//	}
//
//	// Add elements from set B that are not already in result
//	for (int i = 0; i < sizeB; i++) {
//		if (!isPresent(setB[i], result, sizeResult)) {
//			result[sizeResult++] = setB[i];
//		}
//	}
//
//	// Print the union set
//	cout << "Union: ";
//	for (int i = 0; i < sizeResult; i++) {
//		cout << result[i] << " ";
//	}
//	cout << "\n";
//}
//
//// Function to compute the intersection of two sets
//void intersectionSets(int setA[], int sizeA, int setB[], int sizeB, int result[], int& sizeResult) {
//	sizeResult = 0;
//
//	// Add elements that are present in both sets
//	for (int i = 0; i < sizeA; i++) {
//		if (isPresent(setA[i], setB, sizeB)) {
//			result[sizeResult++] = setA[i];
//		}
//	}
//
//	// Print the intersection set
//	cout << "Intersection: ";
//	for (int i = 0; i < sizeResult; i++) {
//		cout << result[i] << " ";
//	}
//	cout << "\n";
//}
//
//// Function to compute the difference of two sets (A - B)
//void differenceSets(int setA[], int sizeA, int setB[], int sizeB, int result[], int& sizeResult) {
//	sizeResult = 0;
//
//	// Add elements from A that are not in B
//	for (int i = 0; i < sizeA; i++) {
//		if (!isPresent(setA[i], setB, sizeB)) {
//			result[sizeResult++] = setA[i];
//		}
//	}
//}
//
//// Function to print a set
//void printSet(const int set[], int size, const string& setName) {
//	cout << setName << ": ";
//	for (int i = 0; i < size; i++) {
//		cout << set[i] << " ";
//	}
//	cout << "\n";
//}
//
//// Function to calculate the total number of relations between two sets
//void calculateRelations(int sizeA, int sizeB) {
//	cout << "Total number of relations: " << sizeA * sizeB << "\n";
//}
//
//// Function to display reflexive relations
//void reflexiveRelations(int setA[], int sizeA, int setB[], int sizeB) {
//	cout << "Reflexive Relations:\n";
//
//	// Reflexive relation: (x, x) where x is in both sets
//	for (int i = 0; i < sizeA; i++) {
//		if (isPresent(setA[i], setB, sizeB)) {
//			cout << "(" << setA[i] << ", " << setA[i] << ") ";
//		}
//	}
//	cout << "\n";
//}
//
//// Function to display symmetric relations
//void symmetricRelations(int setA[], int sizeA, int setB[], int sizeB) {
//	cout << "Symmetric Relations:\n";
//
//	// Symmetric relation: (x, y) and (y, x) for all pairs
//	for (int i = 0; i < sizeA; i++) {
//		for (int j = 0; j < sizeB; j++) {
//			cout << "(" << setA[i] << ", " << setB[j] << ") ";
//			cout << "(" << setB[j] << ", " << setA[i] << ") ";
//		}
//	}
//	cout << "\n";
//}
//
//// Function to display anti-symmetric relations
//void antisymmetricRelations(int setA[], int sizeA, int setB[], int sizeB) {
//	cout << "Anti-symmetric Relations:\n";
//
//	// Anti-symmetric relation: (x, y) but not (y, x)
//	for (int i = 0; i < sizeA; i++) {
//		for (int j = 0; j < sizeB; j++) {
//			if (setA[i] != setB[j] || !isPresent(setA[i], setB, sizeB)) {
//				cout << "(" << setA[i] << ", " << setB[j] << ") ";
//			}
//		}
//	}
//	cout << "\n";
//}
//
//int main() {
//	int sizeA, sizeB, sizeResult;
//	int setA[100], setB[100], result[200];
//	int choice;
//
//	do {
//		// Display menu
//		cout << "\nMenu:\n";
//		cout << "1. Create sets\n2. Union of two sets\n3. Intersection of two sets\n";
//		cout << "4. Print sets\n5. A - B\n6. B - A\n";
//		cout << "7. Total number of relations\n8. Reflexive Relations\n";
//		cout << "9. Symmetric Relations\n10. Anti-symmetric Relations\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			// Create sets
//			createSet(setA, sizeA, "Set A");
//			createSet(setB, sizeB, "Set B");
//			break;
//		case 2:
//			// Union
//			unionSets(setA, sizeA, setB, sizeB, result, sizeResult);
//			break;
//		case 3:
//			// Intersection
//			intersectionSets(setA, sizeA, setB, sizeB, result, sizeResult);
//			break;
//		case 4:
//			// Print sets
//			printSet(setA, sizeA, "Set A");
//			printSet(setB, sizeB, "Set B");
//			break;
//		case 5:
//			// A - B
//			differenceSets(setA, sizeA, setB, sizeB, result, sizeResult);
//			cout << "A - B: ";
//			printSet(result, sizeResult, "");
//			break;
//		case 6:
//			// B - A
//			differenceSets(setB, sizeB, setA, sizeA, result, sizeResult);
//			cout << "B - A: ";
//			printSet(result, sizeResult, "");
//			break;
//		case 7:
//			// Total number of relations
//			calculateRelations(sizeA, sizeB);
//			break;
//		case 8:
//			// Reflexive Relations
//			reflexiveRelations(setA, sizeA, setB, sizeB);
//			break;
//		case 9:
//			// Symmetric Relations
//			symmetricRelations(setA, sizeA, setB, sizeB);
//			break;
//		case 10:
//			// Anti-symmetric Relations
//			antisymmetricRelations(setA, sizeA, setB, sizeB);
//			break;
//		case 0:
//			// Exit
//			cout << "Exiting...\n";
//			break;
//		default:
//			cout << "Invalid choice. Try again.\n";
//		}
//	} while (choice != 0);
//
//	system("pause");
//	return 0;
//}
