/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int len_dest = 0;
    int len_src = 0;

    for (len_dest = 0; dest[len_dest] != '\0'; len_dest++);
    for (len_src = 0; src[len_src] != '\0'; len_src++);
    for (i = len_dest; i < len_src + len_dest; i++) {
        dest[i] = src[j];
        j += 1;
    }
    dest[i] = '\0';
    return (dest);
}
