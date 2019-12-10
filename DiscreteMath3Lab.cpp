#include <iostream>
#include "MyFunction.h"
using namespace std;

int main() {
	int ElementsA, ElementsB;
	
	cout << "Enter a number of the elements of the first array: ";
	cin >> ElementsA;
	if (ElementsA < 0 || !cin) {
		cout << "Error";
		return 0;
	}
	
	cout << "Enter a number of the elements of the second array: ";
	cin >> ElementsB; 
	if (ElementsB < 0 || !cin) {
		cout << "Error";
		return 0;
	}
	int* A = new int[ElementsA];
	int* B = new int[ElementsB];
	
	cout << "Enter the elements of the first array: ";
	for (int i = 0; i < ElementsA; i++) {
		cin >> A[i];
		if (!cin) {
			cout << "Error";
			return 0;
		}
	}
	
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < ElementsB; i++) {
		cin >> B[i];
		if (!cin) {
			cout << "Error";
			return 0;
		}
	}
	
	int** AxB = new int* [ElementsA * ElementsB];
	for (int i = 0; i < ElementsA * ElementsB; i++)
	{
		AxB[i] = new int[2];
	}
	
	int** AttitudeMatrix = new int* [ElementsA];
	for (int i = 0; i < ElementsA; i++)
	{
		AttitudeMatrix[i] = new int[ElementsB];
	}
	Cartes(AxB, A, B, ElementsA, ElementsB);
	OutputMatrix(AxB, AttitudeMatrix, ElementsA, ElementsB);
	
	if (ElementsA != ElementsB) {
		cout << "It's not a square matrix";
		return 0;
	}
	int reflex, transitive;
	int* preflex = &reflex;
	int* ptransitive = &transitive;
	Reflexity(AttitudeMatrix, ElementsA, preflex);
	Transitivity(AttitudeMatrix, ElementsA, ptransitive);
	cout << "This attitude matrix is: ";
	if (*preflex == 1)
		cout << "reflexive and ";
	else if (*preflex == 0)
		cout << "antireflexive and ";
	else
		cout << "not reflexive or antireflexive and ";
	if (*ptransitive == 1)
		cout << "transitivity.";
	else if (*ptransitive == 0)
		cout << "not transitivity.";
	delete[] A;
	delete[] B;
	for (int i = 0; i < ElementsA * ElementsB; i++)
	{
		delete AxB[i];
	}
	delete[] AxB;
	for (int i = 0; i < ElementsA; i++)
	{
		delete AttitudeMatrix[i];
	}
	delete[] AttitudeMatrix;
	return 0;
}