#include<iostream>
#include<string.h>
#include<conio.h>
int a[]={3,55,7,22,3,8,9,12,4,3,5,6,77,33,9,2,13,65,73,93,12,67,34,56,77,99,51,19,18,90,55,69,32,44,123,121,232,50,89,111,323};
using namespace std;
void ench(char str[],int n)
{
	for(int i=0;i<n;i++)
	{
	if(str[i]==' '){
	str[i]='c';
	}
	else {
	str[i]=str[i]^a[i];
	}
	}
}
void dech(char str[],int n)
{
	for(int i=0;i<n;i++)
	{
	if(str[i]==' '){
	str[i]='c';
	}
	else {
	str[i]=str[i]^a[i];
	}
	}
}
