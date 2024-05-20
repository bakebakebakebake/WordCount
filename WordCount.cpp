#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countCharacters(FILE* file) {
    int characterCount = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        characterCount++;
    }
    printf("字符数：%d\n", characterCount);
}

void countWords(FILE* file) {
    int wordCount = 0;
    char c;
    int inWord = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' | c == '\t' || c == '\n' || c == ',') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }
    printf("单词数：%d\n", wordCount);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("错误的参数数量\n");
        return 1;
    }

    char* parameter = argv[1];
    char* fileName = argv[2];

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", fileName);
        return 1;
    }

    if (strcmp(parameter, "-c") == 0) {
        countCharacters(file);
    } else if (strcmp(parameter, "-w") == 0) {
        countWords(file);
    } else {
        printf("无效的参数 %s\n", parameter);
        return 1;
    }

    fclose(file);

    return 0;
}