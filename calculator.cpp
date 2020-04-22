#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int stack[MAX];     // 배열을 이용한 스택 구현
int top;            // 스택의 상단(스택에 대한 배열의 마지막 INDEX 번호)

/* 1단계 : 스택 구현*/
/*=========================================================*/
void init_stack(void) {	
	top = -1;		// 배열 index가 -1 = 스택에 저장된 값이 없음
}

int push(int t) {

	/* 정해진 스택의 크기를 초과한 경우 */
	if (top >= MAX - 1) {
		printf("\n    Stack overflow.");
		return -1;
	}

	/* 스택 범위 내에서 마지막 데이터의 INDEX 번호 증가
	   스택에 데이터 추가*/
	stack[++top] = t;
	return t;
}

/* 스택에서 데이터를 꺼내옴 */
int pop(void) {	
	if (top < 0) {
		printf("\n   Stack underflow.");
		return -1;
	}
	return stack[top--];
}

/* 스택에 저장된 모든 데이터 출력*/
void print_stack(void) {
	int i;
	printf("\n Stack contents : TOP ----> Bottom\n");
	for (i = top; i >= 0; i--) {
		printf("%-6d", stack[i]);
	}
}

// 스택의 TOP의 값을 가져온다.
int get_stack_top(void) {
	return (top < 0) ? -1 : stack[top];
}

// 스택이 비어있는지 검사
int is_stack_empty(void) {
	return (top < 0);
}

/* 2단계: 연산자 우선순위 설정*/
/*=========================================================*/

// k 가 연산자인지 판단한다.
int is_operator(int k) {
	return (k == '+' || k == '-' || k == '*' || k == '/' || k == '^' || k == '%');
}

// 후위표기법 수식이 형식상 적절한지 체크
int is_legal(char *pf) {
	int f = 0;
	while (*pf) {

		// 처음 공백 넘어가기
		while (*pf == ' ') {
			pf++;
		}

		/* 연산자인 경우*/
		if (is_operator(*pf)) {
			f--;
		}
		else {	// 연산자, 공백이 모두 아닌 경우
			f++;
			while (*pf != ' ' && *pf != '\t') {	// 공백이 아닌 경우

				pf++;
			}
		}

		if (f < 1) 
			break;	// 연산자만 연달아 사용된 경우
		pf++;
	}
	return (f == 1);
}

// 괄호와 연산자의 우선순위 설정
int precedence(int op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/' || op == '%') return 2;
	if (op == '^') return 3;
	else return 99999;
}

/* 3단계 : 중위표기식을 후위표기식으로 변환*/
/*=========================================================*/

// 중위표기법을 후위표기법으로 변환
void postfix(char *pf, char *expr) {

	init_stack();	// 초기화된 스택에는 아무 값도 저장되지 않음
	while (*expr) {	
		// 현재 가리키는 배열의 index의 값이 왼쪽 괄호이면 stack에 추가
		if (*expr == '(') {
			push(*expr);	// 스택에 괄호 추가
			expr++;			// 포인터를 다음 주소로 이동
		}
		/* 현재 가리키는 값이 오른쪽 괄호인 경우 */
		else if (*expr == ')') {
			/* 괄호가 닫히기 전까지 아래의 작업 수행*/
			while (get_stack_top() != '(') {
				*pf++ = pop();		// 스택에서 꺼낸 값을 pf에 저장 후 다음으로 이동
				*pf++ = ' ';
			}
			pop();
			expr++;
		}
		/* 괄호가 아닌 연산자인 경우 */
		else if (is_operator(*expr)) {
			while (!is_stack_empty() &&
				precedence(get_stack_top()) >= precedence(*expr)) { // 연산자의 우선순위 고려
				*pf++ = pop();	// 스택에서 꺼낸 연산자를 배열 pt에 저장
				*pf++ = ' ';
			}
			push(*expr);
			expr++;
		}
		/* 숫자인 경우 정수로 변환 */
		else if (*expr >= '0' && *expr <= '9') {
			do {
				*pf++ = *expr++;	// 식의 처음 값을 배열 pf에 저장 
			} while (*expr >= '0' && *expr <= '9');
			*pf++ = ' ';
		}
		else {
			expr++;	// 포인터를 식에 대한 문자열에서의 다음 index로 이동
		}
	}

	/* 후위표기식으로의 변환이 끝나면 이제 필요없어진 스택의 데이터는 모두 비우고 
	배열 pf를 가리키는 포인터도 해제됨 */
	while (!is_stack_empty()) {
		*pf++ = pop();
		*pf++ = ' ';
	}
	pf--;
	*pf = 0;
}

/* 4단계 : 후위표기식 계산*/
/*=========================================================*/

// 후위표기법으로 계산한다.
int calc(char *p) {
	int i;
	init_stack();
	while (*p) {
		/* 숫자인 경우 정수로 변환 */
		if (*p >= '0' && *p <= '9') {
			i = 0;
			do {
				i = i * 10 + *p - '0';
				p++;
			} while (*p >= '0' && *p <= '9');
			push(i);
		}
		/* 사칙연산과 거듭제곱, 나머지 연산 수행*/
		switch (*p) {
		case '+':		// 덧셈
			push(pop() + pop());
			break;
		case '*':		// 곱하기
			push(pop() * pop());
			break;
		case '-':		// 뺄셈
			i = pop();
			push(pop() - i);
			break;
		case '/':		// 나눗셈
			i = pop();
			if (i == 0) {// 0으로 나누는 경우에 대한 예외처리
				printf("\ncannot divided by 0!\n");
				exit(1);
			}
			else
				push(pop() / i);
			break;
		case '^':
			push(pow(pop(), pop()));	// pow() 함수를 이용한 거듭제곱 연산 실시
			break;
		case '%':				// 나머지 연산
			int val1 = pop();	// 스택에서 먼저 빠져나옴 -> 스택의 하단 -> 제수
			int val2 = pop();	// 스택에서 나중에 빠져나옴 -> 스택의 상단 -> 피제수
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
	scanf_s("%[^\n]", exp, sizeof(exp));	// 계산할 식 입력(연산자, 숫자 간 공백 허용)
	char pf[256];						// 후위표기식으로 변환한 연산식 저장

	postfix(pf, exp);
	printf("\nPostfix : %s", pf);		// 후위표기식으로 변환한 식 출력

	if (!is_legal(pf)) {
		printf("\n Exprssion is illegal!");
		exit(1);
	}

	result = calc(pf);
	
	printf("\nAnswer : %d", result);			// 계산 결과 출력

	return 0;
}
