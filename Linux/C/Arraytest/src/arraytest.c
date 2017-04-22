/*
到目前为止，介绍的都是基本数据类型（整型、字符型、浮点型等），C语言还提供了3种复合数据类型：数组、结构体、共用体。复合数据类型是由基本数据类型按照一定的规则构造的。

一维数组的定义和使用
数组是由类型名、标识符、维数组成的复合数据类型。类型名规定了存放在数组种的元素的类型，而维数则指定了数组中包含的元素个数，标识符用来标识这个数组。
数组定义的一般形式是：
数据类型 标识符[元素个数]
例如，以下定义了一个含有10个整型元素的数组：
int a[10]:
数组元素的类型可以是基本类型也可以是复合数据类型。标识符的命名规则和一般变量名相同。元素个数指定了数组中元素的个数，它必须是常量表达式。
下面定义的数组是不合法的：
int n=10;
int a[n];
n是变量而不是常量或常量表达式。
数组和变量一样，也是先定义后使用，C语言规定只能引用数组的一个元素而不能一次引用整个数组，数组引用的一般形式是：
标识符[下标]
例如：数组a[10]的10个元素分别为a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]
a[0]=10;
把10赋给数组的第一个元素。
在定义数组时可以进行初始化，例如：
int a[10]={9,8,7,6,5,4,3,2,1,0};
则a[0]被赋予了初值9，a[1]为8，以此类推。
可以为数组的部分元素指定初始值，例如：
a[10]={9,8};
a[10]、a[1]被赋予了初值9、8,其余元素被自动赋予初值0.
如果定义数组时，它所有的元素都进行了初始化就不用指定元素的个数，例如下面也定义了一个含有10个整型元素的数组。
int a[]={9,8,7,6,5,4,3,2,1,0};
注意：在所有函数外定义的数组的所有元素将被自动赋予初值0，在函数内部定义的数组，系统不会为其进行初始化，在使用数组元素前必须先对元素进行初始化。

二位数组的定义和使用
二位数组定义的一般形式为:
数据类型 标识符[第一维维数][第二维维数]
第一维通常称为行，第二维则称为列，与一维数组一样，二维数组的维数也必须是常量表达式。
例如：
float array[3][4];
定义了一个3行4列的数组。它的所有元素为：
a[0][0]	a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2]	a[2][3]
可以用以下方法对二维数组进行初始化。
1)将所有数据写在一个大括号内，例如：
array[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
a[0][0]、a[0][1]到a[2][3]依次被赋初值1,2到12。
2)分行赋值
array[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
这种赋值比较直观，第1个大括号内的数据赋给第一行，第2个大括号内的数据赋给第二行，依次类推。
3)部分赋值
array[3][4]={{1},{2,3},{4,5,6}};
以这种方式赋值，array数组的所有元素为：
1,0,0,0
2,3,0,0
4,5,6,0
这种方式在数组的大部分元素的初值为0的情况下使用比较方便，
也可以只对某几行元素进行赋值，例如：
array[3][4]={{1},{2,3}};
则各个元素的值为：
1,0,0,0
2,3,0,0
0,0,0,0
4)如果对全部元素都赋初值，则定义数组时第一维的维数可以省略，但第二维的维数必须指定，例如：
array[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
系统自动计算第一维的维数，第一维的维数是12/4,即3。
或者：
array[][4]={{1},{},{4,5,6}};
系统会自动识别该数组的第一维的维数是3。这个数组的各个元素值为:
1,0,0,0
0,0,0,0
4,5,6,0

将一个二维数组的行和列元素互换，存到另一个二维数组中，如有一个二维数组：
1,2,3,4,
5,6,7,8
则交换后的数组为：
1,5
2,6
3,7
4,8
程序代码如下:
*/
#include <stdio.h>
int main(){
	int a[2][4]={{1,2,3,4},{5,6,7,8}};
	int b[4][2],i,j;
	
	printf("array a:\n");
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			printf("%5d",a[i][j]);
			b[j][i]=a[i][j];
		}
		printf("\n");
	}
	printf("array b:\n");
	for(i=0;i<4;i++){
		for(j=0;j<2;j++){
			printf("%5d",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
