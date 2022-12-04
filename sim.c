#include<stdio.h>
int main() {
    int a = 1234;
    printf("%#o %#X", a, a);
    return 0;
    return 0;
}
typedef int STDataType;

struct Stack
{
	//存放数据的空间
	STDataType* data;
	//栈顶位置
	size_t top;
	//栈的容量
	size_t Cacpcity;
}ST;
void StackInto(ST* ST)
{
	ST->data = NULL;
	ST->top = 0;
	ST->Cacpcity = 0;
}
void CheckCacpcity(ST* ST)
{
	//容量等于top时，说明数组没有空间了
	if (ST->Cacpcity == ST->top)
	{
		//如果空间为0，初始空间4，如果不为0，空间*2
		int NewCacpcity = ST->Cacpcity == 0 ? 4 : ST->Cacpcity * 2;
		//扩容
		STDataType* newdata = (STDataType*)realloc(ST->data, sizeof(STDataType) * NewCacpcity);
		//扩容是否成功
		if (newdata == NULL)
		{
			printf("reallo fail\n");
			exit(-1);
		}
		ST->data = newdata;
		//更新容量
		ST->Cacpcity = NewCacpcity;
	}
}

//数据入栈
void StackPush(ST* ST, STDataType x)
{
	//断言，传进来的指针不能为空
	assert(ST);
	//容量不够自动增容
	CheckCacpcity(ST);

	//尾部数据入栈
	*(ST->data + ST->top) = x;
	ST->top++;
}
