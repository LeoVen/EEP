#include <windows.h>

DWORD WINAPI ThreadFunc(void* data) {
	// Do stuff. This will be the first function called on the new thread.
	// When this function returns, the thread goes away. See MSDN for more details.
	return 0;
}

int main(int argc, char const *argv[])
{

	for (;;) {
		HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	}

}