#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int stack[MAX];     // �迭�� �̿��� ���� ����
int top;            // ������ ���(���ÿ� ���� �迭�� ������ INDEX ��ȣ)

/* 1�ܰ� : ���� ����*/
/*=========================================================*/
void init_stack(void) {	
	top = -1;		// �迭 index�� -1 = ���ÿ� ����� ���� ����
}

int push(int t) {

	/* ������ ������ ũ�⸦ �ʰ��� ��� */
	if (top >= MAX - 1) {
		printf("\n    Stack overflow.");
		return -1;
	}

	/* ���� ���� ������ ������ �������� INDEX ��ȣ ����
	   ���ÿ� ������ �߰�*/
	stack[++top] = t;
	return t;
}

/* ���ÿ��� �����͸� ������ */
int pop(void) {	
	if (top < 0) {
		printf("\n   Stack underflow.");
		return -1;
	}
	return stack[top--];
}

/* ���ÿ� ����� ��� ������ ���*/
void print_stack(void) {
	int i;
	printf("\n Stack contents : TOP ----> Bottom\n");
	for (i = top; i >= 0; i--) {
		printf("%-6d", stack[i]);
	}
}

// ������ TOP�� ���� �����´�.
int get_stack_top(void) {
	return (top < 0) ? -1 : stack[top];
}

// ������ ����ִ��� �˻�
int is_stack_empty(void) {
	return (top < 0);
}

/* 2�ܰ�: ������ �켱���� ����*/
/*=========================================================*/

// k �� ���������� �Ǵ��Ѵ�.
int is_operator(int k) {
	return (k == '+' || k == '-' || k == '*' || k == '/' || k == '^' || k == '%');
}

// ����ǥ��� ������ ���Ļ� �������� üũ
int is_legal(char *pf) {
	int f = 0;
	while (*pf) {

		// ó�� ���� �Ѿ��
		while (*pf == ' ') {
			pf++;
		}

		/* �������� ���*/
		if (is_operator(*pf)) {
			f--;
		}
		else {	// ������, ������ ��� �ƴ� ���
			f++;
			while (*pf != ' ' && *pf != '\t') {	// ������ �ƴ� ���

				pf++;
			}
		}

		if (f < 1) 
			break;	// �����ڸ� ���޾� ���� ���
		pf++;
	}
	return (f == 1);
}

// ��ȣ�� �������� �켱���� ����
int precedence(int op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/' || op == '%') return 2;
	if (op == '^') return 3;
	else return 99999;
}

/* 3�ܰ� : ����ǥ����� ����ǥ������� ��ȯ*/
/*=========================================================*/

// ����ǥ����� ����ǥ������� ��ȯ
void postfix(char *pf, char *expr) {

	init_stack();	// �ʱ�ȭ�� ���ÿ��� �ƹ� ���� ������� ����
	while (*expr) {	
		// ���� ����Ű�� �迭�� index�� ���� ���� ��ȣ�̸� stack�� �߰�
		if (*expr == '(') {
			push(*expr);	// ���ÿ� ��ȣ �߰�
			expr++;			// �����͸� ���� �ּҷ� �̵�
		}
		/* ���� ����Ű�� ���� ������ ��ȣ�� ��� */
		else if (*expr == ')') {
			/* ��ȣ�� ������ ������ �Ʒ��� �۾� ����*/
			while (get_stack_top() != '(') {
				*pf++ = pop();		// ���ÿ��� ���� ���� pf�� ���� �� �������� �̵�
				*pf++ = ' ';
			}
			pop();
			expr++;
		}
		/* ��ȣ�� �ƴ� �������� ��� */
		else if (is_operator(*expr)) {
			while (!is_stack_empty() &&
				precedence(get_stack_top()) >= precedence(*expr)) { // �������� �켱���� ���
				*pf++ = pop();	// ���ÿ��� ���� �����ڸ� �迭 pt�� ����
				*pf++ = ' ';
			}
			push(*expr);
			expr++;
		}
		/* ������ ��� ������ ��ȯ */
		else if (*expr >= '0' && *expr <= '9') {
			do {
				*pf++ = *expr++;	// ���� ó�� ���� �迭 pf�� ���� 
			} while (*expr >= '0' && *expr <= '9');
			*pf++ = ' ';
		}
		else {
			expr++;	// �����͸� �Ŀ� ���� ���ڿ������� ���� index�� �̵�
		}
	}

	/* ����ǥ��������� ��ȯ�� ������ ���� �ʿ������ ������ �����ʹ� ��� ���� 
	�迭 pf�� ����Ű�� �����͵� ������ */
	while (!is_stack_empty()) {
		*pf++ = pop();
		*pf++ = ' ';
	}
	pf--;
	*pf = 0;
}

/* 4�ܰ� : ����ǥ��� ���*/
/*=========================================================*/

// ����ǥ������� ����Ѵ�.
int calc(char *p) {
	int i;
	init_stack();
	while (*p) {
		/* ������ ��� ������ ��ȯ */
		if (*p >= '0' && *p <= '9') {
			i = 0;
			do {
				i = i * 10 + *p - '0';
				p++;
			} while (*p >= '0' && *p <= '9');
			push(i);
		}
		/* ��Ģ����� �ŵ�����, ������ ���� ����*/
		switch (*p) {
		case '+':		// ����
			push(pop() + pop());
			break;
		case '*':		// ���ϱ�
			push(pop() * pop());
			break;
		case '-':		// ����
			i = pop();
			push(pop() - i);
			break;
		case '/':		// ������
			i = pop();
			if (i == 0) {// 0���� ������ ��쿡 ���� ����ó��
				printf("\ncannot divided by 0!\n");
				exit(1);
			}
			else
				push(pop() / i);
			break;
		case '^':
			push(pow(pop(), pop()));	// pow() �Լ��� �̿��� �ŵ����� ���� �ǽ�
			break;
		case '%':				// ������ ����
			int val1 = pop();	// ���ÿ��� ���� �������� -> ������ �ϴ� -> ����
			int val2 = pop();	// ���ÿ��� ���߿� �������� -> ������ ��� -> ������
			push(val2 % val1);
			break;
		}
		p++;
	}
	return pop();
}

int main(void) {

	int result;
	char exp[256];
	scanf_s("%[^\n]", exp, sizeof(exp));	// ����� �� �Է�(������, ���� �� ���� ���)
	char pf[256];						// ����ǥ������� ��ȯ�� ����� ����

	postfix(pf, exp);
	printf("\nPostfix : %s", pf);		// ����ǥ������� ��ȯ�� �� ���

	if (!is_legal(pf)) {
		printf("\n Exprssion is illegal!");
		exit(1);
	}

	result = calc(pf);
	
	printf("\nAnswer : %d", result);			// ��� ��� ���

	return 0;
}
