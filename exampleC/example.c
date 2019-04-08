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
