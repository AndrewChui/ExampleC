//
//  example.c
//  exampleC
//
//  Created by 崔舒宁 on 2019/4/8.
//  Copyright © 2019 崔舒宁. All rights reserved.
//
#include <string.h>
#include "exampleC.h"
/* 给出一个X>=2,判断x是否是素数*/
int IsPrime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
/*判断一个正整数是否是闰年*/
int IsLeap(int year)
{
    return (year%4==0&&year%100)||(year%400==0);
}

/*将一个正整数按指定的进制分解为数字存入数组中
 如7按2进制分解为1 1 1
 18按10进制分解为1 8
 函数的返回值为分解的位数
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

/*将字符串开头处指定的字符删除
 如：sss123ss移去s后是123ss
 函数的返回值是指向移去后的字符串的指针/
 */

char* RomoveCharAtBegin(char* str,char ch)
{
    int i=0;
    //找到第一个不是ch的字符
    while(str[i]==ch && str[i])
    {
        i++;
    }
    int j=0;
    //移除字符
    while(str[j++]=str[i++]);
    return str;
}

/*删除指定结尾处的字符*/

char* RomoveCharAtEnd(char* str,char ch)
{
    int i=strlen(str);
    i--;
    //从结尾开始找到最后一个ch
    while(str[i]==ch && i>=0)
    {
        i--;
    }
    //放置结尾标记
    str[++i]=0;
    return str;
}

/*输入一个10进制的整数，按指定进制反转
 如：7按2进制反转后是7，16按2进制反转后是1*/

int Reverse(int x,int radix)
{
    int y=0;
    while(x)
    {
        y=y*radix+y%radix;
        y=y/radix;
    }
    return y;
}

/*给出一个只含有数字的字符串，按指定进制转换为整数*/
int CharToInt(char* num,int radix)
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
/*整数的从小到大的冒泡排序*/
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
//将一个字符串按指定字符分隔为若干字符串存储到二维数组中
//函数的返回值为分隔字符串个数
int SplitString(char split[][100],char* str,char x)
{
    RomoveCharAtEnd(str, x);
    RomoveCharAtBegin(str, x);
    int sum=0;
    int i=0;
    int j=0;
    while(str[i])
    {
        if(str[i]==x)  //遇见分隔字符
        {
            split[sum][j]=0;  //该行结束
            sum++;
            j=0;
            while(str[i++]==x);  //跳过连续的分隔字符
            i--;
        }
        else
        {
            split[sum][j++]=str[i++];  //拷贝字符到二维数组
        }
    }
    split[sum][j]=0;
    return ++sum;
}

//将整数按指定的进制（2<=radix<=16) 分解为字符串
char* IntToChar(char* num,int n,int radix)
{
    int i=0;
    while(n)
    {
        int m=n%radix;
        if(0<=m && m<=9)  //转换为ASCII码
        {
            num[i++]=m+'0';
        }
        else   //超过10转为A-F
        {
            num[i++]=m-10+'A';
        }
        n=n/radix; //缩小准备取下一位
    }
    num[i]=0;
    strrev(num);  //反转字符串
    return num;
}
//反转字符串，strrev在c99标准中不是标准库函数，一些编译器并没提供
//如果编译器提供了该函数，尽量使用编译器提供的版本
char* strrev(char* str)
{
    int j=strlen(str);   //得到字符串长度
    for(int i=0;i<j/2;i++)  //首尾交换
    {
        char t=str[i];
        str[i]=str[j-i-1];
        str[j-i-1]=t;
    }
    return str;
}
