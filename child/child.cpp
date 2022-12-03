#include<iostream> 
#include<stdlib.h> 

using namespace std;

int main(int argc, char* argv[])
{


	cout << "Child created" << endl;
	int Y = atoi(argv[0]);
	int size = atoi(argv[1]);
	cout << "Number to find is " << Y << endl;
	cout << "Size of array is " << size << endl;

	int* mas = new int[size];
	int counter = 0;
	for (int i = 2; i < argc; i++)
	{
		mas[counter] = atoi(argv[i]);
		counter += 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (mas[j] > mas[j + 1]) {
				int b = mas[j]; 
				mas[j] = mas[j + 1]; 
				mas[j + 1] = b; 
			}
		}
	}


	for (int i = 0; i < size; i++) {
		cout << mas[i] << " ";
	}


	cout << endl;

	system("pause");
	delete[] mas;
	return 0;

}