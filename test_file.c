int checkPrimeNumber(int n);

int main() 
{
    float x = 3.657;
    int n1, n2, i, flag;
    for (i = n1 + 1; i < n2; i = i + 1) 
    {
        flag = checkPrimeNumber(i);
        if (flag == 1)
            x = x - 1.5;
    }
    return 0;
}

int checkPrimeNumber(int n) 
{
    int j, flag = 1;
    for (j = 2; j <= n / 2; j = j + 1) 
    {
        if (n % j == 0) 
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

%token INT FLOAT
%token <str> NAME <num_i> NUM_INT <num_f> NUM_FLOAT
%token LESS GREATER EQUAL LESS_EQUAL GREATER_EQUAL NOT_EQUAL IS_EQUAL
%token AND OR NOT
%token PLUS MINUS MUL DIV MOD
%token SEMI COMMA COLON
%token LB RB LC RC
%token MAIN VOID RETURN BREAK DEFAULT IF ELSE SWITCH CASE FOR WHILE