//  example.c
//  exampleC
//  Created by 崔舒宁 on 2019/4/8.
//  Copyright © 2019 崔舒宁. All rights reserved.
//
#include <string.h>
#include "exampleC.h"

/* 
*@简介：给出一个X>=2,判断x是否是素数
*@brief: given a nonnegative integer x>=2, judge x is a prime or not
*@parameter: x, a nonnegative integer
*@return: 1 if x is prime, 0 or not
*/
int IsPrime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

/*
*@简介：判断一个正整数是否是闰年
*@brief: judge a year is leap year or not
*@parameter: year, nonnegative integer of year
*@return: 1 if year is leap year, 0 or not
*/
int IsLeap(int year)
{
    return (year%4==0&&year%100)||(year%400==0);
}

/*
*@简介：将一个正整数按指定的进制分解为数字存入数组中
*for example, 7 decomposed 1 1 1 by binary
*@brief: Decomposing a positive integer into numbers 
*according to the specified base and storing them in the array
*@parameter: x[], store the result
*@parameter: n, a positive integer will be decomposed
*@parameter: radix, the specified base
*@return: number of digits after decomposition 
*/
int ParsingIntWithRadix(int x[],int n,int radix)
{
    int i=0;
    while(n)
    {
        x[i++]=n%radix;
        n/=radix;
    }
    return i;
}

/*
*@简介：将字符串开头处指定的字符删除
*for example, "sss123ss" after removed 's' is "123ss"
*@parameter: str, the original character string
*@parameter: ch, the character will be removed
*@return: the pointer of string after removed
*/
char* RomoveCharAtBegin(char* str,char ch)
{
    int i=0;
    //find the first character that do not equal ch
    while(str[i]==ch && str[i])
    {
        i++;
    }
    int j=0;
    //remove the character
    while(str[j++]=str[i++]);
    return str;
}

/*
*@简介：将字符串结尾处指定的字符删除
*for example, "sss123ss" after removed 's' is "sss123"
*@parameter: str, the original character string
*@parameter: ch, the character will be removed
*@return: the pointer of string after removed
*/
char* RomoveCharAtEnd(char* str,char ch)
{
    int i=strlen(str);
    i--;
    //find the last character equal ch form the end of string
    while(str[i]==ch && i>=0)
    {
        i--;
    }
    //put the zero end of string
    str[++i]=0;
    return str;
}

/*
*@简介：输入一个10进制的整数，按指定进制反转
*for example, 7 after reversed is 7 by binary base
*@parameter: x, the number will be reversed
*@parameter: radix, reversed by the specified base
*@return: the decimal number of reversed 
*/

int Reverse(int x,int radix)
{
    int y=0;
    while(x)
    {
        y=y*radix+x%radix;
        x=x/radix;
    }
    return y;
}

/*
*@简介：给出一个只含有数字的字符串，按指定进制转换为整数
*@brief: given a character string just include number digital,
*and convert it into a integer by the specified base
*@parameter: num, the pointer of the character string
*@parameter: radix, the specified base
*@return: the integer after conversion
*/
int StringToInt(char* num,int radix)
{
    int x=0;
    int i=0;
    while(num[i])
    {
        x=x*radix+(num[i]-'0');
        i++;
    }
    return x;
}

/*
*@简介：整数的从小到大的冒泡排序
*@brief: Bubble ordering of integers from small to large
*@parameter: a, the integer array will be ordered
*@parameter: n, number of items will be ordered in the array
*/
void Bubble(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                flag=0;
            }
        }
        if(flag)
            break;
    }
}

/*
*@简介：将一个字符串按指定字符分隔为若干字符串存储到二维数组中
*brief: Separate a string into several strings according 
*to the specified characters and 
*store them in a two-dimensional array
*@parameter: split, the 2-D array stored the substrings
*@parameter: str, the original character string
*@parameter: x, the separated character
*@return: the number of separator strings
*/
int SplitString(char split[][100],char* str,char x)
{
    RomoveCharAtEnd(str, x);
    RomoveCharAtBegin(str, x);
    int sum=0;
    int i=0;
    int j=0;
    while(str[i])
    {
        if(str[i]==x)  //meet the separated character
        {
            split[sum][j]=0;  //the end of this line
            sum++;
            j=0;
            while(str[i++]==x);  //skip consecutive separators
            i--;
        }
        else
        {
            split[sum][j++]=str[i++];  //copy to the 2-D array
        }
    }
    split[sum][j]=0;
    return ++sum;
}

/*
*@简介：将整数按指定的进制（2<=radix<=16) 分解为字符串
*@brief: Decomposes an integer into a string in 
*the specified base (2 < = radius < = 16)
*@parameter: num, the decomposed character string
*@parameter: n, the integer will be decomposed
*@parameter: radix, the specified base
*@return: the pointer of the decomposed character string, 
*that is the pointer of num
*/
char* IntToString(char* num,int n,int radix)
{
    int i=0;
    while(n)
    {
        int m=n%radix;
        if(0<=m && m<=9)  //convert it to ASCII code
        {
            num[i++]=m+'0';
        }
        else   //convert it to 'A'-'F' over 10
        {
            num[i++]=m-10+'A';
        }
        n=n/radix; //the next number
    }
    num[i]=0;
    strrev(num);  //reverse the string
    return num;
}
/*
*@简介: 反转字符串，strrev在c99标准中不是标准库函数，一些编译器并没提供
*如果编译器提供了该函数，尽量使用编译器提供的版本
*@brief: Strrev is not a standard library function in C99 standard. Some compilers do not provide
If the compiler provides the function, try to use the version provided by the compiler
*/

char* strrev(char* str)
{
    int j=strlen(str);   //the length of string
    for(int i=0;i<j/2;i++)  //swap head and tail
    {
        char t=str[i];
        str[i]=str[j-i-1];
        str[j-i-1]=t;
    }
    return str;
}
