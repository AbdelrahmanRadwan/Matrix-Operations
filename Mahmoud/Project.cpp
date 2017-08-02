//case: [10 2.13 3;-5 0 4;16.5 1 8]
#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
float Arr[100][100], Result[100][100],Matrix1[100][100],Matrix2[100][100];
int Row = 1, Column=1;
string input1, input2;
void FillArray(string input)
{
	istringstream is(input);
	float number;
	for (int i = 0; i < Column; i++)
	{
		is >> number;
		Arr[Row-1][i] = number;
	}
}
void TransformTheString(string input)
{
	Row = 1, Column = 1;
	string temp="";// the record 
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ';')
			FillArray(temp), temp = "", Column = 1, Row++;
		else if (input[i] != '[' && input[i] != ';' && input[i]!=']')
			temp += input[i];
		if (input[i] == ' ')
				Column++;
		if (input[i] == ']')
			FillArray(temp);
	}
}
void ReUse(float arr[100][100])
{
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
			arr[i][j] = Arr[i][j];
}
void print()
{
	cout << "[";
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
		{
			cout << Result[i][j];
			if (j != Column - 1)
				cout << " ";
			else if (i!=Row-1)
				cout << ";";
		}
	cout << "]"<<endl;
}
void Add()
{
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
			Result[i][j] = Matrix1[i][j] + Matrix2[i][j];
}
void Subtract()
{
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
			Result[i][j] = Matrix1[i][j] - Matrix2[i][j];
}
void transpose()
{
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
		{
			if (i == j)
				break;
			swap(Arr[i][j], Arr[j][i]);
		}
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
			Result[i][j] = Arr[i][j];
}
float Calculate(int i, int j)
{
	float result = 0;
	for (int k = 0; k < Column; k++)
		result += (Matrix1[i][k] * Matrix2[k][j]);
	return result;
}
void Multiplication()
{
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++)
		{
			Result[i][j] = Calculate(i,j);
		}
}
void Manipulation(char operation)
{
	switch (operation)
	{
	case '+':
		{
			cin.ignore();
			getline(cin, input2);
			TransformTheString(input2);
			ReUse(Matrix2);
			Add();
			break;
		}
	case '-':
	{
		cin.ignore();
		getline(cin, input2);
		TransformTheString(input2);
		ReUse(Matrix2);
		Subtract();
		break;
	}
	case '*':
	{
		cin.ignore();
		getline(cin, input2);
		TransformTheString(input2);
		ReUse(Matrix2);
		Multiplication();
		break;
	}
	case 'T':
	{
		transpose();
		break;
	}
	}
}
int main()
{
	char operation;
		getline(cin, input1);
		TransformTheString(input1);
		ReUse(Matrix1);
		cin >> operation;
		Manipulation(operation);
		print();
	return 0;
}