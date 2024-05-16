#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 *  * _printf - Custom implementation of printf function.
 *   * @format: The format string containing the characters and the specifiers.
 *    *
 *     * Return: The number of characters printed.
 *      */
int _printf(const char *format, ...)
{
	    va_list args;
	        int count = 0;
		    const char *ptr;
		        char *str;
			    char ch;

			        va_start(args, format);

				    for (ptr = format; *ptr != '\0'; ptr++) {
					            if (*ptr == '%') {
							                ptr++;
									            switch (*ptr) {
											                    case 'c':
														                        ch = (char) va_arg(args, int);
																	                    write(1, &ch, 1);
																			                        count++;
																						                    break;
																								                    case 's':
																								                        str = va_arg(args, char *);
																											                    while (*str) {
																														                            write(1, str, 1);
																																	                            str++;
																																				                            count++;
																																							                        }
																													                        break;
																																                case '%':
																																                    write(1, "%", 1);
																																		                        count++;
																																					                    break;
																																							                    default:
																																							                        write(1, "%", 1);
																																										                    write(1, ptr, 1);
																																												                        count += 2;
																																															                    break;
																																																	                }
										            } else {
												                write(1, ptr, 1);
														            count++;
															            }
						        }

				        va_end(args);
					    return count;
}

int main(void)
{
	    int len;

	        len = _printf("Hello, %s!\n", "world");
		    _printf("Length: %d\n", len);

		        len = _printf("Character: %c\n", 'A');
			    _printf("Length: %d\n", len);

			        len = _printf("Percentage: %%\n");
				    _printf("Length: %d\n", len);

				        return 0;
}
