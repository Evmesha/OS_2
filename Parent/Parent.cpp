#include<iostream> 
#include<windows.h> 
#include<conio.h> 
#include<stdio.h> 
#include<tchar.h> 
#include<string> 

using namespace std;



int main()
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int* array = new int[size];
	cout << "Enter " << size << " elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}

	unsigned int Y;
	cout << "Enter Y shift: ";
	cin >> Y;

	string cmd_args;
	cmd_args = to_string(Y);
	cmd_args += " ";
	cmd_args += to_string(size);
	cmd_args += " ";
	for (int i = 0; i < size; i++)
	{
		cmd_args += to_string(array[i]);
		if (i != size - 1)
		{
			cmd_args += " ";
		}
	}

	wstring stemp = wstring(cmd_args.begin(), cmd_args.end());
	LPCTSTR lpszAppName = L"child.exe";
	STARTUPINFO si;
	PROCESS_INFORMATION piApp;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USEPOSITION;
	si.dwY = Y;

	if (!CreateProcess(lpszAppName, &stemp[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		cout << "No new process" << endl;
		return 0;
	}

	cout << "New process is created" << endl;
	WaitForSingleObject(piApp.hProcess, INFINITE);

	CloseHandle(piApp.hThread);
	CloseHandle(piApp.hProcess);
	delete[]array;
	return 0;

}