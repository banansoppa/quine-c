#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char *argv[]) {
    char out[] = "#include <stdio.h>\n#include <string.h>\n#include <stdbool.h>\nint main(int argc, char *argv[]) {\n    char out[] = \"?\";\n    bool foundQ = false;\n    for(int i = 0; i < strlen(out); i++) {\n        if(out[i]=='?' && !foundQ) {\n            foundQ = true;\n            for(int j = 0; j < strlen(out); j++) {\n                char toPrint = out[j];\n                if(out[j]=='\\n') {\n                    toPrint = 'n';\n                    printf(\"%c\", '\\');\n                } else if(out[j]=='\"') {\n                    toPrint = '\"';\n                    printf(\"%c\", '\\');\n                } else if(out[j]=='\\') {\n                    toPrint = '\\';\n                    printf(\"%c\", '\\');\n                }\n                printf(\"%c\", toPrint);\n            }\n        } else {\n            if(out[i]=='\\' && out[i+1]!='n') {\n                printf(\"%c\",'\\');\n            }\n            printf(\"%c\",out[i]);\n        }\n    }\n    return 0;\n}\n";
    bool foundQ = false;
    for(int i = 0; i < strlen(out); i++) {
        if(out[i]=='?' && !foundQ) {
            foundQ = true;
            for(int j = 0; j < strlen(out); j++) {
                char toPrint = out[j];
                if(out[j]=='\n') {
                    toPrint = 'n';
                    printf("%c", '\\');
                } else if(out[j]=='"') {
                    toPrint = '"';
                    printf("%c", '\\');
                } else if(out[j]=='\\') {
                    toPrint = '\\';
                    printf("%c", '\\');
                }
                printf("%c", toPrint);
            }
        } else {
            if(out[i]=='\\' && out[i+1]!='n') {
                printf("%c",'\\');
            }
            printf("%c",out[i]);
        }
    }
    return 0;
}
