#include <stdio.h>

template<class T>
struct  HeapPointer
{
	T* P = NULL;
};

template<class T>
HeapPointer<T> ConstructHeapPointer(T* In) {
	HeapPointer<T> HP;
	HP.P = In;

	return HP;
}

template<class T>
T* Free(HeapPointer<T>& In) {
	T* P = In.P;
	In.P = NULL;
	return P;
}
template <class T>
T* GetPTR(HeapPointer<T>& In) {
	return In.P;
}

int main() {
	int* P = new int();
	HeapPointer<int> HP = ConstructHeapPointer(P);
	int* T = GetPTR(HP);
	(*T) = 0xdeadbeef;
	printf("%d", *T);
	int* E=Free(HP);
	delete E;
	E = nullptr;
	T = nullptr;
	P = nullptr;

	return 0;
}