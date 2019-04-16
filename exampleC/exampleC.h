//
//  exampleC.h
//  exampleC
//
//  Created by 崔舒宁 on 2019/4/8.
//  Copyright © 2019 崔舒宁. All rights reserved.
//

#ifndef exampleC_h
#define exampleC_h
int IsPrime(int x);
int IsLeap(int year);
int ParsingIntWithRadix(int x[],int n,int radix);
char* RomoveCharAtBegin(char* str,char ch);
char* RomoveCharAtEnd(char* str,char ch);
int Reverse(int x,int radix);
int CharToInt(char* num,int radix);
void Bubble(int* a,int n);
int SplitString(char split[][100],char* str,char x);
char* IntToChar(char* num,int n,int radix);
char* strrev(char* str);
#endif /* exampleC_h */
