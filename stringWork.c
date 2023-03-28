#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Created by Artem on 15.03.2023.
//
char *findString(char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j])
                return &str[i];
        }
    }

    return NULL;
}

int getCount(const char *str, const char *substr) {
    int j; int count = 0;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                count++;
            }
        }
    }

    return count;
}

int contains(const char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                return 1;
            }
        }
    }

    return 0;
}

void getTagText(char *tag, char *buffer) {
    char *ptr1; const char *ptr2;

    ptr1 = findString(tag, ">") + 1;
    ptr2 = findString(ptr1, "<");
    strncpy(buffer, ptr1, ptr2-ptr1);
    buffer[ptr2-ptr1] = '\0';
}

char* getLeft(const char* str) {
    int sub = 0;
    char nbsp[6] = "&nbsp;";
    int j; int i;
    for(i = 0; str[i]; i++) {
        if(str[i] == '&' || str[i] == ' ') {
            for(j = 0; j < 6 && str[i+j] != nbsp[j]; j++);
            if(j == 6 || str[i] == ' ')
            {
                sub = i;
                break;
            }
        }
    }
    if(sub == 0)
        sub = i;
    char* buf = (char*)malloc((sub+1)*sizeof(char));
    strncpy(buf, str, sub);
    buf[sub] = '\0';
    return buf;
}
void removeSpaces(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
