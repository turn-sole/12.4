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
	//������ݵĿռ�
	STDataType* data;
	//ջ��λ��
	size_t top;
	//ջ������
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
	//��������topʱ��˵������û�пռ���
	if (ST->Cacpcity == ST->top)
	{
		//����ռ�Ϊ0����ʼ�ռ�4�������Ϊ0���ռ�*2
		int NewCacpcity = ST->Cacpcity == 0 ? 4 : ST->Cacpcity * 2;
		//����
		STDataType* newdata = (STDataType*)realloc(ST->data, sizeof(STDataType) * NewCacpcity);
		//�����Ƿ�ɹ�
		if (newdata == NULL)
		{
			printf("reallo fail\n");
			exit(-1);
		}
		ST->data = newdata;
		//��������
		ST->Cacpcity = NewCacpcity;
	}
}

//������ջ
void StackPush(ST* ST, STDataType x)
{
	//���ԣ���������ָ�벻��Ϊ��
	assert(ST);
	//���������Զ�����
	CheckCacpcity(ST);

	//β��������ջ
	*(ST->data + ST->top) = x;
	ST->top++;
}
