# ft_printf - Logic

### 1. va_arg를 통해 "*"을 통해 들어온 width나 precision등의 값을 할당 && 포맷에 해당하는 타입의 값을 할당.
|**모두 공통적인 사항이다.**|
|--|
|`flag`자리에는 각 해당하는 formats->format을 인자로 넣어주면 된다.|
```c
alloc_va_arg(t_format *formats, va_list *ap, int flag, ...);
```
---
### 2. 처리해줄 예외사항 처리해주기
|%duixX|%s|
|--|--|
|`([%.d, %.0d], 0, 0) -> [width만큼의 공백] 출력` |`([%10.3s, NULL]) -> [^^^^(nu] 출력`<br>NULL 포인터가 들어올 경우 출력 문자는 `"(null)"`로 바뀌기 때문에 새로 tmp에 할당을 해줘야 한다.|
```c
//ft_printf_hex.c && ft_printf_int.c && ft_printf_unsigned.c 
if (i == 0 && formats->precision == 0)
{
    print_blank(formats->width);
    return (formats->width);
}

//ft_printf_str.c
if (tmp == 0)
    if (!(tmp = ft_strndup("(null)", 6)))
        return (-1);
```
---
### 3. 공백을 제외한 출력문자의 길이를 구함.(0을 삽입한 후의 길이) && 예외사항 적용
|%p|%s|
|--|--|
|`(%.p, 0) dot==TRUE && precision == 0` -> `0x`<br>(※ 이 때, %.0p가 오면 에러(precision 에 해당하는 수가 있기 때문.)<br>`(%p, 0) -> 0x0`<br> 따라서, 각각에 맞게 2와 3으로 길이를 할당해준다.|precision에 따라 str이 precision에 맞추어 짤린다.<br> `precision < strlen(str) -> write(1, str, precision)`<br> 위와 같이 precision만큼만 출력하게 된다.|
```c
//ft_printf_addr.c
count_addr(unsigned long long addr, int *count);
if (addr == 0) //예외사항
    len1 = formats->precision == 0 ? 2 : 3; 


//ft_printf_int.c && ft_printf_hex.c && ft_printf_unsigned.c
j = get_len(t_format *formats, int i, int precision, int width);
j = get_u_len(t_format *formats, unsigned i, int precision, int width);
j = get_hex_len(t_format *formats, unsigned i, int precision, int width);


//ft_printf_str.c
ft_strlen(char *str);
if (formats->precision < len1 && formats->precision != MINUS) //예외사항
    len1 = formats->precision;


//ft_printf_char.c && ft_printf_per.c
그냥 1.
```
---
### 4. 출력할 공백의 개수를 구함
|모두 width와 비교하여 width가 더 크다면 그 차이만큼 공백 출력|
|--|
```c
//ft_printf_addr.c
len2 = formats->width > len1 ? formats->width - len1 : 0;


//ft_printf_int.c && ft_printf_hex.c && ft_printf_unsigned.c
j = formats->width > j ? formats->width - j : 0;


//ft_printf_str.c
len2 = formats->width > len1 ? (formats->width - len1) : 0;


//ft_printf_char.c && ft_printf_per.c
len = formats->width > 1 ? formats->width - 1 : 0;
```
---
### 5. 공백과 공백이 아닌 문자(0이 삽입되있는)를 순서에 맞게(flag가 '-'냐 아니냐에 맞게) 출력
|%%|else|
|--|--|
|**%만** 조건 없이 0플래그 적용.| **%c , %s , %p** 는 **0 플래그 금지(undefined behavior)**<br>**%d , %u , %i , %x , %X** 는 `dot==FALSE`(precision이 정의 X) 일때만 0플래그 적용.|
```c
// ft_printf_per.c
if (formats->flag != '-')
{
    if (formats->flag == '0')
        print_zero(len);
    else
        print_blank(len);
}
write(1, "%", 1);
if (formats->flag == '-')
    print_blank(len);
    
    
// else
if (formats->flag != '-')
    print_blank(int j);
print_tmp;
if (formats->flag == '-')
    print_blank(int j);
```
---
### 6. 출력한 공백의 개수 + 공백이 아닌 문자의 개수를 반환해준다.
